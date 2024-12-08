#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int responseTime;
};

bool compare(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}

void calculateTimes(vector<Process> &processes)
{
    int n = processes.size();
    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentTime < processes[i].arrivalTime)
        {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].responseTime = processes[i].waitingTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
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
    }

    sort(processes.begin(), processes.end(), compare);

    calculateTimes(processes);
    displayResults(processes);

    return 0;
}