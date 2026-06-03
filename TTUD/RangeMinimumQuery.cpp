/*
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cin >> m;
    vector<vector<int>> b(m, vector<int>(2,0));
    for(int i =0; i < m; i++){
        cin >> b[i][0] >> b[i][1];
    }

    vector<int> min(m,0);
    for(int i =0; i <m; i++){
        min[i] = *min_element(a.begin() + b[i][0],a.begin() + b[i][1]);
    }
    int sum =0;
    for(int i = 0; i < m; i++){
        sum += min[i]; 
    }
    cout << sum;
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int a[maxN], n, m, M[maxN][30];
int rmq(int i, int j) {
    int res = a[i];
    for(int k =i+1; k < j; k++){
        res=min(res,a[k]);
    }
    return res;

    int k = log2(j-i+1);
    return min(a[M[i][k]], a[M[j-(1<<k)+1][k]]);
}
void buildM(){
    for(int i =0; i<n; i++){
        M[i][0] = i;
    }

    for(int j=0;(1<<j)<=n; j++){
        for(int i =0; i+(1<<j)-1 <n;i++){
            if(a[M[i][j-1]] < a[M[i+(1<<(j-1))][j-1]]){
                M[i][j] = M [i][j-1];
            }else{
                M[i][j] = M[i+(1<<(j-1))][j-1];
            }
        }
    }
}
int main(int argc, char const *argv[]){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    buildM();
    cin >> m;
    int sum =0;
    for(int i=0; i<m; i++){
        int l,r;
        cin >> l >>r;
        sum+= rmq(l,r);
    }
    cout << sum<< endl;
    return 0;
}
*/



#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 5;
const int LOG = 21;

int a[maxN];
int M[maxN][LOG];
int n, m;

void buildM() {
    for (int i = 0; i < n; i++) {
        M[i][0] = i;
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            int left = M[i][j - 1];
            int right = M[i + (1 << (j - 1))][j - 1];

            if (a[left] <= a[right]) {
                M[i][j] = left;
            } else {
                M[i][j] = right;
            }
        }
    }
}

int rmq(int i, int j) {
    int k = log2(j - i + 1);

    int left = M[i][k];
    int right = M[j - (1 << k) + 1][k];

    return min(a[left], a[right]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    buildM();

    cin >> m;

    long long sum = 0;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        sum += rmq(l, r);
    }

    cout << sum << '\n';

    return 0;
}