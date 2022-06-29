#include <iostream>
#include <string>
using namespace std;
class Book{

private:
    int isbn;
    string title;
public:
    Book(int isbn, string& title){
        this -> isbn = isbn;
        this -> title = title;
    }
    Book(int isbn){
        this -> isbn = isbn;
        this -> title = "unknown";
    }
    operator int() const{
        return isbn;
    }
    void display(){
        cout << isbn << ":" << title << endl;
    }
};

bool check(int isbn){
    cout << isbn << endl;
    return true;
}

int main(){
    Book b1 = 9782001;
    // Book b1 = 9.73; 이렇게 했을때 변환 생성자는 실수 -> 정수 -> 객체로 자동 형변환 시켜준다
    // 이를 방지하기 위해서는 operator int() const{} 앞에 explicit을 붙여주면 자동 타입 변환이 안된다.
    b1.display();
    int isbn = b1;
    cout << isbn << endl;
    check(b1);

    return 0;
}

