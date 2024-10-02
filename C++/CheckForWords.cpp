#include <iostream>
#include <string>
using namespace std;

int main() {

	int num;
	cout<<"Enter Integer number"<<endl;
	cin>>num;
	string stinput= to_string(num);

	for(int x=0; x<stinput.length(); x++) {
		(stinput.length()==2) {
			string a=" ";
			for(char digit : stinput) {
					 a+=digit;
				for(char dig : stinput) {

				 a+=dig;
				}
				cout<<"starting is "<<a<<endl;
			}
		}
	}
	return 0;
}