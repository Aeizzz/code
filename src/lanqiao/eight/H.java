package lanqiao.eight;

import java.util.Scanner;

/**
 * 标题：包子凑数
 * <p>
 * 小明几乎每天早晨都会在一家包子铺吃早餐。他发现这家包子铺有N种蒸笼，其中第i种蒸笼恰好能放Ai个包子。每种蒸笼都有非常多笼，可以认为是无限笼。
 * <p>
 * 每当有顾客想买X个包子，卖包子的大叔就会迅速选出若干笼包子来，使得这若干笼中恰好一共有X个包子。比如一共有3种蒸笼，分别能放3、4和5个包子。当顾客想买11个包子时，大叔就会选2笼3个的再加1笼5个的（也可能选出1笼3个的再加2笼4个的）。
 * <p>
 * 当然有时包子大叔无论如何也凑不出顾客想买的数量。比如一共有3种蒸笼，分别能放4、5和6个包子。而顾客想买7个包子时，大叔就凑不出来了。
 * <p>
 * 小明想知道一共有多少种数目是包子大叔凑不出来的。
 * <p>
 * 输入
 * ----
 * 第一行包含一个整数N。(1 <= N <= 100)
 * 以下N行每行包含一个整数Ai。(1 <= Ai <= 100)
 * <p>
 * 输出
 * ----
 * 一个整数代表答案。如果凑不出的数目有无限多个，输出INF。
 * <p>
 * 例如，
 * 输入：
 * 2
 * 4
 * 5
 * <p>
 * 程序应该输出：
 * 6
 * <p>
 * 再例如，
 * 输入：
 * 2
 * 4
 * 6
 * <p>
 * 程序应该输出：
 * INF
 * <p>
 * 样例解释：
 * 对于样例1，凑不出的数目包括：1, 2, 3, 6, 7, 11。
 * 对于样例2，所有奇数都凑不出来，所以有无限多个。
 * <p>
 * 资源约定：
 * 峰值内存消耗（含虚拟机） < 256M
 * CPU消耗  < 1000ms
 * <p>
 * <p>
 * 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 * <p>
 * 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 * 不要使用package语句。不要使用jdk1.7及以上版本的特性。
 * 主类的名字必须是：Main，否则按无效代码处理。
 * 提交程序时，注意选择所期望的语言类型和编译器类型。
 */


public class H {
    private static int a[] = new int[100 + 10];
    private static int dp[] = new int[10000 + 10];


    public static void main(String[] args) {
        int n;
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = cin.nextInt();
        }
        int flag = 0;
        int p = a[0];
        for (int i = 1; i < n; i++) {
            p = gcd(p, a[i]);
            if (p == 1) {
                flag = 1;
                break;
            }
        }
        if (flag != 1) {
            System.out.println("INF");
            return;
        }
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 10000; j++) {
                if (a[i] > j) continue;
                if (dp[j - a[i]] == 1) dp[j] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 10000; i++) {
            if (dp[i] != 1) res++;
        }
        System.out.println(res);
    }

    private static int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

}
