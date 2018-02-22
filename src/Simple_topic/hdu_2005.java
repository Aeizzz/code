package Simple_topic;

import java.util.Scanner;

public class hdu_2005 {
    static int[] months = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    public static void main(String[] args) {
        String s;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            s = cin.nextLine();
            String[] a = s.split("/");
            int year = Integer.parseInt(a[0]);
            int month = Integer.parseInt(a[1]);
            int r = Integer.parseInt(a[2]);
            int num = 0;
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                if (month > 2) {
                    num = months[month - 1] + 1 + r;
                } else {
                    num = months[month - 1] + r;
                }
            } else {
                num = months[month - 1] + r;
            }
            System.out.println(num);

        }

    }
}
