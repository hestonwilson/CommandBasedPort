#pragma once
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/BeltSubsystem.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class RunIntake : public frc2::CommandHelper<frc2::CommandBase, RunIntake> {
 public:
   RunIntake(IntakeSubsystem* intake, BeltSubsystem* belt);
  
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  IntakeSubsystem* m_intake;
  BeltSubsystem* m_belt;
};
