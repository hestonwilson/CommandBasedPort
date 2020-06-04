#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <units/units.h>

#include "subsystems/LimelightSubsystem.h"
#include "subsystems/DriveSubsystem.h"

#include "Constants.h"


class AlignToTarget : public frc2::CommandHelper<frc2::CommandBase, AlignToTarget> {
 public:
  AlignToTarget(LimelightSubsystem* limelight, DriveSubsystem* drivetrain);

  

 
};