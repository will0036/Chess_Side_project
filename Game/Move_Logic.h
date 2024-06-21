#include "Board.h"

//Adds all valid_moves into an array
void Pawn_logic(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2],int colour){
    int num_moves = 0;
    if(Board[Row+colour][Column].icon == 'E'){
        valid_moves[num_moves] = {Row+colour,Column};
        num_moves+=1;
    }
    if(Board[Row+colour][Column-1].colour== 0-colour){
        valid_moves[num_moves] = {Row+colour,Column-1};
        num_moves+=1;
    }
    if(Board[Row+colour][Column+1].colour== 0-colour){
        valid_moves[num_moves] = {Row+colour,Column+1};
        num_moves+=1;
    }
    if(Row ==7 &&colour == -1 && Board[Row+colour][Column].icon == 'E'&&Board[Row+(colour*2)][Column].icon == 'E'){
        valid_moves[num_moves] = {Row+(colour*2),Column};
        num_moves+=1;
    }
    if(Row ==1 &&colour == 1 && Board[Row+colour][Column].icon == 'E'&&Board[Row+(colour*2)][Column].icon == 'E'){
        valid_moves[num_moves] = {Row+(colour*2),Column};
        num_moves+=1;
    }
}