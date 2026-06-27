TARGET      := ml-dsa

SRC_DIR     := src
INC_DIR     := include
OBJ_DIR     := build/obj
BIN_DIR     := build/bin

BUILD       ?= generic      # generic | stm32

CC          ?= gcc
AR          ?= ar

RM          := rm -rf
MKDIR       := mkdir -p

CSTD        := -std=c99
OPT         ?= -O2

WARNINGS := \
    -Wall \
    -Wextra \
    -Wpedantic \
    -Wshadow \
    -Wconversion

CPPFLAGS := \
    -I$(INC_DIR) \
    -I$(SRC_DIR) \
    -I$(SRC_DIR)/math \
    -MMD \
    -MP

CFLAGS := \
    $(CSTD) \
    $(WARNINGS) \
    $(OPT)

LDFLAGS :=
LDLIBS  :=

ifeq ($(BUILD),stm32)

CC := arm-none-eabi-gcc
AR := arm-none-eabi-ar

CPUFLAGS := \
    -mcpu=cortex-m4 \
    -mthumb

CFLAGS += $(CPUFLAGS)

endif

LIB_SRCS := $(shell find $(SRC_DIR) -name "*.c")

APP_SRCS := $(wildcard example/generic/*.c)

SRCS := \
    $(LIB_SRCS) \
    $(APP_SRCS)

OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJS)
	@$(MKDIR) $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) build

rebuild: clean all

print:
	@echo "Compiler : $(CC)"
	@echo "Build    : $(BUILD)"
	@echo "Sources:"
	@printf "  %s\n" $(SRCS)

-include $(DEPS)

.PHONY: all clean rebuild print