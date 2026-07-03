SRC_DIR := src
INC_DIR := include

OBJ_DIR := build/obj
BIN_DIR := build/bin
LIB_DIR := build/lib

CC ?= gcc
AR ?= ar

RM := rm -rf
MKDIR := mkdir -p
FIND := find

CSTD := -std=c99

WARNINGS := \
    -Wall \
    -Wextra \
    -Wpedantic \
    -Wshadow \
    -Wconversion

OPT ?= -O2

CPPFLAGS := \
    -I. \
    -I$(INC_DIR) \
    -I$(SRC_DIR)

CFLAGS := \
    $(CSTD) \
    $(WARNINGS) \
    $(OPT)

LDFLAGS :=
LDLIBS :=

LIB_SRCS := $(shell $(FIND) $(SRC_DIR) -name '*.c')

EXAMPLE_SRCS := $(shell $(FIND) example -name '*.c')

TEST_SRCS := $(shell $(FIND) test -name '*.c')

LIB_OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(LIB_SRCS))

EXAMPLE_OBJS := \
    $(patsubst %.c,$(OBJ_DIR)/%.o,$(EXAMPLE_SRCS))

TEST_OBJS := \
    $(patsubst %.c,$(OBJ_DIR)/%.o,$(TEST_SRCS))

LIBRARY := $(LIB_DIR)/lib$(PROJECT).a

EXAMPLE := $(BIN_DIR)/example

TEST := $(BIN_DIR)/test

all: example

example: $(EXAMPLE)

test: $(TEST)

$(LIBRARY): $(LIB_OBJS)
	@$(MKDIR) $(LIB_DIR)
	$(AR) rcs $@ $^

$(EXAMPLE): $(LIBRARY) $(EXAMPLE_OBJS)
	@$(MKDIR) $(BIN_DIR)
	$(CC) $(EXAMPLE_OBJS) $(LIBRARY) -o $@ $(LDFLAGS) $(LDLIBS)

$(TEST): $(LIBRARY) $(TEST_OBJS)
	@$(MKDIR) $(BIN_DIR)
	$(CC) $(TEST_OBJS) $(LIBRARY) -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) build

rebuild: clean all

print:
	@echo "Library Sources"
	@printf "  %s\n" $(LIB_SRCS)
	@echo
	@echo "Example Sources"
	@printf "  %s\n" $(EXAMPLE_SRCS)
	@echo
	@echo "Test Sources"
	@printf "  %s\n" $(TEST_SRCS)

DEPS := $(LIB_OBJS:.o=.d)
DEPS += $(EXAMPLE_OBJS:.o=.d)
DEPS += $(TEST_OBJS:.o=.d)

-include $(DEPS)

.PHONY: all example test clean rebuild print