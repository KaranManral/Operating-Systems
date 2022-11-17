#include<iostream>
using namespace std;
  
void firstFit(int blockSize[], int m, 
              int processSize[], int n)
{
    int allocation[n];

    for(int i=0;i<n;i++)
        allocation[i]=-1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
  
                blockSize[j] -= processSize[i];
  
                break;
            }
        }
    }
  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" 
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
  
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
  
    for(int i=0;i<n;i++)
        allocation[i]=-1;
  
    for (int i=0; i<n; i++)
    {
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
  
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
  
            blockSize[bestIdx] -= processSize[i];
        }
    }
  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" 
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void worstFit(int blockSize[], int m, int processSize[],
                                                 int n)
{
    int allocation[n];
 
    for(int i=0;i<n;i++)
        allocation[i]=-1;
 
    for (int i=0; i<n; i++)
    {
        int wstIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
 
        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;

            blockSize[wstIdx] -= processSize[i];
        }
    }
 
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t" 
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int *blockSize,*processSize,blocks,n;
    cout<<"Enter the number of blocks in the memory"<<endl;
    cin>>blocks;
    blockSize=new int[blocks];
    for(int i=0;i<blocks;i++)
    {
        cout<<"Enter size of block "<<i+1<<" : ";
        cin>>blockSize[i];
    }
    cout<<"Enter the number of Processes"<<endl;
    cin>>n;
    processSize=new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter size of process "<<i+1<<" : ";
        cin>>processSize[i];
    }
    int temp_blockSize[blocks];  
    int temp_processSize[n];
    int temp1_blockSize[blocks];  
    int temp1_processSize[n];
    for(int i=0;i<blocks;i++)
        temp_blockSize[i]=blockSize[i];
    for(int i=0;i<n;i++)
        temp_processSize[i]=processSize[i];
    for(int i=0;i<blocks;i++)
        temp1_blockSize[i]=blockSize[i];
    for(int i=0;i<n;i++)
        temp1_processSize[i]=processSize[i];
    cout<<endl<<"First Fit"<<endl;
    firstFit(temp_blockSize,blocks, temp_processSize, n);
    cout<<endl<<"Best Fit"<<endl<<"-------------------------------------------------------------------------------------------------------------------\n\n"<<endl;
    bestFit(temp1_blockSize,blocks, temp1_processSize, n);
    cout<<endl<<"Worst Fit"<<endl<<"-------------------------------------------------------------------------------------------------------------------\n\n"<<endl;
    worstFit(blockSize,blocks, processSize, n);
    return 0 ;
}