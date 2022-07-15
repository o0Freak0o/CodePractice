import GraphCreator.Edge;
import GraphCreator.Node;

import java.util.HashMap;

public class Dijestra {
    public static class Noderecord{
        public Node node;
        public int dis;
        public Noderecord(Node node,int dis){
            this.node = node;
            this.dis = dis;
        }
    }

    public static class NodeHeap{
        private Node[] nodes;
        private HashMap<Node,Integer> HeapIndexMap;
        private HashMap<Node,Integer> disMap;
        private int size;

        public NodeHeap(int size){
            nodes = new Node[size];
            HeapIndexMap = new HashMap<>();
            disMap = new HashMap<>();
        }
        public void addOrUpdateOrIgnore(Node node,int dis){
            if(inHeap(node)){
                disMap.put(node,Math.min(disMap.get(node),dis));
                insertHeapify(node,HeapIndexMap.get(node));
            }
            if(!isEntered(node)){
                nodes[size] = node;
                HeapIndexMap.put(node,size);
                disMap.put(node,dis);
                insertHeapify(node,size++);
            }
        }
        public Noderecord pop(){
            Noderecord noderecord = new Noderecord(nodes[0],disMap.get(nodes[0]));
            swap(0,size-1);
            HeapIndexMap.put(nodes[size-1],-1);
            disMap.remove(nodes[size-1]);
            nodes[size-1] = null;
            heapify(0,--size);
            return noderecord;
        }
        boolean isEmpty(){
            return size == 0;
        }
        private void insertHeapify(Node node, int index){
            while (disMap.get(nodes[index]) < disMap.get(nodes[(index-1)/2])){
                swap(index,(index-1)/2);
                index = (index-1)/2;
            }
        }

        private void heapify(int index,int size){
            int left = index *2;
            while (left < size){
                int smallest = (left+1)<size && disMap.get(nodes[left+1])<disMap.get(nodes[left]) ? left+1 : left;
                smallest = disMap.get(nodes[smallest])<disMap.get(nodes[index]) ? smallest : index;
                if(smallest == index){
                    break;
                }
                swap(smallest,index);
                index = smallest;
                left = index *2 +1;
            }
        }

        private boolean isEntered(Node node){
            return HeapIndexMap.containsKey(node);
        }
        private boolean inHeap(Node node){
            return isEntered(node) && HeapIndexMap.get(node)!=-1;
        }
        private void swap(int index1,int index2){
            HeapIndexMap.put(nodes[index1],index2);
            HeapIndexMap.put(nodes[index2],index1);
            Node tmp = nodes[index1];
            nodes[index1] = nodes[index2];
            nodes[index2] = tmp;
        }
    }
    public static HashMap<Node,Integer> dijestra(Node head, int size){
        NodeHeap nodeHeap = new NodeHeap(size);
        nodeHeap.addOrUpdateOrIgnore(head,0);
        HashMap<Node,Integer> result = new HashMap<>();
        while (!nodeHeap.isEmpty()){
            Noderecord record = nodeHeap.pop();
            Node cur = record.node;
            int dis = record.dis;
            for(Edge  edge : cur.edges){
                nodeHeap.addOrUpdateOrIgnore(edge.to,edge.weight+dis);
            }
            result.put(cur,dis);
        }
    return result;
    }
}
