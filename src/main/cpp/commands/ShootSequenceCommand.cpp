#include "commands/ShootSequenceCommand.h"

ShootSequenceCommand::ShootSequenceCommand(BeltSubsystem* belt, ShooterSubsystem* shooter)
: m_belt{belt},
m_shooter{shooter}
 {
    AddCommands(
        SpinUpCommand(shooter),
        BeltCommand(belt)
    );
}

 void ShootSequenceCommand::End(bool interrupted) {
     m_belt->Stop();
     m_shooter->Stop();
 }