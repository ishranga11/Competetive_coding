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
#define mp make_pair

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
#define MOD 1000000009
#define PI 3.14159265

struct point
{
    int x, y;
    bool operator < (const point & b) const
    {
        return x < b.x || (x == b.x && y < b.y);
    }
};

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

vector<point> v;
queue <int> q;
bool vis[100000];
int d[100000],a,xf,yf;

int findp ( point z ){

    int it = lower_bound(all(v), z ) - v.begin();
    if ( it==v.size() ) return -1;
    if ( z.x != v[it].x || z.y != v[it].y ) return -1;
    return it;

}

int bfs ( int x, int y ){

    int t,tx,ty,p;
    while( !q.empty() ){
        t = q.front();
        q.pop();
        if ( v[t].x == xf && v[t].y == yf ) return d[t];
        forn(i,8){
            tx = v[t].x+dx[i];
            ty = v[t].y+dy[i];
            p = findp( (point){tx,ty});
            if ( p==-1 || vis[p] ) continue;
            vis[p] = 1;
            q.push(p);
            d[p] = d[t]+1;
        }
    }
    return -1;

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	in(xi);in(yi);
	cin >>xf>>yf;
	in(n);
	int r,a,b;
	forn(i,n){
        cin >> r >> a >> b;
        forni(i,a,b+1)v.pb((point){r,i});
	}
	sort ( all(v) );
	while ( !q.empty() ) q.pop();
	a = findp((point){xi,yi});
	vis[a] = 1;
	d[a] = 0;
	q.push(a);
	cout << bfs(xi,yi) << edl;
}
