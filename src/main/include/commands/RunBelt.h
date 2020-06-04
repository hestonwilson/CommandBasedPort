#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/BeltSubsystem.h"

class RunBelt : public frc2::CommandHelper<frc2::CommandBase, RunBelt> {
public:
 /**
   * Creates a new RunBelt Command
   *
   * @param subsystem The belt subsystem used by this command.
   */
explicit RunBelt(BeltSubsystem* subsystem);

void Execute() override;
bool IsFinished() override;

private:
BeltSubsystem* m_belt;
};