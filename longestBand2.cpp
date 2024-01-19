#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findLongestBand(vector<int> numbers) {
    int longestBand = 0;

    // insert all the numbers in a lookup set
    unordered_set<int> lookup_s;
    for (int n: numbers) {
        lookup_s.insert(n);
    }

    // iterate over the numbers
    for (int current: numbers) {
        int previous = current - 1;
        if (lookup_s.find(previous) == lookup_s.end()) {
            int count = 1;
            int next = current + 1;
            while (lookup_s.find(next) != lookup_s.end()) {
                count++;
                next++;
            }
            longestBand = max(count, longestBand);
        }
    }

    return longestBand;
}

int main(void) {
    vector<int> numbers = {1,9,3,0,18,5,2,4,10,7,12,6};

    cout << findLongestBand(numbers) << endl;

    return 0;
} 