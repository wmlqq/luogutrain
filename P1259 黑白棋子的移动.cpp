#include<iostream>
#include<vector>
using namespace std;

void printS(vector<int>s){
	for(int num:s){
		if(num==1)cout<<'o';
		else if(num==2)cout<<'*';
		else cout<<'-';
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int>s(n,1);
	s.insert(s.end(),n,2);
	s.insert(s.end(),2,0);
	int index0=2*n;
	int mid=n-1;
	printS(s);
	s[index0]=1;
	s[index0+1]=2;
	s[mid]=0;
	s[mid+1]=0;
	printS(s);
	index0-=2;

	while(index0>7){
		s[index0]=0;
		s[index0+1]=0;
		s[mid]=2;
		s[mid+1]=2;
		mid-=1;
		printS(s);

		s[index0]=1;
		s[index0+1]=2;
		s[mid]=0;
		s[mid+1]=0;
		index0-=2;
		printS(s);

	}

	vector<int>news(s.begin()+9,s.end());
	cout<<"ooo*o**--";
	printS(news);
	cout<<"o--*o**oo";
	printS(news);
	cout<<"o*o*o*--o";
	printS(news);
	cout<<"--o*o*o*o";
	for(int num:news){
		if(num==1)cout<<'o';
		else if(num==2)cout<<'*';
		else cout<<'-';
	}
	return 0;
	
}