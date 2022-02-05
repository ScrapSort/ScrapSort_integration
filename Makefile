CC=clang
CFLAGS= -Wall -Wextra -Wpedantic

SRC=src
DST=build
TARGET=${DST}/main

# Get all source and header files, substitute '.o' for object files
SRCS := $(wildcard ${SRC}/*.c)
HDRS := $(wildcard ${SRC}/*.h)
OBJS := $(patsubst ${SRC}/%.c, ${DST}/%.o, $(SRCS))

# Link
$(TARGET): $(OBJS) $(HDRS)
	@mkdir -p ${DST}
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile
${DST}/%.o: ${SRC}/%.c $(HDRS)
	@mkdir -p ${DST}
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

# Debugging

# Usage: make print-VAR_NAME, e.g., make print-SRCS
print-%  : ; @echo $* = $($*)