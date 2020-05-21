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
  //this is not necessary, TODO
//   m_centerOfRotation = m_centerOfRotationChooser();
//   m_fieldOriented = m_fieldOrientedChecker();

  //Test if my approach with passing in lambdas works.
  frc::SmartDashboard::PutBoolean("FieldOriented", m_fieldOriented);
  frc::SmartDashboard::PutNumber("CenterOfRotationX", m_centerOfRotation.X().to<double>());
  frc::SmartDashboard::PutNumber("CenterOfRotationY", m_centerOfRotation.Y().to<double>());
  frc::SmartDashboard::PutNumber("FwdCommand", m_forward());
  frc::SmartDashboard::PutNumber("StrCommand", m_strafe());
  frc::SmartDashboard::PutNumber("RotCommand", m_rotation());
}

void DriveCommand::Initialize(){}

void DriveCommand::Execute() {

}
//keep the drive command going.
bool DriveCommand::IsFinished() {return false;}



