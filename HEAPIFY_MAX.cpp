#include <iostream.h>
#include <conio.h>

//HEAPIFY_MAX

class HEAPIFY_MAX
{
	private:
		int*A,n;
	public:
		HEAPIFY_MAX(int size);
		void READ();
		void ADJUST(int node, int n);
		void HEAPIFY();
		void DISPLAY();

};
HEAPIFY_MAX :: HEAPIFY_MAX(int size)
{
	n = size;
	A= new int[n+1];
}
void HEAPIFY_MAX :: READ()
{
	for(int i=1; i<=n; i++)
	{
		cin>>A[i];
	}
}
void HEAPIFY_MAX :: ADJUST(int node, int n)
{
	int j, item;
	j = 2*node;
	item = A[node];
	while(j<=n)
	{
		if(j < n && A[j] < A[j+1])
		{
			j = j + 1;
		}
		if(item>A[j])
			break;
		else
		{
			A[j/2] = A[j];
			j = 2*j;
		}
	}
	A[j/2] = item;
}
void HEAPIFY_MAX :: HEAPIFY()
{
	for(int i= n/2; i>=1; i--)
	{
		ADJUST(i,n);
	}
}
void HEAPIFY_MAX :: DISPLAY()
{
	for(int i=1; i<=n; i++)
	{
		cout<<A[i]<<" ";
	}
}
void main()
{
	clrscr();
	int size;
	cout<<"Enter the size of list: ";
	cin>>size;
	HEAPIFY_MAX heap(size);

	heap.READ();
	cout<<"\nYou Entered Elements are: ";
	heap.DISPLAY();
	heap.HEAPIFY();
	cout<<"\nElements after Creating MAX_HEAP: ";
	heap.DISPLAY();
	getch();
}

