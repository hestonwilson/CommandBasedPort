// #include "commands/AlignToTargetCommand.h"
// #include "RobotContainer.h"
// #include <cmath>

// AlignToTargetCommand::AlignToTargetCommand(LimelightSubsystem* limelight, DriveSubsystem* drivetrain)
// :m_limelight{limelight},
// m_drivetrain{drivetrain}
// {

// }
// void AlignToTargetCommand::Initialize() {
//   startTime = m_timer.Get();
//   lastTime = m_timer.GetFPGATimestamp();
//   m_timer.Start(); //TODO: check if the timer can actually be used like this. 
  
// }
// void AlignToTargetCommand::Execute() {
//   double time = m_timer.GetFPGATimestamp();
//   double dt = time - lastTime;
//   m_limelight->TurnLEDOn();
//   m_limelight->SetAsVisionProcessor();
//   //TODO: get this good.
//   //m_timer.Delay(0.3);
//   double scalar = 0.15;
//   double strafe;
//   double forward = m_leftJoystick.GetRawAxis(1);
//   //forward *= -1;  //TODO: invert forward or not?
//   forward = PenguinUtil::smartDeadband(forward, -0.2, 0.16) * scalar;
      
//       forward = copysign(pow(forward, 2), forward);
//       double strafe = m_rightJoystick.GetRawAxis(0);
//       //strafe = PenguinUtil::smartDeadband(strafe, -0.18, 0.15);
//       //strafe *= -1;
//       //strafe = copysign(pow(strafe, 2), strafe);
//       double rotation = m_leftJoystick.GetRawAxis(2);
//       // SD::PutNumber("rot raw", rotation);
      
//       rotation = copysign(pow(rotation, 2), rotation);
//   //TODO make this section of code not absolute garbage.
//   if(m_limelight->HasAnyValidTargets() && fabs(PenguinUtil::deadband((m_rightJoystick.GetRawAxis(0)), 0.025) < 0.75)){
//     strafe = controller.Calculate(units::radian_t(m_limelight.horizontalOffsetAngle), dt); 
//   } else {
//       value = PenguinUtil::deadband(m_rightJoystick.GetRawAxis(0));
//       strafe = -PenguinUtil::deadband(strafe);
//       strafe = copysign(strafe * strafe, strafe);            
//   }
//   double rotation = m_leftJoystick.GetRawAxis(2);
//   rotation *= -1;
//   rotation = PenguinUtil::deadband(rotation, 0.025);
//   rotation = copysign(rotation * rotation, rotation);
  
// }
// bool AlignToTargetCommand::IsFinished() {
// //   double tx = m_limelight.horizontalOffsetAngle;
// //   double ta = m_limelight.targetArea;
// //   double angleTolerance = 0.9;
// //   if(m_timer.Get() - startTime < 300 && tx == 0) {
// //       return false; //TODO: check if this condition works
// //   }
// //   if(tx > -1 * angleTolerance &7 tx < angleTolerance) {
// //       m_drivetrain.Drive(0, 0, 0, false, 0);
// //   } else {
  
    
// //   }
// //no end condition because this command will be run by a button.
//   return false;
// }
// void AlignToTargetCommand::End(bool interrupted) {
//     m_limelight->SetAsDriverCamera();
// }