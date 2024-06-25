#include "Move_Logic.h"
#include "Misc_functions.h"

int main(){
    //initialise Board as a 2 dimensional array of pieces and run Board_Intialisation to fill with pieces in correct position
    Piece Board[8][8];
    int move_list[1000][2];
    Board_Initialisation(Board);
    Print_Board(Board);
    Move_list(Board,1,1,move_list);
    for(int i = 0; i>3; i++){
        for(int j = 0; j>3; j++){
            printf("%d",move_list[i][j]);
        }
    }
    return 0;

};