#pragma once
#include <frc/command/CommandHelper.h>
#include <frc/command/CommandBase.h>
#include <frc2/Timer.h>
#include "subsystems/LimelightSubsystem.h"
#include "subsystems/DriveSubsystem.h"

class AlignToTargetCommand : public frc2::CommandHelper<CommandBase, AlignToTargetCommand> {

 public:
  AlignToTargetCommand(LimelightSubsystem* limelight, DriveSubsystem* drivetrain);
  frc2::timer m_timer;
  units::second_t m_currentTime = units::second_t(0);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  units::seconds_t startTime = 0_s;
  units::milliseconds_t lastTime = units::milliseconds_t(0);
  LimelightSubsystem* m_limelight;
  DriveSubsystem* m_drivetrain;
}