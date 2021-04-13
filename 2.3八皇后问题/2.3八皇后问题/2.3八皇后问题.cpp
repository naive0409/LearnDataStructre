/*
2.3 题目 3——应用实验
题目：八皇后问题。
八皇后问题 19 世纪著名的数学家高斯于 1850 年提出的。他的问题是：在 8*8 的棋盘
上放置 8 个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列、同一斜
线上。请设计算法打印所有可能的摆放方法。
提示：
1、可以使用递归或非递归两种方法实现
2、实现一个关键算法：判断任意两个皇后是否在同一行、同一列和同一斜线上
*/

#include <iostream>
using namespace std;

int answer = 0;

void print(bool arr[8][8])
{
    answer++;
    printf("Answer No.%d:\n", answer);
    for (int i = 0; i < 8; i++)
    {   
        cout << "\t";
        for (int j = 0; j < 8; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "\n\n";
}

bool check(bool arr[8][8], int row, int column)
{
    int r, c;
    //不会在一行里放两个棋子，所以不用判定是不是在同一行
    
    //在一列吗
    for (r = 0; r < row; r++)
        if (arr[r][column]) return 0;//同一列已经有棋子了

    //斜对角线:左下右上
    r = row - 1;
    c = column + 1;
    while (r >= 0 && c <= 7)
    {
        if (arr[r][c])  return 0;//对角线已经有棋子了
        r--; c++;
    }

    //斜对角线:左上右下
    r = row - 1;
    c = column - 1;
    while (r >= 0 && c >= 0)
    {
        if (arr[r][c])  return 0;//对角线已经有棋子了
        r--; c--;
    }

    return 1;
}

void queen(bool arr[8][8], int row)
{
    for (int c = 0; c < 8; c++)
    {
        arr[row][c] = 1;//放一个棋子试试
        if (check(arr, row, c))//如果能放的话
        {
            if (row == 7) print(arr);
            //整个棋盘都检测完了,就输出吧
            else queen(arr, row + 1);
            //能放就先放这儿,再考虑下一个棋子(它一定在下一行)
        }
        arr[row][c] = 0;    //放不了就别放了，
    }                       //然后再看看右边的位置能不能放(回溯)
}

void main()
{
    bool chessboard[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            chessboard[i][j] = 0;//初始化数组

    queen(chessboard, 0);//从第一行开始放棋子

    cout << "We have " << answer << " answers to the question in total." << endl;
}