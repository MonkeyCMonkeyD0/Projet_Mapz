CC = g++
CCFLAGS = -Wall -Werror -std=c++11 -g
LIBFLAGS = 

SRC_DIR = ../src/
OBJ_DIR = ../bin/

SRC = $(wildcard $(SRC_DIR)*.cpp)
TST = $(wildcard *.cpp)
OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
OBJ_TEST = $(filter-out $(OBJ_DIR)main.o, $(OBJ)) $(TST:%.cpp=%.o)


testcase: $(OBJ_TEST)
	$(CC) $(CCFLAGS) $(LIBFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean:
	rm -f $(OBJ_TEST) testcase
