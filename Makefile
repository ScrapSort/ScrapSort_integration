CC=clang
CFLAGS= -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wunreachable-code

# Source / build directories and executables

SRC=src
DST=build
TST=test
TARGET=${DST}/main
TST_TARGET=${DST}/run_tests

# Get all source and header files, substitute '.o' for object files
SRCS := $(wildcard ${SRC}/*.c)
HDRS := $(wildcard ${SRC}/*.h)
OBJS := $(patsubst ${SRC}/%.c, ${DST}/%.o, $(SRCS))

# Get test sources, headers, and objects
TST_SRCS := $(wildcard ${TST}/*.c)
TST_HDRS := $(wildcard ${TST}/*.h)
TST_OBJS := $(patsubst ${TST}/%.c, ${DST}/%.o, $(TST_SRCS))

all: $(TARGET) $(TST_TARGET)

# Link

$(TARGET): $(OBJS) $(HDRS)
	@mkdir -p ${DST}
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(TST_TARGET): $(TST_OBJS) $(filter-out ${TARGET}.o, $(OBJS))
	@mkdir -p ${DST}
	$(CC) $(CFLAGS) $^ -o $@

# Compile

${DST}/%.o: ${SRC}/%.c $(HDRS)
	@mkdir -p ${DST}
	$(CC) $(CFLAGS) -c $< -o $@

${DST}/%.o: ${TST}/%.c $(TST_HDRS) $(HDRS)
	@mkdir -p ${DST}
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) $(TST_OBJS)

# Debugging

# Usage: make print-VAR_NAME, e.g., make print-SRCS
print-%  : ; @echo $* = $($*)
