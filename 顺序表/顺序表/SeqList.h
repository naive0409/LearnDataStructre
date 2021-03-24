const int MAXSIZE = 1000;  //定义顺序表的最大长度



template <class T>         //定义模板类SeqList
class SeqList
{
public:
	SeqList(){length=0;}	//无参构造函数
	SeqList(const T a[], int n);	//有参构造函数，使用含有n个元素的数组a初始化
	int GetLength(){return length;}	//获取线性表的长度
	T Get(int i);			//获取线性表第i个位置上的元素
	int Locate(T x);		//查找线性表中值为x的元素，找到后返回其位置
	void Insert(int i, T x);//在线性表的第i个位置上插入值为x的新元素
	T Delete(int i);		//删除线性表第i个元素，并将该元素返回
	void PrintList();		//按次序遍历线性表中的各个数据元素 
private:
	T data [MAXSIZE];		//存储线性表数据元素的数组
	int length;				//线性表的长度
};
