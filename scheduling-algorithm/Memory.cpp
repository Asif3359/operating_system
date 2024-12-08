#include <iostream>
#include <vector>
using namespace std;

// Function for First Fit allocation
void firstFit(const vector<int> &blockSize, const vector<int> &processSize)
{
    int n = blockSize.size();
    int m = processSize.size();
    vector<int> allocation(m, -1);
    vector<bool> used(n, false); // DP array to track used blocks

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                used[j] = true; // Mark block as used
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

// Function for Best Fit allocation
void bestFit(const vector<int> &blockSize, const vector<int> &processSize)
{
    int n = blockSize.size();
    int m = processSize.size();
    vector<int> allocation(m, -1);
    vector<bool> used(n, false); // DP array to track used blocks

    for (int i = 0; i < m; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            used[bestIdx] = true; // Mark block as used
        }
    }

    cout << "\nBest Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

// Function for Worst Fit allocation
void worstFit(const vector<int> &blockSize, const vector<int> &processSize)
{
    int n = blockSize.size();
    int m = processSize.size();
    vector<int> allocation(m, -1);
    vector<bool> used(n, false); // DP array to track used blocks

    for (int i = 0; i < m; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            used[worstIdx] = true; // Mark block as used
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << "\n";
        else
            cout << "Not Allocated\n";
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of memory blocks: ";
    cin >> n;
    vector<int> blockSize(n);
    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> m;
    vector<int> processSize(m);
    cout << "Enter the size of each process:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> processSize[i];
    }

    firstFit(blockSize, processSize);
    bestFit(blockSize, processSize);
    worstFit(blockSize, processSize);

    return 0;
}
