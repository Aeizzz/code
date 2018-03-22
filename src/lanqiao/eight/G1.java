package lanqiao.eight;

import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.IOException;
import java.io.BufferedReader;


public class G1 {
    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        String s = sc.readLine();
        String[] S = s.split("/");
        int a = Integer.parseInt(S[0]);
        int b = Integer.parseInt(S[1]);
        int c = Integer.parseInt(S[2]);

        int[] sum = new int[6];
        sum[0] = (1900 + a) * 10000 + b * 100 + c;
        sum[1] = (1900 + c) * 10000 + b * 100 + a;
        sum[2] = (1900 + c) * 10000 + a * 100 + b;
        sum[3] = (2000 + a) * 10000 + b * 100 + c;
        sum[4] = (2000 + c) * 10000 + b * 100 + a;
        sum[5] = (2000 + c) * 10000 + a * 100 + b;
        Arrays.sort(sum);
        int[] D = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < sum.length; i++) {
            int year = sum[i] / 10000;
            int month = (sum[i] % 10000) / 100;
            int date = sum[i] % 100;
            if (i != 0 && sum[i] == sum[i - 1]) continue;
            if (year >= 1960 && year <= 2059) {
                if (leap(year)) {
                    D[2 - 1] = 29;
                } else {
                    D[2 - 1] = 28;
                }
                if (month >= 1 && month <= 12) {
                    if (date > 0 && date <= D[month - 1]) {
                        String f = sum[i] + "";
                        System.out.println(f.substring(0, 4) + "-" + f.substring(4, 6) + "-" + f.substring(6, 8));
                    }

                }
            }
        }

    }

    private static boolean leap(int year) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return true;
        else
            return false;
    }
}
