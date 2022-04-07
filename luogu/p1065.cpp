#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>

using namespace std;

/*
每个工件的结构体
@params
machineid : 该工件此道工序在哪个机器上进行
time_cost : 该工件这个工序下需要的时间
初始化一个20 x 20的数组存储每一个工件在每道工序下的时间
*/
struct workpiece
{
    int machineid;
    int time_cost;
} w[20][20];
/*
可以理解成工序图
最多20个工件 
最多20道工序
每道工序最多20s
假设所有工件只能在一道工序上处理，时间最长不过8000s
这里为了安全起见开到8400
*/
int work_process[20][8400] = {0};
/*
记录每个工件处理完当前工序后的时间戳
*/
int last_time[20] = {0};
/*
记录每个工件此时已经进行到第几道工序
*/
int work2process[20] = {1};
/*
工作流存储数组
*/
int workflow[400];
int time_cost[20] = {0};
int m, n;

void Init();
void process();
bool judge(int btime,int etime,int machineid);
bool compare(int a, int b){
    return a > b;
}

int main(){
    Init();
    process();
    sort(last_time, last_time + 20, compare);
    cout << last_time[0];
    cout << endl;
    return 0;

}

void Init(){
    cin >> m >> n;
    for (int i = 1; i <= n * m; i++){
        cin >> workflow[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++){
            cin >> w[i][j].machineid;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++){
            cin >> w[i][j].time_cost;
        }
    for (int i = 1; i <= 20; i++)
        work2process[i] = 1;
}
bool judge(int btime,int etime,int machineid){
    for (int i = btime; i <= etime;i++){
        if(work_process[machineid][i] == 1)
            return false;
    }
    return true;
}

void process(){
    for (int i = 1; i <= n * m; i++){
        int wid = workflow[i];
        int pid = work2process[wid]++;
        int machineid = w[wid][pid].machineid;
        int process_time_cost = w[wid][pid].time_cost;
        //有坑
        int btime = last_time[wid];
        while(true){
            if(judge(btime+1,btime+process_time_cost,machineid)){
                for (int j = btime + 1; j <= btime + process_time_cost; j++){
                    work_process[machineid][j] = 1;
                }
                last_time[wid] = btime + process_time_cost;
                // cout<<"wid = "<<wid<<endl;
                // cout<<"pid = "<<pid<<endl;
                // cout<<last_time[wid]<<endl;
                break;
            }
            btime++;
        }
    }
}