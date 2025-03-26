#include<iostream>
#include<vector>
using namespace std;

vector<vector<vector<long long>>>memo(21,vector<vector<long long>>(21,vector<long long>(21,-1)));

long long function(long long a,long long b,long long c){
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return function(20,20,20);
    if(memo[a][b][c]!=-1)return memo[a][b][c];
    if(a<b&&b<c){
        long long res=function(a,b,c-1)+function(a,b-1,c-1)-function(a,b-1,c);
        memo[a][b][c]=res;
        return res;
    }
    else {
        long long res=function(a-1,b,c)+function(a-1,b-1,c)+function(a-1,b,c-1)-function(a-1,b-1,c-1);
        memo[a][b][c]=res;
        return res;
    }
}


int main(){
    while(1){
        long long a,b,c;
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<function(a,b,c)<<endl;
    }
    return 0;
}