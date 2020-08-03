//问题描述：
// 667. 最长的回文序列
// 中文English
// 给一字符串 s, 找出在 s 中的最长回文子序列的长度. 你可以假设 s 的最大长度为 1000.

// 样例
// 样例1

// 输入： "bbbab"
// 输出： 4
// 解释：
// 一个可能的最长回文序列为 "bbbb"
// 样例2

// 输入： "bbbbb"
// 输出： 5

//思路：
//  1.不去设置一个函数来判断是否是回文串
//  2.利用制造回文串的方式去判断是否是回文串
//  f[i][j] -- 表示[i, j]间最长的回文子序列
//  初始化 -- f[i][i] = 1  每一个字符就是一个回文串


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        // write your code here
        int n = (int)s.size();
        if(n < 2){
            return n;
        }
        vector<vector<int>> v(n, vector<int>(n, 1));
        //打印最长的那个回文串
        vector<vector<int>> pi(n, vector<int>(n, 0));


        int len = 3;
        //长度为2时能否成为回文串
        for(int i = 0;i < n - 1;++i){
            if(s[i] == s[i + 1])
                v[i][i + 1] = 2;
        }

        int j  = 0;
        while(len <= n){
            for(int i = 0;i <= n - len;++i){
                j = i + len - 1;
                //              去头        去尾
                v[i][j] = max(v[i + 1][j], v[i][j - 1]);
                if(v[i][j] == v[i + 1][j]){
                    pi[i][j] = 0;
                }
                if(v[i][j] == v[i][j - 1]){
                    pi[i][j] = 1;
                }
                if(s[i] == s[j]){
                    v[i][j] = max(v[i][j], v[i + 1][j - 1] + 2);
                    if(v[i][j] == v[i + 1][j - 1] + 2){
                        pi[i][j] = 2;
                    }
                }
            }
            ++len;
        }
        string ret(v[0][n - 1], '1');
        int p = 0, q = v[0][n - 1] - 1;
        int i = 0;
        j = n - 1;
        while(i <= j){
            //长度是1
            if(i == j){
                ret[p] = s[i];
                break;
            }
            //长度是2
            if(i + 1 == j){
                ret[p] = s[i];
                ret[q] = s[j];
                break;
            }
            //去掉头得到的回文串
            if(pi[i][j] == 0){
                ++i;
            }
            else{
                //去掉尾得到的回文串
                if(pi[i][j] == 1){
                    --j;
                }
                //去掉头与尾得到的回文串
                else{
                    ret[p++] = s[i];
                    ret[q--] = s[j];
                    ++i;
                    --j;
                }
            }
        }

        for(int i = 0;i < v.size();++i){
            for(int k = 0;k < v[0].size();++k){
                cout << v[i][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 0;i < n;++i){
            for(int k = 0;k < n;++k){
                cout << pi[i][k] << " ";
            }
            cout << endl;
        }


        for(auto i : ret){
            cout << i;
        }
        cout << endl;
        return v[0][n - 1];
    }
};

int main(){
    Solution s;
    string str = "bbbbab";
    cout << s.longestPalindromeSubseq(str) << endl;
    return 0;
}