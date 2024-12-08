#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime = 0;
    int turnaroundTime = 0;
    int responseTime = -1;
};

bool compare(const Process &a, const Process &b)
{
    return a.arrivalTime > b.arrivalTime;
}

void calculateTimes(vector<Process> &processes)
{
    int n = processes.size();
    int currentTime = 0;
    int completed = 0;
    queue<int> readyQueue;
    vector<bool> inQueue(n, false);

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (!inQueue[i] && processes[i].arrivalTime <= currentTime)
            {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }

        if (readyQueue.empty())
        {
            currentTime++;
            continue;
        }

        int index = readyQueue.front();
        readyQueue.pop();

        if (processes[index].responseTime == -1)
        {
            processes[index].responseTime = currentTime - processes[index].arrivalTime;
        }

        processes[index].remainingTime--;
        currentTime++;

        if (processes[index].remainingTime == 0)
        {
            processes[index].turnaroundTime = currentTime - processes[index].arrivalTime;
            processes[index].waitingTime = processes[index].turnaroundTime - processes[index].burstTime;
            completed++;
        }
        else
        {
            readyQueue.push(index);
        }
    }
}

void displayResults(const vector<Process> &processes)
{
    cout << left << setw(10) << "PID"
         << setw(15) << "Arrival Time"
         << setw(15) << "Burst Time"
         << setw(15) << "Waiting Time"
         << setw(15) << "Turnaround Time"
         << "Response Time" << endl;

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int totalResponseTime = 0;
    for (const auto &process : processes)
    {
        cout << left << setw(10) << process.pid
             << setw(15) << process.arrivalTime
             << setw(15) << process.burstTime
             << setw(15) << process.waitingTime
             << setw(15) << process.turnaroundTime
             << process.responseTime << endl;

        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnaroundTime;
        totalResponseTime += process.responseTime;
    }

    cout << "\nAverage Waiting Time: "
         << (double)totalWaitingTime / processes.size() << endl;
    cout << "Average Turnaround Time: "
         << (double)totalTurnaroundTime / processes.size() << endl;
    cout << "Average Response Time: "
         << (double)totalResponseTime / processes.size() << endl;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter Arrival Time and Burst Time for each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        cout << "Process " << processes[i].pid << ":\n";
        cout << "Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), compare);

    calculateTimes(processes);
    displayResults(processes);

    return 0;
}
