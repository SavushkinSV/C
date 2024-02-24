CFLAGS=-Werror -Wextra -Wall 
CC=gcc
FSAN=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector

all: build

rebuild: clean build

build: main.c
	gcc $(CFLAGS) main.c

build_fsanitize:
	gcc $(CFLAGS) $(FSAN) main.c

clean:
	rm -rf *.o *.out

check:
	clang-format -n */*.c
	# clang-format -n */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem */*.c
	# valgrind --tool=memcheck --leak-check=yes ./a.out 


