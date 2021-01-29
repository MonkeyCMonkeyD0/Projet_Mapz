CC = g++
CCFLAGS = -Wall -Werror -std=c++11 -g
CFLAGS = -I../include/
LDFLAGS = -L../lib/
LDFLAGS += -lglfw3
FMFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

SRC_DIR = ../src/
OBJ_DIR = ../bin/

SRC = $(wildcard $(SRC_DIR)*.cpp)
TST = $(wildcard *.cpp)
OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
OBJ_TEST = $(filter-out $(OBJ_DIR)main.o, $(OBJ)) $(TST:%.cpp=%.o)


testcase: $(OBJ_TEST)
	$(CC) $(CCFLAGS) $(CFLAGS) $(LDFLAGS) $(FMFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CCFLAGS) $(CFLAGS) -o $@ -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ_TEST) testcase

.PHONY: clean testcase