#
#makefile for Roman Roulette
#

RM = rm -f
SRCPATH = .
TESTNAME = test
TESTSRC = main.cpp

all: re $(SRC) $(TESTSRC)
	g++ $(TESTSRC) -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE -o $(TESTNAME)

debug: re $(SRC) $(TESTSRC)
	g++ $(TESTSRC) -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE -o $(TESTNAME) -g

retest: re test

clean:
	-$(RM) *.o
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) *.gch

fclean: clean
	-$(RM) $(TESTNAME)

re: fclean

test: fclean $(TESTSRC)
	g++ $(TESTSRC) -Wall -Werror -std=c++0x -o $(TESTNAME)
