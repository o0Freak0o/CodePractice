import GraphCreator.Edge;
import GraphCreator.Graph;
import GraphCreator.Node;

import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;


public class Prim {
    public static Set<Edge> primMST(Graph graph) {
        //优先级队列，根据边的大小排
        PriorityQueue<Edge> priorityQueue = new PriorityQueue<>(
                new EdgeComprator());
        //节点Set集，防止重复
        HashSet<Node> set = new HashSet<>();
        //结果集
        Set<Edge> result = new HashSet<>();
        for (Node node : graph.nodes.values()) {
            if (!set.contains(node)) {
                //节点加入Set集
                set.add(node);
                for (Edge edge : node.edges) {
                    //将该节点所连边全部加入小根堆
                    priorityQueue.add(edge);
                }
                //依次处理小根堆里的数据
                while (!priorityQueue.isEmpty()) {
                    Edge edge = priorityQueue.poll();
                    //检查这条边有没有使用过
                    Node toNode = edge.to;
                    if (!set.contains(toNode)) {
                        //没使用过，将该条边加入结果集并将该边对应的节点加入Set
                        set.add(toNode);
                        result.add(edge);
                        for (Edge nextEdge : toNode.edges) {
                            //新加入的节点对应的边全部加入小根堆（小根堆自动排序）
                            priorityQueue.add(nextEdge);
                        }
                    }


                }
            }
        }
        return result;
    }
    //比较器
    public static class EdgeComprator implements Comparator<Edge> {
        @Override
        public int compare(Edge e1, Edge e2){
            return e1.weight - e2.weight;
        }
    }
}
