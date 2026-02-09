#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <numeric>
#include <optional>
#include <algorithm>
#include <cctype>
#include <functional>
using namespace std;

vector<int> solveCrypt(string &first, string &second, const string &third){
    string a = first, b = second, c = third;
    for (char &ch : a) ch = tolower((unsigned char)ch);
    for (char &ch : b) ch = tolower((unsigned char)ch);
    for (char &ch : c) ch = tolower((unsigned char)ch);

    if (a.size() < b.size()) swap(a, b);
    if (c.size() < a.size()) return {};

    vector<char> letters;
    array<bool, 26> seen{};
    seen.fill(false);
    auto addLetters = [&](const string &s){
        for (char ch : s)
            if (isalpha((unsigned char)ch) && !seen[ch - 'a']){
                seen[ch - 'a'] = true;
                letters.push_back(ch);
            }
    };
    addLetters(a);
    addLetters(b);
    addLetters(c);

    if (letters.size() > 10) return {};

    int n = (int)letters.size();
    array<int, 26> map{};
    map.fill(-1);
    array<bool, 10> used{};
    used.fill(false);

    function<bool(int)> dfs = [&](int idx) -> bool{
        if (idx == n){
            auto toValue = [&](const string &s) -> optional<unsigned long long>{
                if (s.size() > 1 && map[s[0] - 'a'] == 0) return nullopt;
                unsigned long long v = 0;
                for (char ch : s){
                    int d = map[ch - 'a'];
                    if (d < 0) return nullopt;
                    v = v * 10 + (unsigned long long)d;
                }
                return v;
            };
            auto v1o = toValue(a);
            auto v2o = toValue(b);
            auto v3o = toValue(c);
            if (!v1o || !v2o || !v3o) return false;
            return (*v1o + *v2o) == *v3o;
        }

        int li = letters[idx] - 'a';
        for (int d = 0; d <= 9; ++d) {
            if (used[d]) continue;
            if (d == 0) {
                if ((a.size() > 1 && letters[idx] == a[0]) ||
                    (b.size() > 1 && letters[idx] == b[0]) ||
                    (c.size() > 1 && letters[idx] == c[0]))
                    continue;
            }
            used[d] = true;
            map[li] = d;
            if (dfs(idx + 1)) return true;
            map[li] = -1;
            used[d] = false;
        }
        return false;
    };

    if (!dfs(0)) return {};
    vector<int> out(26, -1);
    for (int i = 0; i < 26; ++i) out[i] = map[i];
    return out;
}

void printCrypt(const string& first,const string& second,const string& third,vector<int> res = {},bool printRes = false){
    cout << "  ";
    for(char ch:first){
        if (printRes) cout << res[ch-'a'] << " ";
        else cout << ch << " ";
    }
    cout << "\n+ ";
    for(char ch:second){
        if (printRes) cout << res[ch-'a'] << " ";
        else cout << ch << " ";
    }
    cout << "\n----------\n";
    for(char ch:third){
        if (printRes) cout << res[ch-'a'] << " ";
        else cout << ch << " ";
    }
    cout << "\n----------\n";
}

int main(){
    string first = "two",second = "two", third = "five";
    vector<int> res = solveCrypt(first,second,third);
    
    printCrypt(first,second,third);
    printCrypt(first,second,third,res,true);

    return 0;
}