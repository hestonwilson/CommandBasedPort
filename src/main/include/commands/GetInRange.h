#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include <units/units.h>

#include "Constants.h"

#include "subsystems/LimelightSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/AimerSubsystem.h"

/** this command is meant to get the robot to the optimal target distance
 * so the shooter is most accurate. The logic of this command
 * will be moved into the aim command eventually but for now it is separate for testing purposes.
 * This may be converted to a ProfiledPIDCommand eventually
 */
class GetInRange : public frc2::CommandHelper<frc2::PIDCommand, GetInRange> {
 public:
  //todo figure out a way to adjust the range based on target type and maybe include aimer for more control.
  GetInRange(LimelightSubsystem* limelight, DriveSubsystem* drivetrain);
  
  
  bool IsFinished() override;
 private:

  std::string m_target;
  //not empirical like basically every measurement during covid time
  std::map<std::string, double> m_optimalTargetDistanceMap = {{"UpperTarget", 3.2}, {"LowerTarget", 6.0}};
};