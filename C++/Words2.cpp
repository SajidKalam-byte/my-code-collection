#include<iostream>
#include<string.h>
using namespace std;
int input;
string ar1[21]= {" zero","one","two","three","four","five","six","seven","eight","nine","ten",
                 "eleven","twelve","thirteen","fourteen","fifteen","sixteen",
                 "seventeen","eighteen","nineteen","twenty"
                };

string ar3[10]= {"","","","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string result=" ";
void thousands(int input) {

}
void hundreds(int input) {

}
void tens(int input) {

}
void ones(int input) {
	if(input>=0 && input<=20) {
		result+=ar1[input];
	}
	cout<<result<<endl;
}

void word(int input) {
	if((input>=0 && input<=20))
		ones(input);
}
int main() {
	cout<<"Enter Integer number "<<endl;
	cin>>input;
	   word(input);
	return 0;
}