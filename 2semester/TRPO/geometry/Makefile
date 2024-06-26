APP_NAME = geometry
LIB_NAME = libgeometry
TEST_NAME = main_test
TARGET_PATH = ./bin/

BIN = $(shell mkdir -p bin && cp test.txt bin)

TESTFLAGS = -I thirdparty
CFLAGS = -Wall -I src
DEPSFLAGS = -MMD
CC = g++

OBJ_PATH = ./obj/
OBJ_SRC = ./obj/src/
OBJ_LIB_PATH = ./obj/src/libgeometry/
OBJ_TEST_PATH = ./obj/test/


BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.c)
APP_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

.PHONY: all test clean
all: $(APP_PATH)

-include $(DEPS)

# BUILD
$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $< -lm

# TEST
check:
	if [ ! -d "$(OBJ_PATH)" ]; then mkdir $(OBJ_PATH); fi
	if [ ! -d "$(OBJ_SRC)" ]; then mkdir $(OBJ_SRC); fi
	if [ ! -d "$(OBJ_TEST_PATH)" ]; then mkdir $(OBJ_TEST_PATH); fi
	if [ ! -d "$(OBJ_LIB_PATH)" ]; then mkdir $(OBJ_LIB_PATH); fi
	if [ ! -d "$(TARGET_PATH)" ]; then mkdir $(TARGET_PATH); fi

test: check $(LIB_PATH) $(TEST_PATH)
	$(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(DEPSFLAGS) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -o $@ $^ -lm

$(OBJ_DIR)/test/main.o: test/main.c
	$(CC) $(DEPSFLAGS) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

$(OBJ_DIR)/test/tests.o: test/tests.c
	$(CC) $(DEPSFLAGS) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

# RUN
run: all
	$(APP_PATH) $(BIN_DIR)/test.txt

# CLEAN
clean:
	$(RM) $(APP_PATH) $(TEST_PATH) $(OBJ_DIR)/*/*/*.[aod] $(OBJ_DIR)/test/*.[aod]
