#pragma once
#include <frc2/command/ProfiledPIDSubsystem.h>
#include <units/units.h>
#include "ctre/Phoenix.h"
#include "Constants.h"
#include <frc/Encoder.h"
#include "frc/controller/ElevatorFeedforward.h"

class Elevator : public frc2::ProfiledPIDSubsystem<units::meters> {
  Elevator();
  void Periodic() override;
  units::meter_t elevatorPosition;
  units::meter_t GetMeasurement() override;
  void UseOutput(double output, frc::TrapezoidProfile<units::meters>::State setpoint) override;
  
  private:
  /** elevator feedforward 
   *  gains will definitely not 
   * be empirical for now
   */
  frc::ElevatorFeedforward<units::meters> m_feedForward;
  std::shared_ptr<WPI_TalonSRX> m_elevator;
  std::shared_ptr<WPI_VictorSPX> m_elevatorSlave;
  std::shared_ptr<frc::Encoder> m_elevatorEncoder;
};