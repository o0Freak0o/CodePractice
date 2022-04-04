#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<stack>
#include<cstring>
#include<forward_list>

using namespace std;

char c;
int co=1;
int res_count = 1;
char res[62526];
int W;
int L;

int main(){

    while (c = getchar())
    {
        if(c == '\n')
            continue;
        else if(c == 'E')
            break;
        else {
            res[co] = c;
            co++;
        }
    }

    for (int i = 1; i <= co; i++){
        if(res[i] == 'W')
            W++;
        if(res[i] == 'L')
            L++;
        if(W >= 11 || L >= 11){
            if( abs(W - L) >= 2){
                cout << W << ":" << L;
                cout << endl;
                W = 0;
                L = 0;
            }
        }
    }
    cout << W << ":" << L;
    cout << endl;
    cout << endl;
    W = 0;
    L = 0;
    for (int i = 1; i <= co; i++){
        if(res[i] == 'W')
            W++;
        if(res[i] == 'L')
            L++;
        if(W >= 21 || L >= 21){
            if( abs(W - L) >= 2){
                cout << W << ":" << L;
                cout << endl;
                W = 0;
                L = 0;
            }
        }
    }
    cout << W << ":" << L;

    return 0;
}