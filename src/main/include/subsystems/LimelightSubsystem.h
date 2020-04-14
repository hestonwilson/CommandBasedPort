#pragma once
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "PenguinUtil.h"
#include "Constants.h"

class LimelightSubsystem : public frc2::SubsystemBase {
    public:
    LimelightSubsystem();
    void Periodic() override;
    //TODO find solution to doing the autonomous limelight stuff.

    double tx, ty;
    
    private:
    std::shared_ptr<NetworkTable> m_table;
};