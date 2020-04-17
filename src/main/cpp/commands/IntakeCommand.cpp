#include "commands/IntakeCommand.h"

RunIntakeCommand::RunIntakeCommand(IntakeSubsystem* subsystem)
: m_intake{subsystem} {
}

void RunIntakeCommand::Execute() {
m_intake->RunIntake();
}
bool RunIntakeCommand::IsFinished() {
//the intake command will be active while a button is pressed.
return false;
}
void RunIntakeCommand::End(bool interrupted) {
m_intake->Stop();
}