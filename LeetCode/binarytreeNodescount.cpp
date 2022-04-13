#include<bits/stdc++.h>
using namespace std;
/*
����������
�ڱ���һ�ö�����ʱ��ͳ�Ƴ��ڵ��������һ��Ľڵ����
*/
/*
�������ڵ�ṹ��
*/
typedef struct Nodes
{
    int data;
    Nodes *left;
    Nodes *right;
} Node;

/*
�ڵ����
*/
queue<Node> q;
/*
�洢�����е����Ľڵ�
*/
Node cur;
/*
�ڵ�-���� ��ϵ��ӳ��洢map
*/
map<Node,int> m;
/*
��ʶ��ǰ�ڵ������Ĳ�������ֵΪ1
*/
int CurLevel = 1;
/*
��ǰ�����Ľڵ������ͳ�Ʊ���
*/
int CurNodesCount = 0;
/*
�ڵ�������ֵ��ʱ�洢����
*/
int maxNum = -1;

void NodeCount(Node *head){
    //ͷ�ڵ��Ƚ�����
    q.push(*(head));
    //map��洢ͷ�ڵ�Ĳ���
    m[*(head)] = 1;
    while(!q.empty()){
        //�ڵ㵯��
        cur = q.front();
        q.pop();
        //����ʱ�����Ľڵ���Ȼ����һ�㣬�ò�ڵ����++
        if(m[cur] == CurLevel){
            CurNodesCount++;
        }else{
            //������ڣ���ô˵��������һ��
            //�ͺ�maxNum���жԱȸ�ֵ
            maxNum = CurNodesCount > maxNum ? CurNodesCount : maxNum;
            //����++
            CurLevel++;
            //�ò�ڵ������1
            CurNodesCount = 1;
        }
        //�������ڵ�������ӽڵ����Ϣ�洢��Map�Ͷ���
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