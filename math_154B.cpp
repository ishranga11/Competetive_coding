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

int prpos[10000];

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);in(m);
    bool vis[n+1] = {};
    vi fac[n+1];
    int tp;
    int pr = 0;
    forni(i,2,n+1){
        if ( !vis[i] ){
            tp = i;
            while ( tp<=n ){
                fac[tp].pb(pr);
                vis[tp] = 1;
                tp += i;
            }
            pr++;
        }
    }
    bool op[n+1] = {},err;
    char s;
    int num;
    while (m--){

        cin >> s >> num;
        if ( s=='+' ){
            if ( op[num] ){
                cout << "Already on" << edl;
             } else {
                err = 0;
                tr(fac[num],it){
                    if ( prpos[*it] ){
                        cout << "Conflict with " << prpos[*it] << edl;
                        err = 1;
                        break;
                    }
                }
                if ( !err ) {
                    op[num] = 1;
                    tr(fac[num],it){
                        prpos[*it] = num;
                    }
                    cout << "Success " << edl;
                }
             }
        } else {
            if ( op[num] ){
                cout << "Success " << edl;
                tr(fac[num],it){
                    prpos[*it] = 0;
                }
                op[num] = 0;
            } else cout << "Already off" << edl;
        }

    }
}
