#include "SeqList.h"
#include "iostream"
using namespace std;

template <class T>
SeqList<T>::SeqList(const T a[], int n)	//有参构造函数，使用含有n个元素的数组a初始化
{
	if (n>MAXSIZE) throw "数组长度超过线性表的最大长度";
	for (int i=0;i<n;i++)
		data[i]=a[i];
	length=n;
}

template <class T>
void SeqList<T>::PrintList()	//按序号依次遍历线性表中的各个数据元素
{
	cout << "按序号依次遍历线性表中的各个数据元素:" << endl;
	for (int i=0;i<length;i++)
		cout << data[i] << " ";
	cout << endl;
}

template <class T>
void SeqList<T>::Insert(int i, T x) //在线性表的第i个位置上插入值为x的新元素
{
	if (length>=MAXSIZE) throw "上溢";
	if ( i< 1 || i> length+1) throw "位置异常";
	for (int j=length;j>=i;j--) //从最后一个元素开始顺序后移，直到第i个为止
		data[j] = data[j-1];
	data[i-1] = x; //将x插入到线性表第i个位置
	length++;
}

template <class T>
T SeqList<T>::Delete(int i) //在线性表的第i个位置上插入值为x的新元素
{
	if (0==length) throw "下溢";
	if ( i< 1 || i> length) throw "位置异常";
	T x = data[i-1];	//将待删除元素暂存
	for (int j=i;j<length;j++) //从第i+1个元素（下标为i）开始顺序前移，直到最后一个元素
		data[j-1] = data[j];
	length--;
	return x;
}

template <class T>
T SeqList<T>::Get(int i) //获取线性表第i个位置上的元素
{
	if ( i< 1 || i> length) throw "查找位置非法";
	return data[i-1];	
}
template <class T>
int SeqList<T>::Locate(const T x)	//查找线性表中值为x的元素，找到后返回其位置
{
	for (int i=0;i<length;i++)
		if (x==data[i]) return i+1;
	return 0;	//查找失败
}

