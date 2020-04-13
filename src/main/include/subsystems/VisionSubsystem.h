#pragma once
#include "frc2/command/SubsystemBase.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

#include "PenguinUtil.h"
#include "Constants.h"

class Vision : public frc2::SubsystemBase {
    public:
    Vision();
    void Periodic() override;
    //TODO find solution to doing the autonomous limelight stuff.

    double tx, ty;
    void SetVisionCamMode();
    void SetDriveCamMode();
    
    private:
    std::shared_ptr<NetworkTable> table;
}