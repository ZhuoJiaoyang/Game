# Project:Game
# Author: AaronRobert,Zhuojiaoyang
# Makefile created by CodeicBuildTool 1.1

OBJ = \
	./build/intermediate\temp_0.o 
Game.exe:$(OBJ)
	g++.exe $(OBJ) -I.\sdllib\include\SDL2 -L.\sdllib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o ./build/output/Game.exe

./build/intermediate\temp_0.o:./src\main.cpp
	g++.exe -DDEBUG -c ./src\main.cpp -o ./build/intermediate\temp_0.o