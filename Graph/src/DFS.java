import GraphCreator.Node;

import java.util.*;

public class DFS {
    public static void DFS_(Node node){
        if (node == null){
            return;
        }
        //存储当前节点的数据结构，stack
        //需要注意，程序执行完后，stack里存储的就是一次DFS遍历后的结果
        Stack<Node> stack = new Stack<>();
        //存储以己经访问过的节点的set，防止重复
        HashSet<Node> set = new HashSet<>();
        stack.add(node);
        set.add(node);
        //这里需要注意，DFS的首个节点需要先进行操作，因为后续的逻辑会跳过第一个节点，直接对第一个节点的第一个后续节点进行操作
        System.out.println(node.value);
        while (!stack.isEmpty()){
            Node cur = stack.pop();
            for(Node next : cur.nexts){
                if(!set.contains(next)){
                    stack.push(cur);
                    stack.push(next);
                    set.add(next);
                    System.out.println(next.value);
                    break;
                }
            }
        }
    }
}
