/*
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n, m;
vector<vector<int>> a(MAXN, vector<int>(MAXN, 0));
vector<int> height(MAXN, 0);
int max_final_final = 0;

int maxMinTimesLength(vector<int>& arr) {
    int len = arr.size();
    int answer = 0;

    for (int l = 0; l < len; l++) {
        int minValue = INT_MAX;

        for (int r = l; r < len; r++) {
            minValue = min(minValue, arr[r]);

            int length = r - l + 1;
            int value = minValue * length;

            answer = max(answer, value);
        }
    }

    return answer;
}

int solveHistogram(vector<int>& h, int cols) {
    int max_final = 0;
    vector<int> chuoi;

    for (int i = 0; i < cols; i++) {
        if (h[i] == 0) {
            chuoi.clear();
            continue;
        } else {
            chuoi.push_back(h[i]);
            max_final = max(max_final, maxMinTimesLength(chuoi));
        }
    }

    return max_final;
}

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];

            if (a[i][j] == 1) {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }

        max_final_final = max(max_final_final, solveHistogram(height, m));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    cout << max_final_final;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int xuly(vector<int>& height){
    int m =height.size();
    stack<int> st;
    int best=0;

    for (int i =0; i <= m; i++){
        int current_height = 0;
        
        //Dieu kien dung
        if(i == m){ 
            current_height = 0;
        }else{
            current_height = height[i];
        }
        
        
        while (!st.empty() && height[st.top()] > current_height)
        {
            int h = height[st.top()];
            st.pop();
            int right =i;
            int left;

            if(st.empty()){
                left = -1;

            } else{
                left = st.top();
            }

            int width = right - left -1;
            int area = h*width;
            best = max(best, area);
        }
        st.push(i);
        
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> height(m,0);
    int answer = 0;

    for(int i =0; i < n; i++){
        for(int j =0; j <m;j++){
            int x;
            cin >> x;
            if(x==1){
                height[j]++;
            }else{
                height[j] = 0;
            }
        }

        answer = max(answer, )
    }

    return 0;
}
