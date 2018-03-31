package Simple_topic;

import java.util.Scanner;

public class hdu_2089 {
    static int p [] = new int[1000000+100];
    public static void main(String[] args) {
        int n,m;
        Scanner cin = new Scanner(System.in);
        init();
        while (true){
            n=cin.nextInt();
            m=cin.nextInt();
            if(n==0 && m==0){
                break;
            }
            System.out.println(p[m]-p[n-1]);
        }
    }

    public  static void init(){
        p[0]=0;
        for(int i=1;i<=1000000;i++){
            if(judge(i)){
                p[i]=p[i-1]+1;
            }else {
                p[i]=p[i-1];
            }
        }
    }

    private static boolean judge(int i) {
        String s = Integer.toString(i);
        if(s.contains("4")||s.contains("62")){
            return false;
        }else{
            return true;
        }
    }
}
