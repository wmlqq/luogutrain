#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int index=0;
    vector<int>face;
    vector<string>name;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        face.push_back(num);
        string nam;
        cin>>nam;
        name.push_back(nam);
    }
    for(int i=0;i<m;i++){
        int f,s;
        cin>>f>>s;
        int a=f^face[index];
        if(a==1)index+=s;
        if(a==0)index-=s;
        while(index<0)index+=n;
        while(index>=n)index-=n;
    }
    cout<<name[index];
    return 0;
}