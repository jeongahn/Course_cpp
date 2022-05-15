#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, char *argv[]){
	if(argc != 2){
		cout << "usage: ./dice n\n";
		return -1;
	}
	int t = atoi(argv[1]);
	int dice;
 	srand(t);
 	for (int i = 0 ; i < 10 ; i++)
 	{
  		dice = rand() % 6 + 1 ;

  		cout << dice << " ";
	 }
	 cout << endl;

	 return 0;
}
