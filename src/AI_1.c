#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "Checkmate.h"
#include "AI_1.h"
#include "CheckMove.h"
#include "Board.h"
/*
'P' = 1
'R' = 2
'N' = 3
'B' = 4
'Q' = 5
'K' = 6
'p' = 7
'r' = 8
'n' = 9
'b' = 10
'q' = 11
'k' = 12
*/

void AI_1(const char positions[8][8][3], char board[8][8], int piece_color, char *AI_cur_position, char *AI_new_position) {
  int p_numW, p_numB, piece_count, position_index;
  int count = 1;
  int max, min;
  int length = 0;
  int P_count, R_count, N_count, B_count, Q_count; // White Chess piece counts
  int p_count, r_count, n_count, b_count, q_count; // Black Chess piece counts
  time_t t;
  char** moves;
  char p_position[3] = "";
  
  P_count = R_count = N_count = B_count = Q_count = p_count = r_count = n_count = b_count = q_count = 0;
  
  for(int x = 0; x < 8; x++)
 	{
		  for(int y = 0; y < 8; y++)
		  {
           if (board[x][y] == 'P')
           {
               P_count++;
           }
           
           else if (board[x][y] == 'R')
           {
               R_count++;
           }
           
           else if (board[x][y] == 'N')
           {
               N_count++;
           }
           
           else if (board[x][y] == 'B')
           {
               B_count++;
           }
           
           else if (board[x][y] == 'Q')
           {
               Q_count++;
           }
           
           else if (board[x][y] == 'p')
           {
               p_count++;
           }
           
           else if (board[x][y] == 'r')
           {
               r_count++;
           }
           
           else if (board[x][y] == 'n')
           {
               n_count++;
           }
           
           else if (board[x][y] == 'b')
           {
               b_count++;
           }
           
           else if (board[x][y] == 'q')
           {
               q_count++;
           } 
      }
  }
  
  // if player decides to be white pieces, CPU moves black piece 
  if (piece_color == 1) {  
      while (length == 0)
      {
          count = 1;
          // generate value between 7-12 for black pieces
          max = 12;
          min = 7;
          srand((unsigned) time(&t));
          p_numB = rand() % (max + 1 - min) + min;
          if (p_numB == 7) // black pawn
          {
              if(p_count != 0)
              {
              // generate value to randomly select black pawn piece on board
              max = p_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'p')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numB == 8) // black rook
          {
              if(r_count != 0)
              {
              // generate value to randomly select black rook piece on board
              max = r_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'r')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numB == 9) // black knight
          {
              if(n_count != 0)
              {
              // generate value to randomly select black knight piece on board
              max = n_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'n')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numB == 10) // black bishop
          {
              if(b_count != 0)
              {
              // generate value to randomly select black bishop piece on board
              max = b_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'b')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numB == 11) // black queen
          {   
              if(q_count != 0)
              {
              // generate value to randomly select black queen piece on board
              max = q_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'q')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numB == 12) // black king
          {
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'k')
                      {
                          strcpy(p_position, positions[x][y]);
                          break;
                      }
                  }
              }
          }

          length = getLength2(board, positions, p_position);
      }
      printf("\n************ AI Move ************");
      printf("\nCurrent Position: %s", p_position);
      moves = get_all_legal_moves(board, positions, p_position, length);
      //printf("Moves Available:");
      //for (i = 0; i < length; i++)
      //{
      //    printf(" %s", moves[i]);
      //}
      printf("\n");
      // generate value between 1-length to pick random new position
      max = length;
      min = 1;
      srand((unsigned) time(&t));
      position_index = rand() % (max + 1 - min) + min;
      strcpy(AI_cur_position, p_position);
      strcpy(AI_new_position, moves[position_index-1]);
      printf("New Position: ");
      puts(AI_new_position);
      free_all_moves(moves, length);  
  }
          
          
  // if player decides to be black pieces, CPU moves white piece 
  else if (piece_color == 2) {
      while (length == 0)
      {
          count = 1;
          // generate value between 1-6 for white pieces
          max = 6;
          min = 1;
          srand((unsigned) time(&t));
          p_numW = rand() % (max + 1 - min) + min;
          if (p_numW == 1) // white pawn
          {
              if(P_count != 0)
              {
              // generate value to randomly select white pawn piece on board
              max = P_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'P')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numW == 2) // white rook
          {
              if(R_count != 0)
              {
              // generate value to randomly select white rook piece on board
              max = R_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'R')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numW == 3) // white knight
          {
              if(N_count != 0)
              {
              // generate value to randomly select white knight piece on board
              max = N_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'N')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numW == 4) // white bishop
          {
              if(B_count != 0)
              {
              // generate value to randomly select white bishop piece on board
              max = B_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'B')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numW == 5) // white queen
          {
              if(Q_count != 0)
              {
              // generate value to randomly select white queen piece on board
              max = Q_count;
              min = 1;
              srand((unsigned) time(&t));
              piece_count = rand() % (max + 1 - min) + min;
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'Q')
                      {
                          if (count == piece_count)
                          {
                              strcpy(p_position, positions[x][y]);
                              count++;
                              break;
                          }
                          count++;
                      }
                  }
              }
              }
          }
          
          if (p_numW == 6) // white king
          {
              for(int x = 0; x < 8; x++)
            	{
              		for(int y = 0; y < 8; y++)
              		{
                      if (board[x][y] == 'K')
                      {
                          strcpy(p_position, positions[x][y]);
                          break;
                      }
                  }
              }
          }
          length = getLength2(board, positions, p_position);
      }
      printf("\n************ AI Move ************");
      printf("\nCurrent Position: %s", p_position);
      moves = get_all_legal_moves(board, positions, p_position, length);
      //printf("Moves Available:");
      //for (i = 0; i < length; i++)
      //{
      //    printf(" %s", moves[i]);
      //}
      printf("\n");
      // generate value between 1-length to pick random new position
      max = length;
      min = 1;
      srand((unsigned) time(&t));
      position_index = rand() % (max + 1 - min) + min;
      strcpy(AI_cur_position, p_position);
      strcpy(AI_new_position, moves[position_index-1]);
      printf("New Position: ");
      puts(AI_new_position);
      free_all_moves(moves, length);  
  }
}

