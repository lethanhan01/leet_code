#include <bits/stdc++.h>
using namespace std;

bool check(char input, char output){
    return (input == '(' && output == ')')||(input == '[' && output ==']') || (input == '{' && output == '}');
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    cin >> a;
    stack<int> b;
    for(int i =0; i<a.size(); i++){
        if(a[i] == '(' || a[i] == '[' || a[i] == '{'){
            b.push(a[i]);
        }   
        else if(b.empty()){
            cout << 0;
            return 0;
        }
        else if(!check(b.top(), a[i])){
            cout << 0;
            return 0;
        }
        else{
            b.pop();
        }
    }
    if(b.empty()){
       cout << 1;
       return 0; 
    }
    else{
        cout << 0;
        return 0;
    }
    return 0;
}
