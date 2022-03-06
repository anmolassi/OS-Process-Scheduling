#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter the number of processes : ";
	int nprocess;
	cin>>nprocess;
	cout<<"Enter the burst time for each process : "<<endl;
	int burst[nprocess];
	for(int i=0;i<nprocess;i++)
	{
		cout<<"P"<<i+1<<"\t";
		cin>>burst[i];
	}
	int wait[nprocess]={0};
	for(int i=0;i<nprocess;i++)
	{
		for(int j=0;j<i;j++)
		{
			wait[i]=wait[i]+burst[j];
		}
	}
	int turnA[nprocess];
	double avgWait=0;
	double avgTurn=0;
	cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
	for(int i=0;i<nprocess;i++)
	{
		turnA[i]=wait[i]+burst[i];
		avgWait+=wait[i];
		avgTurn+=turnA[i];
		cout<<"P["<<i+1<<"]\t\t"<<burst[i]<<"\t\t"<<wait[i]<<"\t\t"<<turnA[i]<<endl;
	}
	avgWait/=nprocess;
	avgTurn/=nprocess;
	cout<<"Average waiting time: "<<avgWait<<endl;
	cout<<"Average Turnaround Time: "<<avgTurn<<endl;
}