void AIPromotionBlack(char board[8][8], int x)
{
    printf("CPU's pawn has reached the other end!\n");
    printf("Pawn has been promoted to queen\n");
    board[7][x] = ' ';
    board[7][x] = 'q';
}

void AIPromotionWhite(char board[8][8], int x)
{
    printf("CPU's pawn has reached the other end!\n");
    printf("Pawn has been promoted to queen\n");
    board[0][x] = ' ';
    board[0][x] = 'Q';

}

void AI_3(const char positions[8][8][3], char board[8][8], int piece_color, char *AI_cur_position, char *AI_new_position) {

  //int max, min;
  int length = 0;
  time_t t;
  int random_move, capture_move_num;
  char cur_p[3];
  char new_p[3];
  char bestmove[5];
  char** moves;
  int points = 0;
  int max = 0;

  
  
  // if player decides to be white pieces, CPU moves black piece 
  if (piece_color == 1) {  
     
      length = getLength_black(board, positions);
      moves = get_all_legal_moves_black(board, positions, length);
     
      capture_move_num = 0;
      max = -100000;
      
      for(int x = 0; x < length; x++)
      {
          sscanf(moves[x], "%2s%2s", cur_p, new_p);
          points = Test_move(board, positions, cur_p, new_p, 2);
          if(points > max)
          {
              max = points;
              strcpy(bestmove, moves[x]);
          }
      }
      for(int x = 0; x < length; x++)
      {
          sscanf(moves[x], "%2s%2s", cur_p, new_p);
          points = Test_move(board, positions, cur_p, new_p, 2);
          if(points == max)
          {
              capture_move_num++;
          }
 
      }
     // printf("capture move num is %d\n", capture_move_num);
      
      if(capture_move_num <= 1)
      {
        random_move = 0;
      }
      else
      {
        srand((unsigned) time(&t));
        random_move = rand() % capture_move_num;
      }
      //printf("random number is %d\n", random_move);
      int count = 0;
      if(capture_move_num != 0)
      {
          for(int x = 0; x < length; x++)
          {
            sscanf(moves[x], "%2s%2s", cur_p, new_p);
            points = Test_move(board, positions, cur_p, new_p, 2);
            //printf("%s point is %d\n", moves[x], points);
            if(points == max)
            {
                if(count == random_move)
                {
                    strcpy(AI_cur_position, cur_p);
                    strcpy(AI_new_position, new_p);
                }
                count++;
            }
         }
      }
      printf("\n************ AI Move ************");
      printf("\nCurrent Position: %s", AI_cur_position);
      printf("\n");
      printf("New Position: ");
      puts(AI_new_position);
      free_all_moves(moves, length);  
  }
          
          
          
          
                
          
  // if player decides to be black pieces, CPU moves white piece 
  else if (piece_color == 2) {
     
        length = getLength_white(board, positions);
        moves = get_all_legal_moves_white(board, positions, length);
     capture_move_num = 0;
      max = -100000;
      
      for(int x = 0; x < length; x++)
      {
          sscanf(moves[x], "%2s%2s", cur_p, new_p);
          points = Test_move(board, positions, cur_p, new_p, 1);
          if(points > max)
          {
              max = points;
              strcpy(bestmove, moves[x]);
          }
      }
      for(int x = 0; x < length; x++)
      {
          sscanf(moves[x], "%2s%2s", cur_p, new_p);
          points = Test_move(board, positions, cur_p, new_p, 1);
          if(points == max)
          {
              capture_move_num++;
          }
 
      }
     // printf("capture move num is %d\n", capture_move_num);
      
      if(capture_move_num <= 1)
      {
        random_move = 0;
      }
      else
      {
        srand((unsigned) time(&t));
        random_move = rand() % capture_move_num;
      }
      //printf("random number is %d\n", random_move);
      int count2 = 0;
      if(capture_move_num != 0)
      {
          for(int x = 0; x < length; x++)
          {
            sscanf(moves[x], "%2s%2s", cur_p, new_p);
            points = Test_move(board, positions, cur_p, new_p, 1);
            //printf("%s point is %d\n", moves[x], points);
            if(points == max)
            {
                if(count2 == random_move)
                {
                    strcpy(AI_cur_position, cur_p);
                    strcpy(AI_new_position, new_p);
                }
                count2++;
            }
         }
      }
      printf("\n************ AI Move ************");
      printf("\nCurrent Position: %s", AI_cur_position);
      printf("\n");
      printf("New Position: ");
      puts(AI_new_position);
      free_all_moves(moves, length);  
  }
}

