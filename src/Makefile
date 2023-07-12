CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -std=c11
GCOVFLAGS:=-fprofile-arcs -ftest-coverage
LDFLAGS:=-lcheck -lgcov -fprofile-arcs --coverage
ifeq ($(shell uname), Linux)
LDFLAGS +=-lpthread -lrt -lm -lsubunit
OPEN_CMD:=xdg-open
else ifeq ($(shell uname), Darwin)
OPEN_CMD:=open
endif

SRC:= $(wildcard s21_*.c)
OBJ = $(addprefix obj/,$(SRC:.c=.o))
OBJ_GCOV = $(addprefix gcov_obj/,$(SRC:.c=.o))
TEST_SRC:= $(wildcard tests/test_*.c)
TEST_OBJ = $(addprefix tests/,$(TEST_SRC:.c=.o))

all: s21_matrix.a test

s21_matrix.a: $(OBJ)
	ar -src $@ $(OBJ)

s21_matrix_gcov.a: $(OBJ_GCOV)
	ar -src $@ $(OBJ_GCOV) 

test: tests/test_s21_matrix.o s21_matrix_gcov.a
	$(CC) -g $< s21_matrix_gcov.a -o $@ $(LDFLAGS) $(GCOVFLAGS)
	clear
	./test

clean:
	rm -f */*.o
	rm -f gcov_obj/*.gc*
	rm -f ./test
	rm -f -r out
	rm -f gcov_obj/*.info
	rm -f .DS_Store
	rm -f *.a
	rm -rf test.dSYM
	rm -f tests/*.o
	rm -f ../.DS_Store

gcov_obj/%.o: %.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

gcov_report: test
	lcov -c -d gcov_obj/. -o gcov_obj/coverage.info
	genhtml gcov_obj/coverage.info --output-directory out
	$(OPEN_CMD) out/index.html

rebuild: clean all

clang:
	clang-format -i *.c *.h tests/*.c

style:
	clang-format -n *.c *.h tests/*.c

leaks: rebuild
	leaks -atExit -- ./test

valgrind: rebuild
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test