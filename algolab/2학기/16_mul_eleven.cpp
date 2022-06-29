#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int testCase;
    string num;
    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        cin >> num;
        char tmp;
        string answer = "";
        while(num.length() > 1){
            tmp = num[num.length()-1];
            answer += tmp;
            num = num.substr(0,num.length()-1);
            if(num.length() == 1){
                num[num.length() - 1] = num[num.length() - 1] - tmp + 48;
            }
            else{
                if(num[num.length() - 1] < tmp){
                    num[num.length() - 2] = num[num.length() - 2] - 1;
                    num[num.length() - 1] = num[num.length() - 1] - tmp + 58;
                    if(num[0] == '0'){
                        num = num.substr(1,num.length());
                    }
                }else{
                    num[num.length() - 1] = num[num.length() - 1] - tmp + 48;
                }
                

            }
            
        }
        if(num == "0"){
            reverse(answer.begin(), answer.end());
            cout << answer << endl;
        }else{
            cout << 0 << endl;
        }
        
    }
}
