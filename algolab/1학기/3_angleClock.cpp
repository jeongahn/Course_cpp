#include <iostream>

using namespace std;

int angleClock(int h, int m){
	double h_Angle = (h * 30) + (m*0.5);
	double m_Angle = m * 6;
	double  bt_Angle;
	if(h_Angle > m_Angle){
		bt_Angle = h_Angle - m_Angle;
	}else if(h_Angle < m_Angle){
		bt_Angle = m_Angle - h_Angle;
	}else if(h_Angle == m_Angle){
		bt_Angle = 0;
	}
	if(bt_Angle > 180){
			bt_Angle = 360 - bt_Angle;
	}

	return int(bt_Angle); // 혹은 (int)bt_Angle
	/*
	float hour, minute, angle;
	hour = (360/12)*h + (360/12)*((float)m/60);
	minute = (360/60)*m;

	angle= abs(hour-minute);

	if (angle > 180){
		angle = 360-angle;
	}
	return angle;
	*/
}

int main(void){
	int t;
	int h, m;
	
	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> h >> m;
		cout << angleClock(h, m) << endl;
	}

	return 0;
}
