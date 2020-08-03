/* Main.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "Menu.h"
#include "Board.h"
#include "Help.h"
#include "CheckMove.h"
#include "Checkmate.h"
#include "AI_1.h"


char board[8][8] = {

						
							{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
							{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},			
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
							{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},


						};

					
	
const char positions[8][8][3] = 	{
								{"A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8"},
								{"A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7"},
								{"A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6"},
								{"A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5"},
								{"A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4"},
								{"A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3"},
								{"A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2"},
								{"A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"},
						   		};

//global varibles as castling flags
int WhiteKing = 0;
int WRook1 = 0;
int WRook2 = 0;
int BlackKing = 0;
int BRook1 = 0;
int BRook2 = 0;

int main(void)
{
	int size = 9;
	int selection = 0, repeat = 0;
	int y, CPUTrash = 0;
	char temp1, temp2;
	char trash[10];
	char movement[size], opponentCP[3], opponentNP[3], opponentPiece, AI_movement[size];
	char current_position[3], new_position[3];
	char startgame, undo;
	int player = 0, PlayerNum = 1;
	int CPUFLAG = 0;
	int round = 0;
	int challengerOption, colorOption;
	FILE *file;
	int legalFLAG = 0, undoFLAG = 0;
	int checkFLAG = 0, checkmateFLAG = 0;
	int AI_checkFLAG = 0, AI_checkmateFLAG = 0;
	char white_piece;
	char black_piece;
	int color = 0;
	int color_checkx = 0;
	int color_checky = 0;
	int xx = 0, yy = 0;
  	char AI_cur_position[3];
  	char AI_new_position[3];
	int suicide_king = 0;
	int AI_round = 2;
	int AI_roundFLAG = 0;
	int CASTLINGFLAG = 0;
	int large = 80;
	int CPU = 0;
	char check_capture;
	
	//Board
	/*upper case for WHITE*/
	/*lower case for BLACK*/
	
	system("clear");
	printf("\nWelcome to 'The Best Chess Game Ever!'\n\n");
  
	do
	{
		do
		{
			Challenger(); /*Challenger Menu */
			scanf("%s", trash);

			if (isdigit(trash[0]))
				challengerOption = atoi(trash);
				
			if (challengerOption == 1) 
				CPUFLAG = 0;
			else 
				CPUFLAG = 1;
			
			if (challengerOption != 1 && challengerOption != 2)
				printf("Invalid Input!\n");

			printf("\n");

		} while (challengerOption != 1 && challengerOption != 2);
	
		do
		{
			Color(); /* Color Option Menu */
			scanf("%s", trash);
			
			if (isdigit(trash[0]))
				colorOption = atoi(trash);

			if (colorOption == 1) 
			{	player = 1;   /* White Piece */
				CPU = 2;
			}
			else 
			{
				player = 2;   /*Black Piece */
				CPU = 1;
			}
			if (colorOption != 1 && colorOption != 2)
				printf("Invalid Input!\n");

			printf("\n");

		} while (colorOption != 1 && colorOption != 2);
	
		system("clear");

		/* Displays Selections */
		printf("\n****************** Selections ******************\n");
		if (challengerOption == 1)
			printf("Player vs Player\n");
		else if (challengerOption == 2)
			printf("Player vs CPU\n");
		if (colorOption == 1 && challengerOption == 1) {
			printf("Player 1: White Piece (Upper Case)\n");
			printf("Player 2: Black Piece (Lower Case)\n");
		}
		else if (colorOption == 2 && challengerOption == 1) {
                        printf("Player 1: Black Piece (Lower Case)\n");
                        printf("Player 2: White Piece (Upper Case)\n");
                }
		if (colorOption == 1 && challengerOption == 2) {
                        printf("Player 1: White Piece (Upper Case)\n");
                        printf("CPU: Black Piece (Lower Case)\n");
                }
                else if (colorOption == 2 && challengerOption == 2) {
                        printf("Player 1: Black Piece (Lower Case)\n");
                        printf("CPU: White Piece (Upper Case)\n");
                }
		printf("************************************************\n\n");

		printf("Would you like to begin the game? (Y/N) ");
    		scanf("%s", &startgame);
	
		printf("\n");
		
		if (startgame != 'Y' && startgame != 'y')
			system("clear");
		
	} while (startgame != 'Y' && startgame != 'y');
	
	file = fopen("./bin/ChessHistory.txt", "w"); /* Makes txt file */	
	
	system("clear");
	help(); /* Displays the rules of the game */
	definitions();
	round = 1;

	// CPU First movement if CPU is White
	if (CPUFLAG == 1 && colorOption == 2)
	{
		displayboard(board);
		board[6][3] = ' '; //move pawn at D2 to D4
		board[4][3] = 'P';
		AI_roundFLAG = 1;
		printf("           ~ Round 1 ~\n");

		printf("************ AI Move ************\n");
		printf("Current Position: D2\n");
		printf("New Position: D4\n");
		
	}

	displayboard(board); /* Displays the current Board in play */
	/*end of initial set up*/
	
	do
	{			
		if (repeat == 1)
		{
			printf("         ~ Round %d ~\n", round);

			if (CPUFLAG == 0) 
			{
				if (PlayerNum == 1) 
					printf("            White \n");
				else if (PlayerNum == 2) 
					printf("            Black \n");
			}
			else 
			{
				if (player == 1)
					printf("            White \n");
				else
					printf("            Black \n");
			}

			PrintMenu(); //Displays menu options for the game
		}
		
		fgets(trash, 10, stdin);
	
		if (isdigit(trash[0]) && strlen(trash) == 2)
			selection = atoi(trash);
		else
			selection = 0;

		switch (selection)
		{
			case 1: // Make Movement
                                        
				//check for a draw/stalemate in PVP
				if(CPUFLAG == 0){
					if(check_draw(board, positions, PlayerNum) == 1){
						printf("There is a stalemate! The game will end in a draw.\n");
						exit(0);
					}
				}
				//check for draw/stalemate in CPUvP
				else if(CPUFLAG == 1){
					if(check_draw(board, positions, player) == 1){
						printf("There is a stalemate! The game will end in a draw.\n");
						exit(0);
					}
				}
				
				//make a move
				printf("Make your move (example format: A2 to A4): ");
			
				//get the user input
		 		fgets(movement, large, stdin);
				
				
				if((strlen(movement) - 1) > 8){
					printf("Incorrent Format! Please try again\n");
					displayboard(board);
					break;
				}
				/* Checks for valid input for MOVEMENT STRING */
				else if ((strlen(movement) - 1) != 8 || movement[2] != ' ' || movement[3] != 't' || movement[4] != 'o' ||
				    movement[5] != ' ')
				{
					
					printf("Incorrect Format! Please try again\n");
					displayboard(board);
					break;
				}
				else if ((movement[0] < 'A' || movement[0] > 'H') || (movement[1] < '1' || movement[1] > '8') ||
					 (movement[6] < 'A' || movement[6] > 'H') || (movement[7] < '1' || movement[7] > '8'))
				{
					//getchar();
					printf("Incorrect Format! Please try again\n");
                    			displayboard(board);
                    			break;
				}
				
				
				//parse the string
				sscanf(movement, "%s to %s\n\n", current_position, new_position);
			
				/* Sets temp values for pieces incase of undo */
        			for(int i = 0; i<8; i++)
        			{
                			for(int j = 0; j<8; j++)
                			{
                        			if (!strcmp(new_position, positions[i][j]))
                        			{
                            				temp1 = board[i][j];
                        			}

						if (!strcmp(current_position, positions[i][j]))
                        			{
                            				temp2 = board[i][j];
                            			}
                			}
        			}

				//check to make sure players are only moving their pieces
				if ((PlayerNum == 1 && CPUFLAG == 0) || (CPUFLAG == 1 && player == 1)) {
					for(int c = 0; c<8; c++){
						for(int d = 0; d<8; d++){
							color = strcmp(current_position, positions[c][d]);
							if(color == 0){
								color_checkx = c;
								color_checky = d;
							}
						}
					}
					white_piece = board[color_checkx][color_checky];
					if (white_piece != 'P' &&  white_piece != 'R' && white_piece != 'Q' && white_piece != 'K' &&  
					    white_piece != 'B' && white_piece != 'N' && white_piece != ' '){
						printf("Invalid move! You cannot move opponents pieces!\n");
						displayboard(board);
						break;
					}
				}
			
				if ((PlayerNum == 2 && CPUFLAG == 0) || (CPUFLAG == 1 && player == 2)) { //meaning colorOption is 2 so the player is black
					for(int c = 0; c<8; c++){
						for(int d = 0; d<8; d++){
							color = strcmp(current_position, positions[c][d]);
							if(color == 0){
								color_checkx = c;
								color_checky = d;
							}
						}
					}
					black_piece = board[color_checkx][color_checky];
					if (black_piece != 'p' && black_piece != 'r' && black_piece != 'q' && black_piece != 'k' && 
					    black_piece != 'b' && black_piece != 'n' && black_piece != ' '){
						printf("Invalid move! You cannot move opponents' pieces!\n");
						displayboard(board);
						break;
					}
					
				}

			
				
				//check if a player ignores check condition		
				if(CPUFLAG == 0)
				{		
					if(checkFLAG == 1)
					{
						if(ignore_check(board, positions, current_position, new_position, PlayerNum) == 1)
						{
							legalFLAG = 1;
						}
						else
						{
							legalFLAG = CheckPiece(positions, board, current_position, new_position);
							if (legalFLAG == 1)
							{
								if(PlayerNum == 1)
								{
									legalFLAG = BlackEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
								}
								else if(PlayerNum == 2)
								{
									legalFLAG = WhiteEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
								}
							}
																		
						}
						
					}
					//Check if the moves valid 
					else
					{
						//legalFLAG is equal to the ifLegal flag returned from CheckPiece
						legalFLAG = CheckPiece(positions, board, current_position, new_position);
						if (legalFLAG == 1)
						{
							if(PlayerNum == 1)
							{
								legalFLAG = BlackEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
							}
							else if(PlayerNum == 2)
							{
								legalFLAG = WhiteEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
							}
						}
					}
				}
				
				else if(CPUFLAG == 1)
				{		
					if(AI_checkFLAG == 1)
					{
						if(ignore_check(board, positions, current_position, new_position, player) == 1)
						{
							legalFLAG = 1;
						}
						else
						{
							legalFLAG = CheckPiece(positions, board, current_position, new_position);
							if (legalFLAG == 1)
							{
								if(player == 1)
								{
									legalFLAG = BlackEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
								}
								else if(player == 2)
								{
									legalFLAG = WhiteEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
								}
							}
																		
						}
						
					}
					//Check if the moves valid 
					else
					{
						//legalFLAG is equal to the ifLegal flag returned from CheckPiece
						legalFLAG = CheckPiece(positions, board, current_position, new_position);
						if (legalFLAG == 1)
						{
							if(player == 1)
							{
								legalFLAG = BlackEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
							}
							else if(player == 2)
							{
								legalFLAG = WhiteEnpassant(opponentNP, opponentCP, opponentPiece, new_position, current_position, temp2, board, positions);
							}
						}
					}
				}
				//see if the king is trying to place himself in checkmate
				if(CPUFLAG == 0){
					suicide_king = restrict_king(board, positions, PlayerNum, current_position, new_position);
				}
				else if(CPUFLAG == 1){
					suicide_king = restrict_king(board, positions, player, current_position, new_position);
				}
				//changing position to a piece
				check_capture = position_to_piece(board, positions, new_position);
				//update the board only when it is legal
				//0 for legal and 1 for illegal
				if(legalFLAG == 0)
				{
					if(suicide_king == 1){
						printf("King cannot sacrifice itself! Please try again.\n");
						displayboard(board);
						break;
					}
					printf("Legal move!\n");
					if(check_capture != ' '){
				
						printf("An enemy piece has been captured!\n");
					}
					updateboard(current_position, new_position, board, positions);
					
					//move the rook for player castling
					if(strcmp(current_position, "E1") == 0 &&  strcmp(new_position, "G1") == 0)
					{
						updateboard("H1", "F1", board, positions);
						CASTLINGFLAG = 1;
					}
					else if(strcmp(current_position, "E1") == 0 && strcmp(new_position, "C1") == 0)
					{
						updateboard("A1", "D1", board, positions);
						CASTLINGFLAG = 2;
					}
					else if(strcmp(current_position, "E8") == 0 && strcmp(new_position, "G8") == 0)
					{
						updateboard("H8", "F8", board, positions);
						CASTLINGFLAG = 3;
					}
					else if(strcmp(current_position, "E8") == 0 && strcmp(new_position, "C8") == 0)
					{
						updateboard("A8", "D8", board, positions);
						CASTLINGFLAG = 4;
					}
          
					/* White Pawn Promotion */
					for (y = 0; y < 8; y++)
					{
  						if (new_position[1] == '8' && board[0][y] == 'P')
						{
                      					PromotionWhite(board, y);
                 				}
					}

	  				/* Black Pawn Promotion */
          				for (y = 0; y < 8; y++)
          				{
              					if (new_position[1] == '1' && board[7][y] == 'p')
                  				{
                      					PromotionBlack(board, y);
                  				}
              				
          				}
				
        				displayboard(board);

				}

				else if(legalFLAG == 1) /*ifLegal is 1*/
				{	
					printf("Illegal move! Please try again\n");
					displayboard(board);
					break;
				}
				else if(legalFLAG == 2) //ifLegal is 2
				{
					printf("Invalid input! Please try again\n");
					displayboard(board);
					break;
				}
						
				if (CPUFLAG == 1)
				{	
					/* Allows undo only once per round*/
					if (undoFLAG == 0)
					{
						/* Undo Move option */
          					printf("Would you like to undo this move before moving to the next round? (Y/N) ");		
						scanf("%c", &undo);
						getchar();
						
						if (undo == 'y' || undo == 'Y') {
							undoFLAG = 1;
							/* Places temp values to previous spots */
                                			for(int i = 0; i<8; i++)
                                			{
                                        			for(int j = 0; j<8; j++)
                                        			{
                                                			if (!strcmp(new_position, positions[i][j]))
                                                			{
                                                        			board[i][j] = temp1;
                                                			}
                                                			if (!strcmp(current_position, positions[i][j]))
                                                			{
                                                        			board[i][j] = temp2;
                                                			}
                                        			}
                                			}
							if (CASTLINGFLAG == 1)
								updateboard("F1", "H1", board, positions);
							else if (CASTLINGFLAG == 2)
								updateboard("D1", "A1", board, positions);
							else if (CASTLINGFLAG == 3)
								updateboard("F8", "H8", board, positions);
							else if (CASTLINGFLAG == 4)
								updateboard("D8", "A8", board, positions);

							displayboard(board);
							selection = 1;
							break;
						}
						else
						{
							;
						}
					}
				}

				//Check if kings and rooks have moved for castling
				if(board[7][4] == ' ')
				{
					WhiteKing = 1;
				}
				if(board[7][0] == ' ')
				{
					WRook1 = 1;
				}
				if(board[7][7] == ' ')
				{
					WRook2 = 1;
				}
				if(board[0][4] == ' ')
				{
					BlackKing = 1;
				}
				if(board[0][0] == ' ')
				{
					BRook1 = 1;
				}
				if(board[0][7] == ' ')
				{
					BRook2 = 1;
				}

				//check if opponent's king is in check after a move and set the checkFLAG
				if(!CPUFLAG)
				{
				checkFLAG = ifCheck(board, positions, PlayerNum);
				checkmateFLAG = isCheckmate(board, positions, PlayerNum);
				}
				else if(CPUFLAG)
				{
				checkFLAG = ifCheck(board, positions, player);
				checkmateFLAG = isCheckmate(board, positions, player);
				}
				//tell player if they are in check
				if(checkFLAG == 1 && checkmateFLAG == 0)
				{
					printf("\nCheck!\n");
				}
				
        
				if (CPUFLAG == 1) //CPU v Player
				{
					//check if CPU is checkmated
					if(checkmateFLAG)
					{
						printf("\nCheckmate!\n");
						printf("You win!!!\n\n");
						fputs("Checkmate!\nThe player wins!\n", file);
						exit(0);
					}
					//check if CPU has a stalemate
					if(check_draw(board, positions, CPU) == 1){
						printf("There is a stalemate! The game will end in a draw.\n");
						exit(0);
					}
					/* CPU Pawn Promotion */
                			for (y = 0; y < 8; y++)
                    			{
                        			/* White Pawn Promotion */
                        			if (AI_new_position[1] == '8' && board[0][y] == 'P' && player == 2 && CPUFLAG == 1)
                        			{
                            				AIPromotionWhite(board, y);
                        			}

						/* Black Pawn Promotion */
                        			if (AI_new_position[1] == '1' && board[7][y] == 'p' && player == 1 && CPUFLAG == 1)
                        			{
                            				AIPromotionBlack(board, y);
                        			}
                    			}//end of for loop
	
					//print AI rounds
					if(AI_roundFLAG == 1){
						printf("\n           ~ Round %d ~", AI_round);
						AI_round++;
					}
					else{
						printf("\n           ~ Round %d ~", round);
					}

					if(round == 1 && CPU == 2)
					{	
						//move pawn to E6 to counter premade moves
						printf("\n************ AI Move ************\n");
						printf("Current Position: E7\n");
						printf("New Position: E6\n");
						strcpy(AI_cur_position, "E7");
						strcpy(AI_new_position, "E6");
						
					}
					else
					{
						AI_3(positions, board, player, AI_cur_position, AI_new_position);
					}
					
					//AI_1(positions, board, player, AI_cur_position, AI_new_position);

					//update the board with AI move
                    updateboard(AI_cur_position, AI_new_position, board, positions);
					
					//For AI castling:
					if(strcmp(AI_cur_position, "E1") == 0 &&  strcmp(AI_new_position, "G1") == 0)
					{
						updateboard("H1", "F1", board, positions);
					}
					else if(strcmp(AI_cur_position, "E1") == 0 && strcmp(AI_new_position, "C1") == 0)
					{
						updateboard("A1", "D1", board, positions);
					}
					else if(strcmp(AI_cur_position, "E8") == 0 && strcmp(AI_new_position, "G8") == 0)
					{
						updateboard("H8", "F8", board, positions);
					}
					else if(strcmp(AI_cur_position, "E8") == 0 && strcmp(AI_new_position, "C8") == 0)
					{
						updateboard("A8", "D8", board, positions);
					}
					displayboard(board);
					
					//check if opponent's king is in check after a move and set the checkFLAG
					AI_checkFLAG = ifCheck(board, positions, CPU);
					AI_checkmateFLAG = isCheckmate(board, positions, CPU);
				
					if(AI_checkFLAG == 1 && AI_checkmateFLAG == 0)
					{
						printf("Check!\n");
				
					}
					
					/* AI_movement string */
                    			strcpy(AI_movement, AI_cur_position);
					strcat(AI_movement, " to ");  
					strcat(AI_movement, AI_new_position);
					
					//add moves to the log file
					if (player == 1)
					{
						fputs("***** Round ", file);
						fprintf(file, "%d *****\n\n", round);
						fputs("(Player 1) White: ", file);
						fputs(movement, file);
						fputs("\n", file);
						fputs("(CPU) Black: ", file);
						fputs(AI_movement, file);
						fputs("\n\n\n", file);
						undoFLAG = 0;
					}
					else
					{
						fputs("***** Round ", file);
						fprintf(file, "%d *****\n\n", round);
						if (CPUTrash == 0) //if the CPU is the white player
						{
							fputs("(CPU) White: A2 to A4", file);
							CPUTrash = 1;
						}
						else
						{
							fputs("(CPU) White: ", file);
							fputs(AI_movement, file);
						}
						fputs("\n", file);
						fputs("(Player 1) Black: ", file);
						fputs(movement, file);
						fputs("\n\n\n", file);
					}
						
					if (undoFLAG == 1)
						undoFLAG = 0;
					
					round++;	
				}

				else // Player vs Player 
				{
					if (PlayerNum == 1)
					{
						fputs("***** Round ", file);
						fprintf(file, "%d *****\n\n", round);
						fputs("White: ", file);
						fputs(movement, file);
						fputs("\n", file);
						PlayerNum++;       
                    			}
					
					else if (PlayerNum == 2)
					{
						/* New movement for Black Piece */
						fputs("Black: ", file);
						fputs(movement, file);
						fputs("\n\n\n", file);
						round++;
						PlayerNum = 1;	
					}
				}
				// Opponents piece 
				if (CPUFLAG == 0)
				{
					strcpy(opponentNP, new_position);
                			strcpy(opponentCP, current_position);
				}
				else if (CPUFLAG == 1)
				{
					strcpy(opponentNP, AI_new_position);
                                        strcpy(opponentCP, AI_cur_position);
				}
				for (int c = 0; c<8; c++){
                                	for (int d = 0; d<8; d++){
                                        	if (!strcmp(opponentNP, positions[c][d]))
                                                {
                                                        xx = c;
                                                	yy = d;
                                                }
                                        }
                                }

                                opponentPiece = board[xx][yy];

                                strcpy(current_position, "");
                                strcpy(new_position, "");
                                strcpy(movement, "");


				//checkmate code:
				//PlayerNum is alreay swapped at this point
				
				if(CPUFLAG == 0)
				{
					if(checkmateFLAG == 1 && PlayerNum == 2)
					{
						printf("Checkmate!\n");
						printf("White wins!\n\n");
						fputs("Checkmate!\nWhite wins!\n\n", file);
						exit(0);
					}
					else if(checkmateFLAG == 1 && PlayerNum == 1)
					{
						printf("Checkmate!\n");
						printf("Black wins!\n\n");
						fputs("Checkmate!\nBlack wins!\n\n", file);
						exit(0);
					}
				}
				else if(CPUFLAG == 1)
				{
					if(AI_checkmateFLAG == 1)
					{
						printf("Checkmate!\n");
						printf("CPU wins!\n\n");
						fputs("Checkmate!\nCPU wins!\n\n", file);
						exit(0);
					}
				}
				
			
				break;
         
			case 2: // Help
				printf("\n");
				help();
				definitions();
				displayboard(board);
				break;

			case 3:
				break;

			default:
				if (repeat == 1)
				{
					printf("Invalid Selection\n\n");
					displayboard(board);
				}		
				break;
		}
	
		repeat = 1;
	
	} while (selection != 3);

        fclose(file);
	
	
	return 0;
}
