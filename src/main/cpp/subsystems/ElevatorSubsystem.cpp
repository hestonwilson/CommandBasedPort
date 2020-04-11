#include "subsystems/ElevatorSubsystem.h"
#include "Constants.h"
#include "frc/Encoder.h"
using state = frc::TrapezoidProfile<units::meters>::State;

Elevator::Elevator() :
frc2::ProfiledPIDSubsystem<units::meters>(frc::ProfiledPIDController<units::meters>(PenguinConstants::ElevatorControl::P, 0, 0, {PenguinConstants::ElevatorControl::MAX_VEL, PenguinConstants::ElevatorControl::MAX_ACCEL}),
m_feedForward(PenguinConstants::ElevatorControl::FeedforwardGains::kS,PenguinConstants::ElevatorControl::FeedforwardGains::kG, PenguinConstants::ElevatorControl::FeedforwardGains::kV, PenguinConstants::ElevatorControl::FeedforwardGains::kA ),
m_elevator(std::make_shared<WPI_TalonSRX>(PenguinConstants::CAN::ELEVATOR_MASTER)),
m_elevatorSlave(std::make_shared<WPI_VictorSPX>(PenguinConstants::CAN::ELEVATOR_SLAVE)),
m_elevatorEncoder(std::make_shared<frc::Encoder>(PenguinConstants::DIO::ELEVATOR_ENCODER_A, PenguinConstants::DIO::ELEVATOR_ENCODER_B))
{
  
  //m_elevator = std::make_shared<WPI_TalonSRX>(PenguinConstants::CAN::ELEVATOR_MASTER);
  //m_elevatorSlave = std::make_shared<WPI_VictorSPX>(PenguinConstants::CAN::ELEVATOR_SLAVE);
  //m_elevatorEncoder = std::make_shared<frc::Encoder>(PenguinConstants::DIO::ELEVATOR_ENCODER_A, PenguinConstants::DIO::ELEVATOR_ENCODER_B);

  //this is not empirical yet
  m_elevatorEncoder->SetDistancePerPulse(2 * PenguinConstants::MathConstants::PI * 3 * 4 / 8192);
  //don't know if this will work. This is supposed to start elevator at the bottom.
  SetGoal(0_m);


}

void Elevator::UseOutput(double output, State setpoint) {
  units::volt_t feedforward = 
  m_feedforward.Calculate(setpoint.position, setpoint.velocity);
  //add the feedforward to the pid output to get the motor output.
  m_elevator->SetVoltage(units::volts_t(output) + feedforward);
}
units::meter_t Elevator::GetMeasurement() {
return units::meter_t(m_elevatorEncoder->GetDistance());
}