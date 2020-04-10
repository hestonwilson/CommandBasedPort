#pragma once

#include "Constants.h"
#include "ctre/Phoenix.h"
#include "frc2/command/SubsystemBase.h"
#include <frc2/command/PIDSubsystem.h>
#include "frc/Encoder.h"
#include <units/units.h>
#include <frc/controller/ProfiledPIDController.h>
#include <frc/trajectory/TrapezoidProfile.h>

#include "Joystick.h"

/**
 * This class is for the elevator subsystem
 * not sure if it needs to be a pid subsystem.
 *
 */
class ElevatorSubsystem : public frc2::SubsystemBase {
  public:
  ElevatorSubsystem();
  void Periodic() override;
  void ConfigureMotorControllers();
  void RunElevator();
 
  units::meter_t elevatorPosition;
  bool elevatorAtZero;
  bool elevatorNearZero;
  bool elevatorAboveZero;
  frc::TrapezoidProfile<units::meters>::Constraints m_elevatorConstraints{PenguinConstants::ElevatorControl::MAX_VEL, PenguinConstants::ElevatorControl::MAX_ACCEL};
  frc::ProfiledPIDController<units::meters> m_controller{
    PenguinConstants::ElevatorControl::P,
    PenguinConstants::ElevatorControl::I,
    PenguinConstants::ElevatorControl::D,
    m_elevatorConstraints, PenguinConstants::DT
  };

  
  
  //maybe make std::unique_ptr
  std::shared_ptr<WPI_TalonSRX> m_elevator = std::make_shared<WPI_TalonSRX>(PenguinConstants::CAN::ELEVATOR_MASTER);
  std::shared_ptr<WPI_VictorSPX> m_elevatorSlave = std::make_shared<WPI_VictorSPX>(PenguinConstants::CAN::ELEVATOR_SLAVE);
  std::shared_ptr<frc::Encoder> m_elevatorEncoder = std::make_shared<frc::Encoder>(PenguinConstants::DIO::ELEVATOR_ENCODER_A, PenguinConstants::DIO::ELEVATOR_ENCODER_B);
  
};