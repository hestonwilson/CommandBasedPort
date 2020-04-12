#pragma once
#include "Constants.h"
#include "Lidar.h"
/**
 * I have included this file to hold some functions
 * that are duplicated in the belt subsystem and the 
 * intake subsystem.
//  */
// namespace LidarUtil {
//   units::meter_t currentLidarDistance;
//   bool BallDetectedByLidar(units::meter_t lidarDistance) {
//       return lidarDistance < PenguinConstants::ShooterSystem::LIDAR_NORMAL_DISTANCE;
//   }
//   void UpdateDistance(units::meter_t &currentLidarDistance, Lidar ballDetector) {
//       currentLidarDistance = ballDetector.GetDistance();
//       UpdateBallCount();
//   }
//   void UpdateBallCount(bool ballCurrentlyPassinginFrontofLidar) {
//     const bool ballDetected = BallDetectedByLidar();
//     if (!m_ballCurrentlyPassingInFrontOfLidar) {
//     if (ballDetected) {
//       m_ballCurrentlyPassingInFrontOfLidar = true;
//       m_ballCount += 1;
//     }
//   } else {
//     if (!ballDetected) {
//       m_ballCurrentlyPassingInFrontOfLidar = false;
//     }
//   }
// }


// } //ShooterUtil namespace