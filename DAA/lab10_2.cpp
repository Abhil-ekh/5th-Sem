#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    int maxDeadline = 0;
    for (const auto& job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;
    for (const auto& job : jobs) {
        for (int j = job.deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }
    cout << "Selected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            cout << "J" << slot[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    cout << "Enter Deadline and Profit:\n";
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1; 
        cin >> jobs[i].deadline >> jobs[i].profit;
    }
    jobSequencing(jobs);
    return 0;
}