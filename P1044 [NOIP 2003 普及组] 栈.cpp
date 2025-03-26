#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> memo; // 记忆化缓存

long long change(int r, int s) {
    if (r == 0) return 1; // 终止条件
    if (memo[r][s] != -1) return memo[r][s]; // 直接返回缓存值
    
    long long res;
    if (s == 0) {
        res = change(r - 1, s + 1);
    } else {
        res = change(r - 1, s + 1) + change(r, s - 1);
    }
    
    memo[r][s] = res; // 保存结果到缓存
    return res;
}

int main() {
    int n;
    cin >> n;
    memo.resize(n + 1, vector<long long>(n + 1, -1)); // 初始化缓存为-1
    cout << change(n, 0);
    return 0;
}