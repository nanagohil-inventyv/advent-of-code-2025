#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;

bool isvalid(string num){
    int n = num.size();
    if(n % 2){
        return true;
    }
    int l = 0;
    int ls = n/2;
    string lstr = num.substr(0 , ls);
    string rstr = num.substr(ls);
    return lstr != rstr;
}
ll solve(ll L , ll R){
    ll number = L;
    ll result = 0;
    while(number <= R){
        if(!isvalid(to_string(number))){
            result += number;
        }
        number++;
    }
    return result;
}
void solve()
{
    ifstream file("input.txt");
    string content , token;
    if (!file)
    {
        cout << "File not found!" << endl;
        return;
    }
    while (getline(file, token)) {
        content += token;
    }

    stringstream ss(content);

    ll ans = 0;

    while(getline(ss , token , ',')){
        if(token.empty()){
            continue;
        }
        int dash = token.find('-');
        ll start = stoll(token.substr(0,dash));
        ll end = stoll(token.substr(dash + 1));
        ans += solve(start , end);
    }

    cout << ans << endl;

    
}
int main()
{

    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}