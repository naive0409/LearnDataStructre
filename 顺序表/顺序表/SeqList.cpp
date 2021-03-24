#include "SeqList.h"
#include "iostream"
using namespace std;

template <class T>
SeqList<T>::SeqList(const T a[], int n)	//�вι��캯����ʹ�ú���n��Ԫ�ص�����a��ʼ��
{
	if (n>MAXSIZE) throw "���鳤�ȳ������Ա����󳤶�";
	for (int i=0;i<n;i++)
		data[i]=a[i];
	length=n;
}

template <class T>
void SeqList<T>::PrintList()	//��������α������Ա��еĸ�������Ԫ��
{
	cout << "��������α������Ա��еĸ�������Ԫ��:" << endl;
	for (int i=0;i<length;i++)
		cout << data[i] << " ";
	cout << endl;
}

template <class T>
void SeqList<T>::Insert(int i, T x) //�����Ա�ĵ�i��λ���ϲ���ֵΪx����Ԫ��
{
	if (length>=MAXSIZE) throw "����";
	if ( i< 1 || i> length+1) throw "λ���쳣";
	for (int j=length;j>=i;j--) //�����һ��Ԫ�ؿ�ʼ˳����ƣ�ֱ����i��Ϊֹ
		data[j] = data[j-1];
	data[i-1] = x; //��x���뵽���Ա��i��λ��
	length++;
}

template <class T>
T SeqList<T>::Delete(int i) //�����Ա�ĵ�i��λ���ϲ���ֵΪx����Ԫ��
{
	if (0==length) throw "����";
	if ( i< 1 || i> length) throw "λ���쳣";
	T x = data[i-1];	//����ɾ��Ԫ���ݴ�
	for (int j=i;j<length;j++) //�ӵ�i+1��Ԫ�أ��±�Ϊi����ʼ˳��ǰ�ƣ�ֱ�����һ��Ԫ��
		data[j-1] = data[j];
	length--;
	return x;
}

template <class T>
T SeqList<T>::Get(int i) //��ȡ���Ա��i��λ���ϵ�Ԫ��
{
	if ( i< 1 || i> length) throw "����λ�÷Ƿ�";
	return data[i-1];	
}
template <class T>
int SeqList<T>::Locate(const T x)	//�������Ա���ֵΪx��Ԫ�أ��ҵ��󷵻���λ��
{
	for (int i=0;i<length;i++)
		if (x==data[i]) return i+1;
	return 0;	//����ʧ��
}

