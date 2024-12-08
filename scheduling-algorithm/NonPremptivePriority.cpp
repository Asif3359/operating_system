#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
    int priority;
    int waiting = 0;
    int turnaround = 0;
    int response = -1;
};

bool comparePriority(const Process &a, const Process &b)
{
    if (a.arrival == b.arrival)
        return a.priority < b.priority;
    return a.arrival < b.arrival;
}

void calculates(vector<Process> &processes)
{
    int n = processes.size();
    int current = 0;
    int completed = 0;
    vector<bool> isCompleted(n, false);

    while (completed < n)
    {
        int highestPriorityIndex = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!isCompleted[i] && processes[i].arrival <= current && processes[i].priority < highestPriority)
            {
                highestPriority = processes[i].priority;
                highestPriorityIndex = i;
            }
        }

        if (highestPriorityIndex == -1)
        {
            current++;
            continue;
        }

        if (processes[highestPriorityIndex].response == -1)
        {
            processes[highestPriorityIndex].response = current - processes[highestPriorityIndex].arrival;
        }

        current += processes[highestPriorityIndex].burst;
        processes[highestPriorityIndex].turnaround = current - processes[highestPriorityIndex].arrival;
        processes[highestPriorityIndex].waiting = processes[highestPriorityIndex].turnaround - processes[highestPriorityIndex].burst;

        isCompleted[highestPriorityIndex] = true;
        completed++;
    }
}

void displayResults(const vector<Process> &processes)
{
    cout << left << setw(10) << "PID"
         << setw(15) << "Arrival "
         << setw(15) << "Burst "
         << setw(15) << "Priority"
         << setw(15) << "Waiting "
         << setw(15) << "Turnaround "
         << "Response " << endl;

    int totalWaiting = 0;
    int totalTurnaround = 0;
    int totalResponse = 0;
    for (const auto &process : processes)
    {
        cout << left << setw(10) << process.pid
             << setw(15) << process.arrival
             << setw(15) << process.burst
             << setw(15) << process.priority
             << setw(15) << process.waiting
             << setw(15) << process.turnaround
             << process.response << endl;

        totalWaiting += process.waiting;
        totalTurnaround += process.turnaround;
        totalResponse += process.response;
    }

    cout << "\nAverage Waiting : "
         << (double)totalWaiting / processes.size() << endl;
    cout << "Average Turnaround : "
         << (double)totalTurnaround / processes.size() << endl;
    cout << "Average Response : "
         << (double)totalResponse / processes.size() << endl;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter Arrival , Burst , and Priority for each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        cout << "Process " << processes[i].pid << ":\n";
        cout << "Arrival : ";
        cin >> processes[i].arrival;
        cout << "Burst : ";
        cin >> processes[i].burst;
        cout << "Priority (lower number = higher priority): ";
        cin >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), comparePriority);

    calculates(processes);
    displayResults(processes);

    return 0;
}
