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
	ll k,b,n,t;
	cin >> k >> b >> n >> t;
    ll limx = -1,tmp = t;
    if ( k==1 ){
        limx = n- (t-1)/b;
        cout << max(0ll,limx) << endl;
        return 0;
    }
    while ( tmp ){
        limx ++;
        tmp /= k;
    }
    if ( t<k ){
        cout << n << endl;
        return 0;
    }
    ll ans=0;
    for ( ll i=limx; i>=0; i-- ){
        tmp = 1;
        forn(j,i){
            tmp *= k;
        }
        if ( (k-1)*(t-tmp)-(tmp-1)*b>=0 ){
            ans = i;
            break;
        }
    }
    cout << max(0ll,n-ans) << endl;

}
