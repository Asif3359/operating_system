#include <bits/stdc++.h>
using namespace std;

void calculateTimes(const vector<pair<int, int>> &processes, int n, vector<int> &completionTime, vector<int> &waitingTime, vector<int> &turnaroundTime, vector<int> &responseTime)
{
    completionTime[0] = processes[0].first + processes[0].second;
    responseTime[0] = processes[0].first;

    for (int i = 1; i < n; i++)
    {
        completionTime[i] = max(completionTime[i - 1], processes[i].first) + processes[i].second;
        responseTime[i] = max(completionTime[i - 1], processes[i].first);
    }

    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = completionTime[i] - processes[i].first;
        waitingTime[i] = turnaroundTime[i] - processes[i].second;
    }
}

void printProcessDetails(const vector<pair<int, int>> &processes, int n, const vector<int> &completionTime, const vector<int> &waitingTime, const vector<int> &turnaroundTime, const vector<int> &responseTime)
{
    cout << "ID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\t\tResponse\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << processes[i].first << "\t" << processes[i].second
             << "\t" << completionTime[i] << "\t\t" << turnaroundTime[i]
             << "\t\t" << waitingTime[i] << "\t\t" << responseTime[i] << "\n";
    }
}

void printAvgDetails(int n, const vector<int> &turnaroundTime, const vector<int> &waitingTime, const vector<int> &responseTime)
{
    double avgTurnaroundTime = accumulate(turnaroundTime.begin(), turnaroundTime.end(), 0.0) / n;
    double avgWaitingTime = accumulate(waitingTime.begin(), waitingTime.end(), 0.0) / n;
    double avgResponseTime = accumulate(responseTime.begin(), responseTime.end(), 0.0) / n;

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time: " << avgTurnaroundTime << "\n";
    cout << "Average Waiting Time: " << avgWaitingTime << "\n";
    cout << "Average Response Time: " << avgResponseTime << "\n";
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<pair<int, int>> processes(n);
    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i].first >> processes[i].second;
    }

    vector<int> completionTime(n), waitingTime(n), turnaroundTime(n), responseTime(n);

    calculateTimes(processes, n, completionTime, waitingTime, turnaroundTime, responseTime);
    printProcessDetails(processes, n, completionTime, waitingTime, turnaroundTime, responseTime);
    printAvgDetails(n, turnaroundTime, waitingTime, responseTime);

    return 0;
}

/*

Enter the number of processes: 5
Enter arrival time and burst time for each process:
2 6
5 2
1 8
0 3
4 4
ID      Arrival Burst   Completion      Turnaround      Waiting         Response
1       2       6       8               6               0               2
2       5       2       10              5               3               8
3       1       8       18              17              9               10
4       0       3       21              21              18              18
5       4       4       25              21              17              21
Average Turnaround Time: 14.00
Average Waiting Time: 9.40
Average Response Time: 11.80

*/