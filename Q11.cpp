//WAP to implement SRTF process scheduling
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int *wt,*at,*bt,*ta,*temp_bt,*temp_at,n;
vector<int> v;

int linSearch(int element,int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==element)
			return i;
	}
	return -1;
}

double average(int *arr,int size)
{
	double avg=0.0;
	for(int i=0;i<size;i++)
		avg+=arr[i];
	avg=avg/size;
	return avg;
}

int sum(int *arr,int size)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	return sum;
}

void input()
{
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	wt=new int[n];
	at=new int[n];
	bt=new int[n];
	ta=new int[n];
	temp_bt=new int[n];
	temp_at=new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the Arrival Time of process P"<<i+1<<" : ";
		cin>>at[i];
		cout<<"Enter the Burst Time of process P"<<i+1<<" : ";
		cin>>bt[i];
	}
	for(int i=0;i<n;i++)
	{
		wt[i]=0;
		ta[i]=0;
	}
	for(int i=0;i<n;i++)
		temp_bt[i]=bt[i];
	for(int i=0;i<n;i++)
		temp_at[i]=at[i];
}

void printTable()
{
	cout<<endl<<endl<<setw(35)<<"\t\tProcess\t\tArrival Time\t\tBurst Time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t\t   P"<<i+1<<"\t\t\t"<<at[i]<<"\t\t     "<<bt[i]<<endl;
	}
}

void runProcess(int time)
{
	int minTime=v[0],temp=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<minTime)
		{
			minTime=v[i];
			temp=i;
		}	
	}
	int pos=linSearch(v[temp],temp_bt,n);
	v[temp]--;
	temp_bt[pos]--;
	if(temp_bt[pos]==0)
	{
		ta[pos]=time-at[pos];
		wt[pos]=ta[pos]-bt[pos];
		temp_bt[pos]=-1;
	}
}

void pushProcess(int minTime)
{
	for(int i=0;i<n;i++)
	{
		if(temp_at[i]<minTime)
		{
			if(temp_bt[i]>0)
			{
				v.push_back(temp_bt[i]);
			}
		}	
	}
}

void schedule()
{
	int totalTime=sum(bt,n);

	for(int time=1;time<=totalTime;time++)
	{
		pushProcess(time);
		runProcess(time);
		v.clear();
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