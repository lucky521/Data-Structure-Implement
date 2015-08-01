#include <stdio.h>
//向堆中加入新元素并调整
void MinHeapFixup(int a[], int i)
{
	int j, temp;
	if(i==0)
		return;

	temp = a[i];	
	j = (i-1)/2; // j is i's parent
	while(j>=0 && i!=0)
	{
		if(a[j]<=temp)
			break;
		a[i] = a[j];
		i = j;
		j = (i-1)/2;
	}
	a[i] = temp;
}

void MinHeapAddNumber(int a[], int idx,int value)
{
	a[idx] = value;
	MinHeapFixup(a, idx);
}

//将当前的最小元素取出并调整
void MinHeapFixdown(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i+1;
	while(j<n)
	{
		if(j+1<n && a[j+1]<a[j])
			j++;
		if(a[j]>=temp)
			break;
		a[i] = a[j];
		i = j;
		j = 2*i+1;
	}
	a[i] = temp;
}

void MinHeapDelNumber(int a[], int idx)
{
	int tmp;
	tmp = a[0];
	a[0] = a[idx];
	a[idx] = tmp;
	MinHeapFixdown(a, 0, idx);
}

void HeapSort(int a[], int n)
{
	int i;
	//add everyone to heap
	for(i=0;i<n;i++)
		MinHeapAddNumber(a, i, a[i]);
	
	for(i=n-1;i>0;i--)
	{
	//	printf("%d ",a[0]);
		MinHeapDelNumber(a, i);
	}
	//printf("%d\n", a[0]);
	
}

int main()
{
	int i,n;
	int a[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	HeapSort(a, n);

	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	return 1;
}