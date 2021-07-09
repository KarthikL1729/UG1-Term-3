#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vii;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define arr_in                  \
    for (int i = 0; i < n; ++i) \
        cin >> a[i];
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
#define rep(i, a, n) for (ll i = a; i < n; ++i)
#define brep(i, a, n) for (ll i = n - 1; i >= a; --i)
#define godspeed cin.tie(0), cout.tie(0)->sync_with_stdio(0)
bool sortbysec(const pair<string, double> &a,
               const pair<string, double> &b)
{
    return a.second < b.second;
}
int main()
{
    vector<pair<string, double>> invoc;
    cout<<"Enter number of words in input vocab."<<endl;
    ll num;
    cin>>num;
    cout<<"Enter code with probability of occurences, in that order."<<endl;
    for (ll i = 0; i < num; i++)
    {
        string s;
        cin>>s;
        double p;
        cin>>p;
        invoc.pb(mp(s, p));
    }
    sort(invoc.begin(), invoc.end(), sortbysec);
    ll maxl = num - 1;
    vector <string> cw;
    for(ll i = 0; i < num; i++)
    {
        if(i >= 2)
            maxl--;
        char s[maxl+1];
        for(int j = 0; j < maxl - 1; j++)
            s[j] = '1';
        if(i == 0)
            s[maxl - 1] = '1';
        else
            s[maxl - 1] = '0';
        s[maxl] = '\0';
        cw.pb(s);
    }
    double exl = 0;
    cout<<"Entered vocab\n";
    cout<<"Word"<<setw(20)<<"Probability"<<setw(20)<<"Codeword\n";
    for (ll i = 0; i < num; i++)
    {
        cout<<invoc[i].f<<setw(20)<<invoc[i].s<<setw(20)<<cw[i]<<"\n";
        exl += cw[i].length()*invoc[i].s;
    }
    cout<<"Expected Length of the given code = "<<exl<<endl;
    return 0;
}