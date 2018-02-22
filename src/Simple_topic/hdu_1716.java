package Simple_topic;

import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class hdu_1716 {
    int p[] = new int[4], num [] = new int[100],ans=0;
    void run(){
        int cc=0;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int n=0;
            for (int i = 0; i < 4; i++) {
                p[i] = cin.nextInt();
                n+=p[i];
            }
            if(n==0) break;
            solve(p);
            Arrays.sort(num,0,ans);
            if(cc!=0)
                System.out.println();
            cc++;
            for(int i=0;i<ans;i++){
                if(i!=ans-1 && num[i]==num[i+1]){
                    continue;
                }
                if(i==ans-1 || (i!=ans-1 && num[i]/1000 !=num[i+1]/1000)){
                    System.out.println(num[i]);
                }else
                    System.out.print(num[i]+" ");
            }

        }
    }

    private void solve(int[] a) {
        ans=0;
        Arrays.fill(num,0);
        for(int i=0;i<4;i++){
            if(a[i]==0) continue;
            for(int j=0;j<4;j++){
                if(i==j) continue;
                for(int k=0;k<4;k++){
                    if(i==k||k==j) continue;
                    for(int l=0;l<4;l++){
                        if(l==i||l==j||l==k) continue;
                        num[ans++]=a[l]+a[k]*10+a[j]*100+a[i]*1000;
                    }

                }
            }
        }
    }

    public static void main(String[] args) {
        new hdu_1716().run();
    }
    static Scanner cin = new Scanner(new BufferedInputStream(System.in));
}
