#include "../include/Robot.h"
#include <cmath>

Robot::Robot(double radius, double length) : r(radius), L(length), x(0,0,0), vRight(0), vLeft(0)
{
    shape.setSize(sf::Vector2f(50,50));
    shape.setOrigin(sf::Vector2f(25,25));
    shape.setPosition(sf::Vector2f(x.x,x.y));
}

void Robot::update(double& dt, Keys& keys)
{
    double targetV = 5.0; 
    if (keys.A) vLeft = targetV; else vLeft = 0;
    if (keys.D) vRight = targetV; else vRight = 0;

    double linearV = (r/2.0) * (vRight + vLeft);
    double angularW = (r/L) * (vRight - vLeft);

    double dtheta = angularW * dt;
    double thetamid = x.z + (dtheta / 2.0);

    x.x += linearV * cos(thetamid) * dt;
    x.y += linearV * sin(thetamid) * dt;
    x.z += dtheta;

    x.z = std::atan2(std::sin(x.z), std::cos(x.z));
}

void Robot::render(sf::RenderWindow& window)
{
    float screenX = x.x * 100.0f;
    float screenY = 720 - x.y * 100.0f;
    shape.setPosition(sf::Vector2f(screenX, screenY));

    float screenAngle = -x.z;
    sf::Angle angle = sf::radians(screenAngle);
    shape.setRotation(angle);

    window.draw(shape);
}

double Robot::getVLeft()
{
    return vLeft;
}

double Robot::getVRight()
{
    return vRight;
}