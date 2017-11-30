// ��������Counting_Sort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
void Counting_Sort(int* A,int* B,int size,int length)//A���������У�B��������У�size��A�����ݵĴ�С��Χ[0-size]��lengthΪA�����г���
{
	int* C=new int[size+1];//������м�¼��[0-size]�е�ÿ�������ź����е������е�index��
	int i;
	for(i=0;i<=size;i++)
		C[i]=0;//��ʼ��ʱ��ÿ��C��ÿ����Ϊ0
	for(i=1;i<=length;i++)
	{
		C[A[i]]=C[A[i]]+1;//����A�г�����C[i]��i��iΪ[0-size]�е�������
	}
	for(i=1;i<=size;i++)
		C[i]=C[i]+C[i-1];//��������[0-size]�е�����i,����A����C[i]������������i��
	for(i=length;i>=1;i--)
	{
		B[C[A[i]]]=A[i];//��A[i]���ŵ�C[A[i]]λ�á���ΪA[i]Ӧ�ð��������в�����A[i]��������β����������һ���պð�A[i]���ŵ���A[i]���������е�˳��
		C[A[i]]=C[A[i]]-1;//Ϊ�˴�����������
	}
	delete C;
}
//���ۺ������ʱ�临�Ӷ�ΪO(length+size)
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
	int* A=new int[length+1];//������ֽڣ����Ǳ�̸�����
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

