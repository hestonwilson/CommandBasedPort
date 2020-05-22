#include "subsystems/LimelightSubsystem.h"
#include <cmath>

LimelightSubsystem::LimelightSubsystem() 
  : table{nt::NetworkTableInstance::GetDefault().GetTable("limelight")} {  
    
}

void LimelightSubsystem::Periodic() {
  horizontalOffsetAngle = table->GetNumber("tx", 0.0);
  verticalOffsetAngle = table->GetNumber("ty",0.0);
  targetArea = table->GetNumber("ta",0.0);
  targetSkew = table->GetNumber("ts",0.0);
  using SD = frc::SmartDashboard;
  SD::PutNumber("Horizontal offset angle", horizontalOffsetAngle);
  SD::PutNumber("Vertical offset angle", verticalOffsetAngle);
  SD::PutNumber("Target area visible", targetArea);
  SD::PutNumber("Target skew angle", targetSkew);
  SD::PutBoolean("Limelight has any valid targets", HasAnyValidTargets());
  // SD::PutNumber("Distance from target", )
}

void LimelightSubsystem::TurnLEDOn() {
  table->PutNumber("ledMode", 3);
}

void LimelightSubsystem::TurnLEDOff() {
  table->PutNumber("ledMode", 1 );
}

void LimelightSubsystem::SetAsVisionProcessor() {
  table->PutNumber("camMode", 0);
}

units::meter_t LimelightSubsystem::EstimateTargetDistance(units::radian_t mountAngle, units::meter_t limelightHeight, units::meter_t targetHeight, double ty) {
 
  //equation for distance from https://docs.limelightvision.io/en/latest/cs_estimating_distance.html#using-a-fixed-angle-camera
  ty = verticalOffsetAngle;

  //TODO check to make sure this works
  auto distance = units::meter_t(((targetHeight-limelightHeight).to<double>()) * std::tan((mountAngle.to<double>()) + ty));
  frc::SmartDashboard::PutNumber("Distance to target", distance.to<double>());
  return distance;
}

void LimelightSubsystem::SetAsDriverCamera() {
  table->PutNumber("camMode", 1);
}
bool LimelightSubsystem::HasAnyValidTargets() {
  return static_cast<bool>(table->GetNumber("tv", 0.0));  //TODO check if necessary to cast to bool
}
