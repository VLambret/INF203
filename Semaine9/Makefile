.PHONY : all clean test

SRC = variables.c manipulation_variables.c
HEADERS= variables.h manipulation_variables.h

TEST_EXE = interpreterTester
TEST_SRC = test.c test_manipulation_variables.c
TEST_HEADERS= test.h test_manipulation_variables.h

all : interpreter

clean :
	rm -f *.o interpreter $(TEST_EXE)

test : interpreter
	./interpreter example.sh

unit_test : $(TEST_EXE)
	./$(TEST_EXE)

$(TEST_EXE) : main_test.c $(SRC) $(TEST_SRC) $(TEST_HEADERS)
	gcc -o $@ -Wall -Werror main_test.c $(SRC) $(TEST_SRC)

interpreter : main.c $(SRC) $(HEADERS)
	gcc -o $@ -g -Wall -Werror main.c $(SRC)
