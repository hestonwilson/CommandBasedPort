#include "commands/Drive.h"

DriveCommand::DriveCommand(DriveSubsystem *subsystem, std::function<double()> forward, std::function<double()> strafe, std::function<double()> rotation, std::function<bool()> fieldOriented, std::function<frc::Translation2d()> centerOfRotation)
: m_drive{subsystem},
m_forward{forward},
m_strafe{strafe},
m_rotation{rotation},
m_fieldOriented{fieldOriented},
m_centerOfRotation{centerOfRotation}
{   
  AddRequirements({subsystem});
  SetName("DriveCommand");
  
 
  //note: I have no idea if passing lambdas in from robot container will actually allow me to access the joystick values. Otherwise just make them public.
  
}

void DriveCommand::Initialize(){}

void DriveCommand::Execute() {
  double fwd = m_forward();
  double str = m_strafe();
  double rot = m_rotation();
  bool fieldOriented = m_fieldOriented();
  frc::Translation2d centerOfRotation = m_centerOfRotation();

  //Note deadband values may be subject to change and are not covered
  //under warranty
  fwd = PenguinUtil::smartDeadband(fwd, -0.2, 0.16);
  fwd *= -1;
  fwd = copysign(pow(fwd, 2), fwd);
  
  str *= -1;
  str = copysign(pow(str, 2), str);

  rot *= -1;
  rot = copysign(pow(rot, 2), rot);
  using SD = frc::SmartDashboard;
  SD::PutNumber("fwd command", fwd);
  SD::PutNumber("str command", str);
  SD::PutNumber("rot command", rot);
  m_drive->Drive(fwd, str, rot, fieldOriented, centerOfRotation);

}
//keep the drive command going.
bool DriveCommand::IsFinished() {return false;}

void DriveCommand::LogRaw() {
  bool fieldOriented = m_fieldOriented();
  frc::SmartDashboard::PutBoolean("FieldOriented", fieldOriented);
  frc::SmartDashboard::PutNumber("RawFwdCommand", m_forward());
  frc::SmartDashboard::PutNumber("RawStrCommand", m_strafe());
  frc::SmartDashboard::PutNumber("RawRotCommand", m_rotation());
}

