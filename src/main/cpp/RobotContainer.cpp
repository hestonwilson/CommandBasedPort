/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "Constants.h"
#include "subsystems/DriveSubsystem.h"
#include "PenguinUtil.h"
#include "subsystems/ShooterSubsystem.h"

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/PIDCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>



RobotContainer::RobotContainer() : 
m_autonomousCommand(&m_subsystem), 
m_driveCommand(&m_driveSubsystem)
 {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
  //prepare default drive command.
  m_driveSubsystem.SetDefaultCommand(frc2::RunCommand(
    [this] {
      //TODO implement this as an actual command instead of lambda
      bool fieldOrient = !m_rightJoystick.GetRawButton(3);
      double forward = m_leftJoystick.GetRawAxis(1);
      forward = PenguinUtil::smartDeadband(forward, -0.2, 0.16);
      forward *= -1;
      forward = copysign(pow(forward, 2), forward);
      double strafe = m_rightJoystick.GetRawAxis(0);
      strafe = PenguinUtil::smartDeadband(strafe, -0.18, 0.15);
      strafe *= -1;
      strafe = copysign(pow(strafe, 2), strafe);
      double rotation = m_leftJoystick.GetRawAxis(2);
      // SD::PutNumber("rot raw", rotation);
      rotation = PenguinUtil::smartDeadband(rotation, -0.31, 0.02, 0.15);
      rotation *= -1;
      rotation = copysign(pow(rotation, 2), rotation);
      frc::Translation2d centerOfRotation;
      if (m_leftJoystick.GetRawButton(5)) {
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

      m_driveSubsystem.Drive(forward, strafe, rotation, fieldOrient, centerOfRotation);
    },
    {&m_driveSubsystem}));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  //move elevator up.
  frc2::JoystickButton(&m_leftJoystick, 2)
    .WhenPressed([this] {m_elevator->SetGoal(2_m)}, {&m_elevator});
}
//move elevator down
  frc2::JoystickButton(&m_leftJoystick, 3)
    .WhenPressed([this] {m_elevator->SetGoal(0_m)}, {&m_elevator});

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
frc2::Command *RobotContainer::GetDriveCommand()
{
    // teleop drive command
    return &m_driveCommand;
}

// frc2::Command *RobotContainer::GetShootCommand() {
   
//    return &m_shootCommand;
// }
