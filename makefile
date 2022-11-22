# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o tableau.o
    $(CC) $(CFLAGS) -o main main.o tableau.o
 
# The main.o target can be written more simply
 
main.o: main.cpp tableau.h
    $(CC) $(CFLAGS) -c main.cpp
 
tableau.o: tableau.h
