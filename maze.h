#include <iostream>
#include "node.h"	
#include "sq_stack.h"
#include "lk_stack.h"
#include "sq_list.h"
#include "lk_list.h"
#include "circ_queue.h"
#include "lk_queue.h"
using namespace std;

#define MAX_STEP 100000 
//用于记录坐标位置
typedef struct
{
    int x;
    int y;
}PosType;


/// <summary>
/// 打印迷宫信息
/// </summary>
/// <param name="maze">存储迷宫信息的二维动态数组</param>
/// <param name="rows">迷宫的行数</param>
/// <param name="cols">迷宫的列数</param>
void print_maze(int** maze, int rows, int cols)
{
    cout << "迷宫:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}
/// <summary>
/// 打印路径信息
/// </summary>
/// <param name="maze">存储迷宫信息的二维动态数组</param>
/// <param name="rows">迷宫的行数</param>
/// <param name="cols">迷宫的列数</param>
/// <param name="start">迷宫的起点</param>
/// <param name="end">迷宫的终点</param>
/// <param name="direc">存储机器人移动信息的一维动态数组</param>
void print_road(int** maze, int rows, int cols, PosType start, PosType end, int* direc)
{

    //复制迷宫
    char** maze_with_road = new char* [rows]; // 创建一个指向rows个int指针的指针数组
    for (int i = 0; i < rows; i++) {
        maze_with_road[i] = new char[cols];   // 创建每个行的指针，指向cols个int
        for (int j = 0; j < cols; j++) {
            maze_with_road[i][j] = maze[i][j] + '0';
        }
    }

    int q = 0;
    int x = start.x;
    int y = start.y;
    maze_with_road[x][y] = '*';
    while (direc[q] != -1)
    {
        switch (direc[q]) {
        case 1:
            y++;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            x--;
            break;
        default:
            cout << "direction error" << endl;
            break;
        }
        if (maze[x][y] == 1 || q > MAX_STEP) {
            cout << "road error" << endl;
        }
        maze_with_road[x][y] = '*';
        q++;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze_with_road[i][j] << ' ';
        }
        cout << endl;
    }
    // 打印路径长度
    cout << "求得的路径长度为:" << q << endl;
}


/// <summary>
/// 求得一条从起点到终点的通路
/// </summary>
/// <param name="maze">存储迷宫信息的二维动态数组</param>
/// <param name="rows">迷宫的行数</param>
/// <param name="cols">迷宫的列数</param>
/// <param name="start_point">迷宫的起点</param>
/// <param name="end_point">迷宫的终点</param>
/// <returns>存储机器人移动信息，保存到一维动态数组中</returns>
bool pass(int** maze, PosType curpos) {//判断当前道路是否能走通
    if (maze[curpos.x][curpos.y] == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool point(int** maze, PosType curpos) {//标记走过的路
    maze[curpos.x][curpos.y] = 2;
    return true;
}
bool isend(PosType curpos, PosType end_point) {//判断是否到达终点
    if (curpos.x == end_point.x && curpos.y == end_point.y) {
        return true;
    }
    else {
        return false;
    }
}
PosType next(PosType curpos, int direc) {//获取下一个位置
    switch (direc) {
    case 1:
        curpos.y++;
        break;
    case 2:
        curpos.x++;
        break;
    case 3:
        curpos.y--;
        break;
    case 4:
        curpos.x--;
        break;
    }
    return curpos;
}

int* search(int** maze, int rows, int cols, PosType start_point, PosType end_point)
{
    // 实验相关要求
    //1、用结构体PosType存储机器人的位置信息
    //2、机器人前进方向（东为1，南为2，西为3，北为4）：
    //   向东移动：y=y+1
    //   向南移动：x=x+1
    //   向西移动：y=y-1
    //   向北移动：x=x-1
    //3、输出结果为找到的从起点到终点的通路上，机器人移动的方向信息，最后用-1表示结束。
    // 输出结果示例()：
    //   * 标记了找到的从起点（1,1）到终点（4,4）的一条通路
    // 
    //                  1 1 1 1 1 1
    //                  1 * * * 0 1
    //                  1 0 1 * 1 1
    //                  1 0 0 * * 1
    //                  1 0 1 0 * 1
    //                  1 1 1 1 1 1
    // 
    //   那么，输出的一维动态数组内容应为：  1  1  2  2  1  2  -1，末尾的-1是结束的标识符。


    ////////////////////////////////////////////////////////////////////////////
    //------------------------------------start---------------------------------
    //请补全相关代码
    //1、初始化
    //初始化栈
    int maxSize = rows * cols;
    SqStack<int> returns(maxSize);
    SqStack<PosType> way(maxSize);
    //2、求路径
    PosType curpos = start_point;//设置起点,找下一个点
    PosType position = start_point;//当前的位置
    point(maze, position);
    way.Push(position);
    int count = 0;
    while (!isend(position, end_point)){
        for (int d = 1; d < 5; d++) {
            curpos = next(curpos, d);
            if (pass(maze, curpos)) {
                position = curpos;
                way.Push(position);
                point(maze, position);
                returns.Push(d);
                continue;
            }
            else if (!pass(maze, curpos) && d == 4) {
                if (way.Length() == 1) {
                    break;
                }
                else {
                    returns.Pop();
                    way.Pop(position);
                    curpos = position;
                }
            }
            else {
                curpos = position;
            }
            cout << "x:" << position.x << "y:" << position.y << endl;
            count++;
            if (count == 1) {
                break;
            }
        }
    } 

    //3、计算移动方向序列, 并保存到direc数组中
    //int m;
    //int* direc = new int[m];
    int m = returns.Length() + 1;
    int top;
    int* direc = new int[m];//创建一个指向m个int指针的指针数组
    for (int i = 0; i < m - 1; i++) {
        returns.Top(top);
        direc[m - 2 - i] = top;
        returns.Pop();
    }
    direc[m - 1] = -1;
    for (int i = 0; i < m; i++) {
        cout << " " << direc[i] << endl;
    }
    //打印迷宫信息
    print_maze(maze, rows, cols);
    //打印路径信息
    print_road(maze, rows, cols, start_point, end_point, direc);
    //------------------------------------end-----------------------------------
    ////////////////////////////////////////////////////////////////////////////
    //以下操作可以帮助你检查算法是否准确，最后评测时请注释掉。
    //打印迷宫信息
    //print_maze(maze, rows, cols);
    //打印路径信息
    //print_road(maze, rows, cols, start_point, end_point, direc);

    return direc;
}


