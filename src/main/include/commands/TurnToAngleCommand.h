#pragma once

#include <frc2/command/CommandBase.h>
#include <fr2/command/CommandHelper.h>

class TurnToAngleCommand : public frc2::CommandHelper<frc2::CommandBase, TurnToAngleCommand> {
    TurnToAngleCommand();
    void Execute() override;
}