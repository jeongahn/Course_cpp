#include <iostream>
#include <climits>
using namespace std;

int main(void){
	int *i = new int[26];
	for(int j = 0; j < 26; j++){
		i[j] += j + 97; // i[0] = *(i + 0)과 같으므로.
	}
	for(int j = 0 ; j < 26; j++){
		cout << (char)i[j] << " ";
	}
	cout << endl;
	delete [] i;
}