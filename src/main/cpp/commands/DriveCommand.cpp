#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem *subsystem, std::function<double()> forward, std::function<double()> strafe, std::function<double()> rotation, std::function<bool()> fieldOriented, std::function<frc::Translation2d()> centerOfRotation)
: m_subsystem{subsystem},
m_forward{forward},
m_strafe{strafe},
m_rotation{rotation},
m_fieldOrientedChecker{fieldOriented},
m_centerOfRotationChooser{centerOfRotation}
{   
  AddRequirements({subsystem});
  SetName("DriveCommand");
  m_centerOfRotation = m_centerOfRotationChooser();
  m_fieldOriented = m_fieldOrientedChecker();
}

void DriveCommand::Initialize(){}

void DriveCommand::Execute() {

}
//keep the drive command going.
bool DriveCommand::IsFinished() {return false;}



