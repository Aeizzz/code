package lanqiao.eight;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

/**
 * 标题：日期问题
 * <p>
 * 小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
 * <p>
 * 比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。
 * <p>
 * 给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
 * <p>
 * 输入
 * ----
 * 一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)
 * <p>
 * 输入
 * ----
 * 输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。
 * <p>
 * 样例输入
 * ----
 * 02/03/04
 * <p>
 * 样例输出
 * ----
 * 2002-03-04
 * 2004-02-03
 * 2004-03-02
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
 */


public class G {

    private static int[] m = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String tmp = cin.nextLine();
        String s[] = tmp.split("/");
        int a = Integer.parseInt(s[0]);
        int b = Integer.parseInt(s[1]);
        int c = Integer.parseInt(s[2]);

        int sum[] = new int[6];
        sum[0] = (1900 + a) * 10000 + b * 100 + c;
        sum[1] = (1900 + c) * 10000 + a * 100 + b;
        sum[2] = (1900 + c) * 10000 + b * 100 + a;
        sum[3] = (2000 + a) * 10000 + b * 100 + c;
        sum[4] = (2000 + c) * 10000 + a * 100 + b;
        sum[5] = (2000 + c) * 10000 + b * 100 + a;
        Arrays.sort(sum);

        for (int i = 0; i < sum.length; i++) {
            int year = sum[i] / 10000;
            int month = (sum[i] % 10000) / 100;
            int day = sum[i] % 100;
            if (i != 0 && sum[i] == sum[i - 1]) continue;
            if (year >= 1960 && year <= 2059) {
                if (mm(year)) {
                    m[1] = 29;
                } else {
                    m[1] = 28;
                }
                if (month >= 1 && month <= 12) {
                    if (day >= 1 && day <= m[month - 1]) {
                        String f = sum[i] + "";
                        System.out.println(f.substring(0, 4) + "-" + f.substring(4, 6) + "-" + f.substring(6, 8));
                    }
                }
            }
        }


    }

    private static boolean mm(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return true;
        } else return false;
    }


}


