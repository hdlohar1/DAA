#include <iostream.h>
#include <conio.h>

class HEAPIFY_MIN
{
	private:
		int*A,n;
	public:
		HEAPIFY_MIN(int size);
		void READ();
		void ADJUST(int no, int n);
		void HEAPIFY();
		void DISPLAY();

};
HEAPIFY_MIN :: HEAPIFY_MIN(int size)
{
	n = size;
	A= new int[n+1];
}
void HEAPIFY_MIN :: READ()
{
	for(int i=1; i<=n; i++)
	{
		cin>>A[i];
	}
}
void HEAPIFY_MIN :: ADJUST(int no, int n)
{
	int j, item;
	j = 2*no;
	item = A[no];
	while(j<=n)
	{
		if(j < n && A[j] > A[j+1])
		{
			j = j + 1;
		}
		if(item < A[j])
			break;
		else
			A[j/2] = A[j];
		j = 2*j;
	}
	A[j/2] = item;
}
void HEAPIFY_MIN :: HEAPIFY()
{
	for(int i= n/2; i>=1; i--)
	{
		ADJUST(i,n);
	}
}
void HEAPIFY_MIN :: DISPLAY()
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
	HEAPIFY_MIN obj(size);
	obj.READ();
	cout<<"\nYou Entered Elements are: ";
	obj.DISPLAY();
	obj.HEAPIFY();
	cout<<"\nElements after Creating MIN_HEAP: ";
	obj.DISPLAY();
	getch();
}
