#include "snake.hpp"

//Constructors and Destructors
Snake::Snake() : target(nullptr), size(4), velocity(35.f), direction(sf::Vector2f(0.f, 0.f)), moveInterval(0.1f),
  lastPressed(sf::Keyboard::Q), debounceTime(2.f)
{
    initBody();
}

Snake::~Snake(){

}
void Snake::updateDirection(sf::Keyboard::Key key){
    if(key == sf::Keyboard::A){
        if(lastPressed != sf::Keyboard::D){
            direction = sf::Vector2f(-1.f, 0);
            lastPressed = sf::Keyboard::A;
        }
    }
    else if(key == sf::Keyboard::D){
        if(lastPressed != sf::Keyboard::A){
            direction = sf::Vector2f(1.f, 0);
            lastPressed = sf::Keyboard::D;
        }
    }
    else if(key == sf::Keyboard::W){
        if(lastPressed != sf::Keyboard::S){
            direction = sf::Vector2f(0, -1.f);
            lastPressed = sf::Keyboard::W;
        }
    }
    else if(key == sf::Keyboard::S){
        if(lastPressed != sf::Keyboard::W){
            direction = sf::Vector2f(0, 1.f);
            lastPressed = sf::Keyboard::S;
        }
    }
}
void Snake::movement(){
    if (movementClock.getElapsedTime().asSeconds() >= moveInterval){
        if(target){
            sf::RectangleShape newHead = body[0]; //Creates a new head

            body[0].setFillColor(sf::Color(140, 22, 220, 255)); //Changes the old head sprite color to default body color
            sf::Vector2f newPosition = body[0].getPosition() + (direction * velocity);

            if(newPosition.x +35.f > WIDTH)
                newPosition.x = 5.f;
            if(newPosition.x < 0)
                newPosition.x = WIDTH;
            if(newPosition.y + 35.f > HEIGHT)
                newPosition.y = 5.f;
            if(newPosition.y < 0)
                newPosition.y = HEIGHT;
            newHead.setPosition(newPosition); //Sets the new position of the head
            body.insert(body.begin(), newHead); //Inserts the head in the body
            if(!checkFoodEaten())
                body.pop_back(); //Removes the tail
            else{
                sf::RectangleShape tail = body.back();
                increaseBodySize(tail.getPosition());
            }
            //bodyPositions.pop_back();
            //bodyPositions.insert(bodyPositions.begin(), newPosition);
        }

        movementClock.restart();
    }
}

void Snake::initBody(){
    //Inicia a cobra com 4 segmentos e a cabeça com outra cor

    bodyPart.setFillColor(sf::Color(0, 200, 0, 255));
    bodyPart.setSize(sf::Vector2f(30.f, 30.f));
    for(int i = 0; i < size; i++){
        bodyPart.setPosition(sf::Vector2f(((WIDTH/2.f) - 15.f) + 35*i, ((HEIGHT/2.f) - 15.f)));
        body.push_back(bodyPart);
        bodyPart.setFillColor(sf::Color(140, 22, 220, 255));
        //bodyPositions.push_back(bodyPart.getPosition());
    }
}

int Snake::getSize(){
    return body.size();
}

void Snake::increaseBodySize(sf::Vector2f pos){
    if(checkFoodEaten()){
        food->setPosition();
        bodyPart.setPosition(sf::Vector2f(pos));
        body.push_back(bodyPart);
    }
}

void Snake::setRenderTarget(sf::RenderTarget *t){
    /*
        -Recieves the rendering target as parameter
        -Used to render the snake body
    */
    target = t;
}

void Snake::renderSnake(){
    /*
        -Checks if there is a rendering target
        -If so, renders the body on it
    */
    if(target){
        for(int i = body.size() - 1; i >= 0; i--){
            target->draw(body[i]);
        }
    }
}

void Snake::setFood(Food* f){
    food = f;
}

bool Snake::checkFoodEaten() const{
    /*
        Checks if the snake "ate" the food
    */
    float epsilon = 0.5f;
    if(std::abs(food->getPosition().x - body[0].getPosition().x) < 35.f &&
       std::abs(food->getPosition().y - body[0].getPosition().y) < 35.f)
        return true;
    return false;

}

bool Snake::checkCollision(){
    // Verifica se o debounce time expirou
    if (debounceClock.getElapsedTime().asSeconds() < debounceTime) {
        return false; // Não faz a checagem de colisão durante o debounce
    }
    float epsilon = 0.5f; // Tolerância para a comparação
    for (int i = 1; i <= body.size(); i++) {
        if (std::abs(body[0].getPosition().x - body[i].getPosition().x) < epsilon &&
            std::abs(body[0].getPosition().y - body[i].getPosition().y) < epsilon) {
            return true;
        }
    }
    return false;

}
