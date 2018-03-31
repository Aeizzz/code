package lanqiao.eight;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 *
 标题：魔方状态

 二阶魔方就是只有2层的魔方，只由8个小块组成。
 如图p1.png所示。

 小明很淘气，他只喜欢3种颜色，所有把家里的二阶魔方重新涂了颜色，如下：

 前面：橙色
 右面：绿色
 上面：黄色

 下面：橙色
 后面：黄色

 请你计算一下，这样的魔方被打乱后，一共有多少种不同的状态。

 如果两个状态经过魔方的整体旋转后，各个面的颜色都一致，则认为是同一状态。

 请提交表示状态数的整数，不要填写任何多余内容或说明文字。


 */

/**
 *
 * 题目大概是，

 有一个魔方，上  黄色 | 下  橙色  | 左  绿色 |  右  绿色 | 前 橙色 | 后 黄色

 问魔方总共有多少种状态。

 我的答案：216

 我的思路：刚拿到这题有点懵逼，简单分析了一下，其实魔方总共八块，这八块其实就三种颜色

 4块是绿黄橙，2块是绿橙橙，2块是绿黄黄。

 我们就可以把该题简化为四个1，两个2，两个3的排序问题。

 需要注意的是11112233和33221111是一样的。

 代码如下：
 *
 */

public class D {
    static int[] v = new int[8];
    static int[] s = new int[8];
    static ArrayList<String> a = new ArrayList<String>();

    public static void main(String[] args) {
        s(0);
        System.out.println(a.size());
    }
    public static void s(int code){
        if(code==8){
            String t = "";
            String t1 = "";//t正序，t1倒序
            for (int i = 0; i < s.length; i++) {
                t += s[i]+"";
                t1 += s[s.length-1-i]+"";
            }
            if(!a.contains(t)&&!a.contains(t1)){
                a.add(t);
            }
            return;
        }
        for(int i=0;i<8;i++){
            if(v[i]==0){
                v[i]=1;
                if(i<4){
                    s[code] = 1;
                }
                else if(i<6){
                    s[code] = 2;
                }
                else if(i<8){
                    s[code] = 3;
                }
                s(code+1);
                v[i]=0;
            }
        }
    }
}


