#pragma once
#include <math.h>
#include <wpi/math>

#include <units/units.h>
#include "frc/geometry/Rotation2d.h"
#include "frc/I2C.h"



namespace PenguinUtil {
  inline double linearMap(double n, double start1, double stop1, double start2, double stop2) {
    // Credit to the Processing Foundation and p5.js: https://github.com/processing/p5.js/blob/86d6b67707965526ce11cf893e26be5d53a1ad4c/src/math/calculation.js#L461
    return (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;
  }
  
  inline double deadband(double input, double deadband = 0.05) {
    if (fabs(input) < deadband) {
      return 0;
    } else {
      return input;
    }
  }

  inline double tooSmartDeadband(double input, double deadbandStart, double deadbandEnd, double leftRangeStart, double leftRangeEnd, double valueInDeadband, double rightRangeStart, double rightRangeEnd) {
    if (deadbandStart <= input && input <= deadbandEnd) {
      return valueInDeadband;
    } else if (-1 <= input && input < deadbandStart) {
      return linearMap(input, -1, deadbandStart, leftRangeStart, leftRangeEnd);
    } else if (deadbandEnd < input && input <= 1) {
      return linearMap(input, deadbandEnd, 1, rightRangeStart, rightRangeEnd);
    } else {
      return 0.0;
      printf("Line %i: !!! Invalid input (abs(input) > 1) being passed to `PenguinUtil::tooSmartDeadband`. Returned 0.", __LINE__);
    }
  }

  inline double smartDeadband(double input, double deadbandStart, double deadbandEnd, double valueAtDeadBandEdge = 0.1) {
    return tooSmartDeadband(input, deadbandStart, deadbandEnd, -1, -valueAtDeadBandEdge, 0, valueAtDeadBandEdge, 1);
  }

  inline bool approxEqual(double value1, double value2, double tolerance = 0.01) {
    return fabs(value1 - value2) < tolerance;
  }

  /** Returns true when @param value is within @param percentTolerance percent of @param reference. */
  inline bool withinPercentTolerance(double value, double reference, double percentTolerance) {
    return approxEqual(value, reference, reference * percentTolerance / 100);
  }
  inline units::radian_t arbitraryTwoPiRangeNorm(units::radian_t value, units::radian_t mid) {
    units::radian_t ret = value;

    while (ret > mid + 180_deg) {
      ret -= 360_deg;
    }
    while (ret < mid - 180_deg) {
      ret += 360_deg;
    }

    return ret;
  }

  inline units::radian_t piNegPiNorm(units::radian_t value) {
    return arbitraryTwoPiRangeNorm(value, 0_deg);
  }
} // PenguinUtil namespace