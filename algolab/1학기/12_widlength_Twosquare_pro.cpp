#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
	int t, px, py, qx, qy;
	int ax, ay, bx, by;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> px >> py >> qx >> qy;
		cin >> ax >> ay >> bx >> by;

		int len_p_qx = qx - px; int len_p_qy = qy - py;
		int len_a_bx = bx - ax; int len_a_by = by - ay;

		int height, base;

		if(ax > qx || ay > qy || px > bx || py > by){
			cout << (len_p_qx * len_p_qy) + (len_a_bx * len_a_by) << " ";
			cout << 2*(len_p_qx + len_p_qy + len_a_bx + len_a_by) << endl;
		}
		else{
			base = min(bx, qx) - max(ax, px);
			height = min(by, qy) - max(ay, py);
			cout << (len_p_qx * len_p_qy) + (len_a_bx * len_a_by) - base*height << " ";
			cout << 2*(len_p_qx + len_p_qy + len_a_bx + len_a_by) - 2*(height + base) << endl;
		}
	}
	return 0;

}
