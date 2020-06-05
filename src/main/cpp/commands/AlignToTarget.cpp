#include "commands/AlignToTarget.h"


AlignToTarget::AlignToTarget(LimelightSubsystem* limelight, DriveSubsystem* drivetrain)
: CommandHelper(frc2::PIDController(1.5, 0.0, 0.5),
                [drivetrain] { return drivetrain->GetAngle().to<double>(); },
                0, 
                [drivetrain] (double output) { drivetrain->Drive(0.0, 0.0, output, false, frc::Translation2d()); },
                {limelight, drivetrain}) {
  
  
  m_controller.EnableContinuousInput(-180, 180);
  
  //totally random placeholders
  m_controller.SetTolerance(0.2, 0.6);

  AddRequirements({limelight});
  AddRequirements({drivetrain});
}

bool AlignToTarget::IsFinished() { return GetController().AtSetpoint(); }

