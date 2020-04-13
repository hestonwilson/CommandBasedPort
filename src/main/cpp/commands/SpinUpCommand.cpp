#include "commands/SpinUpCommand.h"

explicit SpinUpCommand(ShooterSubsystem* subsystem) 
: m_shooter{subsystem} {

}
//TODO determine if this does not need to be overridden.
void SpinUpCommand::Initialize() {
    //do nothing
}
void SpinUpCommand::Execute() {
m_shooter.Shoot();
}
bool SpinUpCommand::IsFinished() {
if(m_shooter.ShooterReadyToShoot()) {
    return true;
}
return false;
}
}
void SpinUpCommand::End(bool interrupted) {
//do nothing here because the sequential command group needs
//to continue on to the next command.
}