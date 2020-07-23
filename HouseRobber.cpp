//问题描述：
//  一排房子N个，第i个房子中有A[i]个金币
//  不能偷紧挨着两家，求最大能偷的金币数目

//思路：
//   最优策略中的最后一步一定是在选择 最后一栋房子偷或者不偷
//   不偷：f[n - 1]
//   偷：  f[n - 1] && 倒数第二栋房子不偷
//  f[i][0] -- 不偷房子i - 1的情况下，前i栋房子中最多能够偷多少金币
//  f[i][1] -- 偷房子i - 1的前提下，前i栋房子中最多能投多少金币
//  f[i][0] = max(f[i - 1][0], f[i - 1][1]);    房子i - 2偷 / 不偷
//  f[i][1] = f[i - 1][0] + a[i - 1];           房子i - 2必须不能偷

//优化：最后一个房子 不偷         偷（前i - 2栋房子 + 最后一栋房子的金币值）
//  f[i] = max(f[i - 1], f[i - 2] + a[i - 1]);
//  初始值：
//  f[0] = 0;
//  f[1] = a[1];
//  f[2] = max(a[0], a[1]);

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//滚动数组做法
long houseRobber2(vector<int>& A){
    int n = A.size();
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return A[0];
    }
    long old, now;
    old = A[0];
    now = max(A[0], A[1]);
    for(int i = 3;i <= n;++i){
        long t = max(now, old + A[i - 1]);
        old = now;
        now = t;
    }
    return now;
}


long houseRobber(vector<int>& A){
    int n = A.size();
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return A[0];
    }
    vector<int> f(n + 1, 0);
    f[0] = 0;
    f[1] = A[0];
    f[2] = max(A[0], A[1]);
    for(int i = 3;i < n + 1;++i){
        f[i] = max(f[i - 1], f[i - 2] + A[i - 1]);
    }
    return f[n];
}

int main(){
    return 0;
}
