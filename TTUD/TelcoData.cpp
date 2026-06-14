#include <bits/stdc++.h>
using namespace std;

struct TelcoData
{
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

vector<TelcoData> calls;


void input(){
    string type;
    while(cin >> type){
        if(type == "#"){
            break;
        }
        TelcoData c;        
        cin  >> c.from_number >> c.to_number >> c.date >> c.from_time >> c.end_time;
        calls.push_back(c);
    }

    while(cin >> type){
        if(type == "#"){
            break;
        }
        if(type == "?check_phone_number"){
            cout << checkPhoneNumber() << "\n";
        }else if(type == "?number_calls_from"){
            string phonenumber;
            cin >> 
        }else if(type == "?number_total_calls"){

        }else if(type == "?count_time_calls_from"){

        }
    }
}

bool checkPhoneNumber(){
    return 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}