int is_capture_safe(char board[8][8], const char positions[8][8][3], char location[3], int color)
{
    char board_copy[8][8];
    char opponent[16][3];
    int index_x, index_y;
    int new_x = 0;
	int new_y = 0;
    int xx, yy;
    
    for(int x = 0; x < 8; x++)
                        {
                            for(int y = 0; y < 8; y++)
                            {
                                if(strcmp(location, positions[x][y]) == 0)
                                {
                                    xx = x;
                                    yy = y;
                                }
                            }
                        }
    
    //make a copy of the board
        for(int a = 0; a < 8; a++)
        {
            for(int b = 0; b < 8; b++)
            {
                board_copy[a][b] = board[a][b];
            }
        }
    
    board_copy[xx][yy] = ' ';
    if(color == 1)
    {
        
        opponent_positions(board_copy, positions, opponent, color);
        for(int i = 0; i < 16; i++)
        {
            if(strcmp(opponent[i], "") != 0)//make sure it is not empty
            {

                    //in case it is pawn
                    if(position_to_piece(board_copy, positions, opponent[i]) == 'P')
                    {

                        for(int x = 0; x < 8; x++)
                        {
                            for(int y = 0; y < 8; y++)
                            {
                                if(strcmp(opponent[i], positions[x][y]) == 0)
                                {
                                    index_x = x;
                                    index_y = y;
                                }
                            }
                        }
                        for(int x = 0; x < 8; x++)
                        {
                            for(int y = 0; y < 8; y++)
                            {
                                if(strcmp(location, positions[x][y]) == 0)
                                {
                                    new_x = x;
                                    new_y = y;
                                }
                            }
                        }
                        if((new_x == index_x - 1 && new_y == index_y + 1) || (new_x == index_x - 1 && new_y == index_y - 1))
                        {
                            return 1;
                        }
                    }
                    else if(CheckPiece(positions, board_copy, opponent[i], location) == 0)
                    {
                    return 1;
                    }
            }
        }
    }
    
    else if(color == 2)
    {
        opponent_positions(board_copy, positions, opponent, color);
        for(int i = 0; i < 16; i++)
        {
            if(strcmp(opponent[i], "") != 0)//make sure it is not empty
            {
                    if(position_to_piece(board_copy, positions, opponent[i]) == 'p')
                    {

                        for(int x = 0; x < 8; x++)
                        {
                            for(int y = 0; y < 8; y++)
                            {
                                if(strcmp(opponent[i], positions[x][y]) == 0)
                                {
                                    index_x = x;
                                    index_y = y;
                                }
                            }
                        }
                        for(int x = 0; x < 8; x++)
                        {
                            for(int y = 0; y < 8; y++)
                            {
                                if(strcmp(location, positions[x][y]) == 0)
                                {
                                    new_x = x;
                                    new_y = y;
                                }
                            }
                        }
                        if((new_x == index_x + 1 && new_y == index_y + 1) || (new_x == index_x + 1 && new_y == index_y - 1)) 
                        {
                            return 1;
                        }
                    }
                    else if(CheckPiece(positions, board_copy, opponent[i], location) == 0)
                    {
                        return 1;
                    }
                
            }
        }
    }
   
    
    return 0;

}

