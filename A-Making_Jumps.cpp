#include <iostream>
using namespace std;

bool possible(short int r, short int c, short int board[10][10]){
    if(board[r][c] == -1 && r >= 0 && r <= 10 && c >= 0 && c <= 10)
        return true;
    return false;
}

void moves(short int x, short int y, short int steps, short int &total, short int board[10][10]){
    short int moves_r[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    short int moves_c[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    short int next_r, next_c;

    for(short int i=0; i<8; i++){
        next_r = x + moves_r[i];
        next_c = y + moves_c[i];
        if(possible(x  + moves_r[i], y + moves_c[i], board)){
            board[x + moves_r[i]][y + moves_c[i]] = steps;
            moves(next_r, next_c, steps + 1, total, board);
            board[next_r][next_c] = -1;
        }
    }
    if(steps>total)
        total = steps;
}

int main(){
    short int numCases = 0, sqr = 0, total = 0;
    short int rows, cols, skips;
    short int board[10][10];

    do{
        cin >> rows;
        if(rows != 0){
            for(short int i=0; i<10; i++){
                for(short int j=0; j<10; j++)
                    board[i][j] = 0;
            } 
            
            for(short int i=0; i<rows; i++){
                cin >> skips >> cols;
                sqr += cols;
                for(short int j=skips; j< cols+skips; j++)
                    board[i][j] = -1;
            }
            board[0][0] = 0;
            moves(0, 0, 1, total, board);
            numCases++;

            if(sqr - total == 1)
                cout << "Case " << numCases << ", 1 square can not be reached." << "\n";
            else if(sqr - total == 0)
                cout << "Case " << numCases << ", 0 squares can not be reached." << "\n";
            else
                cout << "Case " << numCases << ", " << sqr - total << " squares can not be reached."  << "\n";

            total = 0;
            sqr = 0;
        }
    }while(rows != 0);

    return 0;
}
