#include<iostream>
#include<string>
using namespace std;

string open(){
    int k;
    char c;
    string s="",coding="";

    while(cin>>c){
        if(c=='['){
            cin>>k;
            coding=open();
            for(int i=0;i<k;i++)s+=coding;
        }
        else if(c==']')return s;
        else s+=c;
    }
    return s;
}

int main(){
    cout<<open();
    return 0;
}