//made for AI
int getLength_white(char board[8][8], const char positions[8][8][3])
{   
    char piece_positions[16][3];
    char piece;
    //int checkFLAG_black = ifCheck(board, positions, 1);
    //int checkFLAG_white = ifCheck(board, positions, 2);
    //list all the positions on the board
    char coordinates[8][8][3] = 	{
								{"A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8"},
								{"A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7"},
								{"A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6"},
								{"A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5"},
								{"A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4"},
								{"A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3"},
								{"A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2"},
								{"A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"},
						   		};
    int length = 0;
    opponent_positions(board, positions, piece_positions, 1);
    for(int i = 0; i < 16; i++)
    {
        if(strcmp(piece_positions[i], "") != 0)//make sure it is not empty
        {
            piece = position_to_piece(board, positions, piece_positions[i]);
            //get the length of the array
            for(int x = 0; x < 8; x++)
            {
                for(int y = 0; y < 8; y++)
                {
                    if(CheckPiece(positions, board, piece_positions[i], coordinates[x][y]) == 0)//or 3 
                    {   
                        /*
                        if(checkFLAG_white) //make sure AI does not ignore check
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 1) == 0)
                            {
                                length++;
                            }
                        }
                        else if(checkFLAG_black)
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 2) == 0)
                            {
                                length++;
                            }
                        }    
                        else if(piece == 'K') //make sure king does not move to attacked spots
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 2) == 0)
                            {
                                length++;
                            }
                        }
                        else if(piece == 'k')
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 1) == 0)
                            {
                                length++;
                            }
                        }
                        else
                        {
                            length++;
                        }
                        */
                       if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 1) == 0)
                            {
                                length++;
                            }
                    }
                }
            }
        }
    }
    return length;
}

//made for AI
char** get_all_legal_moves_white(char board[8][8], const char positions[8][8][3], int length)
{

    char piece_positions[16][3];
    char piece;
   // int checkFLAG_black = ifCheck(board, positions, 1);
   // int checkFLAG_white = ifCheck(board, positions, 2);
    //list all the positions on the board
    char coordinates[8][8][3] = 	{
								{"A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8"},
								{"A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7"},
								{"A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6"},
								{"A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5"},
								{"A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4"},
								{"A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3"},
								{"A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2"},
								{"A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"},
						   		};
    
    int index = 0;
    //make an dynamic string array to store the positions of all possible moves
    char** all_moves = malloc(length * sizeof(char*));
    if (!all_moves)
    {
        perror("Out of memory! Aborting...");
        exit(0);
    }
    for(int i = 0; i < length; i++)
    {
        all_moves[i] = malloc(sizeof(char) * 5);
        if (!all_moves[i])
        {
            perror("Out of memory! Aborting...");
            exit(0);
        }
    }
    
    opponent_positions(board, positions, piece_positions, 1);
    for(int i = 0; i < 16; i++)
    {
        if(strcmp(piece_positions[i], "") != 0)//make sure it is not empty
        {
            piece = position_to_piece(board, positions, piece_positions[i]);
            for(int x = 0; x < 8; x++)
            {
                for(int y = 0; y < 8; y++)
                {
                    if(CheckPiece(positions, board, piece_positions[i], coordinates[x][y]) == 0)//or 3 
                    {
/*
                        if(checkFLAG_white) //make sure AI does not ignore check
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 1) == 0)
                            {   
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }
                        else if(checkFLAG_black)
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 2) == 0)
                            {
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }    
                        else if(piece == 'K') //make sure king does not move to attacked spots
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 2) == 0)
                            {
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }
                        else if(piece == 'k')
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 1) == 0)
                            {
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }
                        else
                        {
                            char string[3];
                            strcpy(string, piece_positions[i]);
                            strcat(string, coordinates[x][y]);
                            strcpy(all_moves[index], string);
                            index++;
                        }*/
                         if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 1) == 0)
                            {   
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        //save all ilegal positions a piece can move to into the all_moves array

                    }
                }
            }
        }
    }

    return all_moves;
}

//made for AI
int getLength_black(char board[8][8], const char positions[8][8][3])
{   
    char piece_positions[16][3];
    char piece;
    //int checkFLAG_black = ifCheck(board, positions, 1);
    //int checkFLAG_white = ifCheck(board, positions, 2);
    //list all the positions on the board
    char coordinates[8][8][3] = 	{
								{"A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8"},
								{"A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7"},
								{"A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6"},
								{"A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5"},
								{"A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4"},
								{"A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3"},
								{"A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2"},
								{"A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"},
						   		};
    int length = 0;
    opponent_positions(board, positions, piece_positions, 2);
    for(int i = 0; i < 16; i++)
    {
        if(strcmp(piece_positions[i], "") != 0)//make sure it is not empty
        {
            piece = position_to_piece(board, positions, piece_positions[i]);
            //get the length of the array
            for(int x = 0; x < 8; x++)
            {
                for(int y = 0; y < 8; y++)
                {
                    if(CheckPiece(positions, board, piece_positions[i], coordinates[x][y]) == 0)//or 3 
                    {   
                        /*
                        if(checkFLAG_white) //make sure AI does not ignore check
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 1) == 0)
                            {
                                length++;
                            }
                        }
                        else if(checkFLAG_black)
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 2) == 0)
                            {
                                length++;
                            }
                        }    
                        else if(piece == 'K') //make sure king does not move to attacked spots
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 2) == 0)
                            {
                                length++;
                            }
                        }
                        else if(piece == 'k')
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 1) == 0)
                            {
                                length++;
                            }
                        }
                        else
                        {
                            length++;
                        }
                        */
                       if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 2) == 0)
                            {
                                length++;
                            }
                    }
                }
            }
        }
    }
    return length;
}

//made for AI
char** get_all_legal_moves_black(char board[8][8], const char positions[8][8][3], int length)
{

    char piece_positions[16][3];
    char piece;
    //int checkFLAG_black = ifCheck(board, positions, 1);
    //int checkFLAG_white = ifCheck(board, positions, 2);
    //list all the positions on the board
    char coordinates[8][8][3] = 	{
								{"A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8"},
								{"A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7"},
								{"A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6"},
								{"A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5"},
								{"A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4"},
								{"A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3"},
								{"A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2"},
								{"A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"},
						   		};
    
    int index = 0;
    //make an dynamic string array to store the positions of all possible moves
    char** all_moves = malloc(length * sizeof(char*));
    if (!all_moves)
    {
        perror("Out of memory! Aborting...");
        exit(0);
    }
    for(int i = 0; i < length; i++)
    {
        all_moves[i] = malloc(sizeof(char) * 5);
        if (!all_moves[i])
        {
            perror("Out of memory! Aborting...");
            exit(0);
        }
    }
    
    opponent_positions(board, positions, piece_positions, 2);
    for(int i = 0; i < 16; i++)
    {
        if(strcmp(piece_positions[i], "") != 0)//make sure it is not empty
        {
            piece = position_to_piece(board, positions, piece_positions[i]);
            for(int x = 0; x < 8; x++)
            {
                for(int y = 0; y < 8; y++)
                {
                    if(CheckPiece(positions, board, piece_positions[i], coordinates[x][y]) == 0)//or 3 
                    {
/*
                        if(checkFLAG_white) //make sure AI does not ignore check
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 1) == 0)
                            {   
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }
                        else if(checkFLAG_black)
                        {
                            if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 2) == 0)
                            {
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }    
                        else if(piece == 'K') //make sure king does not move to attacked spots
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 2) == 0)
                            {
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }
                        else if(piece == 'k')
                        {
                            if(isThreatened(board, positions, coordinates[x][y], 1) == 0)
                            {
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        }
                        else
                        {
                            char string[3];
                            strcpy(string, piece_positions[i]);
                            strcat(string, coordinates[x][y]);
                            strcpy(all_moves[index], string);
                            index++;
                        }
                        */
                       if(ignore_check(board, positions, piece_positions[i], coordinates[x][y], 2) == 0)
                            {
                                char string[3];
                                strcpy(string, piece_positions[i]);
                                strcat(string, coordinates[x][y]);
                                strcpy(all_moves[index], string);
                                index++;
                            }
                        //save all ilegal positions a piece can move to into the all_moves array

                    }
                }
            }
        }
    }

    return all_moves;
}

