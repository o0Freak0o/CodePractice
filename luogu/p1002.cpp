#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdlib>

using namespace std;

int checkerboard[21][21] = {0};
int Dp_checkerboard[25][25] = {0};
int DP_HorseLocation[25][25] = {0};
int Horse_control_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Horse_control_y[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int Solider_move_x[2] = {0, 1};
int Solider_move_y[2] = {1, 0};
int Horse_x;
int Horse_y;
int B_x;
int B_y;
int Solider_x = 0;
int Solider_y = 0;
int Path_count = 0;


void Init();
void search(int x, int y);
//动态规划解法
void DP();

int main(){
    // Init();
    // search(0, 0);
    // cout << Path_count << endl;
    DP();
    return 0;
}

void DP(){
    cin >> B_x >> B_y >> Horse_x >> Horse_y;
    B_x += 2;
    B_y += 2;
    Horse_x += 2;
    Horse_y += 2;
    DP_HorseLocation[Horse_x][Horse_y] = 1;
    for (int i = 0; i < 8; i++){
        if(Horse_x + Horse_control_x[i] >= 2 && Horse_x + Horse_control_x[i] <= B_x && Horse_y + Horse_control_y[i] >= 2 && Horse_y + Horse_control_y[i] <= B_y){
            DP_HorseLocation[Horse_x + Horse_control_x[i]][Horse_y + Horse_control_y[i]] = 1;
        }
    }
    Dp_checkerboard[2][1] = 1;
    for (int i = 2; i <= B_x; i++){
        for (int j = 2; j <= B_y; j++){
            if (DP_HorseLocation[i][j] == 1)
                continue;
            else
                Dp_checkerboard[i][j] = Dp_checkerboard[i - 1][j] + Dp_checkerboard[i][j - 1];
        }
    }
    cout << Dp_checkerboard[B_x][B_y];
}

void Init(){
    cin >> B_x >> B_y >> Horse_x >> Horse_y;
    checkerboard[Horse_x][Horse_y] = 1;
    for (int i = 0; i < 8; i++){
        if(Horse_x + Horse_control_x[i] >= 0 && Horse_x + Horse_control_x[i] <= B_x && Horse_y + Horse_control_y[i] >= 0 && Horse_y + Horse_control_y[i] <= B_y){
            checkerboard[Horse_x + Horse_control_x[i]][Horse_y + Horse_control_y[i]] = 1;
        }
    }
    // for (int i = 0; i <= B_x; i++){
    //     for (int j = 0; j <= B_y; j++){
    //         cout << checkerboard[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
}

void search(int x, int y){
    if(x == B_x && x == B_y){
        Path_count++;
    }else{
        for (int i = 0; i < 2; i++){
            if( (x + Solider_move_x[i]) <= B_x && (y + Solider_move_y[i]) <= B_y
              && checkerboard[x + Solider_move_x[i]][y + Solider_move_y[i]] != 1){
                x += Solider_move_x[i];
                y += Solider_move_y[i];
                search(x, y);
                x -= Solider_move_x[i];
                y -= Solider_move_y[i];
            }else{
                continue;
            }
        }
    }
}