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

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	inl(n);
	ll fn = -1, sn = -1;
	if ( n%2==0 && n!=2 ) fn = 2;
	if ( n%4==0 && n!=4 ) sn = 2;
    for ( ll i=3; 1ll*i*i<=n; i+=2 ){
        if ( n%i == 0 ){
            if ( fn==-1 ) {
                fn = i;
                if ( (n/i)%i==0 ) { sn = i; break; }
            } else { sn = i; break; }
        }
    }
    if ( 1ll*fn*sn==n && n!=1 ){
        cout << 2 << edl;
        return 0;
    }
    if ( sn==-1 ){
        if ( fn==-1 ) cout << 1 << edl << 0 << edl;
        else cout << 2 << edl;
    } else cout << 1 << edl << 1ll*fn*sn << edl;

}
