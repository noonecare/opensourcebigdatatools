// 堆排序heapsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void exchange(int& a,int& b)
{
	int c=a;
	a=b;
	b=c;
}
inline int parent(int i){return i/2;}
inline int left(int i){return 2*i;}
inline int right(int i){return 2*i+1;}//由于我要用到这三个函数，所以下标和之前的程序有所不同
void Max_Heaprif(int *A,int i,int Asize)
{
	int l,r,largest;
	l=left(i);
	r=right(i);
	largest=i;
	if(l>Asize) return;
	if(l<=Asize)
	{
		if(A[largest-1]<A[l-1])
			largest=l;
	}
	if(r<=Asize)
	{
		if(A[largest-1]<A[r-1])
			largest=r;
	}
	if(i!=largest)
	{
	exchange(A[i-1],A[largest-1]);
	Max_Heaprif(A,largest,Asize);
	}
}
void Build_Max_Heap(int* A,int Asize)
{
	int length=Asize/2;
	int i;
	for(i=length;i>=1;i--)
	{
		Max_Heaprif(A,i,Asize);
	}
}
void Heap_Sort(int* A,int Asize)
{
	Build_Max_Heap(A,Asize);
	int i;
	for(i=Asize;i>=2;i--)
	{
		exchange(A[0],A[i-1]);
		Asize--;
		Max_Heaprif(A,1,Asize);
	}
}
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout<<"please enter the number of the array"<<endl;
	cin>>n;
	int* A=new int[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	Heap_Sort(A,n);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	return 0;
}

