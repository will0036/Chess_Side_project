#include "Board.h"

//Adds all valid_moves for a pawn into an array
void Pawn_logic(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2]){
    //Checks if square 1 space ahead
    //if square is empty puts row and column in valid moves array
    int num_moves = 0;
    int colour = Board[Row][Column].colour;
    if(Board[Row+colour][Column].icon == 'E'){
        valid_moves[num_moves] = {Row+colour,Column};
        num_moves + =1;
    }
    //Checks if square 1 space ahead and to the 1 to the left has a piece of the other colour
    //if square has other colour puts row and column in valid moves array
    if(Board[Row+colour][Column-1].colour== 0-colour){
        valid_moves[num_moves] = {Row+colour,Column-1};
        num_moves + =1;
    }
    //Checks if square 1 space ahead and to the 1 to the right has a piece of the other colour
    //if square has other colour puts row and column in valid moves array
    if(Board[Row+colour][Column+1].colour== 0-colour){
        valid_moves[num_moves] = {Row+colour,Column+1};
        num_moves + =1;
    }
    //Checks if square 2 space ahead and pawn hasn't made a move
    //if square is empty puts row and column in valid moves
    if(Board[Row][Column].moves == 0 && Board[Row+(colour*2)][Column].icon == 'E'){
        valid_moves[num_moves] = {Row+(colour*2),Column};
        num_moves + =1;
    }
    //en Passant Rule
    //if()
}

//Adds all valid moves for a Bishop into an array
void Bishop_logic(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2]){
    int colour = Board[Row][Column].colour;
    int num_moves = 0;
    //arrays to corellate to the different combitations of directions
    int row_choice[] = {1,1,-1,-1};
    int col_choice[] = {1,-1,1,-1};
    //for loop for the 4 different diagnal directions
    for(int j=0; j<4; j++){    
        int Boolean = 1;
        int new_row = Row;
        int new_column = Column;
        //loops until reaches a non empty square or off the board
        while(Boolean == 1){
            new_row +=row_choice[j];
            new_column +=col_choice[j];
            Boolean = 0;
            if(new_row<7 && new_column<7 && new_row>=0 && new_column>=0){
                //if space empty add to move list and continue loop
                if(Board[new_row][new_column].icon == 'E'){
                    valid_moves[num_moves] = {new_row,new_column};
                    Boolean =1;
                    num_moves+=1;
                }
                //if space is of the opposite colour add to move list but break loop
                else if(Board[new_row][new_column].colour == 0-colour){
                    valid_moves[num_moves] = {new_row,new_column};
                    num_moves+=1;
                }
            }
        }
    }
}

//Adds all valid moves for a Knight into an array
void Knight_logic(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2]){
    int colour = Board[Row][Column].colour;
    //array for all the combinations of moves
    int choice[] = {2,2,-2,-2,1,-1,1,-1};
    int num_moves = 0;
    //loops through the 8 possible different moves
    for(int i=0; i<8; i++){
        int new_row = Row + choice[i];
        int new_column = Column + choice[7-i];
        //checks that move is within bounds
        if(new_row<7 && new_column<7 && new_row>=0 && new_column>=0){
            //if square is not a piece of the same colour it is added to valid move array
            if(Board[new_row][new_column].colour!=colour){
                valid_moves[num_moves] = {new_row,new_column};
                num_moves +=1;
            }
        }
    }
}

//Adds all valid moves for a rook into an array
void Rook_logic(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2]){
    int colour = Board[Row][Column].colour;
    int num_moves = 0;
    int choice[] = {1,-1,0,0};
    //loops through the four different directions
    for(int j=0; j<4; j++){    
        int Boolean = 1;
        int new_row = Row;
        int new_column = Column;
        while(Boolean ==1){
            int new_row = Row + choice[j];
            int new_column = Column + choice[3-j];
            Boolean = 0;
            if(new_row<7 && new_column<7 && new_row>=0 && new_column>=0){
                //if space empty add to move list and continue loop
                if(Board[new_row][new_column].icon == 'E'){
                    valid_moves[num_moves] = {new_row,new_column};
                    Boolean = 1;
                    num_moves += 1;
                }
                //if space is of the opposite colour add to move list but break loop
                else if(Board[new_row][new_column].colour == 0-colour){
                    valid_moves[num_moves] = {new_row,new_column};
                    num_moves+=1;
                }
            }
        }
    }
    int kingpos[2];
    find_king(Board,kingpos);
    //Castling rules
    //checks if king or rook has moved
    //if(Board[Row][Column].moves == 0 && Board[pos[0]][pos[1]].moves == 0 ){
        //if king not in check and not pass through check
            //castle        
    //}
}

