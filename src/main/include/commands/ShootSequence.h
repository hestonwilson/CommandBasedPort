#pragma once
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "commands/BeltCommand.h"
#include "commands/IntakeCommand.h"
#include "commands/SpinUpCommand.h"
class ShootSequenceCommand : public frc2::CommandHelper<frc2::SequentialCommandGroup, ShootSequenceCommand> {
  public:
  /** creates a new shootsequence command
   * @param shooter the shooter subsystem
   * @param intake the intake subsystem
   * @param belt the belt subsystem
   * 
*/
  explicit ShootSequenceCommand(IntakeSubsystem* intake, BeltSubsystem* belt, ShooterSubsystem* shooter);
  void Initialize() override;
  void Execute() override;
  
  
  
}