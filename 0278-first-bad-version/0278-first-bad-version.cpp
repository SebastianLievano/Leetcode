// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int last = n, first = 0, pivot;
        while(first <= last){
            pivot = first + (last - first)/2;
            if(isBadVersion(pivot)){
                last = pivot - 1;
            }
            else{
                first = pivot + 1;
            }
        }
        return first;
    }
};