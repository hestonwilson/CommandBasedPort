#pragma once
#include <frc2/command/ProfiledPIDSubsystem.h>
#include <units/units.h>
#include "ctre/Phoenix.h"
#include <frc/Encoder.h>
#include <frc/controller/ElevatorFeedforward.h>
#include "Constants.h"

class ElevatorSubsystem : public frc2::ProfiledPIDSubsystem<units::meters> {
  ElevatorSubsystem();
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
  std::shared_ptr<WPI_TalonSRX> m_elevator = std::make_shared<WPI_TalonSRX>(PenguinConstants::CAN::ELEVATOR_MASTER);
  std::shared_ptr<WPI_VictorSPX> m_elevatorSlave = std::make_shared<WPI_VictorSPX>(PenguinConstants::CAN::ELEVATOR_SLAVE);
  std::shared_ptr<frc::Encoder> m_elevatorEncoder = std::make_shared<frc::Encoder>(PenguinConstants::DIO::ELEVATOR_ENCODER_A, PenguinConstants::DIO::ELEVATOR_ENCODER_B);
};