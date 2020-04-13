#include "commands/IntakeCommand.h"

explicit RunIntakeCommand::RunIntakeCommand(IntakeSubsystem* subsystem)
: m_intake{subsystem} {

}
void RunIntakeCommand::Initalize() {

}
void RunIntakeCommand::Execute() {
m_intake.Run();
}
bool RunIntakeCommand::IsFinished() {
//the intake command will be active while a button is pressed.
return false;
}
void RunIntakeCommand::End(bool interrupted) {
m_intake.Stop();
}