#include <iostream>
#include <vector>
using namespace std;

int printSolution(vector<vector<int>> &board){
    int n = board.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    return 0L;
}

int ld[100]{0}; // 左對角線紀錄陣列
int rd[100]{0}; // 右對角線紀錄陣列
int cl[100]{0}; // 當行紀錄陣列

bool solveNQutility(vector<vector<int>> &board, int col){
    int n = board.size();
    if(col >= n){
        return true;
    }

    for(int row=0; row<n; row++){
        if( ld[row - col + n-1] !=1 && rd[row+col] != 1 && cl[row] != 1){
            // 目前(row, col)擺放 queen
            board[row][col] = 1;
            
            ld[row - col + n-1] = 1;
            rd[row+col] = 1;
            cl[row] = 1;
            
            // 往下一個 col移動
            if(solveNQutility(board, col+1)){
                return true;
            }
            
            //if false => go Backtrack
            board[row][col] = 0; 
            ld[row - col + n-1] = 0;
            rd[row + col] = 0;
            cl[row] = 0;
        }

    }
    // 若 queen在這 col 無法放置在任何 row, 
    // 就 return false; 讓 recursion往回走 backtrack處理.
    return false;
}


int main(int argc, char* argv[]){
    int n{4};
    if(argc < 2){ cout << "Usage: \n \t nqueen 4" << '\n'; return 0L;}
    n = atoi(argv[1]);    
    vector<vector<int>> board(n, vector<int>(n,0));
    if(solveNQutility(board, 0) == false){
        cout << "不存在solution!" << '\n';
        return 0L;
    }
    printSolution(board);

    


    return 0L;
}