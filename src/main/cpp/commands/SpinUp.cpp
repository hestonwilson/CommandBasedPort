#include "commands/SpinUp.h"
/** This command is intended to be used in the
 * ShootSequence. Due to this it does not override the 
 * end method and should not be used on its own, lest the shooter
 * spin without stopping.
 */

SpinUp::SpinUp(ShooterSubsystem* subsystem) 
: m_shooter{subsystem} {
  
  AddRequirements({subsystem});
}
//TODO determine if this does not need to be overridden.

void SpinUp::Execute() {
m_shooter->Shoot();
}
bool SpinUp::IsFinished() {
if(m_shooter->ShooterReadyToShoot()) {
    return true;
  }
  return false;
}
// Do not end this command because it will be used in a sequential command group,
// the End() method of ShootSequence will stop the shooter.