int getPoints(char board[8][8], const char positions[8][8][3], char new_p[3], int piece_color)
{
   // char piece = position_to_piece(board, positions, new_p);
    int P_count, R_count, N_count, B_count, Q_count; // White Chess piece counts
    int p_count, r_count, n_count, b_count, q_count; // Black Chess piece counts
    int points = 0;
    int isWhiteCheck = ifCheck(board, positions, 2);
    int isBlackCheck = ifCheck(board, positions, 1);
    int isWhiteCheckmate = isCheckmate(board, positions, 2);
    int isBlackCheckmate = isCheckmate(board, positions, 1);
    int bonus_safe = 0;
    //int bonus_threatened = 0;
    char all_positions[16][3];
    char piece;
/*
    if(piece_color == 1)
    {
        if(is_capture_safe(board, positions, new_p, 2) == 1)
        {
            if (piece == 'P')
           {
               bonus_safe = -10;
           }
           
           else if (piece == 'R')
           {
               bonus_safe = -50;
           }
           
           else if (piece == 'N')
           {
               bonus_safe = -30;
           }
           
           else if (piece == 'B')
           {
               bonus_safe = -30;
           }
           
           else if (piece == 'Q')
           {
               bonus_safe = -90;
           }
        }
    }
    else if(piece_color == 2)
    {
        if(is_capture_safe(board, positions, new_p, 1) == 1)
        {
             if (piece == 'p')
           {
               bonus_safe = -10;
           }
           
           else if (piece == 'r')
           {
               bonus_safe = -50;
           }
           
           else if (piece == 'n')
           {
               bonus_safe = -30;
           }
           
           else if (piece == 'b')
           {
               bonus_safe = -30;
           }
           
           else if (piece == 'q')
           {
               bonus_safe = -90;
           }
        }
    }AI
    */
    if(piece_color == 1)
    {
        opponent_positions(board, positions, all_positions, 1);
        for(int x = 0; x < 16; x++)
        {
            if(strcmp(all_positions[x], "") != 0)//make sure it is not empty
            {
                if(isThreatened(board, positions, all_positions[x], 2))
                {
                    piece = position_to_piece(board, positions, all_positions[x]);
                    if (piece == 'P')
                    {
                        bonus_safe -= 10;
                    }
                    
                    else if (piece == 'R')
                    {
                        bonus_safe -= 50;
                    }
                    
                    else if (piece == 'N')
                    {
                        bonus_safe -= 30;
                    }
                    
                    else if (piece == 'B')
                    {
                        bonus_safe -= 30;
                    }
                    
                    else if (piece == 'Q')
                    {
                        bonus_safe -= 90;
                    }
                }
            }
        }
        /*
         opponent_positions(board, positions, all_positions, 2);
        for(int x = 0; x < 16; x++)
        {
            if(strcmp(all_positions[x], "") != 0)//make sure it is not empty
            {
                if(isThreatened(board, positions, all_positions[x], 1))
                {
                    piece = position_to_piece(board, positions, all_positions[x]);
                    if (piece == 'p')
                    {
                        bonus_threatened += 1;
                    }
                    
                    else if (piece == 'r')
                    {
                        bonus_threatened += 5;
                    }
                    
                    else if (piece == 'n')
                    {
                        bonus_threatened += 3;
                    }
                    
                    else if (piece == 'b')
                    {
                        bonus_threatened += 3;
                    }
                    
                    else if (piece == 'q')
                    {
                        bonus_threatened += 9;
                    }
                }
            }
        }*/
    }
    
    else if(piece_color == 2)
    {
        opponent_positions(board, positions, all_positions, 2);
        for(int x = 0; x < 16; x++)
        {
            if(strcmp(all_positions[x], "") != 0)//make sure it is not empty
            {
                if(isThreatened(board, positions, all_positions[x], 1))
                {
                    piece = position_to_piece(board, positions, all_positions[x]);
                    if (piece == 'p')
                    {
                        bonus_safe -= 10;
                    }
                    
                    else if (piece == 'r')
                    {
                        bonus_safe -= 50;
                    }
                    
                    else if (piece == 'n')
                    {
                        bonus_safe -= 30;
                    }
                    
                    else if (piece == 'b')
                    {
                        bonus_safe -= 30;
                    }
                    
                    else if (piece == 'q')
                    {
                        bonus_safe -= 90;
                    }
                }
            }
        }
         /*opponent_positions(board, positions, all_positions, 1);
        for(int x = 0; x < 16; x++)
        {
            if(strcmp(all_positions[x], "") != 0)//make sure it is not empty
            {
                if(isThreatened(board, positions, all_positions[x], 2))
                {
                    piece = position_to_piece(board, positions, all_positions[x]);
                    if (piece == 'P')
                    {
                        bonus_threatened += 1;
                    }
                    
                    else if (piece == 'R')
                    {
                        bonus_threatened += 5;
                    }
                    
                    else if (piece == 'N')
                    {
                        bonus_threatened += 3;
                    }
                    
                    else if (piece == 'B')
                    {
                        bonus_threatened += 3;
                    }
                    
                    else if (piece == 'Q')
                    {
                        bonus_threatened += 9;
                    }
                }
            }
        }*/
    }

    P_count = R_count = N_count = B_count = Q_count = p_count = r_count = n_count = b_count = q_count = 0;

  
  for(int x = 0; x < 8; x++)
 	{
		  for(int y = 0; y < 8; y++)
		  {
           if (board[x][y] == 'P')
           {
               P_count++;
           }
           
           else if (board[x][y] == 'R')
           {
               R_count++;
           }
           
           else if (board[x][y] == 'N')
           {
               N_count++;
           }
           
           else if (board[x][y] == 'B')
           {
               B_count++;
           }
           
           else if (board[x][y] == 'Q')
           {
               Q_count++;
           }
           
           else if (board[x][y] == 'p')
           {
               p_count++;
           }
           
           else if (board[x][y] == 'r')
           {
               r_count++;
           }
           
           else if (board[x][y] == 'n')
           {
               n_count++;
           }
           
           else if (board[x][y] == 'b')
           {
               b_count++;
           }
           
           else if (board[x][y] == 'q')
           {
               q_count++;
           } 
      }
  }
  if(piece_color == 1)
  {
      points = P_count * 10 + R_count * 50 + N_count * 30 + B_count * 30 + Q_count * 90 + isBlackCheck * 10 + isBlackCheckmate * 1000 + bonus_safe /*+ bonus_threatened*/ - p_count * 10 - r_count * 50 - n_count * 30 - b_count * 30 - q_count * 90; 
  }
  else if(piece_color == 2)
  {
      points = p_count * 10 + r_count * 50 + n_count * 30 + b_count * 30 + q_count * 90 + isWhiteCheck * 10 + isWhiteCheckmate * 1000 + bonus_safe /*+ bonus_threatened*/ - P_count * 10 - R_count * 50 - N_count * 30 - B_count * 30 - Q_count * 90; 
  }
  return points;
}

