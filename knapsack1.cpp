#include <iostream.h>
#include <conio.h>

class GREEDY
{
	private:
		float *W, *P, *R, *X, Max, Cu;
		int n;
	public:
		GREEDY(int size, float cap);
		void SET_DATA();
		void SORT_DATA();
		void KNAPSACK();
		void DISPLAY();
};
//------------------------------
GREEDY :: GREEDY(int size, float cap)
{
	Cu = cap;
	n = size;
	W = new float [n+1];	// stores the weights of items;
	P = new float [n+1];    // stores the price of items;
	R = new float [n+1];    // stores ratio of p/w;
	X = new float [n+1];    // stores the collected items;
}
//------------------------------
void GREEDY :: SET_DATA()
{
	for(int i=1; i<=n; i++)
	{
		cout<<"Enter the Weight of item "<<i<<" : ";
		cin>>W[i];
		cout<<"Enter the Profit of item "<<i<<" : ";
		cin>>P[i];
	}
}
//------------------------------
void GREEDY :: SORT_DATA()
{
	float temp;
	// calculate ratio p/w because we have profit of items as per unit;
	// calculate ratio of p/w and store that ratio values in that 'R' array;
	for(int i=1; i<=n; i++)
	{
		R[i] = P[i]/W[i];
	}
	// sort items in 'R'; using bubble sort; and rearrange all elements as per "R";
	for(i=1; i<=n-1; i++)
		for(int j=1; j<=n-i; j++)
			if(R[j] < R[j+1])
			{
				temp = R[j];
				R[j] = R[j+1];
				R[j+1] = temp;

				temp = P[j];
				P[j] = P[j+1];
				P[j+1] = temp;

				temp = W[j];
				W[j] = W[j+1];
				W[j+1] = temp;
			}
}
//------------------------------
void GREEDY :: KNAPSACK()
{
	for(int i=1; i<=n; i++)
	{
	   if(W[i] > Cu)
	   {
			break;
	   }
	   else
	   {
			X[i] = 1;
			Cu = Cu - W[i];
	   }
	}
	if(i <= n)
	{
		X[i] = Cu/W[i];
	}
}
//------------------------------
void GREEDY :: DISPLAY()
{
	float sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum = sum + (P[i] * X[i]);
	}
	cout<<"Your Maximum Profit is: "<<sum<<endl;

	// to check given dataset is proper or not;
	for(i = 1; i <= n; i++)
	{
		cout<<"Weight: "<<W[i]<<" Profit: "<<P[i]<<" Ratio : "<<R[i]<<endl;
		cout<<"Picked quantity of items: "<<X[i]<<endl<<endl;;
	}
}
//------------------------------
void main()
{
	clrscr();

	int size;
	float cap;
	cout<<"Enter the total number of items: ";
	cin>>size;
	cout<<"Enter the maximum capacity of sack: ";
	cin>>cap;


	GREEDY obj(size, cap);

	obj.SET_DATA();
	cout<<endl;

	obj.SORT_DATA();
	obj.KNAPSACK();
	obj.DISPLAY();
	getch();
}
