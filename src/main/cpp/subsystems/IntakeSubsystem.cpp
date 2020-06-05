#include "subsystems/IntakeSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

IntakeSubsystem::IntakeSubsystem()
:m_intakeMotor(PenguinConstants::CAN::INTAKE),
m_ballDetector(PenguinConstants::I2C::BALL_LIDAR) {
  // m_ballCurrentlyPassingInFrontOfLidar = BallDetectedByLidar();
  m_ballDetector.UpdateBallCurrentlyPassingInFrontOfLidar();
  m_intakeMotor.ConfigFactoryDefault();
  // m_intakeMotor.SetSmartCurrentLimit(40);
  
}
void IntakeSubsystem::Periodic() {
// m_currentLidarDistance = m_ballDetector.GetDistance();
// UpdateBallCount();
  m_ballDetector.UpdateDistance();
  m_ballDetector.UpdateBallCount();

}
void IntakeSubsystem::RunIntake() {
  m_intakeMotor.Set(1);
}


// void IntakeSubsystem::UpdateBallCount() {
//     const bool ballDetected = BallDetectedByLidar();
//   if (!m_ballCurrentlyPassingInFrontOfLidar) {
//     if (ballDetected) {
//       m_ballCurrentlyPassingInFrontOfLidar = true;
//       m_ballCount += 1;
//     }
//   } else {
//     if (!ballDetected) {
//       m_ballCurrentlyPassingInFrontOfLidar = false;
//     }
//   }
// }
// bool IntakeSubsystem::BallDetectedByLidar() {
//   return m_currentLidarDistance < PenguinConstants::ShooterSystem::LIDAR_NORMAL_DISTANCE * 0.8;
// }
void IntakeSubsystem::Stop() {
  m_intakeMotor.Set(0);
}