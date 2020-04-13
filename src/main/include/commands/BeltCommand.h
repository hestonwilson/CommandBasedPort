#pragma once
#include <frc/command/CommandBase.h>
#include <frc/command/CommandHelper.h>
#include "subsystems/BeltSubsystem.h"

class BeltCommand : public frc2::CommandHelper<CommandBase, BeltCommand> {
public:
 /**
   * Creates a new BeltCommand Command
   *
   * @param subsystem The belt subsystem used by this command.
   */
explicit BeltCommand(BeltSubsystem* subsystem);
void Initialize() override;
void Execute() override;
void IsFinished() override;
void End(bool interrupted) override;
private:
BeltSubsystem m_belt;
};