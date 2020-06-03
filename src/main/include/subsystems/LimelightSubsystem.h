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
  frc2::PIDController m_controller{1, 0, 0}; 
  void UpdateHorizontalOffsetAngle();
  void UpdateVerticalOffsetAngle();
  /**
   * EstimateTargetDistance estimates distance to a target.
   * @param mountAngle the angle the limelight is mounted at relative to the ground.
   * @param limelightHeight the height of the limelight off the ground
   * @param targetHeight the height of the target
   * @param ty vertical offset from crosshair to target.
   * @return distance from the camera
   * Note: this does not work if the target and camera are at close heights
   * and probably will not work if it is lower than the camera.
   */ 
  units::meter_t EstimateTargetDistance(units::radian_t mountAngle, units::meter_t limelightHeight, units::meter_t targetHeight, double ty);
  units::radian_t cameraMountingAngle = units::radian_t(0);

};