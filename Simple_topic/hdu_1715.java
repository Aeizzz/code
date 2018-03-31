package Simple_topic;

import java.math.BigInteger;
import java.util.Scanner;

public class hdu_1715 {

    static BigInteger p[] = new BigInteger[1000+10];
    public static void main(String[] args) {
        p[1]=BigInteger.valueOf(1);
        p[2]=BigInteger.valueOf(1);
        for(int i=3;i<=1000;i++){
            p[i]=p[i-1].add(p[i-2]);
        }
        int n;
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        while (n-->0){
            int m;
            m=cin.nextInt();
            System.out.println(p[m]);
        }
    }
}
