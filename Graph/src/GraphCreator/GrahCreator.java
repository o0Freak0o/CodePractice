package GraphCreator;

public class GrahCreator {
    public static Graph createGraph(Integer[][] matrix){
        Graph graph = new Graph();
        for (int i = 0; i < matrix.length;i++){
            Integer from = matrix[i][0];
            Integer to = matrix[i][1];
            Integer weight = matrix[i][2];
            if(!graph.nodes.containsKey(from)){
                graph.nodes.put(from,new Node(from));
            }
            if(!graph.nodes.containsKey(to)){
                graph.nodes.put(to,new Node(to));
            }
            Node fromnode = graph.nodes.get(from);
            Node tonode = graph.nodes.get(to);
            Edge edge = new Edge(weight,fromnode,tonode);
            fromnode.nexts.add(tonode);
            fromnode.out++;
            tonode.in++;
            fromnode.edges.add(edge);
            graph.edges.add(edge);
        }
        return graph;
    }
}
