#include<vector>
#include<iostream>
using namespace std;

int main(){
    int r;
    cin>>r;
    vector<int>nums(r*(r+1)/2,0);
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    vector<int>dp(r*(r+1)/2,0);//dp[i]表示从起点到第i个节点的最大和
    int rd=1;
    dp[0]=nums[0];
    for(int i=1;i<r*(r+1)/2;i++){
        if(i==rd*(rd+1)/2){
            dp[i]=nums[i]+dp[i-rd];
            continue;
        }
        if(i==(rd+1)*(rd+2)/2-1){
            dp[i]=nums[i]+dp[i-rd-1];
            rd++;
            continue;
        }
        dp[i]=nums[i]+max(dp[i-rd],dp[i-rd-1]);
    }
    int res=0;
    for(int i=(r-1)*r/2;i<r*(r+1)/2;i++){
        res=max(res,dp[i]);
    }
    cout<<res;
    return 0;
}