#include <iostream>
using namespace std;

class Shape{
protected:
    int x,y;
public:
    void setOrigin(int x, int y){
        this->x = x;
        this->y = y;
    }
    void draw(){
        cout << "Shape ( " << x << ", " << y << " ) ";
    }
};

class Rectangle : public Shape{
    int width, height;
public:
    void setWidth(int w){
        width = w;
    }
    void setHeight(int h){
        height = h;
    }
    void draw(){
        Shape::draw();
        cout << "Rectangle : " << width << " x " << height;
    }
};

class Circle : public Shape{
    int radius;
public:
    void setRadius(int r){
        radius = r;
    }
    void draw(){
        Shape::draw();
        cout << "Circle : " << radius;
    }
};
void move(Shape& s, int dx, int dy){
    s.setOrigin(dx, dy);
}

int main(){
    Rectangle r;
    r.setOrigin(1,1);
    r.setWidth(3);
    r.draw(); cout << endl;

    Shape *p_s;
    Shape shapeArray[2];
    p_s = &r;
    p_s -> setOrigin(10, 10);
    //p_s -> setWidth(100); // compile error
    p_s -> draw(); cout << endl;

    Rectangle *p_r;
    p_r = (Rectangle *)p_s; // Shape * --> Rectangle *
    p_r -> setOrigin(8, 8);
    p_r -> setWidth(16);
    p_r -> draw(); cout << endl;

    ((Circle *)p_s) -> setRadius(11);
    ((Circle *)p_s) -> draw(); cout << endl;
    p_r -> draw(); cout << endl;

    Shape& s = r;
    s.setOrigin(5,5);
    // s.setWidth(7); // compile error
    s.draw(); cout << endl;

    // Rectangle& r_r = (Rectangle)s; //compile error 변환형 함수가 필요하다
    cout << sizeof(shapeArray) << endl;

}