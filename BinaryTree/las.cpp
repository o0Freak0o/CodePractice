#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stack>
using namespace std;

/*
二叉树节点结构体
@params
data : int : 节点数据
left : 指针 : 当前节点的左指针
right : 指针 : 当前节点的右指针
*/
typedef struct Node
{
    int data = 0;
    Node *left;
    Node *right;
} Node;

/*
当前树中待插入节点的指针
*/
Node *cur;
/*
根节点指针
*/
Node *root;
/*
新插入的节点的指针
*/
Node *NewNode;
stack<Node> NodeStack;
//后序非递归遍历辅助栈
stack<Node> Help;
/*
满二叉树初始化
@params
n : 节点数量
*/
void Init(int n);
/*
前序递归遍历
*/
void pre_recursion(Node *cur);
/*
中序递归遍历
*/
void med_recursion(Node *cur);
/*
后序递归遍历
*/
void las_recursion(Node *cur);
/*
前序非递归遍历
*/
void pre();
/*
中序非递归遍历
*/
void med();
/*
后序非递归遍历
*/
void las();

//主函数
int main(){
    // Init(6);
    /*
    程序调试
    cout<<root->left->left->data;
    */
   
    pre_recursion(root);
}

void Init(int n){
    //新节点插入
    for(int i = 1; i <= n; i++){
        NewNode = new Node;
        NewNode->data = i;
        NewNode->left = nullptr;
        NewNode->right = nullptr;
        if( i == 1){
            root = NewNode;
            cur = root;
            continue;
        }
        if(cur->left == nullptr){
            cur->left = NewNode;

        }else if(cur->right == nullptr){
            cur->right = NewNode;
            cur = cur->left;
        }
    }
    //cur回到root
    cur = root;
}

void pre_recursion(Node *cur){
    if(cur != nullptr){
        cout<<cur->data;
        pre_recursion(cur->left);
        pre_recursion(cur->right);
    }else{
        return;
    }
}

void med_recursion(Node *cur){
    if(cur != nullptr){
        pre_recursion(cur->left);
        cout<<cur->data;
        pre_recursion(cur->right);
    }else{
        return;
    }
}

void med_recursion(Node *cur){
    if(cur != nullptr){
        pre_recursion(cur->left);
        pre_recursion(cur->right);
        cout<<cur->data;
    }else{
        return;
    }
}

void pre(Node * cur, stack<Node> s){
    //头节点压栈
    s.push(*(cur));
    //简单的前序遍历
    //先压右再压左
    while(!(s.empty())){
        cout<<s.top().data<<" ";
        Node n = s.top();
        s.pop();
        if(n.right != nullptr)
            s.push(*(n.right));
        if(n.left != nullptr)
            s.push(*(n.left));
    }
}

void las(Node *cur, stack<Node> s, stack<Node> help){
    //头节点压栈
    s.push(*(cur));
    //简单的后序遍历
    //第一个栈的出栈顺序是 头右左
    //那么压入help栈的顺序就是 头右左
    //help出栈顺序就是 左右头
    while(!(s.empty())){
        // cout<<s.top().data;
        Node n = s.top();
        help.push(n);
        s.pop();
        if(n.left != nullptr)
            s.push(*(n.left));
        if(n.right != nullptr)
            s.push(*(n.right));
    }
    while(!(help.empty())){
        Node n = help.top();
        cout<<n.data<<" ";
    }
}

void med(Node *cur, stack<Node> s){
    //核心思想是
    //1.对于任一子树，将其左边统统压栈
    //2.一直压到叶子节点为止
    //3.再弹出栈顶，将其右子节点压栈
    //goto step 1
    if(cur != nullptr){
        while (!s.empty() || cur != nullptr)
        {
            if(cur != nullptr){
                s.push(*(cur));
                cur = cur->left;
            }else{
                Node n = s.top();
                s.pop();
                cout<<n.data<<" ";
                s.push(*(n.right));
            }
        }
    }
}