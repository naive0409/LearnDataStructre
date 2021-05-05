#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
int main(void)
{
	htTree* codeTree = buildTree("I love FishC.com!");      //ʹ�ý϶��ָ���ַ�������huffman��
	hlTable* codeTable = buildTable(codeTree);              //ʹ�ô�����huffman������Table��
	encode(codeTable, "I love FishC.com!");                 //ʹ��Table����ָ���ַ������б���ѹ��
	decode(codeTree, "010101110");                          //ʹ�ø�huffman������ѹָ��������ַ�

	return 0;
}
