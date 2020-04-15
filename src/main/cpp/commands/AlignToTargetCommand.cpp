#include "commands/AlignToTargetCommand.h"
#include "RobotContainer.h"

AlignToTargetCommand::AlignToTargetCommand(LimelightSubsystem* limelight, DriveSubsystem* drivetrain)
:m_limelight{limelight},
m_drivetrain{drivetrain}
{

}
void AlignToTargetCommand::Initialize() {
  startTime = m_timer.Get();
  lastTime = m_timer.GetFPGATimestamp();
  m_timer.Start(); //TODO: check if the timer can actually be used like this. 
  
}
void AlignToTargetCommand::Execute() {
  double time = m_timer.GetFPGATimestamp();
  double dt = time - lastTime;
  m_limelight->TurnLEDOn();
  m_limelight->SetAsVisionProcessor();
  //TODO: get this good.
//   //m_timer.Delay(0.3);
//   double scalar = 0.15;
//   double forward = m_leftJoystick.GetRawAxis(1) * scalar;
//   double strafe;
//   //TODO make this section of code not absolute garbage.
//   if(m_limelight->HasAnyValidTargets() && fabs(m_rightJoystick.GetRawAxis(0);) < 0.75) {
//     strafe = controller.Calculate(units::radian_t(m_limelight.horizontalOffsetAngle), dt); //TODO see if this needs to be passed through deadband
//   } else {
//       value = PenguinUtil::deadband(m_rightJoystick.GetRawAxis(0));
//       strafe = std::copy_sign(value * value, value)               //trying simple deadband like 2910, may not work out
//   }
  
  
  
}
bool AlignToTargetCommand::IsFinished() {
//   double tx = m_limelight.horizontalOffsetAngle;
//   double ta = m_limelight.targetArea;
//   double angleTolerance = 0.9;
//   if(m_timer.Get() - startTime < 300 && tx == 0) {
//       return false; //TODO: check if this condition works
//   }
//   if(tx > -1 * angleTolerance &7 tx < angleTolerance) {
//       m_drivetrain.Drive(0, 0, 0, false, 0);
//   } else {
  
    
//   }
  return false;
}