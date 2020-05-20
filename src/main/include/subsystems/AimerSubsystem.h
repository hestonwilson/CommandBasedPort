#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

#include "Constants.h"
/** The AimerSubsystem controls the aiming motor 
 * on the robot. It is separate from the shooter subsystem
 * to prevent subsystem requirement conflicts between commands.
 */ 
class AimerSubsystem : public frc2::SubsystemBase {
 public:
  AimerSubsystem();
  //TODO implement PID control for the aimer.
  // void Periodic() override;

 private:
  WPI_TalonSRX m_aimer;
};