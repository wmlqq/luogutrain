#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n, m; // 目标点 B 的坐标
    int x, y; // 马的坐标
    cin >> n >> m >> x >> y;

    // 初始化 dp 数组
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    dp[0][0] = 1; // 起点

    // 计算马的控制点
    vector<vector<bool>> blocked(n + 1, vector<bool>(m + 1, false));
    int horseMoves[8][2] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, 
                             {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
    
    // 标记马的控制点
    blocked[x][y] = true; // 马的位置
    for (auto move : horseMoves) {
        int nx = x + move[0];
        int ny = y + move[1];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            blocked[nx][ny] = true;
        }
    }

    // 填充 dp 数组
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (blocked[i][j]) {
                dp[i][j] = 0; // 如果是控制点，路径数为 0
            } else { 
                if (i > 0) dp[i][j] += dp[i - 1][j]; // 从上方来
                if (j > 0) dp[i][j] += dp[i][j - 1]; // 从左方来
            }
        }
    }

    // 输出结果
    cout << dp[n][m] << endl;

    return 0;
}