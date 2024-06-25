#include "Board.h"
#include "Move_Logic.h"

void find_king(Piece (*Board)[8], int *pos[], int colour){
    for(int i=0; i<=7; i++){
        for(int j=0; j<=7; j++){
            if(Board[i][j].colour == colour &&Board[i][j].icon == 'K'){
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
}