#include<iostream>
#include<vector>
using namespace std;

void soluntion(int num){
	if(num==0){
		cout<<"0";
		return;
	}
	if(num==1){
		cout<<"2(0)";
		return;
	}
	if(num==2){
		cout<<"2";
		return;
	}

	int temp=0;
	int count=1;
	while(count*2<=num){
		count*=2;
		temp++;
	}
	if(temp==1)cout<<"2";
	else{
	cout<<"2(";
	soluntion(temp);
	cout<<")";
	}
	if(count!=num){
		cout<<"+";
		soluntion(num-count);
	}
}

int main(){
	int n;
	cin>>n;
	soluntion(n);
	return 0;
}