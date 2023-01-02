#include<iostream.h>
#include<conio.h>
class MAX_MIN
{
	private:
		int *A,p,q,max,min,n,m;
	public:
		MAX_MIN(int);
		void READ();
		void DISPLAY();
		void MAXMIN(int,int,int&,int&);
};
MAX_MIN ::MAX_MIN(int par)
{
	n=par;
	A=new int[n+1];
}
void MAX_MIN:: READ()
{
	for(int i=1;i<=n;i++)
	{
		cin>>A[i];
	}
}
void MAX_MIN :: DISPLAY()
{
	for(int i=1;i<=n;i++)
	{
		cout<<A[i]<<" ";
	}
}
void MAX_MIN :: MAXMIN(int p,int q,int &max, int &min)
{
	int fmax,fmin,hmax,hmin;
	if(p==q)
	{
		max=min=A[p];
	}
	else
	{
		if(p==q-1)
		{
			if(A[p]>A[q])
			{
				max=A[p];
				min=A[q];
			}
			else
			{
				max=A[q];
				min=A[p];
			}
		}
		else
		{
			m=(p+q)/2;
			MAXMIN(p,m,fmax,fmin);
			MAXMIN(m+1,q,hmax,hmin);

			if(fmax > hmax)
			{
				max=fmax;
			}
			else
			{
				max=hmax;
			}
			if(fmin<hmin)
			{
				min=fmin;
			}
			else
			{
				min=hmin;
			}
		}
	}
}
void main()
{
	clrscr();
	int size,max,min;
	cout<<"\n Enter the size of List ";
	cin>>size;
	cout<<"\n Enter Elements for MaxMin List ";
	MAX_MIN m(size);
	m.READ();
	cout<<"\n Your Elements is : ";
	m.DISPLAY();
	m.MAXMIN(1,size,max,min);
	cout<<"\n MAX is : "<<max<<"\t MIN is : "<<min;
	getch();
}