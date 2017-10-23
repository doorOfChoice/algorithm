#include <stdio.h>
#include <memory.h>
#define N 1000005
int time[N] = {0};
int max(int a, int b) {
    return a > b ? a : b;
}
void run()
{
    int prevl, max_have, max_none, n;
    while(scanf("%d", &n) != EOF)
    {
        prevl = max_have = max_none = 0;
        memset(time, 0, sizeof(time));
        for (int i = 0; i < n; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            time[l] = max(r, time[l]);
        }

        for (int i = 0, count = 0; i < N; i++) {
            if (time[i] != 0) {
                if (!count++) {
                    prevl = i;
                    max_have = time[prevl] - prevl;
                }else {
                    if (i <= time[prevl]) {
                        if (time[i] > time[prevl]) {
                            time[prevl] = time[i];
                            max_have = max(time[prevl] - prevl, max_have);
                        }
                    }else {
                        max_none = max(i - time[prevl], max_none);
                        max_have = max(time[i] - i, max_have);
                        prevl = i;
                    }
                }
            }
        }
        printf("%d %d\n", max_have, max_none);
    }
}
int main()
{
    freopen("D:\\linuxshare\\c\\algorithm\\data.in", "r", stdin);
    freopen("D:\\linuxshare\\c\\algorithm\\data.out", "w", stdout);
    run();
}

/**
奶牛問題
Three farmers rise at 5 am each morning and head for the barn to milk three cows. The first farmer begins milking his cow at time 300 (measured in seconds after 5 am) and ends at time 1000. The second farmer begins at time 700 and ends at time 1200. The third farmer begins at time 1500 and ends at time 2100. The longest continuous time during which at least one farmer was milking a cow was 900 seconds (from 300 to 1200). The longest time no milking was done, between the beginning and the ending of all milking, was 300 seconds (1500 minus 1200).

Your job is to write a program that will examine a list of beginning and ending times for N (1 <= N <= 5000) farmers milking N cows and compute (in seconds):

The longest time interval at least one cow was milked.
The longest time interval (after milking starts) during which no cows were being milked.
Input
This problem contains several cases. 
Line 1: The single integer 
Lines 2..N+1: Two non-negative integers less than 1000000, the starting and ending time in seconds after 0500
Output
A single line with two integers that represent the longest continuous time of milking and the longest idle time.

Sample Input
3
300 1000
700 1200
1500 2100

Sample Output
900 300
**/

/**
 這道題很簡單：
    1.如果本次區間的左邊小於等於上次最大的區間的右邊,則判斷本次的右邊是否比上次的右邊大
    大則更新最大區間的右邊,和更新最大區間
    2.如果本次區間左邊大於最大區間的右邊，則更新最大區間的右邊、更新最大無人擠奶區間、最大有人擠奶區間
 總結:
 但是自己做這道題的時候自己給自己挖了一個坑,因爲左值是用數組下標，右值用的數組的值
 以至於錄入的時候沒考慮到一種情況: 左值相等.
**/