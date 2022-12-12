// CS 2336
// Lab 37
// Kangmin Kim

#include <lab37.h>

ostream & operator << (ostream &out, const Sudoku &puzzle)
{

    //Print the game board
    int i, j;
	int n = puzzle.gameBoard.rows();
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            out << puzzle.gameBoard[i][j]<<" ";
        }
        out << endl;
    }
    return out;
}

istream & operator >> (istream &in, Sudoku &puzzle)
{
    int i,j,num;
	int n = puzzle.gameBoard.rows();
    for(i = 0; i < n; ++i){
        in >> num;
        for(j = n - 1; j >= 0; --j){
            puzzle.gameBoard[i][j] = num % 10;
            num /= 10;
        }
    }
    return in;
}


 // default constructor - resizes puzzle to have four rows and four
 // columns
 Sudoku::Sudoku()
 {
	 gameBoard.resize(4 , 4);
 }

 // Returns true if puzzle represents a valid sudoku game board as
 // described in the lab handout
bool Sudoku::isValid() const{
    uint i,j,k;
    uint x;
    bool box1, box2, box3, box4;

   //Check if each row contains the numbers 1,2,3,4
    for(k = 1; k < 5; ++k){
        box1 = false;
        box2 = false;
        box3 = false;
        box4 = false;
        for(i = 0; i < 4; ++i){
            x = 0;
            for(j = 0; j < 4; ++j){
                if(gameBoard[i][j]==k){
                    x = 1;

                    //store the box where the item was found
                    if(i < 2 && j < 2){
                        box1 = true;
                    }
                    else if(i < 2 && j >= 2){
                        box2 = true;
                    }
                    else if(i >= 2 && j < 2){
                        box3 = true;
                    }
                    else{
                        box4 = true;
                    }
                }
            }
            if(x == 0){
                return false;
            }
        }

       // if the item is not present in every box, return
        if((box1 && box2 && box3 && box4) == 0){
            return false;
        }
    }


   //Check if item is present in every column
    for(k = 1; k < 5; ++k){
        for(i = 0; i < 4; ++i){
            x = 0;
            for(j = 0; j < 4; ++j){
                if(gameBoard[j][i] == k){
                    x = 1;
                }
            }
            if(x == 0)
			{
                return false;
            }
        }
    }
    return true;
}
