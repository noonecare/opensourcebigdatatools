// 桶排序BucketSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
const int LIMIT=2000;//可以修改
struct node
{
	double data;
	node* next;
};//用链表实现桶bucket
node* newnode(double a)
{
	node* newnode1=new node;
	newnode1->data=a;
	newnode1->next=NULL;
	return newnode1;
}//对于每一个double a,给出一个以a为data,以NULL为next指针的节点。
void insert(node* L,double a)
{
	if(L==NULL) L=newnode(a);//如果链表为空，直接在表头插入新节点即可。
	else
	{
		node* tmp=L;//如果链表不为空，按照大小顺序，插入新节点到合适的位置。
		if(L->data>=a)
	{
		L=newnode(a);
		L->next=tmp;//如果链表的第一个元素就大于a，那么以a为data的节点应该插入到表头位置。
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
}//我在插入这一步就完成排序，也就是说这个程序会按顺序插入，这样更简单。
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
	//我要用rand()函数给出函数的输入。
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
//BucketSort假设输入序列是在[0，1）区间上的正态分布(uniform distribution)，没有这个假设，算法就失去了价值。
//在这个假设下，分析BucketSort的average case running time(平均时间复杂度)，是这个算法最有价值的地方。详情参见《算法导论》第8节sorting in lineartime 中的BucketSort部分。
