#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stack>
#include<cstring>
#include<forward_list>

using namespace std;

typedef struct Node
{
    int data = 0;
    Node *left;
    Node *right;
} Node;

int sys_min = numeric_limits<int>::min();
int sys_max = numeric_limits<int>::max();
//判断是否是搜索二叉树（递归解法）
//搜索二叉树定义：对于每个节点的子树，其左子树都比该节点小，右子树都比该节点大
//代码逻辑：1.先检查左树是不是搜索二叉树
//以下代码是中序遍历的变体
//打印环节变成了比较处理环节
bool isBST_RE(Node *head){
    if(head == nullptr)
        return true;
    bool isLeftBST = isBST_RE(head->left);
    if(!isLeftBST)
        return false;
    if(head->data <= sys_min)
        return false;
    else
        sys_min = head->data;
    return isBST_RE(head->right);
}
//判断是否是搜索二叉树（非递归解法）
bool isBST_NOR(Node *head){
    if(head != nullptr){
        stack<Node *> s;
        while(!s.empty() || head != nullptr){
            if(head != nullptr){
            s.push(head);
            head = head->left;
            }else{
                head = s.top();
                s.pop();
                if(head->data <= sys_min)
                    return false;
                else
                    sys_min = head->data;
                head = head->right;
                }
            }
        return true;
    }else{
        return true;
    }
}