#include <iostream>
using namespace std;

class Animal{
public:
    Animal(){
        cout << "Animal 생성자" << endl;
    }
    virtual ~Animal(){
        cout <<"Animal 소멸자" << endl; 
    }
    virtual void speak(){
        cout << "Animal speak()" << endl;
    }
};

class Dog : public Animal{
public:
    Dog(){
        cout << "Dog 생성자" << endl;
    }
    ~Dog(){
        cout << "Dog 소멸자" << endl;
    }
    void speak(){
        cout << "멍멍" << endl;
    }
};

int main(){
    Animal *a1 = new Dog();
    a1 -> speak();
    delete a1;
    return 0;
}