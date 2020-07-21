//问题描述：给定区间0 ~ N，求每个数字的二进制位中的1的个数
//思路：
//  1.每个数字的最后一位一定是 0 或 1，去掉最后一位，求剩余位的1的个数
//  2.就相当于
//      f[i] = (f[i] & 1) + f[i >> 2];

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n){
    vector<int> ret(n + 1, 0);
    for(int i = 1;i <= n;++i){
        ret[i] = (i & 1) + ret[i >> 1];
    }
    return ret;
}

void Print(vector<int>& v){
    int j = 0;
    for(auto i : v){
        cout << i << " ";
        if(++j % 10 == 0){
            cout << endl;
        }
    }
    cout << endl;
}

int main(){
    int n = 100;
    vector<int> ret = countBits(n);
    Print(ret);
    int a = 100;
    printf("%p\n",a);
    return 0;
}