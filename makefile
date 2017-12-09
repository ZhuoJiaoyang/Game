# Project:Game
# Author: Zhuojiaoyang
# Makefile created by CodeicBuildTool 1.1

OBJ = \
	./build/intermediate\\temp_0.o 
Game.exe:$(OBJ)
	g++.exe -o ./build/output/Game.exe $(OBJ)

./build/intermediate\\temp_0.o:./src\main.cpp
	g++.exe -DDEBUG -c ./src\main.cpp -o ./build/intermediate\\temp_0.o