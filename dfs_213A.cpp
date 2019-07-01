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

int n;
int cmp[210];
bool graph[210][210];
int cnt[210];
bool used[210];

int calc ( int ps ){

    forn(i,n) cnt[i] = 0;
    forn(i,n) forn(j,n) if (graph[j][i]) cnt[i]++;
    forn(i,n) used[i] = false;
    int tmp = n, ans=0;
    while ( 1 ){

        bool fnd =0;
        int ind;
        forn(i,n){
            if ( !used[i] && cmp[i]==ps && cnt[i]==0 ){
                fnd = 1;
                ind = i;
                break;
            }
        }
        if ( !fnd ){
            ans++;
            ps = (ps+1)%3;
            continue;
        }
        used[ind] = 1;
        forn(j,n) if ( graph[ind][j] ) cnt[j]--;
        tmp--;
        if ( !tmp ) return ans;

    }

}

int main() {

    IOFAST;
    cin >> n;
    forn(i,n) {
        cin >> cmp[i];
        cmp[i]--;
    }
    forn(i,n){
        int op,to;
        cin >> op;
        forn(j,op){
            cin >> to;
            graph[to-1][i] = true;
        }
    }
    int ans = INT_MAX;
    forn(i,3){
        ans = min ( ans, calc(i) );
    }
    cout << ans + n << endl;

}
