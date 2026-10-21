class Solution {
public:
    char smallest, largest;
    int cntLargest, cntSmallest;

    bool isSorted(string s) {
        smallest = 'z';
        largest = 'a';
        cntLargest = 0;
        cntSmallest = 0;

        bool flag = true;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && s[i] > s[i + 1])
                flag = false;

            if (smallest > s[i]) {
                cntSmallest = 1;
                smallest = s[i];
            } else if (smallest == s[i]) {
                cntSmallest++;
            }

            if (largest < s[i]) {
                cntLargest = 1;
                largest = s[i];
            } else if (largest == s[i]) {
                cntLargest++;
            }
        }

        return flag;
    }

    int minOperations(string s) {
        int len = s.size();

        if (isSorted(s)) return 0;
        if (len == 2) return -1;

        if (s[0] == largest && s[len - 1] == smallest){
            if(cntLargest>1 || cntSmallest>1) return 2;
            return 3;
        }

        if (s[0] == smallest || s[len - 1] == largest)
            return 1;

        if (s[0] == largest)
            return 2;

        return 2;
    }
};
