#include "commands/BeltCommand.h"
// TODO bind BeltCommand to a trigger so it can

/** Creates a new BeltCommand
 *  @param subsystem a pointer to a BeltSubsystem
 */
BeltCommand::BeltCommand(BeltSubsystem* subsystem)
:m_belt(subsystem) {
  AddRequirements({subsystem});
}

void BeltCommand::Execute() {
  m_belt->m_beltMotor.Set(1); //TODO make this more precise
}
//BeltCommand does not have finish because 
// it will be interrupted by the ShootSequenceCommand ending.
bool BeltCommand::IsFinished() {
return false;
}
