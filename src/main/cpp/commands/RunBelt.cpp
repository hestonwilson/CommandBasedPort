#include "commands/RunBelt.h"
// TODO bind RunBelt to a trigger so it can

/** Creates a new RunBelt
 *  @param subsystem a pointer to a BeltSubsystem
 */
RunBelt::RunBelt(BeltSubsystem* subsystem)
:m_belt(subsystem) {
  AddRequirements({subsystem});
}

void RunBelt::Execute() {
  m_belt->m_beltMotor.Set(1); //TODO make this more precise
}
//RunBelt does not have finish because 
// it will be interrupted by the ShootSequence ending.
bool RunBelt::IsFinished() {
return false;
}
