#include <iostream>
using namespace std;

int main(){
	int t, px1, py1, qx1, qy1;
	int px2, py2, qx2, qy2;
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> px1>> py1 >> qx1 >> qy1;
		cin >> px2 >> py2 >> qx2 >> qy2;
		int square[100][100] = {};
		int count = 0;
		int overlap_xlength = 0;
		int overlap_ylength = 0;
		int overlap_width = 0;
		int total_length, total_width;
		for(int i = py1; i < qy1; i++){
			for(int j = px1; j < qx1; j++){
				square[j][i] = 1;
			}
		}
		for(int i = py2; i < qy2; i++){
			for(int j = px2; j < qx2; j++){
				if(square[j][i] == 1){
					overlap_width += 1;
					if(count == 0){
						count = j;
						overlap_xlength += 1;
						continue;
					}else if(count == j){
						overlap_xlength += 1;
					}
				}else{
					square[j][i] = 1;
				}
			}
		}
		if(count != 0){
			overlap_ylength = overlap_width / overlap_xlength;
		}
		if(overlap_width > 0){
			total_length = 2*((qx1- px1) + (qy1 - py1)) + 2*((qx2-px2) + (qy2 - py2)) - 2*(overlap_xlength + overlap_ylength);
		}else{
			total_length = 2*((qx1- px1) + (qy1 - py1)) + 2*((qx2-px2) + (qy2 - py2));
		}
		total_width = ((qx1- px1) * (qy1 - py1)) + ((qx2-px2) * (qy2 - py2)) - overlap_width;

		cout << total_width << " " << total_length << endl;
	}
	return 0;
}