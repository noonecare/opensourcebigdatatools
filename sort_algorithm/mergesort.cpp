// 归并算法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void merge(int* A,int left,int right,int middle)//right是最后一个数的指标+1
{
	int i,j,k;
	i=j=k=0;
	int n=right-left+1;
	int* cpy=new int[n];
	while(k<n)
	{
		if(i>middle-left)
		{
			cpy[k++]=A[j+middle+1];
			j++;
		}
		if(j>right-middle-1)
		{
			cpy[k++]=A[i+left];
			i++;
		}
		if(i<=middle-left &&j<=right-middle-1&&A[i+left]<A[j+middle+1])
		{
			cpy[k++]=A[i+left];
			i++;
		}
		if(j<=right-middle-1 &&i<=middle-left&& A[i+left]>=A[j+middle+1])
		{
			cpy[k++]=A[j+middle+1];
			j++;
		}
	}
	for(k=0;k<n;k++)
		A[left+k]=cpy[k];
	delete cpy;
}
void merge1(int* A,int left,int right,int middle)
{
	int length=right-left+1;
	int* tmp=new int[length];
	int i,j,k;
	i=left;
	j=middle+1;
	for(k=0;k<length;)
	{
		if(i<=middle&&j<=right)
		{
			if(A[i]<=A[j])
				tmp[k++]=A[i++];
			else
				tmp[k++]=A[j++];
		}
		else
		{
			if(i>middle)
				tmp[k++]=A[j++];
			else
				tmp[k++]=A[i++];
		}
	}
	for(i=left;i<=right;i++)
		A[i]=tmp[i-left];
	delete tmp;
}
void mergesort1(int* A,int left,int right)
{
	if(right==left) return;
	if(right>left)
	{
		int middle=(left+right)/2;
		mergesort1(A,left,middle);
		mergesort1(A,middle+1,right);
		merge1(A,left,right,middle);
	}
}//merge1,mergesort1是我后来又写的归并排序的程序，我不明白为什么之前的merge，mergesort运行出错，感觉没有问题啊。
//归并算法的时间复杂度。T(n)=T(n/2)+T(n/2)+O(n)(n为偶数时候)，T(n)=T([n/2])+T([n/2]+1)+O(n).每个merge的for循环的每一步都会发生一步赋值一步（或两步）比较所以时间复杂度是O(n)。
//T(n)=n*T(1)+logn*O(n),所以T(n)=O(nlogn)。
void mergesort(int* A,int left,int right)
{
	int middle=(left+right)/2;
	if(right-left==0) ;
	else
	{
		mergesort(A,left,middle);
	mergesort(A,middle+1,right);
	merge(A,left,right,middle);
	}
}
#include<iostream>
#include<stdlib.h>
//这个程序，不知道怎么搞的：数列项数在8以下的时候对，8和8以上的时候运行错误。我操只是哪里出错了。
int _tmain(int argc, _TCHAR* argv[])
{
	int n;//number of the array
    std::cout<<"please enter the number of the array:"<<std::endl;
	std::cin>>n;
	int* A=new int[n];
	std::cout<<"please enter the array:"<<std::endl;
	for(int i=0;i<n;i++)
	{
		//std::cin>>A[i];一步一步输入比较烦，我给个随机给出A[i]的检测程序。
		A[i]=rand();
	}
	mergesort1(A,0,n-1);
	for(int i=0;i<n;i++)
		std::cout<<A[i]<<" ";
	delete A;
	return 0;
}

