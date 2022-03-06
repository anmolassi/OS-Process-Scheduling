#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter the no. of processes : ";
	int nprocess;
	cin>>nprocess;
	cout<<"Enter the burst time for each process : "<<endl;
	int burst[nprocess];
	int index[nprocess];
	for(int i=0;i<nprocess;i++)
	{
		cout<<"P"<<i+1<<"\t";
		cin>>burst[i];
		index[i]=i+1;
	}
	int wait[nprocess]={0};
	int turnA[nprocess]={0};
	for(int i=0;i<nprocess;i++)
	{
		for(int j=0;j<nprocess;j++)
		{
			if(burst[i] < burst[j])
			{
				int temp = burst[i];
				burst[i] = burst[j];
				burst[j] = temp;
				
				int temp1 = index[i];
				index[i] = index[j];
				index[j] = temp1;
			}
		}
	}
	for(int i=1;i<nprocess;i++)
	{
		for(int j=0;j<i;j++)
		{
			wait[i]=wait[i]+burst[j];
		}
	}
	double avgTurn=0,avgWait=0;
	for(int i=0;i<nprocess;i++)
	{
		turnA[i]=wait[i]+burst[i];
		avgTurn+=turnA[i];
		avgWait+=wait[i];
	}
	cout << "Process ID \t Burst Time\t Turnaround Time\t Waiting Time\t" << endl;
	for(int i = 0; i < nprocess; i++)
	{
		cout << "P" << index[i] <<"\t\t " << burst[i] << " \t\t " << turnA[i] << " \t\t\t " << wait[i] << endl;
	}
	cout << "Average Waiting Time : " << (avgWait/nprocess) << endl;
	cout << "Average Turn Around Time : " << (avgTurn/nprocess) << endl;
	return 0;
}
