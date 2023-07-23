#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> dp;

bool scrambleCheck(string& s, string& r) {
    if (s.compare(r) == 0) return true;
    if (s.length() <= 1) return false;

    int n = s.size();
    if (s.length() - r.length() != 0) return false;

    string t = s;
    t.push_back(' ');
    t.append(r);
    if(dp.find(t) != dp.end()) return dp[t];
   
    bool flag = false;
    for (int i = 1; i <= n-1; i++) {
        string a  = s.substr(0, i); 
        string b = r.substr(0, i); 
        string c  = s.substr(i, n-i); 
        string d = r.substr(i, n-i);
        string e = r.substr(n-i, i);
        string f = r.substr(0, n-i);

        if ((scrambleCheck(a, b) && scrambleCheck(c, d)) || (scrambleCheck(a, e) && scrambleCheck(c, f))) {
            flag = true;
            break;
        }
    }
    return dp[t] = flag;
}

bool isScramble(string s, string r) {
    return scrambleCheck(s,r);
}
