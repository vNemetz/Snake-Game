#include "game.hpp"
#include "snake.hpp"
#include "food.hpp"
#define HEIGHT 600
#define WIDTH 810

Game::Game(){
    /*
        Initializes the pointers as null and calls the
            init functions;
    */
    window = nullptr;
    snake = new Snake();
    food = new Food();
    initVariables();
    initWindow();
}

Game::~Game(){
    /*
        Deletes the dinnamically allocated variables
    */
    delete window;
    delete snake;
    delete food;
}
void Game::initVariables(){
    /*
        Initializes variables used in the main game class
    */
    videoMode.height = HEIGHT;
    videoMode.width = WIDTH;
    snake->setFood(food);
}

void Game::initWindow(){
    /*
        Allocates the space for the window, sets the frame rate
            and creates the grid
    */
    window = new sf::RenderWindow(videoMode, "Snake", sf::Style::Default);
    window->setFramerateLimit(60);
    createGrid();
    }

void Game::Update(){
    /*
        Updates the game info
    */
    eventPolling();
    moveSnake();
    snake->movement();
}

void Game::Render(){
    /*
        Renders the game graphics
    */
    window->clear(sf::Color(123, 63, 0, 255));
    renderGrid();
    if(window && snake && snake->getSize() > 0 && food){
        snake->setRenderTarget(window);
        snake->renderSnake();
        food->setRenderTarget(window);
        food->renderFood();

    }
    window->display();
}

void Game::eventPolling(){
    /*
        Checks if the game was closed or not
            if so, closes the game
    */
    while(window->pollEvent(ev)){
        switch (ev.type){
            case sf::Event::Closed: //If "X" was pressed
                window->close();
                break;
            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape) //If "Esc" was pressed
                    window->close();
                    break;
                }
            }   
}

const bool Game::running() const
{
    /*
        Checks if the game is running
    */
    return (window->isOpen());
}

void Game::createGrid(){
    /*
        Creates the game grid (gameboard), using squares
        Pushes all the squares with it's positions into a vector
    */
    rectGrid.setSize(sf::Vector2f(30.f, 30.f));
    rectGrid.setFillColor(sf::Color(210, 125, 45, 255));
    float width = 0;

    for(float height = 5.f; height <= videoMode.height - 10.f; height += 35.f){
        
        for(width = 5.f; width <= videoMode.width-10.f; width += 35.f){
            rectGrid.setPosition(sf::Vector2f(width, height));
            grid.push_back(rectGrid);
        }
        width = 0;
    }
}

void Game::renderGrid(){
    /*
        Renders the game grid
    */
    for(int i = 0; i < grid.size(); i++){
        window->draw(grid[i]);
    }
}

void Game::moveSnake(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            snake->updateDirection(sf::Keyboard::A);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            snake->updateDirection(sf::Keyboard::D);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            snake->updateDirection(sf::Keyboard::W);
        } 
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            snake->updateDirection(sf::Keyboard::S);
        }
}

bool Game::endGame() const{
    if(snake->checkCollision()){
        return true;
    }
    return false;
}

void Game::renderMenu(){
    window->clear(sf::Color::Yellow);
    window->display();
}

void Game::updateMenu(){
    
}

void Game::stateManager(int state){

}
