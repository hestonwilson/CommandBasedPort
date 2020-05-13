#pragma once
#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

#include "Constants.h"
#include "Lidar.h"

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();
  WPI_TalonSRX m_intakeMotor;
  int m_ballCount;
  void Periodic() override;
  void UpdateBallCount();
  void RunIntake();
  bool BallDetectedByLidar();
  void Stop();
  
 private:
  bool m_ballCurrentlyPassingInFrontOfLidar;
  units::inch_t m_currentLidarDistance;
  Lidar m_ballDetector;
};