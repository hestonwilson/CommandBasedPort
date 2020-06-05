#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>
#include <frc/controller/PIDController.h>
#include <frc/geometry/Translation2d.h>

#include <units/units.h>

#include "subsystems/LimelightSubsystem.h"
#include "subsystems/DriveSubsystem.h"

#include "Constants.h"

/** AlignToTarget uses the limelight to align with the 
 * target and aim. It is a PIDCommand so PID control
 *  is built in.
 */
class AlignToTarget : public frc2::CommandHelper<frc2::PIDCommand, AlignToTarget> {
 public:
  AlignToTarget(LimelightSubsystem* limelight, DriveSubsystem* drivetrain);
  
  bool IsFinished() override;
  
  
 private:
  LimelightSubsystem m_limelight;
  DriveSubsystem m_drivetrain;

 
};