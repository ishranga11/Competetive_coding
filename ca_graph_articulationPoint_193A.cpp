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

const int sz = 210;
// vi adj[sz];
int disc[sz][sz],low[sz][sz];
ii par[sz][sz];
bool vis[sz][sz];
int tim;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
string inp[sz];

int n,m;

bool AP ( int i, int j ){

    vis[i][j] = 1;
    tim++;
    disc[i][j] = low[i][j] = tim;
    int child = 0;
    forn(k,4){
        if ( i+dx[k]<n && i+dx[k]>=0 && j+dy[k]<m && j+dy[k]>=0 && inp[i+dx[k]][j+dy[k]]=='#' ){
            if ( !vis[i+dx[k]][j+dy[k]]  ){
                child++;
                par[i+dx[k]][j+dy[k]] = {i,j};
                if ( AP(i+dx[k],j+dy[k]) ) return true;
                low[i][j] = min ( low[i][j], low[i+dx[k]][j+dy[k]] );
                if ( (par[i][j].first==-1 && child>1) || par[i][j].first!=-1 && low[i+dx[k]][j+dy[k]]>=disc[i][j] )
                    return true;
            } else if ( par[i][j].first!=i+dx[k] || par[i][j].second!=j+dy[k] ){
                low[i][j] = min ( low[i][j],disc[i+dx[k]][j+dy[k]] );
            }
        }
    }
    return false;

}

int main() {

    IOFAST;
    cin >> n >> m;
    forn(i,n){
        cin >> inp[i];
    }
    int cnt = 0;
    forn(i,n){
        forn(j,m){
            if( inp[i][j]=='#' ) cnt++;
        }
    }
    if ( cnt<3 ){
        cout << -1 << endl;
        return 0;
    }
    forn(i,n){
        forn(j,m){
            par[i][j] = {-1,-1};
        }
    }
    int ans = 4;
    forn(i,n){
        forn(j,m){
            if ( inp[i][j]=='#' ){
                if ( AP(i,j) ){
                    ans = 1;
                    break;
                }
            }
        }
    }
    ans = min(ans,2);
    cout << ans << endl;

}
