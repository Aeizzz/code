package Simple_topic;

import java.util.Scanner;

public class hdu_2011 {
    public static void main(String[] args) {
        int m;
        Scanner cin = new Scanner(System.in);
        m = cin.nextInt();
        for (int i = 0; i < m; i++) {
            int n;
            n = cin.nextInt();
            double x = 0.0;
            for (int j = 1; j <= n; j++) {
                if (j % 2 == 0) {
                    x -= 1.0 / j;
                } else {
                    x += 1.0 / j;
                }

            }
            System.out.println(String.format("%.2f",x));
        }
    }
}
