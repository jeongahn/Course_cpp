#include <iostream>
#include <string>
using namespace std;

int main(){
    int testCase;
    
    string var;
    
    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        int answer = 1;
        cin >> var;

        if((var[0] < 65) || (var[0] > 90 && var[0] < 95) || (var[0] == 96) || (var[0] > 122)){
            answer = 0;
        }

        for(int i = 1; i< var.length(); i++){
            if((var[i] < 48) || (var[i] >= 58 && var[i] <= 64) || (var[i] >= 91 && var[i] < 95) || (var[i] == 96) || (var[i] > 122)){
                answer = 0;
                break;
            }
        }

        cout << answer << endl;
    }
}