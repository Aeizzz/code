package lanqiao.six;

/**
 *
 *
 立方变自身

 观察下面的现象,某个数字的立方，按位累加仍然等于自身。
 1^3 = 1
 8^3  = 512    5+1+2=8
 17^3 = 4913   4+9+1+3=17
 ...

 请你计算包括1,8,17在内，符合这个性质的正整数一共有多少个？

 请填写该数字，不要填写任何多余的内容或说明性的文字。

 */

public class B {
    public static void main(String[] args) {
        long Max = 500000;
        int sum=0;
        for(long i=1;i<=Max;i++){
            if(i==judge(i*i*i)){
                System.out.println(i);
                sum++;
            }

        }
        System.out.println(sum);
    }

    private static long judge(long x){
        long sum = 0;
        while (x>0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
}
