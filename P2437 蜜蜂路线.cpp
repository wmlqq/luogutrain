#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>first(1500,0);
    vector<int>second(1500,0);
    second[0]=1;
    int m,n;
    cin>>m>>n;
    int N=n-m;
    while(N!=0){
        int temp=0;
        for(int i=0;i<1500;i++){
            int add=first[i]+second[i]+temp;
            first[i]=second[i];
            second[i]=add%10;
            temp=add/10;
        }
        N--;
    }
    int i;
    for( i=second.size()-1;i>=0;i--){
        if(second[i]!=0)break;
    }
    while(i>=0){
        cout<<second[i];
        i--;
    }
    return 0;

}