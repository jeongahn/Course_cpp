#include <iostream>
#include <string>

using namespace std;

class Car{
public:
    int speed;
    int gear; // 주행거리
    string color;

    void setGear(int newGear){
        this->gear = newGear;
    }
    void speedUp(int increment){
        speed += increment;
    }
    void speedDown(int decrement){
        speed -= decrement;
    }
};

class SportsCar : public Car{ // Car상속
    bool turbo; // private 
public:
    void setTurbo(bool newValue){
        turbo = newValue;
    }
};

int main(){
    SportsCar c;
    c.color = "Red";
    c.setGear(3);
    c.speedUp(100);
    c.speedDown(30);
    c.setTurbo(true);
    return 0;
}