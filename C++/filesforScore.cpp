#include <iostream>
#include <fstream>
using namespace std;
void score(char points){
	  
	cout<<"~~~~Updating score~~~~"<<endl;
	ofstream obj("score.txt",ios::app);
	obj<<points;
	obj.close();
	
	char arr1[100];
	fstream obj1("score.txt");
	obj1.getline(arr1,100);
	cout<<"~~~Scores are~~~"<<arr1<<endl;
	obj1.close();
	
	fstream file("score.txt");
	if(!file.is_open()){
		cerr<<"*****Error showing scores*****"<<endl;
	}	
	char c;
	int p1=0,p2=0;
	while(file.get(c)){
		if(c=='0')
		p1++;
		if(c=='1')
		p2++;
	}
	cout<<"Player 1 score= "<<p1<<endl;
	cout<<"Player 2 score= "<<p2<<endl;
	file.close();
}

int main(){
	char a='1',point;
	if (a== 'O') {
				cout << "\n Player 1 wins! \n";
				point='1';
				score(point);
			} else {
				cout << "\n Player 2 wins! \n";
				point='0';
				score(point);
			}
	
	return 0;
}