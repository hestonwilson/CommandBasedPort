#include "commands/ShootSequence.h"

ShootSequence::ShootSequence(BeltSubsystem* belt, ShooterSubsystem* shooter)
: m_belt{belt},
m_shooter{shooter}
 {
    AddCommands(
        SpinUp(shooter),
        RunBelt(belt)
    );
}

 void ShootSequence::End(bool interrupted) {
     m_belt->Stop();
     m_shooter->Stop();
 }