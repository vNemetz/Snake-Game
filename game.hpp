
#ifndef _GAME_HPP_
#define _GAME_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <vector>
#include <iostream>

#define HEIGHT 600
#define WIDTH 810

class Snake;
class Food;

class Game{
private:
    //Window Attributes
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event ev;
    //Grid
    std::vector<sf::RectangleShape> grid;
    sf::RectangleShape rectGrid;
    //Snake
    Snake *snake;
    //Food
    Food* food;
public:
    //Constructors and Destructors
    Game();
    ~Game();

    //Initializing
    void initVariables();
    void initWindow();

    //Uptading and Rendering
    void Update();
    void Render();

    //Functions
    void eventPolling();
    const bool running() const;
    //Grid
    void createGrid();
    void renderGrid();
    //Snake
    void renderSnake();
    void moveSnake();
    //End Game
    bool endGame() const;
    //Menu
    void renderMenu();
    void updateMenu();
    //Checks if we are in menu, game or game over.
    void stateManager(int state);

};

#endif