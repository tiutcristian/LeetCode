#include <vector>
#include <climits>
#include <iostream>
using namespace std;

double medianOf2(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    
      // If a[] has more elements, then call medianOf2 
      // with reversed parameters
    if (n > m)
        return medianOf2(b, a);
  
    int lo = 0, hi = n;
    while (lo <= hi) {
        int mid1 = (lo + hi) / 2;
        int mid2 = (n + m + 1) / 2 - mid1;

        // Find elements to the left and right of partition in a[]
        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        // Find elements to the left and right of partition in b[]
        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : b[mid2]);

        // If it is a valid partition
        if (l1 <= r2 && l2 <= r1) {
          
              // If the total elements are even, then median is 
              // the average of two middle elements
            if ((n + m) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
          
              // If the total elements are odd, then median is 
             // the middle element
            else
                return max(l1, l2);
        }

        // Check if we need to take lesser elements from a[]
        if (l1 > r2)
            hi = mid1 - 1;
      
        // Check if we need to take more elements from a[]
        else
            lo = mid1 + 1;
    }
    return 0;
}

int main() {
    vector<int> a = {1, 3, 8, 9, 15};
    vector<int> b = {7, 11, 18, 19, 21, 25};
    cout << medianOf2(a, b) << endl;
    return 0;
}