#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//initialise enum Type for types of pieces
enum Type{
    NONE = 0,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
};

//Initialise enum Colour for colour of pieces
enum Colour{
    NEITHER = 0,
    WHITE =-1,
    BLACK = 1  
};

//Initialise Piece structure made up of type and colour
typedef struct Piece{
    enum Type type;
    enum Colour colour;
    char icon;
    int moves;
    int check;
}Piece;

//Fill 2 dimensional Board array with pieces for white and black in the correct positions
void Board_Initialisation(Piece (*Board)[8]){
    Piece Empty = {NONE,NEITHER,'0',0,0};
    Piece W_Pawn = {PAWN,WHITE,'P',0,0};
    Piece W_Bishop = {BISHOP,WHITE,'B',0,0};
    Piece W_Knight = {KNIGHT,WHITE,'H',0,0};
    Piece W_Rook = {ROOK,WHITE,'R',0,0};
    Piece W_Queen = {QUEEN,WHITE,'Q',0,0};
    Piece W_King = {KING,WHITE,'K',0,0};
    Piece B_Pawn = {PAWN,BLACK,'P',0,0};
    Piece B_Bishop = {BISHOP,BLACK,'B',0,0};
    Piece B_Knight = {KNIGHT,BLACK,'H',0,0};
    Piece B_Rook = {ROOK,BLACK,'R',0,0};
    Piece B_Queen = {QUEEN,BLACK,'Q',0,0};
    Piece B_King = {KING,BLACK,'K',0,0};
    for(int i=0; i<=7;i++){
        Board[1][i] = B_Pawn;
        Board[6][i] = W_Pawn;
        Board[2][i] = Empty;
        Board[3][i] = Empty;
        Board[4][i] = Empty;
        Board[5][i] = Empty;
    }
    Board[0][0] = B_Rook;
    Board[0][7] = B_Rook;
    Board[0][1] = B_Knight;
    Board[0][6] = B_Knight;
    Board[0][2] = B_Bishop;
    Board[0][5] = B_Bishop;
    Board[0][3] = B_Queen;
    Board[0][4] = B_King;
    Board[7][0] = W_Rook;
    Board[7][7] = W_Rook;
    Board[7][1] = W_Knight;
    Board[7][6] = W_Knight;
    Board[7][2] = W_Bishop;
    Board[7][5] = W_Bishop;
    Board[7][3] = W_Queen;
    Board[7][4] = W_King;
};

void Print_Board(Piece (*Board)[8]){
    for(int i=0; i<=7; i++){
        for(int j=0; j<=7; j++){
            printf("%c",Board[i][j].icon);
        }
        printf("\n");
    }
};
