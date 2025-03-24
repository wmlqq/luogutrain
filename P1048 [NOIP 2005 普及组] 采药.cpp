#include<iostream>
#include<vector>
using namespace std;
int main(){
    int M,T;
    cin>>T>>M;
    vector<int>dp(T+1,0);
    int time,value;
    for(int i=0;i<M;i++){
        cin>>time>>value;
        for(int j=T;j>=time;j--){
            dp[j]=max(dp[j],dp[j-time]+value);
        }
    }
    cout<<dp[T];
    return 0;
}