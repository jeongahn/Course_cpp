#include <iostream>
using namespace std;

#define N 8



int main(){
    
    int testCase;
    
    cin >> testCase;
    
    int dir[8][2] = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    for(int i = 0; i < testCase; i++){
        
        int Black = 0;
        int White = 0;
        
        char Othello_Board[N][N] = {{'+','+','+','+','+','+','+','+'},
                                    {'+','+','+','+','+','+','+','+'},
                                    {'+','+','+','+','+','+','+','+'},
                                    {'+','+','+','O','X','+','+','+'},
                                    {'+','+','+','X','O','+','+','+'},
                                    {'+','+','+','+','+','+','+','+'},
                                    {'+','+','+','+','+','+','+','+'},
                                    {'+','+','+','+','+','+','+','+'}};
        
        int num;
        int row, col;

        cin >> num;

        int turn = 0;
        char Stone;

        for(int n = 0; n < num; n++){
            cin >> row >> col;
            
            row = row - 1;
            col = col - 1;
            
            if(turn == 0){
                Stone = 'X';
            }else if(turn == 1){
                Stone = 'O';
            }

            Othello_Board[row][col] = Stone;

            for(int c = 0; c < N; c++){
                
                bool Continue = false;

                for(int k = 1; k < N; k++){
                    int pdr = row + dir[c][0] * k; // pd - product
                    int pdc = col + dir[c][1] * k;

                    if(pdr < 0 || pdc < 0 || pdr > N - 1 || pdc > N - 1){
                        break;
                    }
                    if(Othello_Board[pdr][pdc] == '+'){
                        break;
                    }
                    if(Othello_Board[pdr][pdc] == Stone && Continue == false){
                        break;
                    }
                    if(Othello_Board[pdr][pdc] != '+' && Othello_Board[pdr][pdc] != Stone){
                        Continue = true;
                    }
                    if(Othello_Board[pdr][pdc] == Stone && Continue == true){
                        while(1){
                            if(pdr == row && pdc == col){
                                break;
                            }
                            pdr = pdr - dir[c][0];
                            pdc = pdc - dir[c][1];
                            Othello_Board[pdr][pdc] = Stone;
                        }
                        break;
                    }
                }          

            }

            if(turn == 0){
                turn = 1;
            }else if(turn == 1){
                turn  = 0;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(Othello_Board[i][j] == 'X'){
                    Black++;
                }else if(Othello_Board[i][j] == 'O'){
                    White++;
                }
            }
        }
        cout << Black << " " << White << endl;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << Othello_Board[i][j];
            }
            cout << endl;
        }
        
    }
}
