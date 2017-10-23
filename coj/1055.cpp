#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
using namespace std;
#define FILE_IN "D:\\linuxshare\\c\\algorithm\\data.in"
#define FILE_OUT "D:\\linuxshare\\c\\algorithm\\data.out"

void print(string s[10], int n) {
    for(int i = 0; i < n; i++)
        cout << s[i] << endl;
    cout << endl;
}

bool equal(string a[10], string b[10], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                return 0;
    return 1;
}

bool rotate90(string s[10], string cmp[10], int n, int times)
{
    string t[10];
    for(int i = 0; i < n; i++)
        t[i] = s[i];
    while (times--)
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j <= n - i - 2; j++)
            {
                char temp = t[i][j];
                t[i][j] = t[n - j - 1][i];
                t[n - j - 1][i] = t[n - i - 1][n - j - 1];
                t[n - i - 1][n - j - 1] = t[j][n - i - 1];
                t[j][n - i - 1] = temp;
            }
        }
    }
    return equal(t, cmp, n);
}

bool reflect(string s[10], string cmp[10], int n, bool combine) {
    string t[10];
    for(int i = 0; i < n; i++)
        t[i] = s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n / 2; j++) {
            char ch = t[i][j];
            t[i][j] = t[i][n - j - 1];
            t[i][n - j - 1] = ch;
        }
    }
    // print(t, n);
    if(combine) {
        return rotate90(t, cmp, n, 1) ||
               rotate90(t, cmp, n, 2) ||
               rotate90(t, cmp, n, 3);
    }
    return equal(t, cmp, n);
}

void run()
{
    string s[10], t[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    if(rotate90(s, t, n, 1)) {
        cout << "1" << endl;
    }else if(rotate90(s, t, n, 2)) {
        cout << "2" << endl;
    }else if(rotate90(s, t, n, 3)) {
        cout << "3" << endl;
    }else if(reflect(s, t, n, false)) {
        cout << "4" << endl;
    }else if(reflect(s, t, n, true)) {
        cout << "5" << endl;
    }else if(equal(s, t, n)) {
        cout << "6" << endl;
    }else {
        cout << "7" << endl;
    }
    
    
}
int main()
{
    freopen(FILE_IN, "r", stdin);
    freopen(FILE_OUT, "w", stdout);
    run();
}

/**
1055: [USACO 1.2.2]方块转换
时间限制: 1 Sec  内存限制: 64 MB
题目描述

一块N x N（1<=N<=10）正方形的黑白瓦片的图案要被转换成新的正方形图案。写一个程序来找出将原始图案按照以下列转换方法转换成新图案的最小方式： #1：转90度：图案按顺时针转90度。 #2：转180度：图案按顺时针转180度。 #3：转270度：图案按顺时针转270度。 #4：反射：图案在水平方向翻转（形成原图案的镜像）。 #5：组合：图案在水平方向翻转，然后按照#1-#3之一转换。 #6：不改变：原图案不改变。 #7：无效转换：无法用以上方法得到新图案。如果有多种可用的转换方法，请选择序号最小的那个。
输入

第一行： 单独的一个整数N。 第二行到第N+1行： N行每行N个字符（不是“@”就是“-”）；这是转换前的正方形。 第N+2行到第2*N+1行： N行每行N个字符（不是“@”就是“-”）；这是转换后的正方形。
输出

单独的一行包括1到7之间的一个数字（在上文已描述）表明需要将转换前的正方形变为转换后的正方形的转换方法。
样例输入

3
@-@
---
@@-
@-@
@--
--@
样例输出

1
=====================
這道題主要考察矩形旋轉，而無其他難點就是代碼可能會堆的多一點.
如何順時針旋轉一個矩陣?
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
先旋轉
[1]   2  3  [4]
5     6  7   8
9    10 11  12
[13] 14 15 [16]
再旋轉
1   [2]  3   4
5   6    7  [8]
[9] 10  11  12
13  14 [15] 16
最後旋轉
1    2  [3]  4
[5]  6   7   8
9   10  11  [12]
13 [14] 15  16
**/