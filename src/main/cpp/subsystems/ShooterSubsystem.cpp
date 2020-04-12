#include "subsystems/ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem(int shooterID, int beltID)
: m_shooter{shooterID, rev::CANSparkMax::MotorType::kBrushless},
m_aimer{aimerID} 
{
  
  m_shooterPID.SetP(PenguinConstants::ShooterSystem::ShooterPID::P);
  m_shooterPID.SetI(PenguinConstants::ShooterSystem::ShooterPID::I);
  m_shooterPID.SetIZone(PenguinConstants::ShooterSystem::ShooterPID::IZone);
  m_shooterPID.SetD(PenguinConstants::ShooterSystem::ShooterPID::D);

  m_shooter.SetClosedLoopRampRate(0);
  m_shooterEncoder.SetVelocityConversionFactor(1);
}
bool ShooterSubsystem::ShooterReadyToShoot() {
  const bool flywheelAdjusted = true; // TODO: adjust based off of limelight, probably. maybe also use odometry?
  const bool shootingFastEnough = PenguinUtil::withinPercentTolerance(m_shooterEncoder.GetVelocity(), atSpeed.to<double>(), withinPercent);
  return flywheelAdjusted && shootingFastEnough;     
}