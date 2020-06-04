#include "commands/RunIntake.h"

RunRunIntake::RunRunIntake(IntakeSubsystem* subsystem)
: m_intake{subsystem} {
  AddRequirements({subsystem});
}

void RunRunIntake::Execute() {
m_intake->RunIntake();
}

//RunRunIntake does not have an exit condition because it is bound to a trigger.
bool RunRunIntake::IsFinished() {
return false;
}

void RunRunIntake::End(bool interrupted) {
m_intake->Stop();
}