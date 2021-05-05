#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
int main(void)
{
	htTree* codeTree = buildTree("I love FishC.com!");      //使用较多的指定字符串创建huffman树
	hlTable* codeTable = buildTable(codeTree);              //使用创建的huffman树创建Table表
	encode(codeTable, "I love FishC.com!");                 //使用Table表，对指定字符串进行编码压缩
	decode(codeTree, "010101110");                          //使用该huffman树，解压指定编码的字符

	return 0;
}
