CC := clang
AR := llvm-ar
BUILD_DIR := build
SRC := source

C_FLAGS := --target=x86_64-elf -ffreestanding -fno-stack-protector -mno-red-zone -mno-sse -mno-sse2 -fno-pie -fno-builtin -nostdlib -O0 -Wall -Wextra -Iinclude

SRCS := $(wildcard $(SRC)/*/*.c)
OBJS := $(SRCS:$(SRC)/%.c=$(BUILD_DIR)/%.o)

all: $(BUILD_DIR)/mistic.a

$(BUILD_DIR)/mistic.a: $(OBJS)
	@mkdir -p $(dir $@)
	$(AR) rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@ -g

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
