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

int col[100010],ccol[100010];
int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);
    Arr(n);
    set <int> s;
    int cnt=0,ans=0;
    forn(i,n){
        if ( !col[arr[i]] ) cnt++;
        else {
            ccol[col[arr[i]]]--;
            if ( !ccol[col[arr[i]]] ) s.erase(col[arr[i]]);
        }
        col[arr[i]]++;
        ccol[col[arr[i]]]++;
        s.insert(col[arr[i]]);
        if ( cnt==1 || ccol[1]==cnt ){
            ans = i+1;
            continue;
        }
        if ( s.size() == 2 ){
            if ( ccol[1]==1 ){
                ans = i+1;
            } else {
                int it = *(s.begin());
                if ( ccol[it+1]==1 && ccol[it]==cnt-1 ) ans = i+1;
            }
        }
    }
    cout << ans << endl;
}
