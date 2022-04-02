#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;

char str[] = "";
const string a[10][5] = {
    {"#","#","#","#","#"},
    {"#","#","#","#","#"},
    {"#","a","b","c","#"},
    {"#","d","e","f","#"},
    {"#","g","h","i","#"},
    {"#","j","k","l","#"},
    {"#","m","n","o","#"},
    {"#","p","q","r","s"},
    {"#","t","u","v","#"},
    {"#","w","x","y","z"}
};
int count_[10] = {
    0, 0, 3, 3, 3, 3, 3, 4, 3, 4
    };

int main(){
    gets(str);
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    queue<string> q1;
    queue<string> q2;
    queue<string> q3;
    for (int i = 0; i < length; i++){
        for (int j = 0; j < count_[int(str[i] - '2') + 2];j++){
            if(i == 0){
                q1.push(a[int(str[i] - '2') + 2][j+1]);
                continue;
            }
            else{
                while(!q1.empty()){
                    string c = q1.front()+a[int(str[i] - '2') + 2][j+1];
                    q2.push(c);
                    q3.push(q1.front());
                    q1.pop();  
                }
                while (!q3.empty()){
                    q1.push(q3.front());
                    q3.pop();
                }
            }
        }
        if(i == 0){
            continue;
        }
        else{
while (!q1.empty()){
                q1.pop();
            }
        while (!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        
    }
    while (!q1.empty())
    {
        cout << q1.front() << endl;
        q1.pop();
    }
    return 0;
}