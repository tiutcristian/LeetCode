#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<short> lastPos(256, -1);
    int len = s.size();
    int crtlen = 0, maxlen = 0;
    for (int i = 0; i < len; i++) {
        if (lastPos[s[i]] == -1) {
            crtlen++;
        } else {
            if (maxlen < crtlen) {
                maxlen = crtlen;
            }
            for (int j = i - crtlen; j < lastPos[s[i]]; j++) {
                lastPos[s[j]] = -1;
            }
            crtlen = i - lastPos[s[i]];
        }
        lastPos[s[i]] = i;
    }
    if (maxlen < crtlen) {
        maxlen = crtlen;
    }
    return maxlen;
}

int main () {
    string s = "abba";
    int l = lengthOfLongestSubstring(s);
    cout << l << endl;
    return 0;
}