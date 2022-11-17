//WAP to implement FCFS process scheduling
#include <iostream>
#include <iomanip>

using namespace std;

int *wt,*at,*bt,*ta,n;

double average(int *arr,int size)
{
	double avg=0.0;
	for(int i=0;i<size;i++)
		avg+=arr[i];
	avg=avg/size;
	return avg;
}

void input()
{
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	wt=new int[n];
	at=new int[n];
	bt=new int[n];
	ta=new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the Arrival Time of process P"<<i+1<<" : ";
		cin>>at[i];
		cout<<"Enter the Burst Time of process P"<<i+1<<" : ";
		cin>>bt[i];
	}
}

void printTable()
{
	cout<<endl<<endl<<setw(35)<<"\t\tProcess\t\tArrival Time\t\tBurst Time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t\t   P"<<i+1<<"\t\t\t"<<at[i]<<"\t\t     "<<bt[i]<<endl;
	}
}

int toBeScheduled()
{
	int minPos;
	for(int i=0;i<n;i++)
		if(at[i]!=-1)
		{
			minPos=i;
			break;
		}
	for(int i=0;i<n;i++)
	{
		if(at[i]!=-1)
		{
			if(at[i]<at[minPos])
				minPos=i;
			else if(at[i]==at[minPos])
				minPos=(i<minPos)?i:minPos;
		}
	}
	return minPos;
}

void schedule()
{
	int count=0,time=0;
	while(count<n)
	{
		int pos=toBeScheduled();
		time+=bt[pos];
		ta[pos]=time-at[pos];
		wt[pos]=ta[pos]-bt[pos];
		at[pos]=-1;
		count++;
	}
}

void printOutput()
{
	cout<<"\n"<<setw(35)<<"\t\tProcess\t\tWait Time\t\tTurn Around Time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t\t   P"<<i+1<<"\t\t    "<<wt[i]<<"\t\t\t   "<<ta[i]<<endl;
	}
	cout<<"\n";
	cout<<"Average Wait Time="<<average(wt,n)<<endl;
	cout<<"Average Turn Around Time="<<average(ta,n)<<endl;
}

int main()
{
	input();
	printTable();
	schedule();
	printOutput();
	return 1;
}