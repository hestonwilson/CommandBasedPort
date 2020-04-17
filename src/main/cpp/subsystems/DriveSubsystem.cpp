/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "subsystems/DriveSubsystem.h"
#include "subsystems/SwerveModule.h" 
#include "frc/Joystick.h"


DriveSubsystem::DriveSubsystem() :
m_odometry{m_kinematics, PenguinConstants::MathConstants::ZERO_ROT, m_location} {
  ResetGyroscope();
  // m_navX->SetInverted(true); // just have to take the opposite of the result every time, I guess

  printf("front left angle offset: %f", FRONT_LEFT_ANGLE_OFFSET.to<double>());
  printf("front left angle offset: %f", FRONT_RIGHT_ANGLE_OFFSET.to<double>());
  printf("front left angle offset: %f", BACK_LEFT_ANGLE_OFFSET.to<double>());
  printf("front left angle offset: %f", BACK_RIGHT_ANGLE_OFFSET.to<double>());
}
void DriveSubsystem::Periodic() {

  m_odometry.Update(
    GetAngleAsRot(),
    m_frontLeftModule.GetState(), m_frontRightModule.GetState(), 
    m_backLeftModule.GetState(), m_backRightModule.GetState());
  
}

void DriveSubsystem::SetModuleStates(std::array<frc::SwerveModuleState, 4> desiredStates) {
  m_kinematics.NormalizeWheelSpeeds(&desiredStates, 
                                    PenguinConstants::DrivetrainAutonomous::K_MAX_VELOCITY);
  m_frontLeftModule.SetDesiredState(desiredStates[0]);
  m_backLeftModule.SetDesiredState(desiredStates[1]);
  m_frontRightModule.SetDesiredState(desiredStates[2]);
  m_backRightModule.SetDesiredState(desiredStates[3]);  
}
void DriveSubsystem::Drive(units::meters_per_second_t fwd, units::meters_per_second_t str, units::radians_per_second_t rot, bool fieldOriented, frc::Translation2d centerOfRotation) {
  // rot *= 2. / HYPOT; // TODO: see if this improves things

  auto states = m_kinematics.ToSwerveModuleStates(
    fieldOriented
      ? frc::ChassisSpeeds::FromFieldRelativeSpeeds(fwd, str, rot, GetAngleAsRot())
      : frc::ChassisSpeeds{fwd, str, rot},
    centerOfRotation
  );

  m_kinematics.NormalizeWheelSpeeds(&states, 1_mps);
  // m_kinematics.NormalizeWheelSpeeds(&states, K_MAX_VELOCITY); // flag: CONTROL_VELOCITY_DIRECTLY

  auto [fl, fr, bl, br] = states;

  m_backLeftModule.SetDesiredState(bl);
  m_backRightModule.SetDesiredState(br);
  m_frontLeftModule.SetDesiredState(fl);
  m_frontRightModule.SetDesiredState(fr);
}
// void DriveSubsystem::ResetOdometry(frc::Pose2d pose) {
//   m_odometry.ResetPosition(pose, frc::Rotation2d(units::degree_t(GetHeading())));
// } //TODO get rid of get heading.

// }

void DriveSubsystem::Drive(double fwd, double str, double rot, bool fieldOriented, frc::Translation2d centerOfRotation) {

  // frc::Translation2d centerOfRotation;
  // switch (COR) {
  //   case BACK_LEFT:
  //     centerOfRotation = BACK_LEFT_CORNER_LOCATION;
  //     break;
  //   case BACK_RIGHT:
  //     centerOfRotation = BACK_RIGHT_CORNER_LOCATION;
  //     break;
  //   case FRONT_LEFT:
  //     centerOfRotation = FRONT_LEFT_CORNER_LOCATION;
  //     break;
  //   case FRONT_RIGHT:
  //     centerOfRotation = FRONT_RIGHT_CORNER_LOCATION;
  //     break;
  //   default:
  //     centerOfRotation = frc::Translation2d();
  // }

  Drive(
    fwd * PenguinConstants::DrivetrainAutonomous::K_MAX_VELOCITY,
    str * PenguinConstants::DrivetrainAutonomous::K_MAX_VELOCITY,
    rot * PenguinConstants::DrivetrainAutonomous::K_MAX_ANGULAR_VELOCITY,
    fieldOriented,
    centerOfRotation
  );
}

void DriveSubsystem::PutDiagnostics() {
  using SD = frc::SmartDashboard;

  m_backLeftModule.PutDiagnostics();
  m_backRightModule.PutDiagnostics();
  m_frontLeftModule.PutDiagnostics();
  m_frontRightModule.PutDiagnostics();

  SD::PutNumber("Gyroscope Angle", GetAngle().to<double>());
  
  SD::PutNumber("x location", m_location.Translation().X().to<double>());
  SD::PutNumber("y location", m_location.Translation().Y().to<double>());
}
frc::Pose2d DriveSubsystem::GetPose() {return m_odometry.GetPose();}

void DriveSubsystem::Update() {
  // m_backLeftModule.SDS_UpdateState();
  // m_backRightModule.SDS_UpdateState();
  // m_frontLeftModule.SDS_UpdateState();
  // m_frontRightModule.SDS_UpdateState();

  m_frontLeftModule.ReadSensors();
  m_frontRightModule.ReadSensors();
  m_backLeftModule.ReadSensors();
  m_backRightModule.ReadSensors();

  m_odometry.Update(
    GetAngleAsRot(),
    m_frontLeftModule.GetState(), m_frontRightModule.GetState(), m_backLeftModule.GetState(), m_backRightModule.GetState()
  );

  m_location = m_odometry.GetPose();
}

void DriveSubsystem::ResetGyroscope() {
  // m_navX->SetAngleAdjustment(m_navX->GetAngle());
  m_navX->Reset();
  // m_navX->SetAngleAdjustment(m_navX->GetUnadjustedAngle()); // `GetUnadjustedAngle` isn't a real function, but it's how they do it in SDS
  m_odometry.ResetPosition(frc::Pose2d(), PenguinConstants::MathConstants::ZERO_ROT);
}

units::degree_t DriveSubsystem::GetAngle() const {
  units::degree_t ret =  units::degree_t(fmod(-m_navX->GetAngle(), 360.0));
  return ret < 0_deg ? ret + 360_deg : ret; // TODO: possibly this breaks swerve, check
}

frc::Rotation2d DriveSubsystem::GetAngleAsRot() const {
  return frc::Rotation2d(GetAngle());
}


void DriveSubsystem::UpdateModuleEncoderOFfsetAngles() {
  m_backLeftModule.UpdateAnalogOffset();
  m_backRightModule.UpdateAnalogOffset();
  m_frontLeftModule.UpdateAnalogOffset();
  m_frontRightModule.UpdateAnalogOffset();
}