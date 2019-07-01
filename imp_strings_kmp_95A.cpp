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
    string forb[n];
    forn(i,n){
        cin >> forb[i];
        transform(forb[i].begin(), forb[i].end(), forb[i].begin(), ::tolower );
    }
    string mn;
    cin >> mn;
    char spc;
    cin >> spc;
    char extra = 'a';
    if ( spc=='a' || spc=='A' ) extra = 'b';
    bool flp[mn.length()] = {};
    forn(i,n){

        int len = forb[i].length();
        int kmp[len] = {};
        int st = 0,j=1;
        while ( j<len ) {
            if ( forb[i][j]==forb[i][st] ){
                st++;
                kmp[j] = st;
                j++;
            } else {
                if ( st ){
                    st = kmp[st-1];
                } else {
                    kmp[j] = 0;
                    j++;
                }
            }
        }
        st = j = 0;
        while ( st<mn.length() ){
            if ( tolower(mn[st]) ==forb[i][j] ){
                st++;
                j++;
            }
            if ( j==len ){
                forni( k,st-len,st ){
                    flp[k] = 1;
                }
                j = kmp[j-1];
            } else if ( st!=mn.length() && tolower(mn[st])!=forb[i][j] ){
                if ( j ) j = kmp[j-1];
                else st++;
            }
        }

    }
    forn(i,mn.length()){
        if ( flp[i] ) {
            bool shf=0;
            if ( mn[i]<='Z' ) shf = 1;
            if ( tolower( mn[i] )==spc ) mn[i] = extra;
            else mn[i] = spc;
            if ( shf ) mn[i]-=32;
        }
    }
    cout << mn << endl;

}
