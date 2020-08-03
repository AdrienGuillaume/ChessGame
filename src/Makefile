# Makefile

# Variables
CFLAGS = gcc -g -ansi -std=c99 -Wall -c
FLAGS = gcc -ansi -std=c99 -Wall -g
DESIGN = Chess

# Default target
all: Chess

test: Chess
	./Chess

txt: Chess
	cat ChessHistory.txt

######################### Generate object files #######################
# Target for Board.o
Board.o: Board.h Board.c
	$(CFLAGS) Board.c -o Board.o

# Target for Chess_Pieces.o
CheckMove.o: CheckMove.h Board.h CheckMove.c
	$(CFLAGS) CheckMove.c -o CheckMove.o -lm

# Target for IsOccupied.o
IsOccupied.o: IsOccupied.h IsOccupied.c
	$(CFLAGS) IsOccupied.c -o IsOccupied.o 
 
# Target for Checkmate.o
Checkmate.o: Checkmate.h CheckMove.h Checkmate.c
	$(CFLAGS) Checkmate.c -o Checkmate.o

# Target for Help.o
Help.o: Help.h Help.c
	$(CFLAGS) Help.c -o Help.o

# Target for Menu.o
Menu.o: Menu.h Menu.c
	$(CFLAGS) Menu.c -o Menu.o

# Target for Main.o
Main.o: Main.c Menu.h Help.h Board.h 
	$(CFLAGS) Main.c -o Main.o
 
# Target for AI_1.o
AI_1.o: AI_1.c AI_1.h Checkmate.h
	$(CFLAGS) AI_1.c -o AI_1.o

######################### Generate the executable #####################
# Target for Chess
Chess: Main.o Menu.o Help.o Board.o CheckMove.o IsOccupied.o Checkmate.o AI_1.o
	$(FLAGS) Main.o Menu.o Help.o Board.o CheckMove.o IsOccupied.o Checkmate.o AI_1.o -o Chess -lm

###############################  others  ##############################
# Target for clean
clean:
	rm -f *.o $(DESIGN)

