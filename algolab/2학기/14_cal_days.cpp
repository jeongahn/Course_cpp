#include <iostream>

using namespace std;

bool isleapyear(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    int testCase;
    cin >> testCase;

    

    for(int i = 0; i < testCase; i++){
        int years, month, days;
        int sumdays = 0;
        cin >> years >> month >> days;
        
        int monthList[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isleapyear(years) == true){
            monthList[1] = 29;
        }

        int thisdays = 0;
        for(int i = 0; i < month - 1; i++){
            thisdays += monthList[i];
        }
        thisdays += days;

        for(int i = 0; i < years; i++){
            if(isleapyear(i) == true){
                sumdays += 366;
            }else{
                sumdays += 365;
            }
        }
        sumdays += thisdays;
        cout << (sumdays - 366) % 7 << endl;
    }
    /*
    years -= 1;
    days += (years + years / 4 - years / 100 + years / 400); 모든 해를 다 더해줄 필요가 없다.
    월을 더해주고 윤년이면 하루를 더 더해준다.
}
