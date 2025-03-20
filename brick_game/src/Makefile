CC = gcc -arch x86_64
CFLAGS = -Wall -Werror -Wextra -std=c11
LDFLAGS = -lcheck -lm -lcurses -lncurses

SOURCEPATH = brick_game/tetris
SOURCEFILES = fsm.c backend.c
SOURCEOBJ = $(SOURCEFILES:%.c=%.o)
TETRISPATH = gui/cli
TETRISFILES = frontend.c tetris.c
TETRISOBJ =  $(TETRISFILES:%.c=%.o)
TESTPATH = test_source
TESTFILES = tetris_tests.c
TESTOBJ = $(TESTFILES:%.c=%.o)

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
	LDFLAGS += -lsubunit -lrt
endif

.PHONY: all install uninstall clean dvi dist test gcov_report

all: install

install: $(SOURCEOBJ) $(TETRISOBJ)
	$(CC) -o tetris $(TETRISOBJ) $(SOURCEOBJ) $(LDFLAGS)
	touch data.txt
	rm -rf *.o

uninstall: clean
	rm -rf tetris data.txt

$(TETRISOBJ): $(addprefix $(TETRISPATH)/,$(TETRISFILES))
	$(CC) -c $^

$(SOURCEOBJ): $(addprefix $(SOURCEPATH)/,$(SOURCEFILES))
	$(CC) -c $^

test: $(SOURCEOBJ) $(TESTOBJ)
	$(CC) $(CFLAGS) -o $@ $(SOURCEOBJ) $(TESTOBJ) $(LDFLAGS)
	rm -rf $(SOURCEOBJ) $(TESTOBJ) 

$(TESTOBJ):
	$(CC) $(CFLAGS) -c $(addprefix $(TESTPATH)/,$(TESTFILES))

dvi:
	@doxygen

gcov_report:
	$(CC) $(CFLAGS) --coverage $(addprefix $(SOURCEPATH)/,$(SOURCEFILES)) $(addprefix $(TESTPATH)/,$(TESTFILES)) $(LDFLAGS) -o tetris_report 
	./tetris_report
	lcov -t "tetris_report" -o tetris_report.info -c -d .
	genhtml -o report tetris_report.info
	open report/index.html

clean:
	rm -rf *.o report *.gcno *.gcda *.info doxygen test

rebuild: clean all
