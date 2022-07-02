import GraphCreator.Graph;
import GraphCreator.Node;
import java.util.*;

//算法适用条件;
//1.有向图
//2.有入度为0的节点
//3.没有环
public class TopologicalSorting {
    public static List<Node> TopologicalSort(Graph graph){
        //存储某个节点入度数量的数据结构
        HashMap<Node,Integer> inMap = new HashMap<>();
        //入度值为0的节点才可以进入这个队列
        Queue<Node> zeroInQueue = new LinkedList<>();
        //inMap和zeroInQueue初始化操作
        for(Node node : graph.nodes.values()){
            inMap.put(node,node.in);
            if(node.in == 0) {
                zeroInQueue.add(node);
            }
        }
        List<Node> result = new ArrayList<>();
        while (!zeroInQueue.isEmpty()){
            Node cur = zeroInQueue.poll();
            result.add(cur);
            for(Node next : cur.nexts){
                inMap.put(next,inMap.get(next)-1);
                if(inMap.get(next) == 0){
                    zeroInQueue.add(next);
                }
            }
        }
        return result;
    }

}
