#include <iostream>
using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        int N;
        cin >> N;
        int magic_square[N][N];
        int row_len = sizeof(magic_square) / sizeof(magic_square[0]);
        int col_len = sizeof(magic_square[0]) / sizeof(int);
        for(int i = 0; i < row_len; i++){
            for(int j = 0; j < col_len; j++){
                magic_square[i][j] = 0;
            }
        }
        
        magic_square[0][N/2] = 1;
        int value = 1;
        int row = 0;
        int col = N/2;
        int tmp = N;
        int count = 1;
        if(N == 1){
            for(int i = 0; i < row_len; i++){
                for(int j = 0; j < col_len; j++){
                    cout << magic_square[i][j] << " ";
                }
                cout << endl;
            }
        }else{
            while(N > 0){
                if(row == 0 && col == tmp - 1){
                    row += 1;
                    magic_square[row][col] = ++value;         
                }else if(row == 0 && col != tmp - 1){
                    row = tmp - 1;
                    col += 1;
                    magic_square[row][col] = ++value;
                }else if(col == tmp - 1){
                    row -= 1;
                    col = 0;
                    magic_square[row][col] = ++value;
                }else{
                    if(magic_square[row-1][col+1] != 0){
                        row += 1;
                        magic_square[row][col] = ++value;
                    }else{
                        row -= 1;
                        col += 1;
                        magic_square[row][col] = ++value;
                    }
                }
                ++count;
                if(count == tmp){
                    count = 0;
                    N--;
                }
            }
            for(int i = 0; i < row_len; i++){
                for(int j = 0; j < col_len; j++){
                    cout << magic_square[i][j] << " ";
                }
                cout << endl;
            }
        }

    }
}
