#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Constants.h"

#include "subsystems/LimelightSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/AimerSubsystem.h"

/** this command is meant to get the robot to the optimal target distance
 * so the shooter is most accurate. The logic will of this command
 * will be moved into the aim command eventually but for now it is separate for testing purposes.
 */
// class GetInRangeCommand : public frc2::CommandHelper<frc2::CommandBase, GetInRangeCommand> {
//  public:
//   GetInRangeCommand();

  
// };