//Adds all valid moves for a queen into an array
void Queen_logic(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2]){
    int colour = Board[Row][Column].colour;
    int num_moves = 0;
    int choice[] = {1,-1,0,0};
    //loops through the four different straight directions
    for(int j=0; j<4; j++){    
        int Boolean = 1;
        int new_row = Row;
        int new_column = Column;
        while(Boolean ==1){
            int new_row = Row + choice[j];
            int new_column = Column + choice[3-j];
            Boolean = 0;
            if(new_row<7 && new_column<7 && new_row>=0 && new_column>=0){
                //if space empty add to move list and continue loop
                if(Board[new_row][new_column].icon == 'E'){
                    valid_moves[num_moves] = {new_row,new_column};
                    Boolean = 1;
                    num_moves += 1;
                }
                //if space is of the opposite colour add to move list but break loop
                else if(Board[new_row][new_column].colour == 0-colour){
                    valid_moves[num_moves] = {new_row,new_column};
                    num_moves+=1;
                }
            }
        }
    }
    //arrays to corellate to the different combitations of directions
    int row_choice[] = {1,1,-1,-1};
    int col_choice[] = {1,-1,1,-1};
    //for loop for the 4 different diagnal directions
    for(int j=0; j<4; j++){    
        int Boolean = 1;
        new_row = Row;
        new_column = Column;
        //loops until reaches a non empty square or off the board
        while(Boolean == 1){
            new_row +=row_choice[j];
            new_column +=col_choice[j];
            Boolean = 0;
            if(new_row<7 && new_column<7 && new_row>=0 && new_column>=0){
                //if space empty add to move list and continue loop
                if(Board[new_row][new_column].icon == 'E'){
                    valid_moves[num_moves] = {new_row,new_column};
                    Boolean =1;
                    num_moves+=1;
                }
                //if space is of the opposite colour add to move list but break loop
                else if(Board[new_row][new_column].colour == 0-colour){
                    valid_moves[num_moves] = {new_row,new_column};
                    num_moves+=1;
                }
            }
        }
    }
}

//Adds all valid moves for a king into an array
void King_logic(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2]){
    int colour = Board[Row][Column].colour;
    int num_moves = 0;
    int row_choice[] = {1,0,-1,-1,1,1,0,-1};
    int col_choice[] = {1,1,1,0,0,-1,-1,-1};
    for(int i = 0; int i>8; i++){
        int new_row = row + row_choice[i];
        int new_column = column + col_choice[i] ;
        if(new_row<7 && new_column<7 && new_row>=0 && new_column>=0){
            //if not in check 
            if(Board[new_row][new_column].colour!=colour){
                valid_moves[num_moves] = {new_row,new_column};
                num_moves += 1;
            }
        }
    }
}

void Move_list(Piece (*Board)[8],int Row,int Column, int (*valid_moves)[2]){
    if(Board[Row][Column].icon == 'P'){
        Pawn_logic(Board,Row,Column,valid_moves);
    }
    else if(Board[Row][Column].icon == 'B'){
        Bishop_logic(Board,Row,Column,valid_moves);
    }
    else if(Board[Row][Column].icon == 'H'){
        Knight(Board,Row,Column,valid_moves);
    }
    else if(Board[Row][Column].icon == 'R'){
        Rook_logic(Board,Row,Column,valid_moves);
    }
    else if(Board[Row][Column].icon == 'Q'){
       Queen_logic(Board,Row,Column,valid_moves);
    }
    else if(Board[Row][Column].icon == 'K'){
        King_logic(Board,Row,Column,valid_moves);
    }
}