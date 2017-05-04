//

#include "stdafx.h"
void InsertSort(int* A,int length)
{
	int j;
	int key;
	int i;
	for(j=1;j<length;j++)
	{
		key=A[j];
		i=j-1;
		while(i>=0&&A[i]>key)
		{
			A[i+1]=A[i];
			i--;
		}
		A[i]=key;
	}
}
#include<iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int length;
	cout<<"please enter the length of the array:"<<endl;
	cin>>length;
	int* A=new int[length];
	for(int i=0;i<length;i++)
		A[i]=rand();
	InsertSort(A,length);
	for(int i=0;i<length;i++)
		cout<<A[i]<<" ";
	return 0;
}

