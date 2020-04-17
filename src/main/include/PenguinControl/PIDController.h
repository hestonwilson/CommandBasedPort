// #pragma once
// #include <cmath>
// #include <limits>
// #include <vector>

// /** Here I intend to experiment with the possibility
//  *  of writing our own pid controller. I am not sure
//  * how we would use it but it would be cool
//  */

// class PenguinPIDController {

// public:
// PenguinPIDController(double kP, double kI, double kD);
// double tolerance = 10e-9;
// double Calculate(double current, double dt);
// void Reset();
// double GetSetpoint();
// void SetSetpoint(double setpoint);
// void SetContinuous(bool continuous);
// void SetInputRange(double min, double max);
// void SetIntegralRange(double integralRange);
// void SetClearIntegralOnErrorSignChange(bool clearIntegralOnSignChange);
// void SetOutputRange(double min, double max);
// double ClampVals(double value, double min, double max);
// bool IsBasicallyEqual(double min, double max);
// private:
// bool IsContinuous = false;
// double setpoint;
// double kP;
// double kI;
// double kD;
// //not sure how well numeric_limits will work for this
// double inputRange = 10000; //std::numeric_limits<double>::infinity(); 
// double minOutput = -10000; //-std::numeric_limits<double>::infinity();
// double maxOutput =  10000; //std::numeric_limits<double>::infinity();
// double lastError = NAN;
// double integralAccumulation = 0.0;
// double integralRange = 1000000; //std::numeric_limits<double>::infinity();
// bool clearIntegralOnErrorSignChange = false;
// };