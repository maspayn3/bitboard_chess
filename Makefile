# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Board.o
	$(CC) $(CFLAGS) -o main main.o Board.o
 
# The main.o target can be written more simply
 
main.o: main.cpp Board.h 
	$(CC) $(CFLAGS) -c main.cpp
 
Board.o: Board.h