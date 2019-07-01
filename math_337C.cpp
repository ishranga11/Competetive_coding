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
	in(n);in(m);in(k);
	ll rem = n%k+(n/k)*(k-1);
	if ( m<=rem ) {
        cout << m << endl;
        return 0;
	}
	rem = n%k;
	n -= rem;
	m -= rem;
	int bl = m-(n/k)*(k-1);
	ll ans = k;
	ans *= poww(2,bl+1);
	ans += m-bl*k+rem-2*k+MOD;
	ans %= MOD;
	cout << ans << edl;

}
