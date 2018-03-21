//
// Created by aei on 2018/3/21.
//





/**
题目大概是，

有一个魔方，上  黄色 | 下  橙色  | 左  绿色 |  右  绿色 | 前 橙色 | 后 黄色

问魔方总共有多少种状态。

我的答案：216

我的思路：刚拿到这题有点懵逼，简单分析了一下，其实魔方总共八块，这八块其实就三种颜色

4块是绿黄橙，2块是绿橙橙，2块是绿黄黄。

我们就可以把该题简化为四个1，两个2，两个3的排序问题。

需要注意的是11112233和33221111是一样的。

代码如下：

**/

#include<cstdio>
#include<algorithm>
#include <string>
#include <set>

using namespace std;
string s = "11112233";
set<string> se;

string re(string s) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        t += s[s.size() - 1 - i];
    }
    return t;
}


int main() {
    int sum = 0;
    do {
        if (!se.count(s) && !se.count(re(s))) {
            se.insert(s);
        }

        //se.insert(re(s));
    } while (next_permutation(s.begin(), s.end()));
    printf("%d", se.size());


    return 0;
}
