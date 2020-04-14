#include "subsystems/LimelightSubsystem"

LimelightSubsystem::LimelightSubsystem() {
    m_table{nt::NetworkTableInstance::GetDefault().GetTable("limelight")} {
        
    }
}

LimelightSubsystem::Periodic() {
tx = m_table->GetNumber("tx", PenguinConstants::Limelight::DEFAULT_VALUE);
ty = m_table->GetNumber("ty", PenguinConstants::Limelight::DEFAULT_VALUE);

}