#include<bits/stdc++.h>
using namespace std;

char inp[14];
int main(){
    for (int i = 1; i < 14; i++)
    scanf("%c",&inp[i]);
    // int language = int(inp[1]);
    // int perss = int(inp[3]*100+inp[4]*10+inp[5]);
    // int num = int(inp[7]*10000+inp[8]*1000+inp[9]*100+inp[10]*10+inp[11]);
    if(inp[13]!='X'){
    int identity = int(inp[13]-'0');
    int identity_cal = int(int(inp[1]-'0')+int(inp[3]-'0')*2+int(inp[4]-'0')*3+int(inp[5]-'0')*4+int(inp[7]-'0')*5+int(inp[8]-'0')*6+int(inp[9]-'0')*7+int(inp[10]-'0')*8+int(inp[11]-'0')*9)%11;
    if(identity == identity_cal)
    cout<<"Right";
    else
    {
        if(identity_cal==10)
        inp[13]='X';
        else
        inp[13] = identity_cal+'0';
        for (int i = 1; i < 14; i++)
        cout<<inp[i];
    }}
    else{
        char identity = 'X';
        int identity_cal = int(int(inp[1]-'0')+int(inp[3]-'0')*2+int(inp[4]-'0')*3+int(inp[5]-'0')*4+int(inp[7]-'0')*5+int(inp[8]-'0')*6+int(inp[9]-'0')*7+int(inp[10]-'0')*8+int(inp[11]-'0')*9)%11;
        if(identity_cal == 10)
        cout<<"Right";
        else
        {
            inp[13] = identity_cal+'0';
            for (int i = 1; i < 14; i++)
            cout<<inp[i];
        }
    }
    return 0;
}