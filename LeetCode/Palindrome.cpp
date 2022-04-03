#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stack>
#include<cstring>
using namespace std;

char str[] = "n";
char str_fu[] = "n";

stack<char> s;
//链表初始化函数
bool isPalin(char str[], int size){
    if (size == 1)
        return true;
    for (int i = 0; i < size; i++){
        s.push(str[i]);
    }
    for (int i = 0; i < size; i++){
        char c = s.top();
        str_fu[i] = c;
        s.pop();
    }
    for (int i = 0; i < size; i++){
        if(i == size-1 && str[i] == str_fu[i])
            return true;
        if(str[i] == str_fu[i])
            continue;
        else
            return false;
    }
}
int main(){
    cin >> str;
    bool res = isPalin(str, strlen(str));
    cout << res;
}