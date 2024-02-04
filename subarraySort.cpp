#include <iostream>
#include <vector>

using namespace std;

bool outOfOrder(vector<int> arr, int i) {
    if ( i == 0 ) {
        return arr[i] > arr[i+1];
    }
    else if ( i == arr.size()-1 ) {
        return arr[i] < arr[i-1];
    }
    else {
        return ( arr[i] < arr[i-1] ) || ( arr[i+1] < arr[i] ); 
    }
}

pair<int,int> subArraySort(vector<int> array) {
    int smallest = INT_MAX;
    int largest = INT_MIN;

    int n = array.size() - 1;
    for (int i = 0; i < n; i++) {
        if ( outOfOrder(array, i) ) {
            largest = max( largest, array[i] );
            smallest = min( smallest, array[i] );
        }
    }

    int first = 0;
    while ( smallest >= array[first] ) {
        first++;
    }

    int second = n;
    while ( largest <= array[second] ) {
        second--;
    }

    if ( (first > -1) && (second > -1) )
        return {first, second};
    else 
        return {-1, -1};
}

int main(void) {
    vector<int> array = {1,2,3,4,5,8,6,7,9,10,11};
    pair<int,int> subarray = subArraySort(array);

    cout << subarray.first << " " << subarray.second << endl;

    return 0;
}