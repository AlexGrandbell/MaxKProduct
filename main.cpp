#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//最大k乘积问题
//设I是一个n位十进制整数I。如果将I划分为k段，则可得到k个整数。这k个整数的乘积称为I的一个k乘积。试设计一个算法，对于给定的I、n和k，求出I的最大k乘积。
//以下函数使用动态规划法实现该算法
int max_k_product(int I,int n, int k) {
    //创建一个二维数组dp，dp[i][j]表示将i位整数划分为j段的最大乘积
    vector<vector<int>> dp(n, vector<int>(k, -1));
    //初始化dp数组划分为1时是前i个数字本身
    for (int i = 1; i <= n; i++) {
        dp[i][0] = I / pow(10, n - i);
    }




//    //创建一个二维数组dp，dp[i][j]表示将i位整数划分为j段的最大乘积
//    int dp[10][10] = {0};
//    //初始化dp数组
//    for (int i = 0; i < n; i++) {
//        dp[i][1] = I / (int)pow(10, n - i - 1);
//    }
//    //动态规划求解dp数组
//    for (int i = 1; i < n; i++) {
//        for (int j = 2; j <= k; j++) {
//            for (int m = 0; m < i; m++) {
//                dp[i][j] = max(dp[i][j], dp[m][j - 1] * (I % (int)pow(10, n - i) / (int)pow(10, n - i - m)));
//            }
//        }
//    }
//    return dp[n - 1][k];

}

int main() {
    //输入
    int n, k,I;
    cin >> n >> k >> I;
    //输出I的最大k乘积
    cout << max_k_product(I,n, k) << endl;
    return 0;
}
