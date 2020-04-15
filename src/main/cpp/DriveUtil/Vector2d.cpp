#include "DriveUtil/Vector2d.h"
Vector2d::Vector2d(double x, double y)
:x{x},
y{y} 
{
length = std::hypot(x, y);
}