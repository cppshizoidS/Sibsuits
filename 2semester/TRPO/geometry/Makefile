CC = g++
CFLAGS = -Wall -Werror
DEPS = -MMD

OUT_DIR = bin

TARGET = main
TARGET_OUT_NAME = geometry
LIB_TARGET = libgeometry
LIB_OUT_NAME = $(LIB_TARGET).a
LIB_HEADERS_DIR = $(SRC_DIR)/libgeometry/headers

SRC_DIR = src
OBJ_DIR = obj
LIB_OBJ_DIR = $(OBJ_DIR)/$(LIB_TARGET)
LIB_SRC_DIR = $(SRC_DIR)/$(LIB_TARGET)
LIB_INC_DIR = $(LIB_SRC_DIR)/headers

LIB_OBJECTS = $(LIB_OBJ_DIR)/utils.o \
	$(LIB_OBJ_DIR)/point.o \
	$(LIB_OBJ_DIR)/figure.o \
	$(LIB_OBJ_DIR)/circle.o \
	$(LIB_OBJ_DIR)/triangle.o \
	$(LIB_OBJ_DIR)/parser.o

THIRDPARTY_DIR = thirdparty

TEST_SRC_DIR = test
TEST_OUT_NAME = $(TARGET_OUT_NAME)-test
TEST_OBJ_DIR = $(OBJ_DIR)/$(TEST_OUT_NAME)
TEST_OBJECTS = $(TEST_OBJ_DIR)/ctest.o $(TEST_OBJ_DIR)/main.o

SRCS := $(shell find . -type f -name '*.cpp')
HDRS := $(shell find . -type f -name '*.h')

all: clean format \
	$(OUT_DIR)/$(TARGET_OUT_NAME)/$(LIB_OUT_NAME) \
	test \
	$(OUT_DIR)/$(TARGET_OUT_NAME)/$(TARGET) 

# Final
$(OUT_DIR)/$(TARGET_OUT_NAME)/$(TARGET): \
	$(SRC_DIR)/$(TARGET_OUT_NAME)/$(TARGET).cpp \
	$(OUT_DIR)/$(TARGET_OUT_NAME)/$(LIB_OUT_NAME)

	$(CC) $(CFLAGS) -I$(LIB_HEADERS_DIR) -L$(OUT_DIR)/$(TARGET_OUT_NAME) -l$(TARGET_OUT_NAME) -o $@ $^
	
# Lib
$(OUT_DIR)/$(TARGET_OUT_NAME)/$(LIB_OUT_NAME): $(LIB_OBJECTS)
	ar rcs $@ $^

$(LIB_OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(DEPS) -I$(LIB_INC_DIR) -c $< -o $@

# Test
$(OUT_DIR)/$(TEST_OUT_NAME)/$(TEST_OUT_NAME): $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) -I$(THIRDPARTY_DIR) -I$(LIB_HEADERS_DIR) -L$(OUT_DIR)/$(TARGET_OUT_NAME) -l$(TARGET_OUT_NAME) -w -o $@

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp
	$(CC) $(DEPS) -I$(THIRDPARTY_DIR) -I$(LIB_HEADERS_DIR) -L$(OUT_DIR)/$(TARGET_OUT_NAME) -l$(TARGET_OUT_NAME) -c $< -w -o $@

# Utils
run: $(OUT_DIR)/$(TARGET_OUT_NAME)/$(TARGET)
	./$< geometry.txt

test: $(OUT_DIR)/$(TEST_OUT_NAME)/$(TEST_OUT_NAME)
	./$<

clean:
	rm -rf $(OBJ_DIR)/geometry/*.o $(OBJ_DIR)/geometry/*.d
	rm -rf $(TEST_OBJ_DIR)/*.o $(TEST_OBJ_DIR)/*.d
	rm -rf $(LIB_OBJ_DIR)/*.o $(LIB_OBJ_DIR)/*.d

format:
	clang-format -i $(SRCS) $(HDRS)

a:
	echo $(wildcard TEST_SRC_DIR/*.cpp)

.PHONY: all run clean format test
