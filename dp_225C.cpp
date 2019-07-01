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

    in(n);in(m);in(x);in(y);
    char t;
    int arr[m+1] = {};
    forn(i,n){
        forn(j,m){
            cin >> t;
            if ( t=='#' )
                arr[j+1]++;
        }
    }
    int arr2[2][m+1];
    forn(i,m+1){
        arr2[0][i] = arr2[1][i] = 100000001;
    }
    forni(i,1,m+1){
        arr[i] += arr[i-1];
    }
    arr2[0][0] = arr2[1][0] = 0;
    int j,it0,it1;
    forni(i,1,m+1){
        j = x;
        it0 = it1 = 100000001;
        while ( j<=y && i-j>=0 ){
            it0 = min(it0,arr2[0][i-j]+arr[i]-arr[i-j] );
            it1 = min(it1,arr2[1][i-j]+j*n - (arr[i]-arr[i-j]) );
            j++;
        }
        arr2[0][i] = it1;
        arr2[1][i] = it0;
    }
    cout << min(arr2[0][m],arr2[1][m]);
}
