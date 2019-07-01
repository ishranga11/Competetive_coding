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

bool comp ( pair<ii,int> a, pair<ii,int> b ){

    if ( a.first.first ==b.first.first ) return a.first.second<b.first.second;
    return a.first.first<b.first.first;

}

int main() {

    IOFAST;
    in(n);
    pair<ii,int> les[n];
    int o,t;
    forn(i,n){
        cin >> o >> t;
        les[i] = {{o,t},i};
    }
    sort( les,les+n, comp );
    vector<int> ans;
    bool bad = 0;
    forni(i,2,n){
        if ( les[i-1].first.second > les[i].first.first ){
            bad = 1;
            break;
        }
    }
    if ( !bad ) ans.pb(les[0].second);
    forni(j,1,n){
        bad = 0;
        forni(i,1,n){
            if ( i==j ) continue;
            int prv = i-1;
            if (i-1==j) prv = i-2;
            if ( les[prv].first.second > les[i].first.first ){
                bad = 1;
                break;
            }
        }
        if ( !bad ) ans.pb(les[j].second);
    }
    cout << ans.size() << endl;
    sort ( all(ans) );
    forn(i,ans.size()) cout << ans[i]+1 << " ";
    return 0;

}
