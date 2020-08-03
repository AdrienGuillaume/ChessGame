#ifndef CPU_H
#define CPU_H

//AI randomly picking pieces and making random moves
void AI_1(const char positions[8][8][3], char board[8][8], int piece_color, char *AI_cur_position, char *AI_new_position);

//AI would go for capture and check based on points
void AI_3(const char positions[8][8][3], char board[8][8], int piece_color, char *AI_cur_position, char *AI_new_position);

//AI's pawn piece will automatically be promoted to queen if it reaches the other side of the board (white)
void AIPromotionWhite(char board[8][8], int x);

//AI's pawn piece will automatically be promoted to queen if it reaches the other side of the board (white)
void AIPromotionBlack(char board[8][8], int x);

int is_capture_safe(char board[8][8], const char positions[8][8][3], char location[3], int color);

char** get_all_legal_moves_white(char board[8][8], const char positions[8][8][3], int length);

int getLength_white(char board[8][8], const char positions[8][8][3]);

char** get_all_legal_moves_black(char board[8][8], const char positions[8][8][3], int length);

int getLength_black(char board[8][8], const char positions[8][8][3]);

int getPoints(char board[8][8], const char positions[8][8][3], char new_p[3], int piece_color);

int Test_move(char board[8][8], const char positions[8][8][3], char cur_p[3], char new_p[3], int color);
#endif
