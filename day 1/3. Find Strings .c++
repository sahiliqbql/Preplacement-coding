#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void generateSubstrings(const string& str, set<string>& substrings) {
    int n = str.size();
    for (int i = 0; i < n; ++i) {
        string substring = "";
        for (int j = i; j < n; ++j) {
            substring += str[j];
            substrings.insert(substring);
        }
    }
}

vector<string> findStrings(vector<string> w, vector<int> queries) {
    set<string> allSubstrings;
    for (const string& word : w) {
        generateSubstrings(word, allSubstrings);
    }

    vector<string> sortedSubstrings(allSubstrings.begin(), allSubstrings.end());

    vector<string> results;
    for (int k : queries) {
        if (k <= 0 || k > sortedSubstrings.size()) {
            results.push_back("INVALID");
        } else {
            results.push_back(sortedSubstrings[k - 1]); // 1-based index
        }
    }

    return results;
}

int main() {
    int n;
    cin >> n;
    vector<string> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    vector<string> results = findStrings(w, queries);

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
