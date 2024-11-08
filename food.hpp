#ifndef _FOOD_HPP_
#define _FOOD_HPP_
#include "game.hpp"
#include <cstdlib>

//Class that controls the snake food behaviours
class Food{
private:
    sf::RectangleShape foodShape;
    sf::RenderTarget* target;

public:

    Food();
    ~Food();
    //Food attributes
    void initFood();
    void setRenderTarget(sf::RenderTarget* t);

    //Position
    void setPosition();
    sf::Vector2f getPosition();
    //Render
    void renderFood();
    
};
#endif