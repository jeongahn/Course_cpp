#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#define N 10
int main(){
    int i;
    stack<int> st;

    for(i = 0; i < N; i++){
        st.push(i);
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    queue<int> qu;
    for(i = 0; i < N; i++){
        qu.push(i);
    }
    while(!qu.empty()){
        cout << qu.front() << " ";
        qu.pop();
    }
    cout << endl;

    priority_queue<int> pq;
    for(i = 0; i < N; i++){
        pq.push(i);
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl; // priority_queue에서 int는 큰 값이 priority가 높다는 것을 알 수 있다.
}