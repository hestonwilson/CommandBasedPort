// #include "subsystems/ShooterSubsystem.h"
// #include "Constants.h"
// #include "PenguinUtil.h"

// ShooterSubsystem::ShooterSubsystem(int shooterID, int beltID, int aimerID, int intakeID, frc::I2C::Port lidarPort) 
//   : m_shooter{shooterID, rev::CANSparkMax::MotorType::kBrushless},
//   m_belt{beltID},
//   m_aimer{aimerID},
//   m_intake{intakeID},
//   m_ballDetector{lidarPort} 
// {
//   m_ballCurrentlyPassingInFrontOfLidar = BallDetectedByLidar();
//   //set PID gains.
//   m_shooterPID.SetP(PenguinConstants::ShooterSystem::ShooterPID::P);
//   m_shooterPID.SetI(PenguinConstants::ShooterSystem::ShooterPID::I);
//   m_shooterPID.SetIZone(PenguinConstants::ShooterSystem::ShooterPID::IZone);
//   m_shooterPID.SetD(PenguinConstants::ShooterSystem::ShooterPID::D);

//   m_shooter.SetClosedLoopRampRate(0);
//   m_shooterEncoder.SetVelocityConversionFactor(1);
// }
// void ShooterSubsystem::Periodic(){
//     int x{3};
//     int y{4};
//     int bruh = x * y;
//     // why not
// }
// void ShooterSubsystem::Update() {
//   m_currentLidarDistance = m_ballDetector.GetDistance();

//   UpdateBallCount();
// }

// void ShooterSubsystem::UpdateBallCount() { 
//   const bool ballDetected = BallDetectedByLidar();
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

// void ShooterSubsystem::PutDiagnostics() {
//   using SD = frc::SmartDashboard;

//   SD::PutBoolean("ball in front of lidar", m_ballCurrentlyPassingInFrontOfLidar);
//   SD::PutNumber("balls in system", m_ballCount);
//   SD::PutNumber("lidar currently reporting (in)", units::inch_t(m_currentLidarDistance).to<double>());
//   // SD::PutString("shooter mode:", MODE_STRINGS[m_mode]); // TODO: maybe `MODE_STRINGS.find(m_mode);` instead? // errors as currently stands
//   SD::PutNumber("shooter speed", m_shooterEncoder.GetVelocity());
// }

// bool ShooterSubsystem::ShooterReadyToShoot(units::revolutions_per_minute_t atSpeed = SHOOTING_SPEED, double withinPercent = 10) {
//   const bool flywheelAdjusted = true; // TODO: adjust based off of limelight, probably. maybe also use odometry?
//   const bool shootingFastEnough = PenguinUtil::withinPercentTolerance(m_shooterEncoder.GetVelocity(), atSpeed.to<double>(), withinPercent);
//   return flywheelAdjusted && shootingFastEnough;    
// }

// bool ShooterSubsystem::BallDetectedByLidar() {
//   return m_currentLidarDistance < PenguinConstants::ShooterSystem::LIDAR_NORMAL_DISTANCE * 0.8;
// }

// void ShooterSubsystem::Intake(bool run) {
//   m_mode = Mode::INTAKING;

//   if (run && m_ballCount < 5) {
//     m_intake.Set(1);
//     if (m_ballCount <= 2 && m_ballCurrentlyPassingInFrontOfLidar) {
//       m_belt.Set(ControlMode::PercentOutput, 0.6);
//     } else {
//     }
//   } else {
//     m_intake.Set(0);
//     m_belt.Set(0);
//   }
// }

// void ShooterSubsystem::Shoot(bool run) {
//   m_mode = Mode::SHOOTING;
  
//   if (run) {
//     RunShooterWithWPIFF(true);
//     if (ShooterReadyToShoot()) {
//       m_belt.Set(ControlMode::PercentOutput, 1);
//     } else {
//       m_belt.Set(ControlMode::PercentOutput, 0);
//     }
//   }
// }

// void ShooterSubsystem::DontRun() {
//   m_shooter.Set(0);
//   m_aimer.Set(0);
//   m_intake.Set(0);
//   m_belt.Set(0);
// }

// void ShooterSubsystem::RunShooterIf(bool run) {
//   m_mode = Mode::SHOOTING;

//   if (run) {
//     m_shooterPID.SetReference(SHOOTING_SPEED.to<double>(), rev::ControlType::kVelocity);
//     // m_shooterPID.SetReference(4500, rev::ControlType::kVelocity);
//   } else {
//     // m_shooterPID.SetReference(0, rev::ControlType::kDutyCycle);
//     m_shooter.Set(0);
//   }
// }

// void ShooterSubsystem::RunShooterWithWPIFF(bool run) {
//   m_mode = Mode::SHOOTING;

//   if (run) {
//     m_shooter.SetVoltage(m_shooterFF.Calculate(SHOOTING_SPEED));
//   } else {
//     m_shooter.Set(0);
//   }
// }

// void ShooterSubsystem::RunIntakeIf(bool run) {
//   if (run) {
//     m_intake.Set(1);
//   } else {
//     m_intake.Set(0);
//   }
// }

// void ShooterSubsystem::RunBeltIf(bool run) {
//   if (run) {
//     m_belt.Set(1);
//   } else {
//     m_belt.Set(0);
//   }
// }

// void ShooterSubsystem::EnterManualMode() {
//   if (m_mode != Mode::MANUAL) {
//     m_mode = Mode::MANUAL;
//   }
// }

// bool ShooterSubsystem::InManualMode() {
//   return m_mode == Mode::MANUAL;
// }

// void ShooterSubsystem::ConfigESCs() {
//   m_intake.ConfigFactoryDefault();
//   m_belt.ConfigFactoryDefault();
//   m_aimer.ConfigFactoryDefault();
//   // Not calling a factory default on the shooter b/c it's on a SparkMax, and [`RestoreFactoryDefaults`](http://www.revrobotics.com/content/sw/max/sw-docs/cpp/classrev_1_1_c_a_n_spark_max_low_level.html#a557335092c72f5a39b19604b365360c2) (I think, based on observed behavior and the wording of the documentation) resets _all_ parameters -- including the CAN ID.

//   m_intake.SetInverted(false);
//   m_belt.SetInverted(true);
//   m_aimer.SetInverted(true);ks
//   m_shooter.SetInverted(true);

//   m_shooter.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

//   // m_aimer.ConfigForwardSoftLimitThreshold(___); // TODO
//   // m_aimer.ConfigReverseSoftLimitThreshold(___); // TODO
//   // m_aimer.ConfigForwardSoftLimitEnable(true); // TODO: when we get the above two done
//   // m_aimer.ConfigReverseSoftLimitEnable(true); // TODO: when we get the above two done

//   m_aimer.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
//   m_aimer.SetSelectedSensorPosition(0); // !Imp: Assumes the aimer is always in the same place when the robot turns on
//   m_aimer.SetSensorPhase(false); // TODO
// }
