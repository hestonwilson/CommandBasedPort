#include "commands/ShootSequenceCommand.h"

ShootSequenceCommand::ShootSequenceCommand(IntakeSubsystem* intake, BeltSubsystem* belt, ShooterSubsystem* shooter) {
    addCommands(
        SpinUpCommand(shooter),
        BeltCommand(belt)
    );

   

}
 void End(bool interrupted) {
     belt->Stop();
     shooter->Stop();
 }