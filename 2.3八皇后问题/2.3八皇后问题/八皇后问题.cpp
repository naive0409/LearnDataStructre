///*
//2.3 ��Ŀ 3����Ӧ��ʵ��
//��Ŀ���˻ʺ����⡣
//�˻ʺ����� 19 ������������ѧ�Ҹ�˹�� 1850 ������ġ����������ǣ��� 8*8 ������
//�Ϸ��� 8 ���ʺ�ʹ�䲻�ܻ��๥���������������ʺ󶼲��ܴ���ͬһ�С�ͬһ�С�ͬһб
//���ϡ�������㷨��ӡ���п��ܵİڷŷ�����
//��ʾ��
//1������ʹ�õݹ��ǵݹ����ַ���ʵ��
//2��ʵ��һ���ؼ��㷨���ж����������ʺ��Ƿ���ͬһ�С�ͬһ�к�ͬһб����
//*/
//#include <iostream>
//using namespace std;
//
//const int ArSize = 8;//��������ڼ������Ǽ��ʺ�
//int num = 0;
//void solve(bool arr[ArSize][ArSize], int row);
//bool check(bool arr[ArSize][ArSize], int row, int column);
//void outPut(bool arr[ArSize][ArSize]);
//
//int main()
//{
//    bool chessboard[ArSize][ArSize];
//    // �����ʼ��
//    for (auto& i : chessboard)
//    {
//        for (auto& j : i)
//        {
//            j = false;
//        }
//    }
//    solve(chessboard, 0);
//    cout << "�˻ʺ����⹲��" << num << "�ֽ⣡" << endl;
//    system("pause");
//    return 0;
//}
//// ���ݷ�
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
//// �жϻʺ������Ƿ�Ϲ�
//bool check(bool arr[ArSize][ArSize], int row, int column)
//{
//    if (row == 0)
//    {
//        return true;
//    }
//    int i, j;
//    // �ж������Ƿ��г�ͻ
//    for (i = 0; i < row; ++i)
//    {
//        if (arr[i][column])
//        {
//            return false;
//        }
//    }
//    i = row - 1;
//    j = column - 1;
//    // �ж���б�Խ����Ƿ��г�ͻ
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
//    // �жϸ�б�Խ����Ƿ��г�ͻ
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
//// ��ӡÿ����ȷ�Ľⷨ
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