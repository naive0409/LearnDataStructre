const int MAXSIZE = 1000;  //����˳������󳤶�



template <class T>         //����ģ����SeqList
class SeqList
{
public:
	SeqList(){length=0;}	//�޲ι��캯��
	SeqList(const T a[], int n);	//�вι��캯����ʹ�ú���n��Ԫ�ص�����a��ʼ��
	int GetLength(){return length;}	//��ȡ���Ա�ĳ���
	T Get(int i);			//��ȡ���Ա��i��λ���ϵ�Ԫ��
	int Locate(T x);		//�������Ա���ֵΪx��Ԫ�أ��ҵ��󷵻���λ��
	void Insert(int i, T x);//�����Ա�ĵ�i��λ���ϲ���ֵΪx����Ԫ��
	T Delete(int i);		//ɾ�����Ա��i��Ԫ�أ�������Ԫ�ط���
	void PrintList();		//������������Ա��еĸ�������Ԫ�� 
private:
	T data [MAXSIZE];		//�洢���Ա�����Ԫ�ص�����
	int length;				//���Ա�ĳ���
};
