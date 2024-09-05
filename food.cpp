#include "food.hpp"

Food::Food(){
    initFood();
}

Food::~Food(){

}

void Food::initFood(){
    foodShape.setFillColor(sf::Color::Yellow);
    foodShape.setSize(sf::Vector2f(30.f, 30.f));
    setPosition();
}

void Food::setRenderTarget(sf::RenderTarget *t){
    target = t;
}

void Food::setPosition(){
    srand(time(NULL));
    foodShape.setPosition(sf::Vector2f(5 + (rand() % ((WIDTH - 5) / 35)) * 35, 5 + (rand() % ((HEIGHT - 5) / 35)) * 35));
}

sf::Vector2f Food::getPosition(){
    return(foodShape.getPosition());
}

void Food::renderFood(){
    target->draw(foodShape);
}
