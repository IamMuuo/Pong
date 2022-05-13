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




Pong: main.o Bat.o Hud.o Ball.o
	$(CXX) main.o Bat.o Ball.o Hud.o -o Pong $(LIBS) 

Bat.o: include/Bat.cpp
	$(CXX) -c $(CXXFLAGS) -o Bat.o include/Bat.cpp 

Hud.o: include/Hud.cpp
	$(CXX) -c $(CXXFLAGS) -o Hud.o include/Hud.cpp 

main.o: main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Ball.o:include/Ball.cpp
	$(CXX) -c $(CXXFLAGS) -o Ball.o include/Ball.cpp 
clean:
	rm *.o Pong
