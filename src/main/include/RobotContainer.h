/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RunCommand.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>
#include <frc/controller/PIDController.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/Trajectory.h>

#include "commands/ExampleCommand.h"
#include "commands/DriveCommand.h"
#include "commands/IntakeCommand.h"
#include "commands/BeltCommand.h"
#include "commands/SpinUpCommand.h"
#include "commands/ShootSequenceCommand.h"

#include "subsystems/ExampleSubsystem.h"
#include "subsystems/ElevatorSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/BeltSubsystem.h"
#include "subsystems/LimelightSubsystem.h"
#include "subsystems/AimerSubsystem.h"

#include "Constants.h"
#include "PenguinUtil.h"

// #include "Autonomous/Trajectories.h"

/**
 * This class is where the bulk of the robot is declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic is
 *  handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) is declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  
  //TODO give options for autonomous
  enum AutonomousAction {
    DoNothing = 0
  };
  
 private:
  // The robot's subsystems and commands are defined here...
 
  //Subsystems
  ExampleSubsystem m_subsystem;
  DriveSubsystem m_driveSubsystem;
  ElevatorSubsystem m_elevatorSubsystem;
  BeltSubsystem m_beltSubsystem;
  IntakeSubsystem m_intakeSubsystem;
  ShooterSubsystem m_shooterSubsystem;
  AimerSubsystem m_aimerSubsystem;
  
  //Joysticks
  frc::Joystick m_leftJoystick{0};
  frc::Joystick m_rightJoystick{1};
  frc::Joystick m_gamerJoystick{2};
  frc::Joystick m_utilityJoystick{3};
  
  //Joystick Buttons
  frc2::JoystickButton elevatorUpButton{&m_leftJoystick, PenguinConstants::CommandButtons::ELEVATOR_UP_BUTTON};
  frc2::JoystickButton elevatorDownButton{&m_leftJoystick, PenguinConstants::CommandButtons::ELEVATOR_DOWN_BUTTON};
  frc2::JoystickButton SpinUpButton{&m_gamerJoystick, PenguinConstants::CommandButtons::SPIN_UP_BUTTON};
  frc2::JoystickButton RunIntakeButton{&m_gamerJoystick, PenguinConstants::CommandButtons::RUN_INTAKE_BUTTON};
  frc2::JoystickButton resetGyroButton{&m_leftJoystick, PenguinConstants::CommandButtons::RESET_GYRO_BUTTON}; //forgot what joystick flight is so this is a guess.

  //Commands
  ExampleCommand m_autonomousCommand;
  // DriveCommand m_driveCommand;
  RunIntakeCommand m_intakeCommand;
  BeltCommand m_beltCommand;
  SpinUpCommand m_spinUpCommand;
  ShootSequenceCommand m_shootSequenceCommand;
  frc2::InstantCommand m_resetGyro{[this] {m_driveSubsystem.ResetGyroscope();}, {&m_driveSubsystem}};
  //chooser for autonomous
  frc::SendableChooser<frc2::Command*> m_chooser;
  //chooser for autonomous actions
  frc::SendableChooser<AutonomousAction> m_actionChooser;
  //private methods.
  void ConfigureButtonBindings();
};
