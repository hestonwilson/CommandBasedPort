#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/BeltSubsystem.h"

class BeltCommand : public frc2::CommandHelper<CommandBase, BeltCommand> {
public:
 /**
   * Creates a new BeltCommand Command
   *
   * @param subsystem The belt subsystem used by this command.
   */
explicit BeltCommand(BeltSubsystem* subsystem);

void Execute() override;
bool IsFinished() override;

private:
BeltSubsystem* m_belt;
};