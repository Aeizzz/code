package lanqiao.six;

/**
 * 牌型种数
 * <p>
 * 小明被劫持到X赌城，被迫与其他3人玩牌。
 * 一副扑克牌（去掉大小王牌，共52张），均匀发给4个人，每个人13张。
 * 这时，小明脑子里突然冒出一个问题：
 * 如果不考虑花色，只考虑点数，也不考虑自己得到的牌的先后顺序，自己手里能拿到的初始牌型组合一共有多少种呢？
 * <p>
 * 请填写该整数，不要填写任何多余的内容或说明文字。
 */

public class G {
    private static int sum = 0;
    private static int num = 0;

    public static void main(String[] args) {
        dfs(0);
        System.out.println(sum);
    }

    private static void dfs(int n) {
        if (num > 13) return;
        if (n == 13) {
            if (num == 13) {
                sum++;
            }
            return;
        }
        for (int i = 0; i <= 4; i++) {
            num += i;
            dfs(n + 1);
            num -= i;
        }

    }
}
