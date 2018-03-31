package Simple_topic;

import java.util.Scanner;

public class hdu_2026 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String s;
        while (cin.hasNext()){
            s = cin.nextLine();
            String[] s1 = s.split(" ");
            for(int i=0;i<s1.length;i++) {
                System.out.print(captureName(s1[i]));
                if(i==s1.length-1){
                    System.out.println();
                }else {
                    System.out.print(" ");
                }
            }

        }
    }
    public static String captureName(String name) {
        char[] cs=name.toCharArray();
        cs[0]-=32;
        return String.valueOf(cs);

    }
}
