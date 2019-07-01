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
    in(n); in(m); in(s);
    ll r = n%s, l = m%s;
    ll er = n/s, el= m/s;
    if ( r ) er++; if ( l ) el++;
    if ( !r ) r=s; if ( !l ) l = s;
    cout << 1ll*l*r*er*el << endl;

}
