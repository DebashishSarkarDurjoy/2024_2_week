#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int minSwaps(vector<int> nums) {
    int n = nums.size();

    pair<int,int> pa[n];
    for (int i = 0; i < nums.size(); i++) {
        pa[i] = {nums[i], i}; 
    }

    sort(pa, pa+n);

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
        if (cycle) ans += (cycle - 1);
    }



    return ans;
}

int main(void) {
    vector<int> numbers = {2,4,5,1,3};
    cout << minSwaps(numbers) << endl;

    return 0;
}