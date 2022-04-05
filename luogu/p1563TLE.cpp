#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<cstring>

using namespace std;

typedef struct person
{
    int direction;
    string names;
    struct person *next;
    struct person *previous;
} person;

int PersonNum;
int CommandNum;
int Pdirection;
int order;
char Pname[10] = "None";
person *Head;
person *Personcur;
person *cur = new person;

int main(){
    cur->next = nullptr;
    cur->previous = nullptr;
    cin >> PersonNum >> CommandNum;
    for (int i = 0; i < PersonNum; i++){
        Personcur = new person;
        cin >> Pdirection >> Pname;
        Personcur->direction = Pdirection;
        Personcur->names = Pname;
        cur->previous = Personcur;
        Personcur->previous = nullptr;
        Personcur->next = cur;
        cur = Personcur;
        if(i == 0){
            Head = Personcur;
        }
        if(i == PersonNum-1){
            Personcur->previous = Head;
            Head->next = Personcur;
        }
    }

    cur = Head;

    for (int i = 0; i < CommandNum; i++){
        cin >> Pdirection >> order;
        //以下4个if判断可以合并成2个，这里为了清晰选择全部列出
        //面朝里边，方向左边 next指针
        if(Pdirection == 0 && cur->direction == 0){
            for (int j = 0; j < order; j++){
                cur = cur->next;
            }
        }
        //面朝里边，方向右边 previous指针
        else if(Pdirection == 0 && cur->direction == 1){
            for (int j = 0; j < order; j++){
                cur = cur->previous;
            }
        }
        //面朝外边，方向左边 previous指针
        else if(Pdirection == 1 && cur->direction == 0){
            for (int j = 0; j < order; j++){
                cur = cur->previous;
            }
        }
        //面朝外边，方向右边 next指针
        else if(Pdirection == 1 && cur->direction == 1){
            for (int j = 0; j < order; j++){
                cur = cur->next;
            }
        }
    }
    cout << cur->names;
    return 0;
}