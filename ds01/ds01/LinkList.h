

const int NULL =0;

template <class T>
struct Node 
{
	T data;					//������
	struct Node <T> * next; //ָ����������<T>��ʡ��
};

template <class T>
class LinkList
{
public:
	LinkList(){first = new Node <T>; first->next = 0;}//�޲ι��캯�� //=NULL?
	LinkList(T a [], int n);//�вι��캯����ʹ�ú���n��Ԫ�ص�����a��ʼ��������
	~LinkList();			//��������
	int GetLength();		//��ȡ���Ա�ĳ���
	Node <T> * Get(int i);			//��ȡ���Ա��i��λ���ϵ�Ԫ�ؽ���ַ
	int Locate (T x);		//�������Ա���ֵΪx��Ԫ�أ��ҵ��󷵻���λ��
	void Insert (int i, T x);//�����Ա�ĵ�i��λ���ϲ���ֵΪx����Ԫ��
	T Delete(int i);		//ɾ�����Ա��i��Ԫ�أ�������Ԫ�ط���
	void PrintList();		//������������Ա��еĸ�������Ԫ�� 
	Node <T> * GetFirst(){return first;}
private:
	Node <T>* first;		//ͷָ��
};