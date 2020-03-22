CC=gcc
CFLAGS=`pkg-config --cflags --libs gtk+-3.0`
PROGRAM=interface

all: compile

test: compile run clean

compile: $(PROGRAM).c $(PROGRAM)
	$(CC) $(PROGRAM).c -o $(PROGRAM) $(CFLAGS) 

run: $(PROGRAM)
	./$(PROGRAM)

clean: $(PROGRAM)
	rm $(PROGRAM)