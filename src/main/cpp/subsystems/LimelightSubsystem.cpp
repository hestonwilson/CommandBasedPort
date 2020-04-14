#include "subsystems/LimelightSubsystem"

LimelightSubsystem::LimelightSubsystem() {
    m_table{nt::NetworkTableInstance::GetDefault().GetTable("limelight")} {
        
    }
}

LimelightSubsystem::Periodic() {
tx = m_table->GetNumber("tx", PenguinConstants::Limelight::DEFAULT_VALUE);
ty = m_table->GetNumber("ty", PenguinConstants::Limelight::DEFAULT_VALUE);

}

void Limelight::SetVisionCamMode() {
  table->PutNumber("ledMode", 3); // force LEDs on
  table->PutNumber("camMode", 0); // vision processor
}

void Limelight::SetDriveCamMode() {
  table->PutNumber("ledMode", 1); // force LEDs off
  table->PutNumber("camMode", 1); // drive cam (increases exposure, disables vision processing)
}
//TODO figure out best way to use the limelight autonomous as subsystem
// could be setdefault command
// units::radians_per_second_t LimelightAutonomous::Calculate(units::radian_t currentAngle) {
//   const LimelightValues vals = m_limelight->GetInfo();

//   return units::radians_per_second_t(
//     m_pidController.Calculate(vals.tx)
//   );
// }
// }
// LimelightAutonomous::LimelightAutonomous(Limelight* limelight)
// :m_limelight{limelight} {
//     m_pidController.SetSetpoint(0);
//     m_pidController.SetTolerance(2);
// }
