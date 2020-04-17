#pragma once
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/controller/PIDController.h>
#include "PenguinUtil.h"
#include "Constants.h"


class LimelightSubsystem : public frc2::SubsystemBase {
public:
LimelightSubsystem();
void Periodic() override;
std::shared_ptr<NetworkTable> table;
double horizontalOffsetAngle;
double verticalOffsetAngle;
double targetArea;
double targetSkew;
void TurnLEDOn();
void TurnLEDOff();
void SetAsVisionProcessor();
void SetAsDriverCamera();
bool HasAnyValidTargets();
frc::PIDController m_controller{1, 0, 0}; //see if this works.
units::meter_t FindTargetDistance(units::radian_t mountAngle, units::meter_t limelightHeight, units::meter_t targetHeight);
units::radian_t cameraMountingAngle;

};