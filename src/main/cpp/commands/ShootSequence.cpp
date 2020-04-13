#include "commands/ShootSequence.h"

ShootSequenceCommand::ShootSequenceCommand(IntakeSubsystem* intake, BeltSubsystem* belt, ShooterSubsystem* shooter) {
    addCommands(
        SpinUpCommand(shooter),
        BeltCommand(belt)
    );

}