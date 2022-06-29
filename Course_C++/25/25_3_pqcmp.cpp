#include <iostream>
#include <queue>

using namespace std;

class Cmp{
public:
    bool operator()(int& a, int& b){
        return a%3 < b%3;
    }
};

#define N 10
int main(){
    int i;
    priority_queue<int, vector<int> , Cmp>pq;

    for(i = 0; i < N; i++) pq.push(i);

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

}