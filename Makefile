all: 
	g++ -o main main.cpp game.cpp snake.cpp food.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clear: main