import java.util.Arrays;
import java.util.Comparator;

/**
 * 问题描述：
 * 一些项目要占用一个会议室宣讲，会议室不能同时容纳两个项目的宣讲
 * 给你每个项目开始的时间和结束的时间（给你一个数组，里边是一个个具体的项目
 * 你来安排宣讲的日程，要求会议室进行的宣讲的场次最多，返回这个最多的宣讲场次
 * 贪心策略：以结束时间最早的项目开始
 * */

public class Meeting {
    public static class program{
        public int start;
        public int end;

        public program(int start,int end){
            this.start = start;
            this.end = end;
        }
    }

    public static class ProgramComparator implements Comparator<program>{
        @Override
        public int compare(program o1,program o2){
            return o1.end-o2.end;
        }
    }
    public static int bestArrange(program[] programs, int timePoint){
        //根据每个会议结束时间进行排序，结束早的在前
        Arrays.sort(programs,new ProgramComparator());
        //最后统计的会议的个数
        int result = 0;
        //对排序好的数据依次处理
        for(int i = 0; i < programs.length; i++){
            if(timePoint <= programs[i].start){
                result++;
                timePoint = programs[i].end;
            }
        }
        return result;
    }
    public static void main(String[] args){

    }
}
