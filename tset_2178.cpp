//
//  tset_2178.cpp
//  algorithm_test
//
//  Created by 한병익 on 2016. 12. 28..
//  Copyright © 2016년 한병익. All rights reserved.
//

#include <iostream>
using namespace std;
/*
int main() {
    int row, col;
    int* back;
    char **maze;
  
    cin >> col >> row;
    
    maze = new char* [col];
    back = new int [row*col];
    
    //미로 생성
    for ( int i = 0 ; i < col ; i++) {
        maze[i] = new char[row];
    }
    
    for(int i = 0 ; i < col ; i ++) {
        for(int j = 0 ; j < row ; j++) {
            cin >> maze[i][j];
        }
    }
    
    int x = 0;
    int y = 0;
    int count = 0;
    bool check = true;
    
    maze[y][x] = '0';
    
    while (check) {
        if(x+1 < row && maze[y][x+1] == '1') {    //오른쪽에 길이 있을 경우
            x = x+1;
            back[count] = 1;
            count ++;
            maze[y][x] = '0';
        }
        else if (y+1 < col && maze[y+1][x] == '1') {  //아래쪽에 길이 있을 경우
            y = y+1;
            back[count] = 2;
            count ++;
            maze[y][x] = '0';
        }
        else if (y-1 >= 0 && maze[y-1][x] == '1') {   //위쪽에 길이 있을 경우
            y = y-1;
            back[count] = 3;
            count ++;
            maze[y][x] = '0';
        }
        else if (x-1 >= 0 && maze[y][x-1] == '1') {   //왼쪽에 길이 있을 경우
            x = x-1;
            back[count] = 4;
            count ++;
            maze[y][x] = '0';
        }
        else {      //길이 없는 경우 되돌아가기
            maze[y][x] = '0';
            switch(back[count-1]) {
        case 1:
            x=x-1;
            break;
        case 2:
            y=y-1;
            break;
        case 3:
            y=y+1;
            break;
        case 4:
            x=x+1;
            break;
        default:
            break;
            }
            count--;
        }
        
        cout << endl;
        for(int i = 0 ; i < col ; i++) {
            for(int j = 0 ; j < row ; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }
        cout << count+1 << endl << endl;
        //미로 끝에 도달할 경우 반복문 탈출
        if(x == row-1 && y == col-1)
            check = false;
    }
    
    cout << count+1 << endl;
    
}
*/

int min_count = 9999;
char maze[102][102];
bool visit[102][102];
void BFS(int x, int y, int count);
int col;
int row;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {
    for(int i = 0 ; i < 102 ; i++) {
        for(int j = 0 ; j < 102 ; j++) {
            maze[i][j] =0;
            visit[i][j]=0;
        }
    }
    cin >> col >> row;
    for(int i = 1 ; i < col+1 ; i++) {
        for(int j = 1 ; j < row+1 ; j++) {
            cin >> maze[i][j];
        }
    }
    BFS(1,1,0);
    cout << min_count<< endl;
}

void BFS(int x, int y, int count) {
    
    visit[x][y] = 1;
    
    if(x == row && y == col) {
        if( count < min_count) {
            min_count = count;
            return;
        }
    }
    
    for(int i = 0 ; i < 4 ; i++) {
        if(x+dx[i] > 0 && y+dy[i] > 0) {
            if(visit[x+dx[i]][y+dy[i]] == 0 && maze[x+dx[i]][y+dy[i]] == 1)
                BFS(x+dx[i],y+dy[i],count+1);
        }
    }
}
