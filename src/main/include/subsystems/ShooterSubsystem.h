#pragma once
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <units/units.h>

#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include "rev/CANEncoder.h"
#include "rev/CANPIDController.h"

#include "Constants.h"
#include "PenguinUtil.h"
#include "subsystems/LimelightSubsystem.h"
/** Originally in the  team 2551 2020 code
 *  the shooter subsystem encapsulated the belt,intake
 * and the shooter/aimer. Now the shooter subsystem is split
 * into the belt, intake, and shooter/aimer. This allows each of them to 
 * be split into their own subsystems and have their own commands.
 * 
 */
class ShooterSubsystem : public frc2::SubsystemBase {
 public:
   ShooterSubsystem();
   void Periodic() override;
   //TODO: make aimer its own subsystem. 
   void Shoot();
   void Stop();
   void PutDiagnostics();
   void RunShooterWithFeedForward();
   
   
   rev::CANSparkMax m_shooter;
   
   rev::CANPIDController m_shooterPID = m_shooter.GetPIDController();
   //LimelightSubsystem m_limelight;

   rev::CANEncoder m_shooterEncoder = m_shooter.GetEncoder();
   /** RPM of NEOs operating at maximum efficiency/max power output.
      * From here: https://motors.vex.com/vexpro-motors/cim-motor.
      */
   //TODO move these to constants
   static constexpr units::revolutions_per_minute_t SHOOTING_SPEED = units::revolutions_per_minute_t(2940);
   static constexpr double PERCENTAGE_TOLERANCE = 10;
   bool ShooterReadyToShoot();
   
   frc::SimpleMotorFeedforward<units::turns> m_shooterFF{PenguinConstants::ShooterSystem::Characterization::kS, PenguinConstants::ShooterSystem::Characterization::kV, PenguinConstants::ShooterSystem::Characterization::kA};
   units::meter_t dist_away_x;
   units::meter_t dist_away_y;
};