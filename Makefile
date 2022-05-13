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




Pong: main.o Bat.o
	$(CXX) main.o Bat.o -o Pong $(LIBS) 

Bat.o: include/Bat.cpp
	$(CXX) -c $(CXXFLAGS) -o Bat.o include/Bat.cpp 

main.o: main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

clean:
	rm *.o Pong
