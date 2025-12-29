#include <SFML/Graphics.hpp>
#include <string>
#include "../include/Robot.h"
#include <string>
 
int main()
{
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Virtual TB3");

    window.setFramerateLimit(60);

    Keys keys;
    keys.A = false;
    keys.D = false;

    sf::Font arialFont("../fonts/ARIAL.TTF");
    sf::Text vInfo(arialFont, "V_Left:\nV_Right:");
    vInfo.setPosition(sf::Vector2f(1050, 50));

    Robot robot(0.033, 0.12);

    sf::Clock clock;

    while (window.isOpen())
    {
        double dt = clock.restart().asSeconds();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            if (event->is<sf::Event::KeyPressed>())
            {
                const auto* keyEvent = event->getIf<sf::Event::KeyPressed>();
                if (keyEvent->code == sf::Keyboard::Key::A)
                {
                    keys.A = true;
                }
                if (keyEvent->code == sf::Keyboard::Key::D)
                {
                    keys.D = true;
                }
            }
            if (event->is<sf::Event::KeyReleased>())
            {
                const auto* keyEvent = event->getIf<sf::Event::KeyReleased>();
                if (keyEvent->code == sf::Keyboard::Key::A)
                {
                    keys.A = false;
                }
                if (keyEvent->code == sf::Keyboard::Key::D)
                {
                    keys.D = false;
                }

            }
        }

        robot.update(dt,keys);
        std::string vLeftText = std::to_string(robot.getVLeft());
        std::string vRightText = std::to_string(robot.getVRight());
        std::string final = "V_Left: " + vLeftText + "\nV_Right: " + vRightText;

        vInfo.setString(final);
        
        window.clear();

        window.draw(vInfo);
        robot.render(window);
 
        window.display();
    }
}