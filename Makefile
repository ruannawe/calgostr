CC = gcc
CFLAGS = -Wall -Wextra -I./include
AR = ar
ARFLAGS = rcs
RM = rm -f

SRC_DIR = src
TEST_DIR = tests
EXAMPLE_DIR = examples
LIB_DIR = lib

SRC_FILES = $(SRC_DIR)/string.c
OBJ_FILES = $(SRC_FILES:.c=.o)
LIB_NAME = libcalgostr.a

TEST_FILES = $(TEST_DIR)/test_string.c
TEST_OBJ = $(TEST_FILES:.c=.o)
TEST_EXEC = test_trim

EXAMPLE_FILES = $(EXAMPLE_DIR)/example_trim.c
EXAMPLE_OBJ = $(EXAMPLE_FILES:.c=.o)
EXAMPLE_EXEC = example_trim

.PHONY: all clean test example

all: $(LIB_DIR)/$(LIB_NAME)

$(LIB_DIR)/$(LIB_NAME): $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_DIR)/*.o $(TEST_DIR)/*.o $(EXAMPLE_DIR)/*.o
	$(RM) $(LIB_DIR)/$(LIB_NAME)
	$(RM) $(TEST_EXEC) $(EXAMPLE_EXEC)

test: $(LIB_DIR)/$(LIB_NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) -L$(LIB_DIR) -lcalgostr
	./$(TEST_EXEC)

example: $(LIB_DIR)/$(LIB_NAME) $(EXAMPLE_OBJ)
	$(CC) $(CFLAGS) -o $(EXAMPLE_EXEC) $(EXAMPLE_OBJ) -L$(LIB_DIR) -lcalgostr
	./$(EXAMPLE_EXEC)
