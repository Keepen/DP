#include <iostream>
#include <string>
#include <vector>
using namespace std;
//问题描述：
// 一条包含字母 A-Z 的消息通过以下方式进行了编码：
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// 给定一个只包含数字的非空字符串，请计算解码方法的总数。

// 示例 1:
// 输入: "12"
// 输出: 2
// 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

//思路：
//  1.定义状态f[i]表示前i个字符的解码方式数目
//      f[i] = f[i - 1] + f[i - 2];

int decodeWays(string& ss){
    size_t len = ss.size();
    if(len <= 1){
        return 1;
    }
    vector<int> ret(len + 1, 0);
    ret[0] = 1;
    int num = 0;
    for(size_t i = 1;i <= len;++i){
        if(ss[i - 1] >= '1' && ss[i - 1] <= '9'){
            ret[i] += ret[i - 1];
        }
        if (i > 1) {
            num = 10 * (ss[i - 2] - '0') + (ss[i - 1] - '0');
            if (num >= 10 && num <= 26) {
                ret[i] += ret[i - 2];
            }
        }
    }
    return ret[len];
}

int main(){
    string ss = "12";
    cout << decodeWays(ss) << endl;
    return 0;
}