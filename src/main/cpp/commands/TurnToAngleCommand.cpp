#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "commands/TurnToAngleCommand.h"


TurnToAngleCommand::TurnToAngleCommand(units::degree_t targetAngle, DriveSubsystem* drivetrain)
: CommandHelper(frc2::PIDController{PenguinConstants::TurnPID::P, PenguinConstants::TurnPID::I, PenguinConstants::TurnPID::D},
                [drivetrain] { return drivetrain->GetAngle().to<double>();},
                targetAngle.to<double>(),
                [drivetrain] (double output) { drivetrain->Drive(0.0, 0.0, output, true, frc::Translation2d());},
                {drivetrain}) {
  
  // Set the controller to be continuous (because it is an angle controller)
  m_controller.EnableContinuousInput(-180, 180);
  // Set the controller tolerance - the delta tolerance ensures the robot is
  // stationary at the setpoint before it is considered as having reached the
  // reference
  m_controller.SetTolerance(kTurnTolerance.to<double>(),
                            kTurnRateTolerance.to<double>());
  AddRequirements({drivetrain});
}


// void TurnToAngleCommand::Execute() {
// //   m_currentAngle = drivetrain->GetAngle();

// }

bool TurnToAngleCommand::IsFinished() { return GetController().AtSetpoint(); }