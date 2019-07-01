#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef map<int,int> mii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())

#define edl '\n'
#define ll long long int

#define in(n) int n; cin >> n;
#define inl(n) ll n; cin >> n;
#define forn(i,n) for ( int i=0 ; i<n ; i++ )
#define forni(i,j,n) for ( int i=j ; i<n ; i++ )
#define forr (i,n) for ( int i=n; i>=0; i-- )
#define numb(arr,i) (int)(arr[i]-'0')

#define filecode ifstream in;ofstream out;in.open("inp.txt");out.open("out.txt");
#define IOFAST ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define setPrecision(n) cout << std::setprecision(n) << std::fixed;
#define outk(z,n) cout << "Case #" << z << ": " << n << endl;

#define MOD 1000000007
#define PI 3.14159265

int main() {

    IOFAST;
    in(n);
    int arr[n];
    forn(i,n) cin >> arr[i];
    map<int,int> mp;
    forn(i,n/2 ){
        mp[arr[i]-i]++;
        mp[arr[n-1-i]-i]++;
    }
    if ( n%2 ){
        mp[arr[n/2]-n/2]++;
    }
    int maxx = 0;
    for ( auto i:mp ){
        if ( i.second>maxx ) maxx = i.second;
    }
    cout << n-maxx << endl;

}
