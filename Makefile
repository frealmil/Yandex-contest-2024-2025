# CC=gcc
# CFLAGS=-std=c11 -Wall -Werror -Wextra -g
# SOURCES=s21_matrix.c
# OBJECTS=$(SOURCES:.c=.o)
# OS = $(shell uname)
# TEST_FILE_NAME = s21_test_matrix.c

# all: s21_matrix.a test

# s21_matrix.a: clean $(OBJECTS)
# 	ar -rcs s21_matrix.a $(OBJECTS)
# 	rm -f *.o

# test: $(TEST_FILE_NAME) s21_matrix.a
# 	$(CC) $(CFLAGS) $(TEST_FILE_NAME) $(SOURCES) -o test $(TEST_LIBS) -L.
# 	./test

# style:
# 	@cp ../materials/linters/.clang-format .
# 	clang-format -i *.c *.h
# 	@rm -rf .clang-format

# clang:
# 	@cp ../materials/linters/.clang-format .
# 	clang-format -n *.c *.h
# 	@rm -rf .clang-format

# clean:
# 	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt test.info test.dSYM *.out

# valgrind:
# 	gcc *.c -lcheck -lsubunit -lm
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./a.out
# 	grep -e ERROR res_leak.txt
# 	rm -rf *.gcda

# cppcheck:
# 	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

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