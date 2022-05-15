#include <iostream>

using namespace std;

int my_strlen(const char *str){
	int i;
	for(i = 0; *str != 0; i++, str++);
	return i;
}
char *my_strcpy(char *d, const char *s){
	char *r = d;
	for(; *s; s++){
		*r++ = *s;
	}
	*r = '\0';
	return d;
}
char *my_strcat(char *d, const char*s){
	char *r = d;
	for(; *r; r++);
	for(; *s; s++){
		*r++ = *s;
	}
	*r = '\0';
	return d;
}

int main(){
	char s1[10], s2[10] = "xxx";
	//s1 = "12";

	my_strcpy(s1, "12");
	cout<< "length of " << s1 << " is " << my_strlen(s1) << endl;
	//s2 = s1 + "ab";
	my_strcpy(s2, s1);
	my_strcat(s2, "ab");
	cout << "length of " << s2 << " is " << my_strlen(s2) << endl;
}

