package Simple_topic;

import java.util.Scanner;

public class hdu_2041 {
    public static void main(String[] args) {
        int n;
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        int p[] = new int[44];
        p[1]=0;
        p[2]=1;
        p[3]=2;
        for(int i=4;i<=40;i++){
            p[i]=p[i-1]+p[i-2];
        }
        while (n-->0){
            int m=cin.nextInt();
            System.out.println(p[m]);
        }
    }
}
