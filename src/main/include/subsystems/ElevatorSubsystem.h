#pragma once
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"
#include "frc/Encoder.h"
class ElevatorSubsystem : public frc2::SubsystemBase {
  public:
  ElevatorSubsystem();
  void Periodic() override;


  private:
  std::shared_ptr<WPI_TalonSRX> m_elevator = std::make_shared<WPI_TalonSRX>(PenguinConstants::CAN::ELEVATOR_MASTER);
}