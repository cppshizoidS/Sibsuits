# COMPILE
CC = g++ -g -Wall -Werror

# TARGETS
TARGET = geometry
TEST_TARGET = tests

# MAIN PATHES
TARGET_PATH = ./bin/
LIB_PATH = ./bin/
INCLUDE_PATH = ./include/
SRC_PATH = ./src/
SRC_LIB_PATH = ./src/libgeometry/
OBJ_PATH = ./obj/
OBJ_SRC = ./obj/src/
OBJ_LIB_PATH = ./obj/src/libgeometry/
OBJ_TEST_PATH = ./obj/test/
TEST_PATH = ./test/
THIRDPARTY_PATH = ./thirdparty/

# LIBRARY
LIBS = -lm
LIB = libgeometry.a

# SRC FILES
SRC = $(wildcard $(SRC_PATH)*.cpp)
SRC_LIB = $(wildcard $(SRC_LIB_PATH)*.cpp)

# OBJ FILES
OBJ = $(patsubst $(SRC_PATH)%.cpp, $(OBJ_SRC)%.o, $(SRC))
OBJ_LIB = $(patsubst $(SRC_LIB_PATH)%.cpp, $(OBJ_LIB_PATH)%.o, $(SRC_LIB))

# TEST FILES
TEST = $(wildcard $(TEST_PATH)*.cpp)
OBJ_TEST = $(patsubst $(TEST_PATH)%.cpp, $(OBJ_TEST_PATH)%.o, $(TEST))

all : check $(TARGET) $(TEST_TARGET)

$(TARGET) : $(LIB) $(OBJ)
	$(CC) $(OBJ) -I $(INCLUDE_PATH) $(LIB_PATH)$(LIB) -o $(TARGET_PATH)$(TARGET) $(LIBS)

$(TEST_TARGET) : $(OBJ_LIB) $(LIB) $(OBJ_TEST)
	$(CC) -I $(INCLUDE_PATH) -I $(THIRDPARTY_PATH) $(OBJ_LIB) $(OBJ_TEST) -o $(TARGET_PATH)$(TEST_TARGET) $(LIBS)

$(LIB) : $(OBJ_LIB)
	ar rcs $(LIB_PATH)$(LIB) $(OBJ_LIB)

clean :
	rm -rf $(TARGET_PATH) $(OBJ_PATH)

rebuild : clean all

run : all
	$(TARGET_PATH)$(TARGET) example/test.txt

run-test : all
	$(TARGET_PATH)$(TEST_TARGET)

check :
	if [ ! -d "$(OBJ_PATH)" ]; then mkdir $(OBJ_PATH); fi
	if [ ! -d "$(OBJ_SRC)" ]; then mkdir $(OBJ_SRC); fi
	if [ ! -d "$(OBJ_TEST_PATH)" ]; then mkdir $(OBJ_TEST_PATH); fi
	if [ ! -d "$(OBJ_LIB_PATH)" ]; then mkdir $(OBJ_LIB_PATH); fi
	if [ ! -d "$(TARGET_PATH)" ]; then mkdir $(TARGET_PATH); fi

$(OBJ_LIB_PATH)%.o : $(SRC_LIB_PATH)%.cpp
	$(CC) -I $(INCLUDE_PATH) -c $< -o $@
	
$(OBJ_SRC)%.o : $(SRC_PATH)%.cpp
	$(CC) -I $(INCLUDE_PATH) -c $< -o $@

$(OBJ_TEST_PATH)%.o : $(TEST_PATH)%.cpp
	$(CC) -I $(INCLUDE_PATH) -I $(THIRDPARTY_PATH) -c $< -o $@
