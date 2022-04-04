#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stack>
#include<cstring>
#include<forward_list>
//Tag:链表 快慢指针 操作符重载 结构体
////////////////////////////////////////////////////////////
//题目如下：                                               //
//给定两个可能有环也可能无环的单链表头结点Head1和Head2        //
//请实现一个函数，如果两个节点链表相交，则返回第一个相交的节点 //
//否则返回Null                                            //
///////////////////////////////////////////////////////////

//无环标记默认value值
#define NOEXISTTLAG -1;

//注意，此题实现时，默认Head结构如下，并且无环标记默认的value值为-1
typedef struct Node
{
    int value;
    struct Node *next;
}Node;

//结构体比较操作符 == 重载
bool operator==(Node n1, Node n2);
//结构体比较操作符 != 重载
bool operator!=(Node n1, Node n2);
//找到链表第一个入环的节点，如果无环则返回NULL;
Node GetLoopNode(Node Head);
//两个无环链表找第一个相交节点
Node NoLoop(Node Head1, Node Head2);
//两个链表都有环,3种情况
Node BothLoop(Node Head1, Node Head2, Node loop1, Node loop2);

int main(){
    return 0;
}
//结构体比较操作符 == 重载
bool operator==(Node n1,Node n2){
    if(&n1 == &n2 && n1.value == n2.value)
        return true;
    else
        return false;
}
//结构体比较操作符 != 重载
bool operator!=(Node n1,Node n2){
    if(&n1 == &n2)
        return false;
    else
        return true;
}

//找到链表第一个入环的节点，如果无环则返回NULL;
//使用快慢指针（节点）
Node GetLoopNode(Node Head){
    //无环标记
    Node RES;
    RES.value = NOEXISTTLAG;
    RES.next = nullptr;
    //慢节点
    Node cur1;
    //快节点
    Node cur2;
    if(Head.value == NULL || Head.next->value == NULL || Head.next->next->value == NULL){
        return RES;
    }
    //慢节点先迈出一步
    //因为如果快慢指针一开始就重合，下边的while循环就会失效
    cur1 = *(Head.next);
    //快节点迈出两步
    cur2 = *(Head.next->next);
    //循环
    //若是有环的，那么快慢指针一定会在环上相遇
    //如果无环，则快指针会先跑到NULL，则返回无环标记
    while (cur1 != cur2)
    {
        //无环，返回
        if(cur2.next == nullptr || cur2.next->next == nullptr)
            return RES;
        //慢节点前进1步
        cur1 = *(cur1.next);
        //快节点前进2步
        cur2 = *(cur2.next->next);
    }
    //注意这里用到一个很重要的结论：
    //快慢节点在环上相遇后，快节点返回开头，快慢节点每次都走一步，那么两个节点一定会在入环节点处相遇
    //快节点回到开头
    cur2 = Head;
    while (cur1 != cur2){
        //慢节点前进1步
        cur1 = *(cur1.next);
        //快节点前进1步
        cur2 = *(cur2.next);
    }
    //返回入环节点
    return cur2;
}

//两个无环链表找第一个相交节点
Node NoLoop(Node Head1, Node Head2){
    //无环标记
    Node RES;
    RES.value = NOEXISTTLAG;
    RES.next = nullptr;
    //第一个无环链表的游标
    Node cur1 = Head1;
    //第二个无环链表的游标
    Node cur2 = Head2;
    //长度计数器
    int n = 0;
    if(Head1.value == NULL || Head2.value == NULL){
        return RES;
    }
    //遍历1号链表
    while (cur1.next != nullptr)
    {
        cur1 = *(cur1.next);
        n++;
    }
    //遍历2号链表
    while (cur2.next != nullptr)
    {
        cur2 = *(cur2.next);
        n--;
    }
    if(cur1 != cur2)
        return RES;
    //哪条长哪条给cur1
    cur1 = n > 0 ? Head1 : Head2;
    //另外一个给cur2
    cur2 = Head1 == cur1 ? Head2 : Head1;
    //取两条链表长度差值的绝对值
    n = abs(n);
    //长的链表的游标先前移，确保遍历的时候能和短的链表移动到同一个地方
    while (n != 0)
    {
        cur1 = *(cur1.next);
        n--;
    }
    //两条链表同时移动
    while (cur1 != cur2)
    {
        cur1 = *(cur1.next);
        cur2 = *(cur2.next);
    }
    return cur1;
}
//一个有环一个无环种情况，这种情况不可能有公共节点，因此跳过
//两个都有环,3种情况
//loop1是第一条链表的入环节点，loop2是第二条链表的入环节点
Node BothLoop(Node Head1, Node Head2, Node loop1, Node loop2){
    //无环标记
    Node RES;
    RES.value = NOEXISTTLAG;
    RES.next = nullptr;
    //第一个无环链表的游标
    Node cur1 = Head1;
    //第二个无环链表的游标
    Node cur2 = Head2;
    //长度计数器
    int n1 = 0;
    int n2 = 0;
    //当两条链的入环节点地址相同的时候是第一种情况。两条链共享一个环，但是只有1个入环节点。
    //这种情况只要把入环节点当成是最后一个节点，当成两个无环链表找第一个相交节点的情况一样处理即可
    //此处不再过多介绍
    if(&loop1 == &loop2){
        while (cur1.next != &loop1)
        {
            n1++;
            cur1 = *(cur1.next);
        }
        while (cur2.next != &loop2)
        {
            n2++;
            cur2 = *(cur2.next);
        }
        cur1 = n1 > n2 ? Head1 : Head2;
        cur2 = cur1 == Head1 ? Head2 : Head1;
        int n = abs(n1 - n2);
        while (n != 0)
        {
            cur1 = *(cur1.next);
            n--;
        }
        while (cur1 != cur2)
        {
            cur1 = *(cur1.next);
            cur2 = *(cur2.next);
        }
        return cur1;
    }else{
        cur1 = loop1;
        while (cur1 != loop1)
        {
            //第三种情况。两条链共享一个环，但是有2个入环节点
            if(cur1 == loop2)
                return loop1;
            cur1 = *(cur1.next);
        }
        //第二种情况，两条链不共享环。
        return RES;
    } 
}