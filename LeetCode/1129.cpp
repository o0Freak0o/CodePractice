class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //����ͼ�ṹ
        vector<vector<pair<int,int>>> graph(n);
        //����������飬ע�⣬�������һ���ڵ��ǿ���ͨ����������·����2�ε�
        //���Գ�ʼ��һ����n,2�������飬��ֵ��Ϊ0
        vector<vector<int>> visit(n,vector<int>(2,0));
        //BFS����
        //�������Ϊ {�ڵ㣬���룬���ýڵ�ıߵ���ɫ}
        queue<vector<int>> q;
        //��Ž����vector���鲢��ʼ��
        vector<int> dis(n,INT_MAX);
        dis[0] = 0;
        //����Ϊͼ�ĳ�ʼ������
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
        //����ΪBFS����
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