//#include "iostream"
//using namespace std;
//
//template<class T, int N>
// class CStack{
//     T item[N];
//     int SP;	// 栈的当前位置
// public:
//	CStack(void);
//	~CStack(void);
//	void push(T e);	// 压栈
//	T pop(void);		// 弹栈
//      T top(void) const;	// 获得栈顶值
//};
//template<class T,int N> CStack<T,N>::CStack(void){  SP=-1;  }
//template<class T,int N> CStack<T,N>::~CStack(void){   }
//template<class T,int N> 
//void CStack<T,N>::push(T e)
//{  if(SP>=N)  cout<<"error."<<endl;
//    item[++SP]=e;
//}
//template<class T,int N> 
//T CStack<T,N>::pop(void)
//{  if(SP<0)  cout<<"error."<<endl;
//    return item[SP--];
//}
//template<class T,int N> T CStack<T,N>::top() const
//{  if(SP<0)   cout<<"error."<<endl;
//    return item[SP];
//}
//void main(void)				
//{    CStack<float, 30> x ;	 // 创建一个类对象x
//      x.push(2.5);
//	cout<<x.top()<<endl;
//	CStack<int, 10> y ;	//  创建一个类对象y
//      y.push(-5);
//	cout<<y.pop()<<endl;
//}
//
