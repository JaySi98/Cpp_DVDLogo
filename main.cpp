#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Logo.h"

void routine(Logo &logo, sf::RenderWindow &window);
float random_float(float f_min, float f_max);

int main()
{
    //srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1280, 800), "DVD screensaver");
    //window_size is needed to set logo at the center of the window
    sf::Vector2u window_size = window.getSize();
    Logo logo(window_size);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                logo.IncreaseSpeed(0.25);
            }

        }

        routine(logo, window);
        window.clear();
        logo.draw(window);
        window.display();
    }

    return 0;
}

//basically this function is responsible for controlling the logo
void routine(Logo &logo, sf::RenderWindow &window)
{
    //logo is touching horizontal sides of the window
    if(logo.CheckColisionX(window.getSize().x))
    {
        logo.changeColor(rand()%7);
        //changes the x-axis of the direction so logo can "bounce off" the side
        logo.SetDirection(-logo.getDirection().x, logo.getDirection().y + random_float(0, 2));

    } //logo is touching vertical sides of the window
    if(logo.CheckColisionY(window.getSize().y))
    {
        logo.changeColor(rand()%7);
        //changes the y-axis of the direction so logo can "bounce off" the side
        logo.SetDirection(logo.getDirection().x + random_float(0, 2), -logo.getDirection().y);
    }
    //move logo by vector direction
    logo.update();
}

float random_float(float f_min, float f_max)
{
    return f_min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(f_max-f_min)));
}
