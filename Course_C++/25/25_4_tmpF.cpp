#include <iostream>
#include <string>

using namespace std;

void my_f0(const string& str, void (*func)(const string& s)){
    func(str);
}
template <class F> // function pointer/functor를 인자로 받을 수 있다.
void my_f(const string& str, F func){
    func(str);
}

class F1{
public:
    void operator()(const string& s){
        cout << "This is a functor F1() : ";
        cout << s << endl;
    }
};

void f2(const string& s){
    cout << "This is a function pointer f2() : ";
    cout << s << endl;
}

int main(){
    F1 o1;
    o1("main() calling o1");
    //my_f0("my_f0 calling o1", o1); -> error 이유는 function pointer만 인자로 받기 때문
    my_f("my f calling o1", o1);

    f2("main() calling f2");
    my_f0("my_f0 calling f2", f2);
    my_f("my_f calling f2", f2);

    auto f4 = [](const string& s){
        cout << "This is a function pointer lambda function f4() : ";
        cout << s << endl;
    };
    f4("main() calling f4");
    my_f0("my_f0 calling f4", f4);
    my_f("my_f calling f4", f4);

}

