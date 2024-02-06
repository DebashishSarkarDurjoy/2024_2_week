#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int> nums) {
    int n = nums.size();

    pair<int,int> pa[n];
    for (int i = 0; i < n; i++) {
        pa[i].first = nums[i];
        pa[i].second = i;
    }

    // for (auto p: pa) {
    //     cout << p.first << " ";
    // }
    // cout << endl;
    // for (auto p: pa) {
    //     cout << p.second << " ";
    // }
    // cout << endl;

    sort(pa, pa+n);

    // cout << endl;

    //     for (auto p: pa) {
    //     cout << p.first << " ";
    // }
    // cout << endl;
    // for (auto p: pa) {
    //     cout << p.second << " ";
    // }
    // cout << endl;


    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cycle = 0;
        int node = i;
        while (!visited[node]) {
            visited[node] = true;
            cycle++;
            node = pa[node].second;
        }
        if (cycle) ans += (cycle-1);

        // cout << cycle << endl;
    }

    return ans;
}

int main(void) {
    vector<int> numbers = {2,4,5,1,3};

    cout << minSwaps(numbers) << endl;


    return 0;
}