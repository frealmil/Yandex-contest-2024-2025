CC = gcc
CFLAGS = -lm -O2 -fno-stack-limit -std=c17 
TARGET = program
SRC = task_5.c

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clang_check:
	clang-format -n *.c

clang:
	clang-format -i *.c

clean:
	rm -f $(TARGET)