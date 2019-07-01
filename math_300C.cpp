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
#define MOD 1000000009

ll poww ( ll a, ll p ){

    if ( p==0 ) return 1;
    ll res = poww ( a, p/2 );
    res = (res*res)%MOD;
    if ( p%2 ) return (res*a)%MOD;
    else return res;

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	in(a);in(b);in(n);
	ll c = 1;
	int minn = min(a,b);
	int maxx = max(a,b);
	ll curr = n*minn,tp,ans=0;
	int rem;
	forn(i,n+1){
	    tp = curr;
        while ( tp ){
            rem = tp%10;
            if ( rem!=a && rem!=b ) break;
            tp /= 10;
        }
        if ( !tp ) ans += c;
        ans = ans%MOD;
        c = (c*(n-i))%MOD;
        c = (c*poww(1+i,MOD-2))%MOD;
        curr += maxx-minn;
	}
	cout << ans << edl;

}
