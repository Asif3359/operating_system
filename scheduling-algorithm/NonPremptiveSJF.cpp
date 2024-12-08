#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
    int waiting = 0;
    int turnaround = 0;
    int response = -1;
};

bool compare(const Process &a, const Process &b)
{
    if (a.arrival == b.arrival)
        return a.burst < b.burst;
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
        int shortestIndex = -1;
        int shortestBurst = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!isCompleted[i] && processes[i].arrival <= current && processes[i].burst < shortestBurst)
            {
                shortestBurst = processes[i].burst;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1)
        {
            current++;
            continue;
        }

        if (processes[shortestIndex].response == -1)
        {
            processes[shortestIndex].response = current - processes[shortestIndex].arrival;
        }

        current += processes[shortestIndex].burst;
        processes[shortestIndex].turnaround = current - processes[shortestIndex].arrival;
        processes[shortestIndex].waiting = processes[shortestIndex].turnaround - processes[shortestIndex].burst;

        isCompleted[shortestIndex] = true;
        completed++;
    }
}

void displayResults(const vector<Process> &processes)
{
    cout << left << setw(10) << "PID"
         << setw(15) << "Arrival "
         << setw(15) << "Burst "
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

    cout << "Enter Arrival  and Burst  for each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        cout << "Process " << processes[i].pid << ":\n";
        cout << "Arrival : ";
        cin >> processes[i].arrival;
        cout << "Burst : ";
        cin >> processes[i].burst;
    }

    sort(processes.begin(), processes.end(), compare);

    calculates(processes);
    displayResults(processes);

    return 0;
}
