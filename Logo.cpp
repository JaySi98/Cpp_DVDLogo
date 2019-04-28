#include "Logo.h"

Logo::Logo(sf::Vector2u window_size)
{
    if(texture.loadFromFile("DVD.png") == false)
        return;

    body.setTexture(&texture, false);
    body.setSize(sf::Vector2f(234.0f, 102.0f));
    body.setPosition((window_size.x/2)-(body.getSize().x/2), window_size.y/2-(body.getSize().y/2));
    SetDirection(rand()%6, rand()%6);
    speed = direction.x/100;
}

Logo::~Logo()
{

}

void Logo::update()
{
    body.move(direction.x * speed, direction.y * speed);
}

void Logo::draw(sf::RenderWindow& window)
{
    window.draw(body);
}

bool Logo::CheckColisionX(int width)
{
    if(body.getPosition().x - 1 <= 0 || body.getPosition().x + body.getSize().x + 1 >= width) return true;
    else return false;
}

bool Logo::CheckColisionY(int height)
{
    if(body.getPosition().y - 1 <= 0 || body.getPosition().y + body.getSize().y + 1 >= height) return true;
    else return false;
}

//
void Logo::changeColor(int num)
{
    if(num < amount)
        body.setFillColor(color_list[num]);
    else
        body.setFillColor(color_list[0]);
}

void Logo::SetDirection(float x, float y)
{
    direction.x = x;
    direction.y = y;
}

sf::Vector2f Logo::getDirection()
{
    return direction;
}

void  Logo::IncreaseSpeed(float val)
{
    speed += val;
}
