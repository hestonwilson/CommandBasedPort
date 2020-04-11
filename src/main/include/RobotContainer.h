/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "commands/DriveCommand.h"
#include <frc2/command/InstantCommand.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "frc/Joystick.h"
#include "subsystems/ElevatorSubsystem.h"




/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  frc2::Command* GetDriveCommand();
  // frc2::Command* GetShootCommand();

  
  

 private:
  // The robot's subsystems and commands are defined here...

  
  ExampleSubsystem m_subsystem;
  DriveSubsystem m_driveSubsystem;
  elevator m_elevatorSubsystem;

  frc::Joystick m_leftJoystick{0};
  frc::Joystick m_rightJoystick{1};
  frc::Joystick m_gamerJoystick{2};
  frc::Joystick m_utilityJoystick{3};

  ExampleCommand m_autonomousCommand;
  DriveCommand m_driveCommand;
  //ShootCommand m_shootCommand;
  //chooser for autonomous
  frc::SendableChooser<frc2::Command*> m_chooser;
  //private methods.
  void ConfigureButtonBindings();
};
