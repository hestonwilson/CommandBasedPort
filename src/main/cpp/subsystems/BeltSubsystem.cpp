#include "subsystems/BeltSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

BeltSubsystem::BeltSubsystem() 
: m_beltMotor{PenguinConstants::CAN::BELT},
m_ballDetector{PenguinConstants::I2C::BALL_LIDAR},
m_beltEncoder{PenguinConstants::DIO::BELT_ENCODER_A, PenguinConstants::DIO::BELT_ENCODER_B} {

  m_beltEncoder.SetDistancePerPulse(PenguinConstants::MathConstants::PI / 8192);
  m_ballCurrentlyPassingInFrontOfLidar = BallDetectedByLidar();
  m_beltMotor.ConfigFactoryDefault();
  m_beltMotor.SetInverted(true);
}

/**
 * TODO: find solution to duplicating the lidar logic in both files,
 * 
 */
void BeltSubsystem::Periodic() {
  m_currentLidarDistance = m_ballDetector.GetDistance();
  UpdateBallCount();
  PutDiagnostics();
}
//not going to add any other logic to this function so that commands can add their own.
void BeltSubsystem::RunBelt(double percentDampen) {
  m_beltMotor.Set(1 * percentDampen);
}
void BeltSubsystem::Stop() {
  m_beltMotor.Set(0);
}
void BeltSubsystem::PutDiagnostics() {
  using SD = frc::SmartDashboard;
  SD::PutBoolean("ball in front of lidar", m_ballCurrentlyPassingInFrontOfLidar);
  SD::PutNumber("balls in system", m_ballCount);
  SD::PutNumber("lidar currently reporting (in)", units::inch_t(m_currentLidarDistance).to<double>());
 
}
void BeltSubsystem::UpdateBallCount() {
  const bool ballDetected = BallDetectedByLidar();
  if (!m_ballCurrentlyPassingInFrontOfLidar) {
    if (ballDetected) {
      m_ballCurrentlyPassingInFrontOfLidar = true;
      m_ballCount += 1;
    }
  } else {
    if (!ballDetected) {
      m_ballCurrentlyPassingInFrontOfLidar = false;
    }
  }
}
bool BeltSubsystem::BallDetectedByLidar() {
  return m_currentLidarDistance < PenguinConstants::ShooterSystem::LIDAR_NORMAL_DISTANCE * 0.8;
}