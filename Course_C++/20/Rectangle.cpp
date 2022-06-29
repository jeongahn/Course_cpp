#include <iostream>
using namespace std;

class Shape{
    int x, y;

public:
    Shape(int x = 0, int y = 0) : x(x), y(y){
        cout << this << " Shape()" << endl;
    }
    ~Shape(){
        cout << this << " ~Shape()" << endl;
    }
    void print(){
        cout << "( " << x << ", " << y << " ) ";
    }
};

class Rectangle : public Shape{
    int width, height;
public:
    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0){
        width = w; height = h;
        cout << this << " Rectangle()" << endl;
    }
    ~Rectangle(){
        cout << this << " ~Rectangle()" << endl;
    }
    void print(){
        Shape::print();
        cout << " : " << width << " x " << height << endl;
    }
};

int main(){
    Rectangle r;
    return 0;
}