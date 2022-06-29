#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	int t;
	int n1, n2, n3;

	cin >> t;
	
	for(int i = 0 ; i < t; i++){

		cin >> n1 >> n2>> n3;
		v.push_back(n1);
		v.push_back(n2);
		v.push_back(n3);
		sort(v.begin(), v.end());
		for(int j = 0; j <v.size(); j++ ){
			cout << v[j] << " ";
		}
		cout << endl;
		v.clear();


	}

	return 0;


}
