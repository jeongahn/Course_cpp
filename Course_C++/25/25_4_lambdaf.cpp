#include <iostream>
#include <string>
using namespace std;

int main(){
    void(*f3)() = [](){cout << "lambda function\n"; };
    auto f4 = [](const string& s){
        cout << "This is a function pointer lambda function f4() : ";
        cout << s << endl;
    };

    f3();
    f4("main() calling f4");
}