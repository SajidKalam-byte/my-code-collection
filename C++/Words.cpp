#include <iostream>
#include <string>
using namespace std;
string ar1[21]= {" zero","one","two","three","four","five","six","seven","eight","nine","ten",
                 "eleven","twelve","thirteen","fourteen","fifteen","sixteen",
                 "seventeen","eighteen","nineteen","twenty"};

string ar3[10]= {"","","","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
//string stinput= to_string(input);
string result=" ";
void words(int input) {
	if (input >= 10000) {
		if((input/1000)> 9 && (input/1000) <=20) {

			result += ar1[input / 1000]; // Handle tens of thousands
			input %= 10000;
		} else if((input/1000)>20) {

			result += ar3[input / 1000]; // Handle tens of thousands
			input %= 10000;
		}
	}
	if (input >= 1000) {
		result += " " + ar1[input / 1000] + " thousand";
		input %= 1000;
	}
	if (input > 0) {
		result += " ";
	}


	if(input>=1000) {
		result+=ar1[input/1000]+" thousand";
		input%=1000;
		if(input>0) {
			result+=" ";
		}
	}
	if(input>=100) {//754
		result+=ar1[input/100]+ " hundred ";
		input%=100;
		if(input>0) {
			result+=" and ";
		}
	}
	if(input>=20) {
		result+=ar3[input/10];
		input%=10;
		if(input>0) {
			result+=" ";
		}
	}
//	if(input>10) {
//		result+=ar1[input-10];
//	}
	if(input>=0 && input<=20) {
		result+=ar1[input];
	}
	cout <<result<<endl;
}

int main() {
	int num;
	cout<<"Enter Integer number"<<endl;
	if(cin>>num) {
		words(num);
	} else
		cout<<"Enter valid integer"<<endl;
	return 0;
}