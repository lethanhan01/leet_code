#include <bits/stdc++.h>
using namespace std;
int maxN =21;
int n;

vector<vector<int>> c(maxN, vector<int>(maxN,0));
int cmin = 0;
vector<int> visited(maxN,0);
int currentDis = 0;
vector<int> X;
int result = INT_MAX;
vector<int> Y;

void input(){
    cin >> n;
    visited.resize(n);
    X.resize(n);
    Y.resize(n);
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> c[i][j];
        }
    }

}

bool check(int v){
    if(visited[v]==1){
        return false;
    }else{
        return true;
    }
}

void Try(int k){
    for(int v = 1; v < n;v++){
        if(!check(v)){
            continue;
        }
        //Set up
        X[k] = v;
        visited[v] = 1;
        currentDis += c[X[k-1]][X[k]];

        //ktra dk dung
        if(k == n-1){
            result = min(result, currentDis + c[X[k]][X[0]]);
        }else{
            int lowerBound = currentDis + cmin*(n -1 - k +1);
            if(lowerBound < result){
                Try(k+1);
            }
        }

        //tra ve trang thai
        visited[v] = 0;
        currentDis -= c[X[k-1]][X[k]]; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    X[0]=0;
    Y[0]=1;
    Try(1);
    cout << result << endl;
    for(int i =0; i < n; i++){
        cout << X[i] << " ";
    }
    return 0;
}