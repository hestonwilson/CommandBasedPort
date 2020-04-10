#include "Constants.h"
#include "subsystems/ElevatorSubsystem.h"
#include "ctre/Phoenix.h"
#include "Joystick.h"
#include "frc/Encoder.h"

ElevatorSubsystem::ElevatorSubsystem() {
  m_elevatorEncoder->Reset();
  m_elevatorEncoder->SetDistancePerPulse(2 * PenguinConstants::MathConstants::PI * 3 * 4 / 8192);
  ConfigureMotorControllers();
}
void ElevatorSubsystem::Periodic() {
    elevatorPosition = units::meter_t(m_elevatorEncoder->GetDistance());
    m_elevator->Set(m_controller.Calculate(units::meter_t(m_elevatorEncoder->GetDistance()))); 
}


void ElevatorSubsystem::RunElevator() {
  if (m_leftJoystick.GetRawButtonPressed(2)) {
      m_controller.SetGoal(2_m);
    } else if (m_leftJoystick.GetRawButtonPressed(3)) {
      m_controller.SetGoal(0_m);
    }
}


void ElevatorSubsystem::ConfigureMotorControllers() {
  m_elevator->ConfigFactoryDefault();
  m_elevatorSlave->ConfigFactoryDefault();

  //always strive to be a leader, not a follower.
  m_elevatorSlave->Set(ControlMode::Follower, PenguinConstants::CAN::ELEVATOR_MASTER);
  m_elevator->SetInverted(true);

  m_elevator->ConfigContinuousCurrentLimit(39);
  m_elevator->ConfigPeakCurrentLimit(0);
  m_elevator->SetNeutralMode(NeutralMode::Brake);

}