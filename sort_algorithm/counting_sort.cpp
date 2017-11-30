// 计数排序Counting_Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void Counting_Sort(int* A,int* B,int size,int length)//A是输入序列，B是输出序列，size是A中数据的大小范围[0-size]，length为A的序列长度
{
	int* C=new int[size+1];//这个序列记录了[0-size]中的每个数在排好序中的序列中的index。
	int i;
	for(i=0;i<=size;i++)
		C[i]=0;//初始化时，每个C的每个项为0
	for(i=1;i<=length;i++)
	{
		C[A[i]]=C[A[i]]+1;//序列A中出现了C[i]个i，i为[0-size]中的整数。
	}
	for(i=1;i<=size;i++)
		C[i]=C[i]+C[i-1];//对于任意[0-size]中的整数i,序列A中有C[i]个整数不大于i。
	for(i=length;i>=1;i--)
	{
		B[C[A[i]]]=A[i];//将A[i]安排到C[A[i]]位置。因为A[i]应该安排在所有不大于A[i]的整数的尾部，所以这一步刚好把A[i]安排到，A[i]在有序列中的顺序。
		C[A[i]]=C[A[i]]-1;//为了处理相等情况。
	}
	delete C;
}
//无论何种情况时间复杂度为O(length+size)
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
    int length;//the length of the input array
	int size;//the size of the input data
	cout<<"please enter the length of the array"<<endl;
	cin>>length;
	cout<<"please enter the size of the data"<<endl;
	cin>>size;
	int* A=new int[length+1];//多出四字节，但是编程更简单了
	int* B=new int[length+1];
	A[0]=B[0]=0;
	for(int i=1;i<=length;i++)
		cin>>A[i];
	Counting_Sort(A,B,size,length);
	for(int i=1;i<=length;i++)
		cout<<B[i]<<" ";
	delete A;
	delete B;
	return 0;
}

