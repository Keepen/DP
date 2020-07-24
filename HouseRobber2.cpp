//问题描述：
//  与HouseRobber类似，不过这次是一圈房子，
//  即最后移动房子不能和第一栋房子同时偷
//  不能偷紧挨着两家，求最多能投多少金币

//思路：
//  由于房子0和房子N - 1不饿能同时偷
//  那就两种情况 -- 去掉房子0时的最有策略；去掉房子N - 1时的最优策略

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int calc(vector<int>& v){
    int n = v.size();
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return v[0];
    }
    int old = 0;        //不偷房子，最大就是0
    int now = v[0];     // 偷前1栋房子，最大就是第一栋房子的价值  
    for(int i = 2;i <= n;++i){
        int t = max(now, old + v[i - 1]);
        old = now;
        now = t;
    }
    return now;
}

int HouseRobber2(vector<int>& v){
    int n = v.size();
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int ret = INT_MIN;
    vector<int> s1(v.begin() + 1, v.end());
    vector<int> s2(v.begin(), v.end() - 1);
    ret = max(calc(s1), calc(s2));
    return ret;
}

int main(){
    return 0;
}

