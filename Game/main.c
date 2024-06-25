#include "Board.h"
#include "Move_Logic.h"
#include "Misc_function.h"

int main(){
    //initialise Board as a 2 dimensional array of pieces and run Board_Intialisation to fill with pieces in correct position
    Piece Board[8][8];
    Board_Initialisation(Board);
    Print_Board(Board);
    return 0;

};