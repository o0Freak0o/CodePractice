#include<iostream>
using namespace std;

typedef struct Nodes{
    int value;
    Node *left;
    Node *right;
} Node;

Node* TreeTrace(Node *head,Node *tar1,Node tar2){
    if(head == nullptr || head->value == tar1->value || head->value == tar2.value){
        return head;
    }
    Node* tmp1 = TreeTrace(head->left, tar1, tar2);
    Node* tmp2 = TreeTrace(head->right, tar1, tar2);
    if(tmp1 != nullptr && tmp2 != nullptr){
        return head;
    }
    return tmp1 != nullptr ? tmp1 : tmp2;
}
int main(){
    
    return 0;
}