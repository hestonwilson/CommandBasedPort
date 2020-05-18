#pragma once
#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>

/** the point of this file is to hold trajectories.
 * 
 * 
 */

//test to see if trajectories will work.

wpi::SmallString<64> deployDirectory;
frc::filesystem::GetDeployDirectory(deployDirectory);
wpi::sys::path::append(deployDirectory, "paths");
wpi::sys::path::append(deployDirectory, "Path1.wpilib.json");


namespace PenguinTrajectories {
frc::Trajectory testTrajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);
}// PenguinTrajectories namespace
