#pragma once
#include "SFML/System/Vector3.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

struct Keys
{
    bool A;
    bool D;
};

class Robot
{
private:
    sf::Vector3<double> x;
    sf::Vector2<double> v;
    double vLeft;
    double vRight;
    const double r;
    const double L;
    sf::RectangleShape shape;
public:
    Robot(double r, double L);
    void update(double& dt, Keys& keys);
    void render(sf::RenderWindow& window);
    double getVLeft();
    double getVRight();
public:
};