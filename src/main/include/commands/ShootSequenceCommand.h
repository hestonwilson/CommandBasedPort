#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/BeltCommand.h"
#include "commands/SpinUpCommand.h"
#include "subsystems/BeltSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
class ShootSequenceCommand : public frc2::CommandHelper<frc2::SequentialCommandGroup, ShootSequenceCommand> {
  public:
  /** creates a new shootsequence command
   * @param shooter the shooter subsystem
   * @param intake the intake subsystem
   * @param belt the belt subsystem
   * 
*/
  ShootSequenceCommand(BeltSubsystem* belt, ShooterSubsystem* shooter);
  
  //not overriding IsFinished because it will end when the button is not held.
   void End(bool interrupted) override;
};