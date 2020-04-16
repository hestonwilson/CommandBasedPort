#pragma once
#include "subsystems/IntakeSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class RunIntakeCommand : public frc2::CommandHelper<frc2::CommandBase, RunIntakeCommand> {

public:
   /**
   * Creates a new RunIntakeCommand
   *
   * @param subsystem The intake subsystem used by this command.
   */
  explicit RunIntakeCommand(IntakeSubystem* subsystem);
  
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

private:
  IntakeSubsystem* m_intake;
};
