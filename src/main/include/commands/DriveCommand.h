#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/geometry/Translation2d.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/DriveSubsystem.h"

#include <functional>

class DriveCommand : public frc2::CommandHelper<frc2::CommandBase, DriveCommand>{
 public:
  /**
   * Creates a new DriveCommand.
   *
   * @param DriveSubsystem The subsystem used by this command.
*/
  
  DriveCommand(DriveSubsystem* subsystem, std::function<double()> forward, std::function<double()> strafe, std::function<double()> rotation, std::function<bool()> fieldOriented, std::function<frc::Translation2d()> centerOfRotation );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;

 private:
  DriveSubsystem* m_subsystem;
  // these are declared as a function object so a lambda can be 
  //used to get the joystick input.
  bool m_fieldOriented;
  frc::Translation2d m_centerOfRotation;
  std::function<bool()> m_fieldOrientedChecker;
  std::function<frc::Translation2d()> m_centerOfRotationChooser;
  std::function<double()> m_forward;
  std::function<double()> m_strafe;
  std::function<double()> m_rotation;
};