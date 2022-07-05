import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 题目描述：
 * 输入：正数数组costs，正数数组profits，正数k，正数m
 * 输出：最后获得的最大钱数
 * 说明：costs[i]表示i号项目的花费，profits[i]标识i号项目在扣除花费后
 * 还能挣到的钱（利润),k表示你只能做最多K个项目，m表示你的初始资金。
 * 贪心策略：首先将所有的任务按照cost从小到大排序生成小顶堆，每次（次数小于K）
 * 从小顶堆中取出所有cost<m的任务，全部加入到profit大顶堆(按照profit从到小排序)中，
 * 从大顶堆中取出一个任务，更新m值，再次循环。
 * */

public class MaxMoney {
    public static class Node{
        //profits
        public int p;
        //costs
        public int c;
        public Node(int p,int c){
            this.c = c;
            this.p = p;
        }
    }
    //按照花费最小排序的小根堆
    public static class MinCostComparator implements Comparator<Node>{
        @Override
        public int compare(Node o1, Node o2){
            return o1.c-o2.c;
        }
    }
    //按照利润最大排序的大根堆
    public static class MaxProfitComparator implements Comparator<Node>{
        @Override
        public int compare(Node o1,Node o2){
            return o2.p-o1.p;
        }
    }
    public static int findMaximizedCapital(int k,int w,int[] Profits,int[] Costs){
        PriorityQueue<Node> minCostQ = new PriorityQueue<>(new MinCostComparator());
        PriorityQueue<Node> maxProfitQ = new PriorityQueue<>(new MaxProfitComparator());
        for(int i = 0; i < Profits.length; i++){
            minCostQ.add(new Node(Profits[i],Costs[i]));
        }
        for(int i = 0; i < k; i++){
            while(!minCostQ.isEmpty() && minCostQ.peek().c <= w){
                maxProfitQ.add(minCostQ.poll());
            }
            if(maxProfitQ.isEmpty()){
                return w;
            }
            w += maxProfitQ.poll().p;
        }
        return w;
    }
}
