#include "subsystems/AimerSubsystem.h"

AimerSubsystem::AimerSubsystem() :
m_aimer{PenguinConstants::CAN::AIMER} {
  m_aimer.ConfigFactoryDefault();
  m_aimer.SetInverted(true);

  // m_aimer.ConfigForwardSoftLimitThreshold(___); // TODO
  // m_aimer.ConfigReverseSoftLimitThreshold(___); // TODO
  // m_aimer.ConfigForwardSoftLimitEnable(true); // TODO: when we get the above two done
  // m_aimer.ConfigReverseSoftLimitEnable(true); // TODO: when we get the above two done

  m_aimer.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
  m_aimer.SetSelectedSensorPosition(0); // !Imp: Assumes the aimer is always in the same place when the robot turns on
  m_aimer.SetSensorPhase(false); // TODO
}

// void AimerSubsystem::Periodic() {
// //   m_aimer.Set(ControlMode::PercentOutput, m_gamerJoystick.GetRawAxis(PenguinConstants::Joysticks::Gamer::Axes::RIGHT_X));

// }
