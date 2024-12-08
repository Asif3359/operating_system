#include <iostream>
#include <vector>
using namespace std;

void displayState(const vector<int> &available, const vector<vector<int>> &max,
                  const vector<vector<int>> &allocation, const vector<vector<int>> &need)
{
    int n = max.size();    
    int m = max[0].size(); 

    cout << "\nCurrent State:\n";
    cout << "Available Resources: ";
    for (int i = 0; i < m; i++)
    {
        cout << available[i] << " ";
    }
    cout << "\n\nMaximum Resources Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << max[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nAllocation Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << allocation[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nNeed Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafeState(const vector<int> &available, const vector<vector<int>> &allocation, const vector<vector<int>> &need)
{
    int n = allocation.size();    
    int m = allocation[0].size(); 

    vector<int> work = available;
    vector<bool> finish(n, false);
    vector<int> safeSequence;

    int count = 0;
    while (count < n)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found)
        {
            cout << "System is not in a safe state!\n";
            return false;
        }
    }

    cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i : safeSequence)
    {
        cout << "P" << i << " ";
    }
    cout << endl;

    return true;
}

int main()
{
    int n, m;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resource types: ";
    cin >> m;

    vector<int> available(m);
    vector<vector<int>> max(n, vector<int>(m));
    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));

    cout << "Enter the available resources:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }

    cout << "Enter the Maximum Resources Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "Enter the Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
            need[i][j] = max[i][j] - allocation[i][j]; 
        }
    }

    displayState(available, max, allocation, need);

    isSafeState(available, allocation, need);

    return 0;
}
