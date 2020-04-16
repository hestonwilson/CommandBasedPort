#include "subsystems/IntakeSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

IntakeSubsystem::IntakeSubsystem(int intakeID, frc::I2C::Port lidarPort)
:m_intakeMotor(intakeID),
m_ballDetector(lidarPort) {
  m_ballCurrentlyPassingInFrontOfLidar = BallDetectedByLidar();
  m_intakeMotor.ConfigFactoryDefault();
  // m_intakeMotor.SetSmartCurrentLimit(40);
  
}
void IntakeSubsystem::Periodic() {
m_currentLidarDistance = m_ballDetector.GetDistance();
UpdateBallCount();
}
void IntakeSubsystem::RunIntake() {
    if(m_ballCount < 5) {
        m_intakeMotor.Set(1);
    }
    else {
        m_intakeMotor.Set(0);
    }
}


void IntakeSubsystem::UpdateBallCount() {
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
bool IntakeSubsystem::BallDetectedByLidar() {
  return m_currentLidarDistance < PenguinConstants::ShooterSystem::LIDAR_NORMAL_DISTANCE * 0.8;
}
void IntakeSubsystem::Stop() {
  m_intakeMotor.Set(0);
}