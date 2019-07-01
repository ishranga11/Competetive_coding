#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define edl '\n'
#define ll long long int
#define mp make_pair

#define in(n) int n; cin >> n;
#define inl(n) ll n; cin >> n;
#define forn(i,n) for ( int i=0 ; i<n ; i++ )
#define forni(i,j,n) for ( int i=j ; i<n ; i++ )
#define forr (i,n) for ( int i=n; i>=0; i-- )

#define filecode ifstream in;ofstream out;in.open("input.txt");out.open("output.txt");
#define Arr(n) int arr[n]={}; forn(i,n) cin>>arr[i];
#define setPrecision(n) cout << std::setprecision(n) << std::fixed;
#define outk(z,n) cout << "Case #" << z << ": " << n << endl;
#define deb cout << "Here" << endl;

vi ans,nds[100001];
bool vis[100001],init[100001];
void dfs ( int i, bool now, bool prev ){

    vis[i] = 1;
    bool t = init[i]^now;
    if ( t ) ans.pb(i+1);
    tr ( nds[i], it ){
        if ( vis[*it] ) continue;
        dfs(*it,prev,init[i]);
    }

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);
    bool bt;
    int u,v;
    forn(i,n-1){
        cin >> u >> v;
        nds[u-1].pb(v-1);
        nds[v-1].pb(u-1);
    }
    forn(i,n){
        cin >> init[i];
    }
    forn(i,n){
        cin >> bt;
        init[i] ^= bt;
    }
    dfs(0,false, false);

    cout << ans.size() << edl;
    tr( ans, it ){
        cout << *it << edl;
    }
}
