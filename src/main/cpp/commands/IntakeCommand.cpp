#include "commands/IntakeCommand.h"

RunIntakeCommand::RunIntakeCommand(IntakeSubsystem* subsystem)
: m_intake{subsystem} {
  AddRequirements(subsystem);
}

void RunIntakeCommand::Execute() {
m_intake->RunIntake();
}

//RunIntakeCommand does not have an exit condition because it is bound to a trigger.
bool RunIntakeCommand::IsFinished() {
return false;
}

void RunIntakeCommand::End(bool interrupted) {
m_intake->Stop();
}