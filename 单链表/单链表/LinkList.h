

const int NULL =0;

template <class T>
struct Node 
{
	T data;					//数据域
	struct Node <T> * next; //指针域，在这里<T>可省略
};

template <class T>
class LinkList
{
public:
	LinkList(){first = new Node <T>; first->next = 0;}//无参构造函数 //=NULL?
	LinkList(T a [], int n);//有参构造函数，使用含有n个元素的数组a初始化单链表
	~LinkList();			//析构函数
	int GetLength();		//获取线性表的长度
	Node <T> * Get(int i);			//获取线性表第i个位置上的元素结点地址
	int Locate (T x);		//查找线性表中值为x的元素，找到后返回其位置
	void Insert (int i, T x);//在线性表的第i个位置上插入值为x的新元素
	T Delete(int i);		//删除线性表第i个元素，并将该元素返回
	void PrintList();		//按次序遍历线性表中的各个数据元素 
	Node <T> * GetFirst(){return first;}
private:
	Node <T>* first;		//头指针
};