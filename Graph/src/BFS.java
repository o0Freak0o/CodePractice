import GraphCreator.Node;

import java.util.*;
public class BFS {
    public static void bfs(Node node){
        if(node == null){
            return;
        }
        //存储当前节点的数据结构，FIFO
        Queue<Node> queue = new LinkedList<>();
        //存储以己经访问过的节点的set，防止重复
        HashSet<Node> set = new HashSet<>();
        queue.add(node);
        set.add(node);
        while (!queue.isEmpty()){
            Node cur = queue.poll();
            //这里可以替换成相应的处理操作
            System.out.println(cur.value);
            //对处理完成的节点的后继节点进行宽度优先遍历，插入队列中等待后续操作
            for(Node next : cur.nexts){
                if(!set.contains(next)){
                    set.add(next);
                    queue.add(next);
                }
            }
        }
    }

}
