#include <iostream>
struct absValue //functor class
{
    float operator()(float f){
        return f > 0 ? f : -f;
    }
};

int main()
{
    using namespace std;

    float f = -123.45;
    absValue aObj;
    float abs_f = aObj(f); // = aObj.operator()(f)
    cout << "f = " << f << "abs_f = " << abs_f << endl;
    return 0;
}