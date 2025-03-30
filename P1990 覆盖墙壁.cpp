#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(max(n+1,3),0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<n+1;i++){
        dp[i]=(2*dp[i-1]+dp[i-3])%10000;
    }
    cout<<dp[n];
    return 0;
}