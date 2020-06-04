#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>
#include <frc2/command/PIDCommand.h>

#include <units/units.h>

#include "subsystems/DriveSubsystem.h"

#include "Constants.h"

class TurnToAngle : public frc2::CommandHelper<frc2::PIDCommand, TurnToAngle> {
 public:
 
  TurnToAngle(units::degree_t targetAngle, DriveSubsystem* drivetrain);
  // void Execute() override;
  bool IsFinished() override;
  // void End(bool interrupted); //this command will likely not be bound to any triggers.

 private:
  frc2::PIDController m_controller{1, 0.5, 1};
  // DriveSubsystem* m_driveSubsystem;
  units::degree_t m_targetAngle;
  units::degree_t m_currentAngle;

  units::degree_t kTurnTolerance = units::degree_t(0.5);
  /**
  * TODO test tolerance
  */
  units::degrees_per_second_t kTurnRateTolerance = 20_deg_per_s; 
};
