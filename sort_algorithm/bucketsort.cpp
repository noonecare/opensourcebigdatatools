// Ͱ����BucketSort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
const int LIMIT=2000;//�����޸�
struct node
{
	double data;
	node* next;
};//������ʵ��Ͱbucket
node* newnode(double a)
{
	node* newnode1=new node;
	newnode1->data=a;
	newnode1->next=NULL;
	return newnode1;
}//����ÿһ��double a,����һ����aΪdata,��NULLΪnextָ��Ľڵ㡣
void insert(node* L,double a)
{
	if(L==NULL) L=newnode(a);//�������Ϊ�գ�ֱ���ڱ�ͷ�����½ڵ㼴�ɡ�
	else
	{
		node* tmp=L;//�������Ϊ�գ����մ�С˳�򣬲����½ڵ㵽���ʵ�λ�á�
		if(L->data>=a)
	{
		L=newnode(a);
		L->next=tmp;//�������ĵ�һ��Ԫ�ؾʹ���a����ô��aΪdata�Ľڵ�Ӧ�ò��뵽��ͷλ�á�
	}
	else
	{
		while(tmp->next!=NULL&&tmp->next->data<a)
			tmp=tmp->next;
		node* tmp1=tmp->next;
		tmp->next=newnode(a);
		tmp->next->next=tmp1;
	}
	}
}//���ڲ�����һ�����������Ҳ����˵�������ᰴ˳����룬�������򵥡�
void BucketSort(double* A,int length)
{
	node** B=new node*[length];
	int i,k;
	for(i=0;i<length;i++)
		B[i]=NULL;
    for(i=0;i<length;i++)
	{
		k=A[i]*length;
		insert(B[k],A[i]);
	}
	node* tmp;
	k=0;
	for(i=0;i<length;i++)
	{
		tmp=B[i];
		while(tmp!=NULL)
		{
			A[k++]=tmp->data;
			tmp=tmp->next;
		}
	}
	delete B;

}
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int length;
	cout<<"please enter the length of the array"<<endl;
	cin>>length;
	double* A=new double[length];
	//cout<<"please enter the array, every member is a real number between [0,1)"<<endl;
	//��Ҫ��rand()�����������������롣
	double a;
	for(int i=0;i<length;i++)
	{
		a=rand()%LIMIT;
		A[i]=a/LIMIT;
	}
	BucketSort(A,length);
	for(int i=0;i<length;i++)
		cout<<A[i]<<" ";
	return 0;
}
//BucketSort����������������[0��1�������ϵ���̬�ֲ�(uniform distribution)��û��������裬�㷨��ʧȥ�˼�ֵ��
//����������£�����BucketSort��average case running time(ƽ��ʱ�临�Ӷ�)��������㷨���м�ֵ�ĵط�������μ����㷨���ۡ���8��sorting in lineartime �е�BucketSort���֡�
