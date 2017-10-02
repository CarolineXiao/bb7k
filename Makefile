#!/bin/bash
CXX = g++
CXXFLAGS = -Wall -MMD
SRCS = main.cc controller.cc grid.cc player.cc cards.cc
OBJS = $(SRCS: .cc=.o)
EXEC = bb7k

$(EXEC): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

main.o: controller.h grid.h player.h cards.h

.cc.o: $(CXX) $(CXXFLAGS) -c $< -o $@

clean:  rm *.o $(EXEC)

