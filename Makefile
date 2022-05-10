#	####################################### #
#	Makefile for poject pong
#	Written By Eric Muuo
#	Email: hearteric57@gmail.com
#	####################################### #

c++ = g++
libs = -lsfml-graphics -lsfml-window -lsfml-system
flags = -Wall -Wextra -std=c++17 -g

Pong: main.o
	$(c++) main.o -o Pong $(libs)

main.o: main.cpp
	$(c++) main.cpp -o main.o -c $(flags)

