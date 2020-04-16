#include "commands/BeltCommand.h"

explicit BeltCommand(BeltSubsystem* subsystem)
:m_belt(subsystem) {

}

void BeltCommand::Execute() {
  m_belt->m_beltMotor.Set(1); //TODO make this more precise
}
bool BeltCommand::IsFinished() {
return false;
//does not have to finish because it will be interrupted when the command group ends.
}