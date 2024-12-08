#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnAround;
    int waiting;
    int firstResponse;
    bool isFirstResponse;  
};

bool compareArrival(Process a, Process b)
{
    return a.arrival < b.arrival;
}

void printResults(const vector<Process> &processes, const vector<int> &completionOrder)
{
    int n = processes.size();
    int totalTurnAround = 0;
    int totalWaiting = 0;
    int totalResponse = 0;

    cout << "Process ID\tArrival \tBurst \tCompletion \tTurnaround \tWaiting \tResponse \n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t"
             << processes[i].arrival << "\t\t"
             << processes[i].burst << "\t\t"
             << processes[i].completion << "\t\t"
             << processes[i].turnAround << "\t\t"
             << processes[i].waiting << "\t\t"
             << processes[i].firstResponse - processes[i].arrival << "\n";

        totalTurnAround += processes[i].turnAround;
        totalWaiting += processes[i].waiting;
        totalResponse += (processes[i].firstResponse - processes[i].arrival);
    }

    cout << "\nCompletion Order: ";
    for (int i = 0; i < n; i++)
    {
        cout << completionOrder[i] << " ";
    }
    cout << endl;
    cout << "\nAverage Turnaround : " << (float)totalTurnAround / n << endl;
    cout << "Average Waiting : " << (float)totalWaiting / n << endl;
    cout << "Average Response : " << (float)totalResponse / n << endl;
}

void preemptiveSJF(vector<Process> &processes)
{
    int n = processes.size();
    int current = 0;
    int completed = 0;
    vector<int> completionOrder;

    while (completed < n)
    {
        int idx = -1;
        int minBurst = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival <= current && processes[i].remaining > 0 && processes[i].remaining < minBurst)
            {
                minBurst = processes[i].remaining;
                idx = i;
            }
        }
        if (idx == -1)
        {
            current++;
            continue;
        }
        if (processes[idx].isFirstResponse == false)
        {
            processes[idx].firstResponse = current;
            processes[idx].isFirstResponse = true;
        }
        processes[idx].remaining--;
        current++;
        if (processes[idx].remaining == 0)
        {
            processes[idx].completion = current;
            processes[idx].turnAround = processes[idx].completion - processes[idx].arrival;
            processes[idx].waiting = processes[idx].turnAround - processes[idx].burst;
            completionOrder.push_back(processes[idx].id);
            completed++;
        }
    }
    printResults(processes, completionOrder);
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter arrival  and burst  for Process " << i + 1 << ": ";
        cin >> processes[i].arrival >> processes[i].burst;
        processes[i].remaining = processes[i].burst; 
        processes[i].isFirstResponse = false;                
    }
    sort(processes.begin(), processes.end(), compareArrival);

    preemptiveSJF(processes);
    return 0;
}
