#include "subsystems/ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem()
: m_shooter{PenguinConstants::CAN::SHOOTER, rev::CANSparkMax::MotorType::kBrushless},
m_aimer{PenguinConstants::CAN::AIMER} 
{
  m_aimer.ConfigFactoryDefault();
  m_shooter.SetClosedLoopRampRate(0);
  m_shooterEncoder.SetVelocityConversionFactor(1);
  m_shooter.SetInverted(true);
  m_shooter.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  // did not make this a pid subsystem because we are using rev
  // can pid  controller.
  m_shooterPID.SetP(PenguinConstants::ShooterSystem::ShooterPID::P);
  m_shooterPID.SetI(PenguinConstants::ShooterSystem::ShooterPID::I);
  m_shooterPID.SetIZone(PenguinConstants::ShooterSystem::ShooterPID::IZone);
  m_shooterPID.SetD(PenguinConstants::ShooterSystem::ShooterPID::D);

  m_aimer.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
  m_aimer.SetSelectedSensorPosition(0); // !Imp: Assumes the aimer is always in the same place when the robot turns on
  m_aimer.SetSensorPhase(false); // TODO

  
}
  bool ShooterSubsystem::ShooterReadyToShoot() {
  const bool flywheelAdjusted = true; // TODO: adjust based off of limelight, probably. maybe also use odometry?
  const bool shootingFastEnough = PenguinUtil::withinPercentTolerance(m_shooterEncoder.GetVelocity(), SHOOTING_SPEED.to<double>(), 10);
  return flywheelAdjusted && shootingFastEnough;     
}
  void ShooterSubsystem::Periodic() {
    PutDiagnostics();
  }
  void ShooterSubsystem::Shoot() {
    RunShooterWithFeedForward();
    //originally the shoot command also activated the belt
    // however now it just needs to spin up to speed.
    // everything else will be handled by other subsystems.
  }
  void ShooterSubsystem::Stop() {
    m_shooter.Set(0);
  }

  void ShooterSubsystem::PutDiagnostics() {
    frc::SmartDashboard::PutNumber("shooter speed", m_shooterEncoder.GetVelocity());
  }
  void ShooterSubsystem::RunShooterWithFeedForward() {
    m_shooter.SetVoltage(m_shooterFF.Calculate(SHOOTING_SPEED));
  }
