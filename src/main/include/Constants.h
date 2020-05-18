/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <math.h>
#include <wpi/math>

#include <units/units.h>
#include "frc/geometry/Rotation2d.h"
#include "frc/I2C.h"
#include <frc/trajectory/TrapezoidProfile.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace PenguinConstants {
  constexpr units::second_t DT = 20_ms;
  constexpr bool DEV_TESTING = true;
  namespace Limelight {
    constexpr double DEFAULT_VALUE = 0.0;
    constexpr units::inch_t HEIGHT = 38.5_in;
  } // Limelight namespace

  namespace MathConstants {
    constexpr double PI = wpi::math::pi;
    constexpr double TWO_PI = 2.0 * wpi::math::pi;
    constexpr units::radian_t PI_RAD = units::radian_t(PI);
    constexpr units::radian_t TWO_PI_RAD = units::radian_t(TWO_PI);
    constexpr frc::Rotation2d ZERO_ROT = frc::Rotation2d();
    const frc::Rotation2d PI_ROT = frc::Rotation2d(PI_RAD);
    const frc::Rotation2d TWO_PI_ROT = frc::Rotation2d(TWO_PI_RAD);

}//MathConstants namespace
  namespace DrivetrainAutonomous {
  //TODO these are placeholders.
    constexpr auto ks = 1_V;
    constexpr auto kv = 0.8 * 1_V * 1_s / 1_m;
    constexpr auto ka = 0.15 * 1_V * 1_s * 1_s / 1_m;
    using radians_per_second_squared_t = units::compound_unit<units::radians, 
                                                              units::inverse<units::squared<units::second>>>;

    constexpr units::meters_per_second_t K_MAX_VELOCITY = 3.5_mps; //TODO make accurate
    constexpr units::meters_per_second_squared_t K_MAX_ACCELERATION = units::meters_per_second_squared_t(2);
    constexpr units::radians_per_second_t K_MAX_ANGULAR_VELOCITY = units::radians_per_second_t(2.5);
    constexpr auto K_MAX_ANGULAR_ACCELERATION = units::unit_t<radians_per_second_squared_t>(3.142); // TODO make accurate

    //TODO get some holonomic following PID constants that are empirical
    constexpr double kPForwardController = 0.5;
    constexpr double kPStrafeController = 0.5;
    constexpr double kPRotationController = 0.5;

    //motion profile for rotation controller
    // frc::TrapezoidProfile<units::radians>::Constraints kRotationControllerConstraints{K_MAX_ANGULAR_VELOCITY, 
                                                                                            // K_MAX_ANGULAR_ACCELERATION};
  }//DrivetrainAutonomous
  namespace CAN {
    namespace SwerveConstants {
      constexpr int FL_DRIVE = 6;
      constexpr int FL_TURN = 5;
  
      constexpr int FR_DRIVE = 8;
      constexpr int FR_TURN = 7;

      constexpr int BL_DRIVE = 2;
      constexpr int BL_TURN = 1;

      constexpr int BR_DRIVE = 3;
      constexpr int BR_TURN = 4;    
    } //SwerveConstants namespace
    
    constexpr int ELEVATOR_MASTER = 16;
    constexpr int ELEVATOR_SLAVE = 11;
    constexpr int SHOOTER = 10;
    constexpr int AIMER = 15;
    constexpr int INTAKE = 12;
    constexpr int BELT = 9;
    constexpr int CENTERER = 14;
  } //CAN namespace

  namespace PWM{}

  namespace AnalogInConstants {
    constexpr int SWERVE_FL_ENCODER = 3;
    constexpr int SWERVE_FR_ENCODER = 2;
    constexpr int SWERVE_BL_ENCODER = 0;
    constexpr int SWERVE_BR_ENCODER = 1;
  }//AnalogInConstants namespace

  namespace DIO {
    constexpr int BELT_ENCODER_A = 1;
    constexpr int BELT_ENCODER_B = 2;
  
    constexpr int ELEVATOR_ENCODER_A = 6;
    constexpr int ELEVATOR_ENCODER_B = 7;
  } //DIO namespace
  namespace I2C {
    constexpr frc::I2C::Port BALL_LIDAR = frc::I2C::Port::kOnboard;
  } //I2C namespace

  namespace ElevatorControl { //placeholders TODO reals
    namespace FeedforwardGains {
      //these constants are placeholders
      using Velocity = units::compound_unit<units::turns, units::inverse<units::seconds>>;
      using Acceleration = units::compound_unit<Velocity, units::inverse<units::seconds>>;
      using kv_unit = units::compound_unit<units::volts, units::inverse<Velocity>>;
      using ka_unit = units::compound_unit<units::volts, units::inverse<Acceleration>>;
      constexpr units::volt_t kS = 0.5_V;
      constexpr units::volt_t kG = 1_V;
    
      constexpr auto kV = 0.8 * 1_V * 1_s / 1_m;
      // constexpr units::unit_t<ka_unit> kA = units::unit_t<ka_unit>(1);
    }
    constexpr units::meters_per_second_t MAX_VEL = 1.75_mps;
    constexpr units::meters_per_second_squared_t MAX_ACCEL = 0.75_mps_sq;

    // Placeholder profiled PID constants
    constexpr double P{1.3};
    constexpr double I{0};
    constexpr double D{0.3};
  } // ElevatorControl namespace

  namespace ShooterSystem {
    namespace ShooterPID { //TODO not final
      constexpr double P = 0.000782;
      constexpr double I = 1e-6;
      constexpr double IZone = 1e-5; // maybe?
      constexpr double D = 0;
    }//ShooterPID namespace
    namespace Characterization {
      // Unit definitions copied [from WPILib](https://github.com/wpilibsuite/allwpilib/blob/0ec8ed6c052b18402924daac591ff9e192695825/wpilibc/src/main/native/include/frc/controller/SimpleMotorFeedforward.h#L21):
      using Velocity = units::compound_unit<units::turns, units::inverse<units::seconds>>;
      using Acceleration = units::compound_unit<Velocity, units::inverse<units::seconds>>;
      using kv_unit = units::compound_unit<units::volts, units::inverse<Velocity>>;
      using ka_unit = units::compound_unit<units::volts, units::inverse<Acceleration>>;  

      constexpr units::volt_t kS = 0.00116 * (1_V);
      constexpr units::unit_t<kv_unit> kV = 0.187 * units::unit_t<kv_unit>(1);
      constexpr units::unit_t<ka_unit> kA = 0.0867 * units::unit_t<ka_unit>(1);
    }//Characterization namespace
     
    constexpr double GEAR_RATIO = 30 / 24;
     /**  The distance the lidar should (approximately) read if there are balls in front of it.
     * This should be the smallest value it will ever reasonably read with no ball, not the average value.
     * TODO: 30 inches seems about right - needs more testing
     */
    constexpr units::inch_t LIDAR_NORMAL_DISTANCE = 30_in;
  }//ShooterSystem namespace
  namespace CommandButtons {
    constexpr int ELEVATOR_UP_BUTTON = 2;
    constexpr int ELEVATOR_DOWN_BUTTON = 3;
    constexpr int SPIN_UP_BUTTON = 1;
    constexpr int RUN_INTAKE_BUTTON = 2; 
  } //CommandButtons namespace
  namespace Joysticks {
    namespace Gamer {
      namespace Buttons {
        constexpr int A = 1;
        constexpr int B = 2;
        constexpr int Y = 4;
        constexpr int X = 3;
        constexpr int LEFT_STICK = 9;
        constexpr int RIGHT_STICK = 10;
        constexpr int START = 8;
        constexpr int BACK = 7;
        constexpr int LEFT_BUMPER = 5;
        constexpr int RIGHT_BUMPER = 6;
      } //buttons namespace
     
      namespace Axes {
        constexpr int LEFT_Y = 1;
        constexpr int LEFT_X = 0;
        constexpr int RIGHT_Y = 5;
        constexpr int RIGHT_X = 4;
        constexpr int LEFT_TRIGGER = 2;
        constexpr int RIGHT_TRIGGER = 3;
      } //Axes namespace
    } //Gamer namespace

    namespace Flight { //TODO
      namespace Buttons {
        constexpr int UPPER_TOP_LEFT = 5;
        constexpr int UPPER_BOTTOM_LEFT = 3;
        constexpr int UPPER_TOP_RIGHT = 6;
        constexpr int UPPER_BOTTOM_RIGHT = 4;
        constexpr int TRIGGER = 1;
        constexpr int SIDE = 2;
        constexpr int LOWER_BOTTOM_LEFT = 11;
        constexpr int LOWER_BOTTOM_RIGHT = 12;
        constexpr int LOWER_MID_LEFT = 9;
        constexpr int LOWER_MID_RIGHT = 10;
        constexpr int LOWER_TOP_LEFT = 7;
        constexpr int LOWER_TOP_RIGHT = 8; 
      } //Buttons namespace
      namespace Axes {
        constexpr int Y = 1;
        constexpr int X = 0; // TODO
        constexpr int ROT = 2; // TODO
        constexpr int TRIM = 3; // TODO
      } //Axes namespace
    } //flight namespace
  } //Joystick namespace
} //PenguinConstants namespace