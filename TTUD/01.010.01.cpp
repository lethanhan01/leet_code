#include <bits/stdc++.h>
using namespace std;

string addStrings(string a, string b) {
    string result = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += (a[i--] - '0');
        if (j >= 0) sum += (b[j--] - '0');
        carry = sum / 10;
        result += (char)('0' + sum % 10);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << addStrings(a, b);
    return 0;
}

/*
1200000002653414
1200000001265341
4

14000000064564858
1400000006456485
8


12


*/
