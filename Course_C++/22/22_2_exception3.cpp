#include <iostream>
using namespace std;

class NonPositiveException{
public:
    int v;
    NonPositiveException(int v = 0) : v(v){}
};
class ZeroException : public NonPositiveException{};
void foo(){
    int v;
    cout << "enter a value : ";
    cin >> v;
    if (v < 0) throw NonPositiveException(v);
    if (v == 0) throw ZeroException();
    cout << "foo\n";
}
int main(){
    try{
        foo();
    }
    catch (ZeroException& e){
        cout << "Zero \n";
    }
    catch (NonPositiveException& e){
        cout << "NonPositive Value : " << e.v << endl;
    }
    cout << "main" << endl;
    return 0;
}