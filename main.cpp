//问题描述
//设I是一个n位十进制整数。如果将I划分为k段，则可得到k个整数。这k个整数的乘积称为I的一个k乘积。试设计一个算法，对于给定的I和k，求出I的最大k乘积。
//例如十进制整数 1234 划分为 3 段可有如下情形：
//1 × 2 × 34 = 68
//1 × 23 × 4 = 92
//12 × 3 × 4 = 144
//
//编程任务
//对于给定的I 和k，编程计算I 的最大k 乘积。
//
//数据输入
//输入的第1 行中有2个正整数n和k。正整数n是序列的长度；正整数k是分割的段数。接下来的一行中是一个n位十进制整数。（n<=10）
//
//结果输出
//计算出的最大k乘积。
//
//输入示例
//3 2
//312
//
//输出示例
//62
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//获取一个整数的位数
int lengthOfInt(int num) {
    int len = 0;
    while (num) {
        num /= 10;
        len++;
    }
    return len;
}

//获取一个整数的前n位数
int frontN(int num, int n) {
    n = lengthOfInt(num) - n;
    return num / pow(10, n);
}

//获取一个整数的后n位数
int backN(int num, int n) {
    return num % (int)pow(10, n);
}

//获取一个整数的n到m位
int middleN(int num, int n, int m) {
    num = backN(num, lengthOfInt(num)-n+1);
    return frontN(num, m-n+1);
}

//最大k乘积问题
//设I是一个n位十进制整数I。如果将I划分为k段，则可得到k个整数。这k个整数的乘积称为I的一个k乘积。试设计一个算法，对于给定的I、n和k，求出I的最大k乘积。
//以下函数使用动态规划法实现该算法
int max_k_product(int I,int n, int k) {
    //创建一个二维数组dp，dp[i][j]表示将i位整数划分为j段的最大乘积
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    //初始化dp数组划分为1时是前i个数字本身
    for (int i = 1; i <= n; i++) {
        dp[i][1] = frontN(I, i);
    }
    //动态规划求解dp数组
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k && j <= i; j++) {
            for (int m = j-1; m <= i; m++) {
                dp[i][j] = max(dp[i][j], dp[m][j - 1] * middleN(I,m+1,i));
            }
        }
    }
    return dp[n][k];

}

int main() {
    //输入
    int n, k,I;
    cin >> n >> k >> I;
    //输出I的最大k乘积
    cout << max_k_product(I,n, k) << endl;
    return 0;
}
