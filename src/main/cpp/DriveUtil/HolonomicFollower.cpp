#include "DriveUtil/HolonomicFollower.h"

//TODO these are totally random.


HolonomicFeedforward::HolonomicFeedforward(DrivetrainFeedforward forwardConstants, DrivetrainFeedforward strafeConstants) 
: forwardConstants{forwardConstants},
strafeConstants{strafeConstants}
{}
HolonomicFeedforward::HolonomicFeedforward(DrivetrainFeedforward translationConstants) 
: translationConstants{forwardConstants},
translationConstants{strafeConstants}
{}
//these constants are placeholders
DrivetrainFeedforward::DrivetrainFeedforward(1.1, 0.1, 1.8)
:1.1{velocityConstant},
0.1{accelerationConstant},
1.8{staticConstant}
{
  
}
Vector2d HolonomicFeedforward::calculateFeedforward(Vector2d velocity, Vector2d acceleration) {
  double forwardFeedforward = forwardConstants.getVelocityConstant() * velocity.x;
  forwardFeedforward += forwardConstants.getAccelerationConstant() * acceleration.x;

  double strafeFeedforward = strafeConstants.getVelocityConstant() * velocity.y;
  strafeFeedforward += strafeConstants.getAccelerationConstant() * acceleration.y;

  Vector2d feedForwardVector{forwardFeedforward, strafeFeedforward};

//   Vector2d feedforwardUnitVector = feedforwardVector.normal() //todo have not implemented yet
forwardFeedforward += copysign(feedforwardUnitVector.x * forwardConstants.GetStaticConstant(),
forwardFeedforward);
strafeFeedforward += Math.copySign(feedforwardUnitVector.y * strafeConstants.GetStaticConstant(),
strafeFeedforward);
return Vector2d(forwardFeedforward, strafeFeedforward);

}
DrivetrainFeedforward GetForwardConstants()
double DrivetrainFeedforward::calculateFeedforward(double velocity, double acceleration) {
    double feedforward = velocityConstant * velocity;
    feedforward += accelerationConstant * acceleration;
    feedforward += copysign(staticConstant, feedforward);
    return feedforward
}
double DrivetrainFeedforward::GetVelocityConstant() {
  return this->velocityConstant;
}
double DrivetrainFeedforward::GetAccelerationConstant() {
  return this->accelerationConstant;
  }
double DrivetrainFeedforward::GetStaticConstant() {
  return this->staticConstant;
  }