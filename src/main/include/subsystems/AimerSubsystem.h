#pragma once

#include <frc2/command/SubsystemBase>
#include "ctre/Phoenix.h"

#include "Constants.h"
/** The AimerSubsystem controls the aiming motor 
 * on the robot. It is separate from the shooter subsystem
 * to prevent subsystem requirement conflicts between commands.
 */ 
class AimerSubsystem : public frc2::SubsystemBase {
 public:
  AimerSubsystem();
 
  void Raise();
  void Lower();

 private:
  WPI_TalonSRX m_aimer;
}