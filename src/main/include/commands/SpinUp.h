#pragma once
#include "subsystems/ShooterSubsystem.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class SpinUp : public frc2::CommandHelper<frc2::CommandBase, SpinUp> {

public:
   /**
   * Creates a new Shoot Command
   *
   * @param subsystem The shooter subsystem used by this command.
   */
  explicit SpinUp(ShooterSubsystem* subsystem);
  
  void Execute() override;
  
  bool IsFinished() override;

private:
  ShooterSubsystem* m_shooter;
};