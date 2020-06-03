#include "commands/GetInRangeCommand.h"
#include <frc/controller/PIDController.h>

GetInRangeCommand::GetInRangeCommand(LimelightSubsystem* limelight, DriveSubsystem* drivetrain)
: CommandHelper(frc2::PIDController(1.5, 0, 0.5),                                       //darn imperial units
                [limelight] {return limelight->EstimateTargetDistance(units::radian_t(0), units::meter_t(38.5_in), 1_m, limelight->horizontalOffsetAngle).to<double>(); },
                2.0,             
                [drivetrain] (double output) {drivetrain->Drive(output, 0.0, 0.0, false, frc::Translation2d()); },
                {drivetrain, limelight}) {

  AddRequirements({drivetrain});
  AddRequirements({limelight});

  m_controller.SetTolerance(0.2, 0.5);
}

bool GetInRangeCommand::IsFinished() { return GetController().AtSetpoint(); }





