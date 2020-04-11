#include "subsystems/VisionSubsystem.h"

Vision::Vision() {
    table{nt::NetworkTableInstance::GetDefault().GetTable("limelight")} {
        
    }
}