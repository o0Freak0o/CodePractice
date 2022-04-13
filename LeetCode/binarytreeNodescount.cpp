#include<bits/stdc++.h>
using namespace std;
/*
问题描述：
在遍历一棵二叉树时，统计出节点个数最多的一层的节点个数
*/
/*
二叉树节点结构体
*/
typedef struct Nodes
{
    int data;
    Nodes *left;
    Nodes *right;
} Node;

/*
节点队列
*/
queue<Node> q;
/*
存储队列中弹出的节点
*/
Node cur;
/*
节点-层数 关系的映射存储map
*/
map<Node,int> m;
/*
标识当前节点所处的层数，初值为1
*/
int CurLevel = 1;
/*
当前层数的节点个数的统计变量
*/
int CurNodesCount = 0;
/*
节点个数最大值临时存储变量
*/
int maxNum = -1;

void NodeCount(Node *head){
    //头节点先进队列
    q.push(*(head));
    //map里存储头节点的层数
    m[*(head)] = 1;
    while(!q.empty()){
        //节点弹出
        cur = q.front();
        q.pop();
        //若此时弹出的节点依然在这一层，该层节点个数++
        if(m[cur] == CurLevel){
            CurNodesCount++;
        }else{
            //如果不在，那么说明到了下一层
            //就和maxNum进行对比赋值
            maxNum = CurNodesCount > maxNum ? CurNodesCount : maxNum;
            //层数++
            CurLevel++;
            //该层节点个数归1
            CurNodesCount = 1;
        }
        //将弹出节点的左右子节点的信息存储进Map和队列
        if(cur.left != nullptr){
            m[*(cur.left)] = (CurLevel+1);
            q.push(*(cur.left));
        }
        if(cur.right != nullptr){
            m[*(cur.right)] = (CurLevel+1);
            q.push(*(cur.right));
        }
    }
}

int main(){
    return 0;
}