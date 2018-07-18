#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int &a,int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void sortvstavka(int *arr,int n)
{
	for(int i = 1; i < n; i++)
	{
		int x = arr[i];
		int j = i;
		while((j > 0)&&(arr[j-1] < x))
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = x;
		
	}
	
}
void merge(int* arr, int fs,int ls)
{
	int mid, st, fn;
	int *buf=new int[ls];
	mid = (fs + ls)/2;
	st = fs;
	fn = mid + 1;

	for (int j = fs; j <= ls; j++)
		if ((st <= mid) && ((fn > ls) || (arr[st] < arr[fn])))
		{
			buf[j]=arr[st];
			st++;
		}
		else
		{
			buf[j] = arr[fn];
			fn++;
		}
	for (int j = fs; j <= ls; j++) 
		arr[j] = buf[j];
		
} 
void merge_sort(int *arr,int fs,int ls)
{
	if (fs<ls)
	{
		int mid = (fs + ls)/2;
		merge_sort (arr, fs, mid);
		merge_sort (arr, mid+1, ls);
		merge(arr, fs, ls);

	}
}

void print(int *arr,int n)
{
	cout<<"massiv:"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << " "<< endl;
}
void main()
{
	int n,k,f=1;
	while(f !=3 )
	{
		cout << "Enter size of array"<< endl;
		cin >> n;

		int *arr = new int[n];
		int *brr = new int[n];

		srand(time(NULL));

		for(int i = 0; i < n; i++)
		{
			arr[i]=rand()% 81 - 40;
			brr[i]=rand()% 81 - 40;
		}
		cout << "1.Sort 'MERGE'"<< endl;
		cout << "2.Sort 'Vstavka'"<< endl;
		cin >> k;
		if (k == 1)
		{
			print(arr,n);
			cout << "Sort"<< endl;
			merge_sort(arr,0,n-1);
			print(arr,n);
		}
		if (k == 2)
		{
			print(brr,n);
			cout << "Sort"<< endl;
			sortvstavka(brr,n);
			print(brr,n);
		}

		cout << "1.Continue"<< endl;
		cout << "2.Exit"<< endl;
		cin>>f;
	
	}

	system("pause");	
}