import java.util.ArrayList;

public class FullArrangeStr {
    public static void process(char[] chs, int i, ArrayList<String> res){
        //递归出口
        if(i == chs.length){
            res.add(String.valueOf(chs));
        }
        //去重所用数组
        boolean[] visit = new boolean[26];
        for(int j = i; j < chs.length; j++){
            if(!visit[chs[j]-'a']){
                visit[chs[j]-'a'] = true;
                swap(chs,i,j);
                process(chs,i+1,res);
                swap(chs,i,j);
            }
        }
    }

    public static void swap(char[] chs,int i, int j){
        char tmp = chs[i];
        chs[i] = chs[j];
        chs[j] = tmp;
    }
}
