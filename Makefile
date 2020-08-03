# Makefile

# Variables
CFLAGS = gcc -ansi -std=c99 -Wall -c
FLAGS = gcc -ansi -std=c99 -Wall 
CDEPS = ./bin/Main.o ./bin/Menu.o ./bin/Help.o ./bin/Board.o ./bin/CheckMove.o ./bin/IsOccupied.o ./bin/Checkmate.o ./bin/AI_1.o
TXT = ./bin/ChessHistory.txt 
# Default target
all: ./bin/Chess

test: 
	./bin/Chess

txt: 
	cat ./bin/ChessHistory.txt
 
tar:
	tar -zcvf Chess_Beta_src.tar.gz README.md INSTALL COPYRIGHT Makefile src bin chess doc

######################### Generate object files #######################
# Target for Board.o
./bin/%.o: ./src/%.c
	$(CFLAGS) $^ -o $@


######################### Generate the executable #####################
# Target for Chess
./bin/Chess: $(CDEPS)
	$(FLAGS) $^ -o $@

###############################  others  ##############################
# Target for clean
clean:
	rm -rf ./bin/*.o $(TXT) ./bin/Chess
