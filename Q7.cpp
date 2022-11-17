//WAP to implement Round Robin
#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int processes[],int at[],int bt[],int n)
{
	cout<<endl<<endl<<setw(35)<<"\t\tProcess\t\tArrival Time\t\tBurst Time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t\t   P"<<i+1<<"\t\t\t"<<at[i]<<"\t\t     "<<bt[i]<<endl;
	}
}

double average(int *arr,int size)
{
	double avg=0.0;
	for(int i=0;i<size;i++)
		avg+=arr[i];
	avg=avg/size;
	return avg;
}

void findWaitingTime(int processes[], int n, int bt[], int wt[],int at[], int quantum)
{
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i]=bt[i];

    int t=0;

    while(1)
    {
        bool finish = true;
        for (int i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                finish = false;

                if (rem_bt[i] > quantum)
                {
                    t+=quantum;
                    rem_bt[i]-=quantum;
                }

                else
                {
                    t=t+rem_bt[i];
                    wt[i]=t-bt[i];

                    rem_bt[i]=0;
                }
            }
        }

        if (finish==true)
			break;
    }
    for (int i = 0 ; i < n ; i++)
        wt[i]-=at[i];
}


void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void printOutput(int wt[],int ta[],int n)
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
	int *processes,n,*bt,*at,*wt,*tat,quan;
	cout<<"Enter the number of processes"<<endl;
	cin>>n;
	processes=new int[n];
    bt=new int[n];
    at=new int[n];
    tat=new int[n];
    wt=new int[n];
    for(int i=0;i<n;i++)
	{
		cout<<"Enter the Arrival Time of process P"<<i+1<<" : ";
		cin>>at[i];
		cout<<"Enter the Burst Time of process P"<<i+1<<" : ";
		cin>>bt[i];
	}
    cout<<"\nEnter the quantum"<<endl;
    cin>>quan;
    printTable(processes,at,bt,n);
    findWaitingTime(processes, n, bt, wt,at, quan);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printOutput(wt,tat,n);
    return 0;
}
