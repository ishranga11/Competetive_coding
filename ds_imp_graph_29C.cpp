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

map<int,int> mp;
int pos=0;
vi vis[100100];
int val[100100];
vi ans;

void dfs ( int st ){

    ans.push_back(val[st]);
    int nxt=-1;
    if ( ans.size()==1 || vis[st][0] != mp[ans[ans.size()-2]] ) nxt = vis[st][0];
    if ( vis[st].size()==2 && vis[st][1] != mp[ans[ans.size()-2]] ) nxt = vis[st][1];
    if ( nxt==-1 ) return;
    dfs ( nxt );

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	in(n);
	int t,tp;
	forn(i,n){
        cin >> t >> tp;
        if ( mp.find(t)==mp.end() ){
            mp[t] = pos++;
            val[mp[t]] = t;
        }
        if ( mp.find(tp)==mp.end() ){
            mp[tp] = pos++;
            val[mp[tp]] = tp;
        }
        vis[mp[t]].pb(mp[tp]);
        vis[mp[tp]].pb(mp[t]);
	}
	int st;
	forn(i,pos){
        if ( vis[i].size()==1 ){
            st = i;
            break;
        }
	}
	dfs(st);
	forn(i,n+1){
        cout << ans[i] << " ";
	}

}
