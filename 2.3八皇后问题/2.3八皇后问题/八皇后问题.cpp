///*
//2.3 题目 3——应用实验
//题目：八皇后问题。
//八皇后问题 19 世纪著名的数学家高斯于 1850 年提出的。他的问题是：在 8*8 的棋盘
//上放置 8 个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列、同一斜
//线上。请设计算法打印所有可能的摆放方法。
//提示：
//1、可以使用递归或非递归两种方法实现
//2、实现一个关键算法：判断任意两个皇后是否在同一行、同一列和同一斜线上
//*/
//#include <iostream>
//using namespace std;
//
//const int ArSize = 8;//这个数等于几，就是几皇后。
//int num = 0;
//void solve(bool arr[ArSize][ArSize], int row);
//bool check(bool arr[ArSize][ArSize], int row, int column);
//void outPut(bool arr[ArSize][ArSize]);
//
//int main()
//{
//    bool chessboard[ArSize][ArSize];
//    // 数组初始化
//    for (auto& i : chessboard)
//    {
//        for (auto& j : i)
//        {
//            j = false;
//        }
//    }
//    solve(chessboard, 0);
//    cout << "八皇后问题共有" << num << "种解！" << endl;
//    system("pause");
//    return 0;
//}
//// 回溯法
//void solve(bool arr[ArSize][ArSize], int row)
//{
//    for (int column = 0; column < ArSize; ++column)
//    {
//        arr[row][column] = true;
//        if (check(arr, row, column))
//        {
//            if (row + 1 == ArSize)
//            {
//                outPut(arr);
//            }
//            else
//            {
//                solve(arr, row + 1);
//            }
//        }
//        arr[row][column] = false;
//    }
//}
//// 判断皇后的落点是否合规
//bool check(bool arr[ArSize][ArSize], int row, int column)
//{
//    if (row == 0)
//    {
//        return true;
//    }
//    int i, j;
//    // 判断纵向是否有冲突
//    for (i = 0; i < row; ++i)
//    {
//        if (arr[i][column])
//        {
//            return false;
//        }
//    }
//    i = row - 1;
//    j = column - 1;
//    // 判断正斜对角线是否有冲突
//    while (i >= 0 && j >= 0)
//    {
//        if (arr[i][j])
//        {
//            return false;
//        }
//        --i;
//        --j;
//    }
//    i = row - 1;
//    j = column + 1;
//    // 判断负斜对角线是否有冲突
//    while (i >= 0 && j <= ArSize - 1)
//    {
//        if (arr[i][j])
//        {
//            return false;
//        }
//        --i;
//        ++j;
//    }
//    return true;
//}
//// 打印每种正确的解法
//void outPut(bool arr[ArSize][ArSize])
//{
//    ++num;
//    cout << "**********************" << num << "*********************" << endl;
//    for (int i = 0; i < ArSize; ++i)
//    {
//        for (int j = 0; j < ArSize; ++j)
//        {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << "*********************************************" << endl;
//}