int Test_move(char board[8][8], const char positions[8][8][3], char cur_p[3], char new_p[3], int color)
{
    char board_copy[8][8];
    char board_copy2[8][8];
    int length = 0;
    char** moves;
    char cp[3];
    char np[3];
    int checkmate = 0;
    //make a copy of the board
    for(int a = 0; a < 8; a++)
    {
        for(int b = 0; b < 8; b++)
        {
            board_copy[a][b] = board[a][b];
        }
    }
    updateboard(cur_p, new_p, board_copy, positions);
    
    //For AI castling:
					if(strcmp(cur_p, "E1") == 0 &&  strcmp(new_p, "G1") == 0)
					{
						updateboard("H1", "F1", board_copy, positions);
					}
					else if(strcmp(cur_p, "E1") == 0 && strcmp(new_p, "C1") == 0)
					{
						updateboard("A1", "D1", board_copy, positions);
					}
					else if(strcmp(cur_p, "E8") == 0 && strcmp(new_p, "G8") == 0)
					{
						updateboard("H8", "F8", board_copy, positions);
					}
					else if(strcmp(cur_p, "E8") == 0 && strcmp(new_p, "C8") == 0)
					{
						updateboard("A8", "D8", board_copy, positions);
					}
                    
           
    // CPU Pawn Promotion 
                			for (int y = 0; y < 8; y++)
                    			{
                        			// White Pawn Promotion 
                        			if (new_p[1] == '8' && board_copy[0][y] == 'P' && color == 1)
                        			{
                            				board_copy[0][y] = ' ';
                                            board_copy[0][y] = 'Q';
                        			}

						//Black Pawn Promotion 
                        			if (new_p[1] == '1' && board_copy[7][y] == 'p' && color == 2)
                        			{
                            				board_copy[7][y] = ' ';
                                            board_copy[7][y] = 'q';
                        			}
                    			}//end of for loop
    
    if(color == 1)
    {
        length = getLength_black(board_copy, positions);
        moves = get_all_legal_moves_black(board_copy, positions, length);
         for(int x = 0; x < length; x++)
         {
            sscanf(moves[x], "%2s%2s", cp, np);
            for(int a = 0; a < 8; a++)
            {
                for(int b = 0; b < 8; b++)
                {
                    board_copy2[a][b] = board_copy[a][b];
                }
            }
             updateboard(cp, np, board_copy2, positions);
    
    //For AI castling:
					if(strcmp(cp, "E1") == 0 &&  strcmp(np, "G1") == 0)
					{
						updateboard("H1", "F1", board_copy2, positions);
					}
					else if(strcmp(cp, "E1") == 0 && strcmp(np, "C1") == 0)
					{
						updateboard("A1", "D1", board_copy2, positions);
					}
					else if(strcmp(cp, "E8") == 0 && strcmp(np, "G8") == 0)
					{
						updateboard("H8", "F8", board_copy2, positions);
					}
					else if(strcmp(cp, "E8") == 0 && strcmp(np, "C8") == 0)
					{
						updateboard("A8", "D8", board_copy2, positions);
					}
                    
           
    // CPU Pawn Promotion 
                			for (int y = 0; y < 8; y++)
                    			{
                        			// White Pawn Promotion 
                        			if (np[1] == '8' && board_copy2[0][y] == 'P' && color == 2)
                        			{
                            				board_copy2[0][y] = ' ';
                                            board_copy2[0][y] = 'Q';
                        			}

						//Black Pawn Promotion 
                        			if (np[1] == '1' && board_copy2[7][y] == 'p' && color == 1)
                        			{
                            				board_copy2[7][y] = ' ';
                                            board_copy2[7][y] = 'q';
                        			}
                    			}//end of for loop
                    
                if(isCheckmate(board_copy2, positions, 2))
                {
                    checkmate = 1;
                }
         } 
    }
    else if(color == 2)
    {
        length = getLength_white(board_copy, positions);
        moves = get_all_legal_moves_white(board_copy, positions, length);
         for(int x = 0; x < length; x++)
         {
            sscanf(moves[x], "%2s%2s", cp, np);
            for(int a = 0; a < 8; a++)
            {
                for(int b = 0; b < 8; b++)
                {
                    board_copy2[a][b] = board_copy[a][b];
                }
            }
             updateboard(cp, np, board_copy2, positions);
    
    //For AI castling:
					if(strcmp(cp, "E1") == 0 &&  strcmp(np, "G1") == 0)
					{
						updateboard("H1", "F1", board_copy2, positions);
					}
					else if(strcmp(cp, "E1") == 0 && strcmp(np, "C1") == 0)
					{
						updateboard("A1", "D1", board_copy2, positions);
					}
					else if(strcmp(cp, "E8") == 0 && strcmp(np, "G8") == 0)
					{
						updateboard("H8", "F8", board_copy2, positions);
					}
					else if(strcmp(cp, "E8") == 0 && strcmp(np, "C8") == 0)
					{
						updateboard("A8", "D8", board_copy2, positions);
					}
                    
           
    // CPU Pawn Promotion 
                			for (int y = 0; y < 8; y++)
                    			{
                        			// White Pawn Promotion 
                        			if (np[1] == '8' && board_copy2[0][y] == 'P' && color == 2)
                        			{
                            				board_copy2[0][y] = ' ';
                                            board_copy2[0][y] = 'Q';
                        			}

						//Black Pawn Promotion 
                        			if (np[1] == '1' && board_copy2[7][y] == 'p' && color == 1)
                        			{
                            				board_copy2[7][y] = ' ';
                                            board_copy2[7][y] = 'q';
                        			}
                    			}//end of for loop
                    
                if(isCheckmate(board_copy2, positions, 1))
                {
                    checkmate = 1;
                }
         }
        }
    
    free_all_moves(moves, length);                            
    return getPoints(board_copy, positions, new_p, color) - checkmate * 1000;
}
