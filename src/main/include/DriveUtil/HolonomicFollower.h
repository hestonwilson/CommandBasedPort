// #pragma once
// #include "DriveUtil/Vector2d.h"
// //TODO encapsulate data when this is not a hacked together solution.
// struct HolonomicDriveSignal {
// HolonomicDriveSignal(Vector2d translation, double rotation, bool fieldOriented);
// Vector2d m_translation;
// double m_rotation;
// bool m_fieldOriented;
// Vector2 GetTranslation();
// double GetRotation();
// bool IsFieldOriented();
// };
// class HolonomicFeedforward {
//  public:
//   HolonomicFeedforward(DrivetrainFeedforward forwardConstants, DrivetrainFeedforward strafeConstants);
//   HolonomicFeedforward(DrivetrainFeedforward translationConstants)
//   Vector2d CalculateFeedforward(Vector2d velocity, Vector2d acceleration);
//   DrivetrainFeedforward GetForwardConstants();
//   DrivetrainFeedforward GetStrafeConstants();
//  private:
//   DrivetrainFeedforward forwardConstants;
//   DrivetrainFeedforward strafeConstants;

// };
// class DrivetrainFeedforward {
//  public:
//   DrivetrainFeedforward(double velocityConstant, double accelerationConstant, double staticConstant);
//   double CalculateFeedforward(double velocity, double acceleration);
//   double GetVelocityConstant();
//   double GetAccelerationConstant();
//   double GetStaticConstant();
//  private:
//   double velocityConstant;
//   double accelerationConstant;
//   double staticConstant;
// };