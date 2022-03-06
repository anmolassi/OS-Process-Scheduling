#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter the number of processes : ";
	int nprocess;
	cin>>nprocess;
	cout<<"Enter the burst time for each process : "<<endl;
	int burst[nprocess];
	int quantum;
	cout<<"Enter quantum"<<endl;
	cin>>quantum;
	for(int i=0;i<nprocess;i++)
	{
		cout<<"P"<<i+1<<"\t";
		cin>>burst[i];
	}
	int wait[nprocess];
    int rem_bt[nprocess];
    for (int i = 0 ; i < nprocess ; i++)
        rem_bt[i] = burst[i];
 
    int t = 0;
    while (1)
    {
        bool done = true;
        for (int i = 0 ; i < nprocess; i++)
        {
           if (rem_bt[i] > 0)
            {
                done = false; 
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wait[i] = t - burst[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
        break;
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
