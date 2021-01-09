CC = g++
CCFLAGS = -Wall -Werror -std=c++11 -g
LIBFLAGS = 

SRC_DIR = src
OBJ_DIR = bin
TST_DIR = tests

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

SAVES = $(wildcard *.txt)
EXEC = main


all: $(EXEC)

testcase: 
	cd $(TST_DIR); make

$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) $(LIBFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)
veryclean: clean
	rm -f $(SAVES)
cleantest:
	cd $(TST_DIR) ; make clean
distclean : clean cleantest