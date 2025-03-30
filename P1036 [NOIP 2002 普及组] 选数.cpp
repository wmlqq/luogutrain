#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

bool isprime(long long n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int choosek(vector<int>nums,int index,int k,int add){
    if(k==0)return isprime(add)?1:0;
    if(nums.size()-index<k)return 0;
    return choosek(nums,index+1,k-1,add+nums[index])+choosek(nums,index+1,k,add);
    
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    cout<<choosek(nums,0,k,0);
    return 0;
    
}