#include <iostream>

using namespace std;


//행렬


int main() 
{
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        
        int mat1[101][101] = {};
        int mat2[101][101] = {};
        int res[101][101] = {};
        int N, M, K;
        cin >> N >> M >> K;
        for(int n = 1; n <= N; n++){
            for(int m = 1; m <= M; m++){
                cin >> mat1[n][m];
            }
        }

        for(int m = 1; m <= M; m++){
            for(int k = 1; k <= K; k++){
                cin >> mat2[m][k];
            }

        }

        //행렬 곱셉

        for(int n = 1; n <= N; n++){
            for(int k = 1; k <= K; k++){
                for (int m = 1; m <= M; m++){
                    res[n][k] += mat1[n][m] * mat2[m][k]; 
                }
                cout << res[n][k] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

