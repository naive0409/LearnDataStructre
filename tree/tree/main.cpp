#include "tree.cpp"
#include <iostream>
using namespace std;
#define MAXSIZE 100
void main()
{
	char buf[MAXSIZE]={'A','B','C','D','E','G',0,0,0,'F',0,0,'H'};
    BiTree<char> ChBiTree;
	ChBiTree.Create(ChBiTree.Root(),buf,1);
    
	ChBiTree.Preorder(ChBiTree.Root());
	cout<<endl;
	
	ChBiTree.Inorder(ChBiTree.Root());
	cout<<endl;
	
	ChBiTree.Postorder(ChBiTree.Root());
	cout<<endl;
    
	ChBiTree.Levelorder(ChBiTree.Root());
	cout<<endl;

	cout<<ChBiTree.CountLeaf(ChBiTree.Root())<<endl;
	cout<<ChBiTree.Count(ChBiTree.Root())<<endl;
	int depth=0;
	cout<<ChBiTree.Depth(ChBiTree.Root(),depth)<<endl;

    Node<char>* p;
	cout<<ChBiTree.Lookup(ChBiTree.Root(),'C',p)<<endl;

	ChBiTree.CopyTree(ChBiTree.Root(),p);

	ChBiTree.Preorder1(p);
	cout<<endl;
	
	ChBiTree.Inorder1(p);
	cout<<endl;
	
	cout<<"后序遍历"<<endl;
	ChBiTree.Postorder1(p);
	cout<<endl;
	
	//线索化
    Node<char>* Thrt;
	ChBiTree.InorderThreading(Thrt,p);
    ChBiTree.InorderThread(Thrt);
    cout<<endl;

	cout<<endl;
	//思考题
	Node<char>* root;
	char PreBuf[]="ABDEFCGH";
	char InBuf[] ="DBFEAGHC";
	int i=0;
	ChBiTree.Create(root,PreBuf,i,InBuf,0,7);
	ChBiTree.Postorder(root);
	cout<<endl;
	ChBiTree.Levelorder(root);
	cout<<endl;
}