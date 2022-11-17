//WAP to implement Non-Preemptive Priority process scheduling
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int *wt,*at,*bt,*ta,*p,*temp_at,*temp_p,n;
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

void input()
{
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	wt=new int[n];
	at=new int[n];
	bt=new int[n];
	ta=new int[n];
	p=new int[n];
	temp_at=new int[n];
	temp_p=new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the Arrival Time of process P"<<i+1<<" : ";
		cin>>at[i];
		cout<<"Enter the Burst Time of process P"<<i+1<<" : ";
		cin>>bt[i];
		cout<<"Enter the Priority of process P"<<i+1<<" : ";
		cin>>p[i];
	}
	for(int i=0;i<n;i++)
		temp_at[i]=at[i];
	for(int i=0;i<n;i++)
		temp_p[i]=p[i];
}

void printTable()
{
	cout<<endl<<endl<<setw(35)<<"\t\tProcess\t\tArrival Time\t\tBurst Time\t\tPriority"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t\t   P"<<i+1<<"\t\t\t"<<at[i]<<"\t\t     "<<bt[i]<<"\t\t\t  "<<p[i]<<endl;
	}
}

int toBeScheduled()
{
	int minPriority=v[0],temp=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<minPriority)
		{
			minPriority=v[i];
			temp=i;
		}	
	}
	v.erase(temp+v.begin());
	int minPos=linSearch(minPriority,temp_p,n);
	temp_p[minPos]=-1;
	return minPos;
}

int minArrivalTime()
{
	int minPos;
	for(int i=0;i<n;i++)
		if(temp_at[i]!=-1)
		{
			minPos=i;
			break;
		}
	for(int i=0;i<n;i++)
	{
		if(temp_at[i]!=-1)
		{
			if(temp_at[i]<temp_at[minPos])
				minPos=i;
			else if(temp_at[i]==temp_at[minPos])
				minPos=(i<minPos)?i:minPos;
		}
	}
	return minPos;
}

void schedule()
{
	int count=0,time=0,arrivalTime=temp_at[minArrivalTime()];

	while(count<n)
	{
		if(v.size()<n)
		{
			for(int i=0;i<n;i++)
			{
				if(temp_at[i]!=-1)
				{
					if(temp_at[i]<=arrivalTime)
					{
						v.push_back(p[i]);
						temp_at[i]=-1;
					}
				}
			}
		}
		int pos=toBeScheduled();
		time+=bt[pos];
		ta[pos]=time-at[pos];
		arrivalTime=ta[pos];
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