#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stack>
using namespace std;

/*
�������ڵ�ṹ��
@params
data : int : �ڵ�����
left : ָ�� : ��ǰ�ڵ����ָ��
right : ָ�� : ��ǰ�ڵ����ָ��
*/
typedef struct Node
{
    int data = 0;
    Node *left;
    Node *right;
} Node;

/*
��ǰ���д�����ڵ��ָ��
*/
Node *cur;
/*
���ڵ�ָ��
*/
Node *root;
/*
�²���Ľڵ��ָ��
*/
Node *NewNode;
stack<Node> NodeStack;
//����ǵݹ��������ջ
stack<Node> Help;
/*
����������ʼ��
@params
n : �ڵ�����
*/
void Init(int n);
/*
ǰ��ݹ����
*/
void pre_recursion(Node *cur);
/*
����ݹ����
*/
void med_recursion(Node *cur);
/*
����ݹ����
*/
void las_recursion(Node *cur);
/*
ǰ��ǵݹ����
*/
void pre();
/*
����ǵݹ����
*/
void med();
/*
����ǵݹ����
*/
void las();

//������
int main(){
    // Init(6);
    /*
    �������
    cout<<root->left->left->data;
    */
   
    pre_recursion(root);
}

void Init(int n){
    //�½ڵ����
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
    //cur�ص�root
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
    //ͷ�ڵ�ѹջ
    s.push(*(cur));
    //�򵥵�ǰ�����
    //��ѹ����ѹ��
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
    //ͷ�ڵ�ѹջ
    s.push(*(cur));
    //�򵥵ĺ������
    //��һ��ջ�ĳ�ջ˳���� ͷ����
    //��ôѹ��helpջ��˳����� ͷ����
    //help��ջ˳����� ����ͷ
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
    //����˼����
    //1.������һ�������������ͳͳѹջ
    //2.һֱѹ��Ҷ�ӽڵ�Ϊֹ
    //3.�ٵ���ջ�����������ӽڵ�ѹջ
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