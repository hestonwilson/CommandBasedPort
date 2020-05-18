#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem *subsystem)
: m_subsystem{subsystem}
{
    AddRequirements(subsystem);
}

void DriveCommand::Initialize(){}

void DriveCommand::Execute() {

}
//keep the drive command going.
bool DriveCommand::IsFinished() {return false;}



