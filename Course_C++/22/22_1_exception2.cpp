#include <iostream>
using namespace std;

class NonPositiveException{
public:
    int v;
    NonPositiveException(int v = 0) : v(v){
        cout << this << " : " << "NonPositiveException\n";
    }
};
class ZeroException : public NonPositiveException{};
int main(){
    int v;
    try{
        cout << " enter a value : ";
        cin >> v;
        if (v < 0) throw NonPositiveException(v);
        if (v == 0) throw ZeroException();
    }
    catch(ZeroException& e){
        cout << "zero \n";
    }
    catch(NonPositiveException& e){
        cout << "NonPositive Value : " << e.v << endl;
    }
    cout << v << endl;
    return 0;
}