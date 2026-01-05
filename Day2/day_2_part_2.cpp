#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;


bool isposible(string& p , string& s){
    int m = p.size();
    int n = s.size();
    if(n % m)return false;
    int l = 0;
    while(l <= n - m){
        string sub = s.substr(l , m);
        if(sub != p)return false;
        l += m;
    }
    return true;

}
bool invalid(string s){
    int n = s.size();
    int r = 1;
    while(r < n){
       if(s[0] == s[r]){
          string ls = s.substr(0,r);
          if(isposible(ls,s)){
              return true;
          }
       }
       r++;
    }
    return false;
}
ll solve(ll L , ll R){
    ll number = L;
    ll result = 0;
    while(number <= R){
 
        if(invalid(to_string(number))){
            result += number;
            // cout << number << endl;
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