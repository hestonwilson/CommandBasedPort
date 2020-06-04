#pragma once
#include <frc2/command/ProfiledPIDSubsystem.h>
#include <units/units.h>
#include "ctre/Phoenix.h"
#include <frc/Encoder.h>
#include <frc/controller/ElevatorFeedforward.h>
#include "Constants.h"
#include <frc/trajectory/TrapezoidProfile.h>

/** ElevatorSubsystem is a ProfiledPIDSubsystem that uses frc::TrapezoidProfile and PID to control the elevator's
 * motion up and down.
 **/
class ElevatorSubsystem : public frc2::ProfiledPIDSubsystem<units::meters> {
 public:
  ElevatorSubsystem();
  void Periodic() override;
  units::meter_t elevatorPosition;
  units::meter_t GetMeasurement() override;
  void UseOutput(double output, frc::TrapezoidProfile<units::meters>::State setpoint) override;
  
 private:
  
  //TODO not really necessary to have a feedforward.
  frc::ElevatorFeedforward<units::meters> m_feedforward;
  std::shared_ptr<WPI_TalonSRX> m_elevator = std::make_shared<WPI_TalonSRX>(PenguinConstants::CAN::ELEVATOR_MASTER);
  std::shared_ptr<WPI_VictorSPX> m_elevatorSlave = std::make_shared<WPI_VictorSPX>(PenguinConstants::CAN::ELEVATOR_SLAVE);
  std::shared_ptr<frc::Encoder> m_elevatorEncoder = std::make_shared<frc::Encoder>(PenguinConstants::DIO::ELEVATOR_ENCODER_A, PenguinConstants::DIO::ELEVATOR_ENCODER_B);
};