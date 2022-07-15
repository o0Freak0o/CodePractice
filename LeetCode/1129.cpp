class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //定义图结构
        vector<vector<pair<int,int>>> graph(n);
        //定义访问数组，注意，这道题里一个节点是可以通过红蓝两条路访问2次的
        //所以初始化一个（n,2）的数组，初值置为0
        vector<vector<int>> visit(n,vector<int>(2,0));
        //BFS队列
        //存放数据为 {节点，距离，到该节点的边的颜色}
        queue<vector<int>> q;
        //存放结果的vector数组并初始化
        vector<int> dis(n,INT_MAX);
        dis[0] = 0;
        //以下为图的初始化操作
        q.push({0,0,1});
        q.push({0,0,0});
        for(auto& edge : blueEdges){
            int from = edge[0];
            int to = edge[1];
            graph[from].push_back({to,1});
        }
        for(auto& edge : redEdges){
            int from = edge[0];
            int to = edge[1];
            graph[from].push_back({to,0});
        }
        //以下为BFS操作
        while(!q.empty()){
            auto cur = q.front();
            int from = cur[0];
            int distance = cur[1];
            int color = cur[2];
            q.pop();
            for(auto& [to,colour] : graph[from]){
                if(color == !colour && !visit[to][colour]){
                    dis[to] = min(dis[to],distance+1);
                    q.push({to,distance+1,colour});
                    visit[to][colour] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX)dis[i]=-1;
        }
        return dis;
    }
};