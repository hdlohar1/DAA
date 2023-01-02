#include <iostream.h>
#include <conio.h>

//INSERT MIN

class INSERT_MIN
{
	private:
		int*A,n;
	public:
		INSERT_MIN(int size);
		void READ();
		void INSERT(int);
		void CREATE_HEAP();
		void DISPLAY();
};
INSERT_MIN :: INSERT_MIN(int size)
{
	n = size;
	A= new int[n+1];
}
void INSERT_MIN :: READ()
{
	for(int i=1; i<=n; i++)
	{
	cin>>A[i];
	}
}
void INSERT_MIN :: INSERT(int node)
{
	int j, i, item;
	j = node; i= node/2; item = A[node];
	while(i> 0 && A[i] > item)
	{
		A[j] = A[i];
		j=i;
		i=i/2;
	}
	A[j] = item;
}
void INSERT_MIN :: CREATE_HEAP()
{
	for(int i= 2; i<=n; i++)
	{
		INSERT(i);
	}
}
void INSERT_MIN :: DISPLAY(){
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
	INSERT_MIN heap(size);

	heap.READ();
	cout<<"\nYou Entered Elements : ";
	heap.DISPLAY();
	heap.CREATE_HEAP();
	cout<<"\n\nElements after Creating MIN_HEAP: ";
	heap.DISPLAY();
	getch();
}


