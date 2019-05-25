#ifndef LOGO_H
#define LOGO_H

#include <SFML/Graphics.hpp>
#define SPEED 5

class Logo
{
private:
    sf::RectangleShape body; //holds the texture and the size of the logo
    float speed; //vector direction is multiplied by so it does move that fast
    sf::Vector2f direction;//
    int amount = 7; //number of available colors
    sf::Color color_list[7] = {sf::Color(255,0,0,255),   //red
                               sf::Color(0,255,0,255),   //green
                               sf::Color(0,0,255,255),   //blue
                               sf::Color(250,250,0,255), //yellow
                               sf::Color(137,0,250,255), //violet
                               sf::Color(250,0,250,255), //pink
                               sf::Color(250,104,0,255)  //orange
							  };

public:
    Logo(sf::Texture* texture, sf::Vector2u window_size, int x, int y);
    ~Logo();

    //moves body by vector "direction"
    void update();
    //return true if body is touching left or right side of the window
    bool CheckColisionX(int width);
    //return true if body is touching top or right bottom of the window
    bool CheckColisionY(int height);
    //draws body at current position
    void draw(sf::RenderWindow& window);
    //sets the random color of the texture from the color_list
    void changeColor(int num);
    //return vector "direction"
    sf::Vector2f getDirection();
    //sets vector "direction"
    void SetDirection(float x, float y);
};

#endif // LOGO_H
