#pragma once
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

#include "PenguinUtil.h"
#include "Lidar.h"
#include "Constants.h"
#include <frc2/command/SubsystemBase.h>

#include "frc/smartdashboard/SmartDashboard.h"
#include "frc/Encoder.h"
#include "frc/controller/SimpleMotorFeedforward.h"

#include "units/units.h"
#include <unordered_map>
class ShooterSubsystem : public frc2::SubsystemBase {
  public:

  ShooterSubsystem(int shooterID, int beltID, int aimerID, int intakeID, frc::I2C::Port lidarPort);
  bool BallDetectedByLidar();
  void Periodic();

  void Update();
  void PutDiagnostics();
  void ConfigESCs();

  void Intake(bool run);
  void Shoot(bool run);
  void RunManual();
  void DontRun();

  void EnterManualMode();
  bool InManualMode();

  void RunShooterIf(bool run);
  void RunShooterWithWPIFF(bool run);
  void RunIntakeIf(bool run);
  void RunBeltIf(bool run);

  rev::CANSparkMax m_shooter; /** +: shoots the ball */
  WPI_TalonSRX m_belt; /** +: moves the ball toward the shooter */
  WPI_TalonSRX m_aimer; /** +: moves the hood up (lowering shot) */
  WPI_TalonSRX m_intake; /** +: picks up the ball */

 private:

  enum Mode {
    INTAKING, SHOOTING, MANUAL
  } m_mode = SHOOTING; // default mode to shooting because that's the first action in a match

  const std::unordered_map<Mode, std::string> MODE_STRINGS = {
    {Mode::INTAKING, "Intaking"}, {Mode::SHOOTING, "Shooting"}, {Mode::MANUAL, "Manual"}
  };

  Lidar m_ballDetector;

  rev::CANEncoder m_shooterEncoder = m_shooter.GetEncoder();
  rev::CANPIDController m_shooterPID = m_shooter.GetPIDController();

  frc::SimpleMotorFeedforward<units::turns> m_shooterFF{PenguinConstants::ShooterSystem::Characterization::kS, PenguinConstants::ShooterSystem::Characterization::kV, PenguinConstants::ShooterSystem::Characterization::kA};

  bool m_ballCurrentlyPassingInFrontOfLidar;
  units::inch_t m_currentLidarDistance; // temp, probably. Would want to move into update and make `const` eventually, but need global to reference in `PutDiagnostics()`.

  /** How many balls are currently being carried by the robot. Hard-coded as 3 to start. */
  public: // TODO: make this private (when counting works reliably)
  int m_ballCount = 3;
  private:

  /** RPM of NEOs operating at maximum efficiency/max power output.
   * From here: https://motors.vex.com/vexpro-motors/cim-motor.
   */
  static constexpr units::revolutions_per_minute_t SHOOTING_SPEED = units::revolutions_per_minute_t(2940);
  bool ShooterReadyToShoot(units::revolutions_per_minute_t atSpeed, double withinPercent);

  void UpdateBallCount();

  units::meter_t dist_away_x;
  units::meter_t dist_away_y;
};

