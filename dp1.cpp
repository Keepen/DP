//问题描述：
//  在数组中，选取不相邻的数字，求出最大和
//由于本问题是重叠子问题，可以使用递归 / 动态规划
//  但是递归可能会造成时间开销过大，所以再实现一个非递归版本

//思路：
//  要还是不要原则：
//  1）如果要当前数字     ：由于是不相邻，所以就变成了v[i] + ret[i - 2];
//             即：当前数字 + 前i - 2个中不相邻最大数字的和    
//  2）如果不要当前数字   ：ret[i - 1]
//             即：前i - 1个中不相邻的最大数字的和

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//表示，在数组v中，到达下标为i的最佳方案是什么
int rec_opt(vector<int>& v, int i){
    if(i == 0){
        return v[0];
    }
    else if(i == 1){
        return max(v[0], v[1]);
    }
    else{
        //选
        int a = rec_opt(v, i - 2) + v[i];
        //不选  
        int b = rec_opt(v, i - 1);
        return max(a,b);
    }
}

//非递归版本
int unrec_opt(vector<int>& v){
    vector<int> ret(v.size(),0);
    ret[0] = v[0];
    ret[1] = max(v[0], v[1]);
    for(int i = 2;i < v.size();++i){
        //要    ：v[i] + v[i - 2]
        //不要  ：v[i - 1]
        ret[i] = max(v[i] + ret[i - 2], ret[i - 1]);
    }
    return ret[v.size() - 1];
}

void solu(){
    vector<int> v = {1,2,4,1,7,8,3};
    vector<int> v2 = {4,1,1,9,1};
    int n;
    cout << rec_opt(v, v.size() - 1) << endl;
    cout << unrec_opt(v2) << endl;
}


int main(){
    solu();
    return 0;
}