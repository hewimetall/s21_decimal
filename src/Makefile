GCC = gcc
CFLAGS = -I. 
LDFLAGS = -c
DIRS = ./comparison ./conversion ./math_ops ./other_func
SOURCE := $(shell find ${DIRS}  -iname "*.c" )
TEST_SOURCE := $(shell find ./tests  -iname "*.c" )
HEADER_SOURCE := $(shell find . -iname "*.h" )

ifeq ($(shell uname -s),Darwin)
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lpthread -lm
else
	TEST_FLAGS  = -fprofile-arcs -ftest-coverage --coverage $^ -o $@ -lcheck -lgcov -lpthread -lm -lsubunit

endif

all: clean s21_math.a test

s21_math.a: ${SOURCE} clean
	$(GCC) $(CFLAGS) $(LDFLAGS) $(SOURCE)
	ar rc $@  *.o
	ranlib $@

test: ${SOURCE} ${TEST_SOURCE}
	$(GCC) $(CFLAGS) $(TEST_FLAGS) 
	./$@

gcov_report: test
	gcov $(SOURCE) $(TEST_SOURCE)
	rm -rf s21_string_test.gcda s21_string_test.gcno
	find ./ -type f -iname '*.gcda'
	lcov --directory ./ --capture --output-file postgresql.info
	mkdir cov-report
	genhtml -o ./cov-report/ postgresql.info

lcov:
ifeq ("", "$(shell PATH=$(PATH) which lcov)")
	$(error Need to install lcov)
endif

cpplint: $(SOURCE) $(SOURCE_TEST)
	python3 ../materials/linters/cpplint.py --extensions=c $^

leaks: test
	leaks -atExit -- ./test

cppcheck: $(SOURCE) $(SOURCE_TEST) ${HEADER_SOURCE}
	cppcheck $^;

format: ${SOURCE} ${TEST_SOURCE} ${HEADER_SOURCE}
	cp .././materials/linters/.clang-format .
	clang-format -i -style=google $^;
	rm .clang-format

clean: 
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./cov-report
	-rm -rf ./report/ && rm -rf test.dSYM
	-rm -rf test
