#include "PenguinControl/PIDController.h"
#include <iostream>
PenguinPIDController::PenguinPIDController(double kP, double kI, double kD)
:kP{kP},
kI{kI},
kD{kD} 
{

}
double PenguinPIDController::Calculate(double current, double dt) {
  double error = setpoint - current;
  if(IsContinuous) {
    error %= inputRange; 
    if(fabs(error) > inputRange / 2.0) {
      if(error > 0.0) {
        error -= inputRange;
      } else {
          error += inputRange;
      }
    }

  }

  if(clearIntegralOnErrorSignChange && !IsBasicallyEqual(error, std::copysign(error, integralAccumulation)) && !IsBasicallyEqual(integralAccumulation, 0.0)) {
    integralAccumulation = 0.0;
  }

  double integral = 0.0;
  if(fabs(error) < integralRange / 2.0) {
      integral = integralAccumulation + error * dt;
  }
  integralAccumulation = integral;

  double derivative = 0.0;
  if(std::isfinite(lastError)) {
    derivative = (error - lastError) / dt;
  }
  lastError = error;
  
  return ClampVals(kP * error + kI * integral + kD * derivative, minOutput, maxOutput);
}
double PenguinPIDController::GetSetpoint() {
    return setpoint;
}
void PenguinPIDController::SetSetpoint(double setpoint) {
    this->setpoint = setpoint;
}
void PenguinPIDController::SetContinuous(bool continuous) {
  this->IsContinuous = continuous;
}
void PenguinPIDController::SetInputRange(double min, double max) {
    this->inputRange = max - min;
}
void PenguinPIDController::SetIntegralRange(double integralRange) {
    this->integralRange = integralRange;
}
void PenguinPIDController::SetClearIntegralOnErrorSignChange(bool ClearIntegralOnErrorSignChange) {
    this->clearIntegralOnErrorSignChange = ClearIntegralOnErrorSignChange;
}
void PenguinPIDController::SetOutputRange(double min, double max) {
    if(max < min) {
    std::cerr << "Error: maximum output cannot be less than minimum output";
    }
    minOutput = min;
    maxOutput = max;
}
double ClampVals(double value, double min, double max) {
  if(min > max) {
      std::cerr << "Error: minimum value can not be greater than maximum.";
  }

  return std::max(min, std::min(value, max));
}