#############################################################################
# Makefile for building: Pong
# Created By Erick Muuo
# Project:  Pong
# Contact: hearteric57@gmail.com
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
CFLAGS        = -g -Wall -Wextra
CXXFLAGS      = -g -std=c++17 -Wall -Wextra
LIBS		  = -lsfml-graphics -lsfml-window -lsfml-system
SOURCES       = main.cpp 




build/Pong: build/main.o build/Game.o build/Bat.o build/Hud.o build/Ball.o
	$(CXX) build/main.o build/Game.o build/Bat.o build/Ball.o build/Hud.o -o build/Pong $(LIBS) 

build/Game.o: include/Game.cpp
	$(CXX) -c $(CXXFLAGS) -o build/Game.o include/Game.cpp

build/Bat.o: include/Bat.cpp
	$(CXX) -c $(CXXFLAGS) -o build/Bat.o include/Bat.cpp 

build/Hud.o: include/Hud.cpp
	$(CXX) -c $(CXXFLAGS) -o build/Hud.o include/Hud.cpp 

build/main.o: main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o main.cpp

build/Ball.o:include/Ball.cpp
	$(CXX) -c $(CXXFLAGS) -o build/Ball.o include/Ball.cpp 

init:
	mkdir build
	cp -r Assets build/Assets
clean:
	rm -rf build