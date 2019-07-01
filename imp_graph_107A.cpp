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
typedef map<int,int> mii;
typedef map< long long int, long long int> mll;

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
#define numb(arr,i) (int)(arr[i]-'0')

#define filecode ifstream in;ofstream out;in.open("input.txt");out.open("output.txt");
#define Arr(n) int arr[n]={}; forn(i,n) cin>>arr[i];
#define setPrecision(n) cout << std::setprecision(n) << std::fixed;
#define outk(z,n) cout << "Case #" << z << ": " << n << endl;
#define MOD 1000000009
#define PI 3.14159265

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);in(p);
    vi conn[n];
    int fr,to,di;
    int par[1001]={},chl[1001]={},d[1001];
    forn(i,n+1) d[i] = 10000000;
    forn(i,p){
        cin >> fr >> to >> di;
        while ( par[fr] ){
            chl[fr] = 0;
            fr = par[fr];
            di = min(di,d[fr]);
        }
        par[to] = fr;
        if ( chl[to] ) { chl[fr] = chl[to]; chl[to] = 0; }
        else chl[fr] = to;
        d[fr] = min(di,min(d[fr],d[to]));
    }
    vi ans;
    forn(i,n+1){
        if ( chl[i] && chl[i]!=i ){
            ans.pb(i);
        }
    }
    cout << ans.size() << edl;
    tr ( ans, it ){
        cout << *it << " " << chl[*it] << " " << d[*it] << edl;
    }

}
