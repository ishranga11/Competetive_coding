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
#define MOD 1000000007
#define PI 3.14159265

bool arr[7][7];

int conv ( string in ){

    if ( in == "Anka" ) return 0;
    if ( in == "Chapay" ) return 1;
    if ( in == "Cleo" ) return 2;
    if ( in == "Troll" ) return 3;
    if ( in == "Dracul" ) return 4;
    if ( in == "Snowy" ) return 5;
    if ( in == "Hexadecimal" ) return 6;

}

int differ ( int a, int b, int c ){

    int diff = max(a,max(b,c));
    diff -= min(a,min(b,c));
    return diff;

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);
    string inp[3];
    forn(i,n){

        cin >> inp[0] >> inp[1] >> inp[2];
        int fr = conv ( inp[0] );
        int to = conv ( inp[2] );
        arr[fr][to] = 1;

    }
    int ex[3];
    cin >> ex[0] >> ex[1] >> ex[2];
    sort ( ex, ex+3 );
    int div[400][3],till=0;
    int diff = ex[2];
    forni(i,1,6){
        forni(j,1,7-i){
            int now = differ(ex[0]/i, ex[1]/j, ex[2]/(7-i-j));
            if ( now<diff ){
                till = 0;
                diff = now;
                div[till][0]=i;
                div[till][1]=j;
                div[till][2]=7-i-j;
                till++;
            } else if ( now==diff ){
                div[till][0]=i;
                div[till][1]=j;
                div[till][2]=7-i-j;
                till++;
            }
        }
    }

    int ans = 0;
    vi bs;
    forn( k,till ){
        bs.clear();
        forn(i,div[k][0]) bs.pb(1);
        forn(i,div[k][1]) bs.pb(2);
        forn(i,div[k][2]) bs.pb(3);
        do {
            int tp = 0;
            forn(i,7){
                forn(j,7){
                    if ( arr[i][j] && bs[i]==bs[j] ) tp++;
                }
            }
            ans = max ( ans,tp );
        } while ( next_permutation(all(bs)) );
    }

    cout << diff << " " << ans << endl;

}
