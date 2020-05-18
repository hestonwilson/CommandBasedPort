#include "subsystems/ElevatorSubsystem.h"
#include "Constants.h"
#include "frc/Encoder.h"



ElevatorSubsystem::ElevatorSubsystem() :
frc2::ProfiledPIDSubsystem<units::meters>
(frc::ProfiledPIDController<units::meters>(
  PenguinConstants::ElevatorControl::P, 0, 0, frc::TrapezoidProfile<units::meters>::Constraints{PenguinConstants::ElevatorControl::MAX_VEL, PenguinConstants::ElevatorControl::MAX_ACCEL}, PenguinConstants::DT)),
m_feedforward{PenguinConstants::ElevatorControl::FeedforwardGains::kS, PenguinConstants::ElevatorControl::FeedforwardGains::kG, PenguinConstants::ElevatorControl::FeedforwardGains::kV}
{
  
  //m_elevator = std::make_shared<WPI_TalonSRX>(PenguinConstants::CAN::ELEVATOR_MASTER);
  //m_elevatorSlave = std::make_shared<WPI_VictorSPX>(PenguinConstants::CAN::ELEVATOR_SLAVE);
  //m_elevatorEncoder = std::make_shared<frc::Encoder>(PenguinConstants::DIO::ELEVATOR_ENCODER_A, PenguinConstants::DIO::ELEVATOR_ENCODER_B);

  //this is not empirical yet
  m_elevatorEncoder->SetDistancePerPulse(2 * PenguinConstants::MathConstants::PI * 3 * 4 / 8192);
  //don't know if this will work. This is supposed to start elevator at the bottom.
  SetGoal(0_m);


}
void ElevatorSubsystem::Periodic() {
  elevatorPosition = units::meter_t(m_elevatorEncoder->GetDistance());

}

void ElevatorSubsystem::UseOutput(double output, frc::TrapezoidProfile<units::meters>::State setpoint) {
  units::volt_t feedforward =  m_feedforward.Calculate(setpoint.velocity);
  //add the feedforward to the pid output to get the motor output.
  m_elevator->SetVoltage(units::volt_t(output) + feedforward);
}
units::meter_t ElevatorSubsystem::GetMeasurement() {
return units::meter_t(m_elevatorEncoder->GetDistance());
}