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
double exl = 0;
typedef struct elem{
    string s;
    double prob;
    string cw;
    elem *l, *r;
}elem;
elem* init(string s, double p)
{
    elem *t;
    t = new elem;
    t->s = s;
    t->prob = p;
    t->l = NULL;
    t->r = NULL;
    return t;
}
struct cmp{
    bool operator()(elem *l, elem *r)
 
    {
        return (l->prob > r->prob);
    }
};
void codegen(elem *head, string s)
{
    if(!head)
        return;
    if(head->s.compare("#") != 0)
    {
        head->cw = s;
        cout<<head->s<<setw(20)<<head->prob<<setw(20)<<head->cw<<endl;
        exl += head->prob*head->cw.length();
    }
    codegen(head->l, s+"0");
    codegen(head->r, s+"1");
}
int main()
{
    elem *l, *r, *head;
    priority_queue<elem*, vector<elem*>, cmp> heap;
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
        heap.push(init(s, p));
    }
    while(heap.size() != 1)
    {
        l = heap.top();
        heap.pop();
        r = heap.top();
        heap.pop();
        head = init("#", l->prob+r->prob);
        head->l = l;
        head->r = r;
        heap.push(head);
    }
    cout<<"Word"<<setw(20)<<"Probability"<<setw(20)<<"Codeword\n";
    codegen(heap.top(), "");
    cout<<"Expected Length of the given code = "<<exl<<endl;
    return 0;
}

/*
Sample test case
6
a 0.073
b 0.367
c 0.102
d 0.220
e 0.058
f 0.176


Expected length = 2.356
Expected length with other prefix free code = 2.398

5
a 0.22
b 0.28
c 0.15
d 0.30
e 0.05

Expected length = 2.2
Expected length with other prefix free code = 2.32
*/

/*
Occurences of alphabets 

e 0.111
a 0.085
r 0.076
i 0.075
o 0.071
t 0.069
n 0.066
s 0.057
l 0.054
c 0.045
u 0.036
d 0.033
p 0.031
m 0.030
h 0.030
g 0.024
b 0.021
f 0.018
y 0.018
w 0.012
k 0.011
v 0.010
x 0.003
z 0.003
j 0.002
q 0.002

*/