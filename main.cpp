#include "game.hpp"

int main(){

    Game game;
    while(game.running() && (!game.endGame())){
        game.Update();
        game.Render();
    }
    
    return 0;
}