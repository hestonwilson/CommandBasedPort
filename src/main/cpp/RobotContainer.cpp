/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() : 
m_autonomousCommand(&m_subsystem),
m_intakeCommand(&m_intakeSubsystem),
m_beltCommand(&m_beltSubsystem),
m_spinUpCommand(&m_shooterSubsystem),
m_shootSequenceCommand(&m_beltSubsystem, &m_shooterSubsystem)
{
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
  //prepare default drive command.
  m_driveSubsystem.SetDefaultCommand( DriveCommand(
    &m_driveSubsystem,
    [this] {return m_leftJoystick.GetRawAxis(1);},
    [this] {return m_rightJoystick.GetRawAxis(0);},
    [this] {return m_leftJoystick.GetRawAxis(2);},
    [this] {return !m_rightJoystick.GetRawButton(3);},
    [this] { 
      frc::Translation2d centerOfRotation;
      if(m_leftJoystick.GetRawButton(3)) {
        centerOfRotation = m_driveSubsystem.FRONT_LEFT_CORNER_LOCATION;
      } else if (m_leftJoystick.GetRawButton(6)) {
        centerOfRotation = m_driveSubsystem.FRONT_RIGHT_CORNER_LOCATION;
      } else if (m_leftJoystick.GetRawButton(3)) {
        centerOfRotation = m_driveSubsystem.BACK_LEFT_CORNER_LOCATION;
      } else if (m_leftJoystick.GetRawButton(4)) {
        centerOfRotation = m_driveSubsystem.BACK_RIGHT_CORNER_LOCATION;
      } else {
        centerOfRotation = frc::Translation2d();
      }
      return centerOfRotation;
    }
    ));
//   m_driveSubsystem.SetDefaultCommand(frc2::RunCommand(
//     [this] {
//       //TODO implement this as an actual command instead of lambda

//       bool fieldOrient = !m_rightJoystick.GetRawButton(3);
//       double forward = m_leftJoystick.GetRawAxis(1);
//       forward = PenguinUtil::smartDeadband(forward, -0.2, 0.16);
//       forward *= -1;
//       forward = copysign(pow(forward, 2), forward);
//       double strafe = m_rightJoystick.GetRawAxis(0);
//       strafe = PenguinUtil::smartDeadband(strafe, -0.18, 0.15);
//       strafe *= -1;
//       strafe = copysign(pow(strafe, 2), strafe);
//       double rotation = m_leftJoystick.GetRawAxis(2);
//       // SD::PutNumber("rot raw", rotation);
//       rotation = PenguinUtil::smartDeadband(rotation, -0.31, 0.02, 0.15);
//       rotation *= -1;
//       rotation = copysign(pow(rotation, 2), rotation);
//       frc::Translation2d centerOfRotation;
//       if (m_leftJoystick.GetRawButton(5)) {
//         centerOfRotation = m_driveSubsystem.FRONT_LEFT_CORNER_LOCATION;
//       } else if (m_leftJoystick.GetRawButton(6)) {
//         centerOfRotation = m_driveSubsystem.FRONT_RIGHT_CORNER_LOCATION;
//       } else if (m_leftJoystick.GetRawButton(3)) {
//         centerOfRotation = m_driveSubsystem.BACK_LEFT_CORNER_LOCATION;
//       } else if (m_leftJoystick.GetRawButton(4)) {
//         centerOfRotation = m_driveSubsystem.BACK_RIGHT_CORNER_LOCATION;
//       } else {
//         centerOfRotation = frc::Translation2d();
//       }

//       m_driveSubsystem.Drive(forward, strafe, rotation, fieldOrient, centerOfRotation);
//     },
//     {&m_driveSubsystem}));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  //move elevator up.
  frc2::JoystickButton(&m_leftJoystick, 2)
    .WhenPressed([this] {m_elevatorSubsystem.SetGoal(2_m);}, {&m_elevatorSubsystem});
    //move elevator down
  frc2::JoystickButton(&m_leftJoystick, 3)
    .WhenPressed([this] {m_elevatorSubsystem.SetGoal(0_m);}, {&m_elevatorSubsystem});

  resetGyroButton.WhenPressed(&m_resetGyro);
  RunIntakeButton.WhileHeld(RunIntakeCommand(&m_intakeSubsystem));

}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  //set up config for trajectory.
  frc::TrajectoryConfig config(PenguinConstants::DrivetrainAutonomous::K_MAX_VELOCITY, 
                               PenguinConstants::DrivetrainAutonomous::K_MAX_ACCELERATION);
  //make sure max velocity is obeyed.
  config.SetKinematics(m_driveSubsystem.m_kinematics);
  
  auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass through these two interior waypoints, making an 's' curve path
      {frc::Translation2d(1_m, 1_m), frc::Translation2d(2_m, -1_m)},
      // End 3 meters straight ahead of where we started, facing forward
      frc::Pose2d(3_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass the config
      config);

      //note: for this command to work the onboard PID controller on the Spark Maxes may need to be used.
      frc2::SwerveControllerCommand<4> swerveControllerCommand(
      exampleTrajectory, [this]() 
      { return m_driveSubsystem.GetPose(); },
      m_driveSubsystem.m_kinematics,
      frc2::PIDController(PenguinConstants::DrivetrainAutonomous::kPForwardController, 0, 0),
      frc2::PIDController(PenguinConstants::DrivetrainAutonomous::kPStrafeController, 0, 0),
      frc::ProfiledPIDController<units::radians>{
        PenguinConstants::DrivetrainAutonomous::kPRotationController, 0, 0, frc::TrapezoidProfile<units::radians>::Constraints {PenguinConstants::DrivetrainAutonomous::K_MAX_ANGULAR_VELOCITY, PenguinConstants::DrivetrainAutonomous::K_MAX_ANGULAR_ACCELERATION}
        },
        [this] (auto moduleStates) {m_driveSubsystem.SetModuleStates(moduleStates);},
     {&m_driveSubsystem});

     return new frc2::SequentialCommandGroup(
      std::move(swerveControllerCommand), std::move(swerveControllerCommand),
      frc2::InstantCommand(
          [this]() {
            m_driveSubsystem.Drive(units::meters_per_second_t(0),
                          units::meters_per_second_t(0),
                          units::radians_per_second_t(0), false);
          },
          {}));
}


