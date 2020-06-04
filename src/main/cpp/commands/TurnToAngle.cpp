#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "commands/TurnToAngle.h"


TurnToAngle::TurnToAngle(units::degree_t targetAngle, DriveSubsystem* drivetrain)
: CommandHelper(frc2::PIDController{1, 0, 0.5},
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


// void TurnToAngle::Execute() {
// //   m_currentAngle = drivetrain->GetAngle();

// }

bool TurnToAngle::IsFinished() { return GetController().AtSetpoint(); }