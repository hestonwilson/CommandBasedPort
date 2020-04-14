#pragma once
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "PenguinUtil.h"
#include "Constants.h"
#include "PenguinControl/PIDController.h"

class LimelightSubsystem : public frc2::SubsystemBase {
    public:
    LimelightSubsystem();
    void Periodic() override;
    //TODO find solution to doing the autonomous limelight stuff.
    void SetVisionCamMode();
    void SetDriveCamMode();
    double tx, ty;
    PenguinPIDController m_pidController{1, 0, 0}; // curious if this will work.
    units::radians_per_second_t CalculateRot(units::radian_t currentAngle);
    private:
    std::shared_ptr<NetworkTable> m_table;
};