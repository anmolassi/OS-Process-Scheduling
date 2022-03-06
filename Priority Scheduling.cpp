#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter the no. of process : ";
	int nprocess;
	cin>>nprocess;
	cout<<"Enter the burst time and priority of each process : "<<endl;
	int burst[nprocess];
	int priority[nprocess];
	int index[nprocess];
	for(int i=0;i<nprocess;i++)
	{
		cout<<"P"<<i+1<<endl;
		cout<<"Enter burst time : ";
		cin>>burst[i];
		cout<<"Enter the priority : ";
		cin>>priority[i];
		index[i]=i+1;
	}
	for(int i=1;i<nprocess;i++)
	{
		for(int j=0;j<nprocess-1;j++)
		{
			if(priority[i]>priority[j])
			{
				int temp= priority[j];
				priority[j]=priority[i];
				priority[i]=temp;
				int temp1=index[i];
				index[i]=index[j];
				index[j]=temp1;
			}
		}
	}
	int turnA[nprocess]={0};
	int wait[nprocess]={0};
	for(int i=1;i<nprocess;i++)
	{
		for(int j=0;j<i;j++)
		{
			wait[i]=wait[i]+burst[j];
		}
	}
	double avgTurn=0;
    double avgWait=0;
	for(int i=0;i<nprocess;i++)
	{
		turnA[i]=wait[i]+burst[i];
		avgWait+=wait[i];
		avgTurn+=turnA[i];
	}
	cout << "Process ID \t Priority\t Burst time\t Waiting Time\t Turnaround time\t" << endl;
	for(int i = 0; i < nprocess; i++)
	{
		cout << "P" << index[i] << "\t\t" << priority[i] << "\t\t" << burst[i] << " \t\t" << wait[i] <<"\t\t" << turnA[i] << endl;
	}
	cout << "\n Average Waiting Time : " << (avgWait/nprocess) << endl;
	cout << "\n Average Turn Around Time : " << (avgTurn/nprocess) << endl;
}
