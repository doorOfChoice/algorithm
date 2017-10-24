#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <ctype.h>
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#define FILE_IN "D:\\linuxshare\\c\\algorithm\\data.in"
#define FILE_OUT "D:\\linuxshare\\c\\algorithm\\data.out"
using namespace std;
bool valid(char ch) {
    return (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z');
}

void run()
{
    string s,t;
    int len=0;
    int maxl=0,maxr=0;
    while(getline(cin, t))s+=t+'\n';
    for (int i = 0, size = s.size(); i < size; i++){
        if(valid(s[i])) {
            int vl = i,vr = i + 1;
            int count = 1;
            for(int l = i-1, r = i+1; l >= 0 && r < size; ) {
                if(!valid(s[l])){l--;continue;}
                if(!valid(s[r])){r++;continue;}
                
                if(tolower(s[l]) != tolower(s[r]))
                    break;
                else {
                    vl = l;
                    vr = r ;
                    count+=2;
                }
                l--;r++;
            }
            if(count > len) {
                len = count;
                maxl = vl;
                maxr = vr;
            }
        }
    }
    cout << len << endl;
    cout << s.substr(maxl, maxr-maxl + 1) << endl;
}
int main()
{
    freopen(FILE_IN, "r", stdin);
    freopen(FILE_OUT, "w", stdout);
    run();
}

/*
1061: [USACO 1.3.3]Calf Flac

时间限制: 1 Sec  内存限制: 64 MB

题目描述

据说如果你给无限只母牛和无限台巨型便携式电脑(有非常大的键盘),那么母牛们会制造出世上最棒的回文。你的工作就是去这些牛制造的奇观(最棒的回文)。在寻找回文时不用理睬那些标点符号、空格(但应该保留下来以便做为答案输出),只用考虑字母'A'-'Z'和'a'-'z'。要你寻找的最长的回文的文章是一个不超过20,000个字符的字符串。我们将保证最长的回文不会超过2,000个字符(在除去标点符号、空格之前)。
输入

一个不超过20,000个字符的文件。
输出

输出的第一行应该包括找到的最长的回文的长度。下一个行或几行应该包括这个回文的原文(没有除去标点符号、空格), 把这个回文输出到一行或多行(如果回文中包括换行符)。如果有多个回文长度都等于最大值,输出那个前出现的。
样例输入

Confucius say: Madam, I'm Adam.
样例输出

11
Madam, I'm Adam

=================
水题一枚。遍历字符串，从一个字符往两边延伸判断.
*/