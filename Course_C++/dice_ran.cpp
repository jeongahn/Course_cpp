#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*void get_random(int n){
	int i;
	for(i = 0; i< n; i++){
		int dice = rand()%6 + 1;
		cout << dice << " ";
	}
	cout << endl;
}*/
int main(){

	int dice;
	time_t t = time(NULL);
 	srand(t);
 	for (int i = 0 ; i < 10 ; i++)
 	{
  		dice = rand() % 6 + 1 ;

  		cout << dice << " ";
	 }
	 cout << endl;

	 return 0;
}
