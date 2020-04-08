#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class DriveCommand : public frc2::CommandHelper<frc2::CommandBase, DriveCommand>{
 public:
  /**
   * Creates a new DriveCommand.
   *
   * @param DriveSubsystem The subsystem used by this command.
*/
  explicit DriveCommand(DriveSubsystem* subsystem);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;

 private:
  DriveSubsystem* m_subsystem;
};