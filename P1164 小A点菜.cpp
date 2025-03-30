#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;//n表示菜品种类，m表示身价
    cin>>n>>m;
    vector<int>dp(m+1,0);
    dp[0]=1;
    int price;

    while(cin>>price){
        for(int i=m;i>=price;i--){
            dp[i]+=dp[i-price];
        }
    }

    cout<<dp[m];
    return 0;
}