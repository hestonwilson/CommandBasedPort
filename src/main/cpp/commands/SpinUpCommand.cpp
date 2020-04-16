#include "commands/SpinUpCommand.h"
/** This command is intended to be used in the
 * ShootSequenceCommand. Due to this it does not override the 
 * end method and should not be used on its own, lest the shooter
 * spin without stopping.
 */

explicit SpinUpCommand(ShooterSubsystem* subsystem) 
: m_shooter{subsystem} {

}
//TODO determine if this does not need to be overridden.

void SpinUpCommand::Execute() {
m_shooter->Shoot();
}
bool SpinUpCommand::IsFinished() {
if(m_shooter->ShooterReadyToShoot()) {
    return true;
  }
}


