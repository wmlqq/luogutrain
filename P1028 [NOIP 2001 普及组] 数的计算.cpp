#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>dp(n+1,0);//dp[i]表示对于i有多少合法数列
    dp[1]=1;
    dp[0]=0;
    for(int i=2;i<n+1;i++){
        dp[i]=1;
        for(int j=1;j<=i/2;j++){
            dp[i]+=dp[j];
        }
    }
    cout<<dp[n];
    return 0;
}