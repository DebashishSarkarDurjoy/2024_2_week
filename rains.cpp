#include <iostream>
#include <vector>

using namespace std;

int findUnitsOfWater(vector<int> rains) {
    int totalUnits = 0;
    int n = rains.size();

    vector<int> highestLeft(n, -1);
    vector<int> highestRight(n, -1);

    highestLeft[0] = rains[0];
    highestRight[n-1] = rains[n-1];

    for (int i = 0; i <= (n-1) -1; i++) {
        
        if ( highestLeft[i] < rains[i+1] ) {
            highestLeft[i+1] = rains[i+1];
        }
        else {
            highestLeft[i+1] = highestLeft[i];
        }

        if ( highestRight[n-1 -i] < rains[n-2 -i] ) {
            highestRight[n-2 -i] = rains[n-2 -i];
        }
        else {
            highestRight[n-2 -i] = highestRight[n-1 -i];
        }

    }

    for (int i = 0; i < n; i++) {
        cout << highestLeft[i] << " ";
    } cout << endl;
    for (int i = 0; i < n; i++) {
        cout << highestRight[i] << " ";
    } cout << endl;

    for (int i = 0; i < n; i++) {
        totalUnits += min(highestLeft[i], highestRight[i]) - rains[i];
    }

    return totalUnits;
}

int main(void) {
    vector<int> rains = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << findUnitsOfWater(rains) << endl;

    return 0;
}