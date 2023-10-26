#include <iostream>
#include "maze.h"
using namespace std;

#define MAX_STEP 100000 

/// <summary>
/// 检查求得的路径是否是一条从起点到终点的通路
/// </summary>
/// <param name="maze">存储迷宫信息的动态二维数据</param>
/// <param name="direc">存储路径（方向）信息的动态一维数组</param>
/// <param name="start_point">迷宫起点</param>
/// <param name="end_point">迷宫终点</param>
/// <returns>true:是一条通路; false:不是</returns>
bool road_check(int** maze, int* direc, PosType start_point, PosType end_point)
{
	if (direc == NULL) {
		cout << "error" << endl;
		return false;
	}

	int q = 0;
	int x = start_point.x;
	int y = start_point.y;
	while (direc[q] != -1)
	{
		//根据机器人行走方向（东为1，南为2，西为3，北为4），更新到达的位置。
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
			cout << "error" << endl;
			return false;
		}
		if (maze[x][y] == 1 || q > MAX_STEP)
		{
			cout << "error" << endl;
			return false;
		}
		q++;
	}
	if (x != end_point.x || y != end_point.y)
	{
		cout << "error" << endl;
		return false;
	}
	return true;
}


int main()
{

	//int rows, cols;
	//std::cin >> rows >> cols;

	//int** matrix = new int* [rows]; // 创建一个指向rows个int指针的指针数组
	//for (int i = 0; i < rows; i++) {
	//    matrix[i] = new int[cols]; // 创建每个行的指针，指向cols个int
	//}
	//for (int i = 0; i < rows; i++) {
	//    for (int j = 0; j < cols; j++) {
	//        std::cin >> matrix[i][j];
	//    }
	//}


 //   int rows = 10;    //迷宫的行
 //   int cols = 10;    //迷宫的列

 //   //迷宫数组,1代表禁止通过,0代表允许通过
	//int matrix[10][10] =
	//{
	//{1,1,1,1,1,1,1,1,1,1},
	//{1,0,0,1,0,0,0,1,0,1},
	//{1,0,0,1,0,0,0,1,0,1},
	//{1,0,0,0,0,1,1,0,0,1},
	//{1,0,1,1,1,0,0,0,0,1},
	//{1,0,0,0,1,0,0,0,0,1},
	//{1,0,1,0,0,0,1,0,0,1},
	//{1,0,1,1,1,0,1,1,0,1},
	//{1,1,0,0,0,1,0,0,0,1},
	//{1,1,1,1,1,1,1,1,1,1},
	//};


	int rows = 20;    //迷宫的行
	int cols = 20;    //迷宫的列

	//迷宫数组,1代表禁止通过,0代表允许通过
	int matrix[20][20] =
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	int** maze = new int* [rows]; // 创建一个指向rows个int指针的指针数组
	for (int i = 0; i < rows; i++) {
		maze[i] = new int[cols]; // 创建每个行的指针，指向cols个int
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			maze[i][j] = matrix[i][j];
		}
	}

	//设置迷宫起点和终点
	PosType start_point;
	start_point.x = 1;
	start_point.y = 1;

	PosType end_point;
	end_point.x = rows - 2;
	end_point.y = cols - 2;

	// 输入迷宫,返回用方向表示的搜索路径序列;
	int* direc = search(maze, rows, cols, start_point, end_point);

	// 检验迷宫网格：判断找到一条起点至终点的通路是否准确；
	if (road_check(maze, direc, start_point, end_point))
	{
		cout << "ok" << endl;
	}
	else
	{
		cout << "error" << endl;
	}
	return 0;
}