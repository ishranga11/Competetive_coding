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

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);in(k);
    Arr(n);
    sort ( arr, arr+n );
    ll sz = 0, num = -1, prev = -1, i=0, j=0, s=0, fsz=0, fnum = -1;
    while ( i<n ){
        num = arr[i];
        j = i+1;
        while ( j<n && arr[j]==num ) j++;
        if ( i!=0 ) s+= sz*(num-prev);
        while ( s>k ){
            s -= num-arr[i-sz];
            sz--;
        }
        sz += j-i;
        if ( sz>fsz ){
            fsz = sz;
            fnum = num;
        }
        //cout << i << " " << num << " " << sz << " " << edl;
        prev = num;
        i = j;
    }
    cout << fsz << " " << fnum << endl;
}
