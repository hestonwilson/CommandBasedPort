#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/RunBelt.h"
#include "commands/SpinUp.h"
#include "subsystems/BeltSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
class ShootSequence : public frc2::CommandHelper<frc2::SequentialCommandGroup, ShootSequence> {
  public:
  /** creates a new ShootSequence
   * @param shooter the shooter subsystem
   * @param belt the belt subsystem
   * 
*/
  ShootSequence(BeltSubsystem* belt, ShooterSubsystem* shooter);
  
  //not overriding IsFinished because it will end when the button is not held.
   void End(bool interrupted) override;

  private:
   BeltSubsystem* m_belt;
   ShooterSubsystem* m_shooter;
};