import GraphCreator.Edge;
import GraphCreator.Graph;
import GraphCreator.Node;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Set;

public class Kruskal {
    public static class Mysets{
        //定义每个点所在的集合
        public HashMap<Node, List<Node>> setMap;
        public Mysets(List<Node> nodes){
            //初始化：刚开始默认每个节点都只在自己的集合里
            for(Node node : nodes){
                List<Node> set = new ArrayList<Node>();
                set.add(node);
                setMap.put(node,set);
            }
        }
        //判断from节点和to节点是否在一个集合里
        public boolean isSameSet(Node from, Node to){
            List<Node> fromset = setMap.get(from);
            List<Node> toset = setMap.get(to);
            //根据内存地址判断是否是一个集合
            return fromset == toset;
        }
        //将from节点所在的集合和to节点所在的集合合并成一个集合
        public void union(Node from, Node to){
            List<Node> fromset = setMap.get(from);
            List<Node> toset = setMap.get(to);
            for(Node node : toset){
                fromset.add(node);
                setMap.put(node,fromset);
            }
        }
    }
}

