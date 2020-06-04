#pragma once
#include "subsystems/IntakeSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class RunRunIntake : public frc2::CommandHelper<frc2::CommandBase, RunRunIntake> {

public:
   /**
   * Creates a new RunRunIntake
   *
   * @param subsystem The intake subsystem used by this command.
   */
  explicit RunRunIntake(IntakeSubsystem* subsystem);
  
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

private:
  IntakeSubsystem* m_intake;
};
