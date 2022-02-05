CC=clang
TARGET=build/main

# Get all source and header files, substitute '.o' for object files
SRCS := $(wildcard src/*.c)
HDRS := $(wildcard src/*.h)
OBJS := $(patsubst src/%.c, build/%.o, $(SRCS))

# Link
$(TARGET): $(OBJS) $(HDRS)
	@mkdir -p build
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile
build/%.o: src/%.c $(HDRS)
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

# Debugging

# Usage: make print-VAR_NAME, e.g., make print-SRCS
print-%  : ; @echo $* = $($*)