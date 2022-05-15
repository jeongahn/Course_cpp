#include <iostream>
using namespace std;

int main() {
  char arr[10];
  int i;

  for (i = 0; i< 10; i++){
    arr[i] = 'a';
  }

  for(i = 0; i< 10; i++)
    cout << arr[i] << endl;

  return 0;
}
