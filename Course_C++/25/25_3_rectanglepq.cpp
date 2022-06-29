#include <iostream>
#include <queue>
using namespace std;

class Rectangle{
    int width, height;
public:
    Rectangle(int w = 0, int h = 0) : width(w), height(h){}
    int area(){
        return width*height;
    }
    friend ostream& operator<< (ostream& os, Rectangle r);
};
ostream& operator<< (ostream& os, Rectangle r){
    os << r.width << " x " << r.height << endl;
    return os;
}
class RectangleCmp{
public:
    bool operator() (Rectangle& r1, Rectangle& r2){
        return (r1.area() < r2.area()) ? true : false;
    }
};
int main(){
    priority_queue<Rectangle, vector<Rectangle>, RectangleCmp> pq;
    pq.push(Rectangle(4,5));
    pq.push(Rectangle(3,5));
    pq.push(Rectangle(4,8));

    while(!pq.empty()){
        cout << pq.top();
        pq.pop();
    }
}