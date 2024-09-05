#ifndef _SNAKE_H_
#define _SNAKE_H_
#include "game.hpp"
#include "food.hpp"
#include <vector>

//Class that control the snake behaviours
class Snake{ 
private:
    //Snake attributes
    
    int size;
    std::vector<sf::RectangleShape> body;
    sf::RectangleShape bodyPart;
    void initBody();

    //Movement attributes
    sf::Event ev;
    float velocity;
    sf::Vector2f direction;
    sf::Keyboard::Key lastPressed;
    //Render
    sf::RenderTarget* target; //Pointer to the rendering target

    //Clock
    sf::Clock movementClock;
    float moveInterval;

    //Food
    Food* food;

    //Body Positions
    std::vector<sf::Vector2f> bodyPositions;

    //Debounce
    sf::Clock debounceClock;
    float debounceTime;

public:

    //Constructors n' destructors
    Snake();
    virtual ~Snake();

    //Movement
    void movement();
    void updateDirection(sf::Keyboard::Key key);

    //Body
    int getSize();
    void increaseBodySize(sf::Vector2f pos);
    
    //Render
    void renderSnake();
    void setRenderTarget(sf::RenderTarget* t);

    //Food
    void setFood(Food* f);
    bool checkFoodEaten() const;

    //Collision
    bool checkCollision();
};
#endif