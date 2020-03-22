CC=gcc
CFLAGS=`pkg-config --cflags --libs gtk+-3.0`
PROGRAM=interface

all: compile_interface run_interface

test_interface: compile_interface run_interface clean_interace

compile_interface: $(PROGRAM).c $(PROGRAM)
	$(CC) $(PROGRAM).c -o $(PROGRAM) $(CFLAGS) 

run_interface: $(PROGRAM)
	./$(PROGRAM)

clean_interace: $(PROGRAM)
	rm $(PROGRAM)