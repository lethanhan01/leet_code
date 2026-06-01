#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    int prefix = 0;
    int minPrefix = 0;
    int answer = INT_MIN;

    for (int i = 0; i < n; i++) {
        prefix += a[i];
        answer = max(answer, prefix - minPrefix);
        minPrefix = min(minPrefix, prefix);
    }

    cout << answer;
    return 0;
}

/*
6
2 4 6 8 10 12
5 2
*/