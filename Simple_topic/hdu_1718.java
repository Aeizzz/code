package Simple_topic;

import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class hdu_1718 {
    int score[] = new int[1000+100],num;
    void run() {
        while (cin.hasNext()) {
            int n = cin.nextInt();
            int t = -1;
            int tmp = 0;
            while (true) {
                t++;
                num = cin.nextInt();
                score[t] = cin.nextInt();
                if (n == num) tmp = score[t];
                if (num == 0 && score[t] == 0) break;
            }
            Arrays.sort(score, 0, t);
            int count = 1;
            for (int i = t - 1; i >= 0; i--) {
                if (tmp < score[i]) count++;
                if (tmp == score[i]) break;
            }
            System.out.println(count);
        }
    }

    public static void main(String[] args) {
        new hdu_1718().run();
    }

    static Scanner cin = new Scanner(new BufferedInputStream(System.in));
}
