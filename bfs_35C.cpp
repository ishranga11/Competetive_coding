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
#define MOD 1000000007
#define PI 3.14159265

bool tr[2000][2000];
ll sz = 0;
int n,m;
queue <ii> s;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int ansx, ansy;

void bfs ( ){

    int crx,cry;
    while ( 1 ){
        if ( !sz ){
            while ( s.size()>1 ) s.pop();
            ansx = s.front().first+1;
            ansy = s.front().second+1;
            break;
        }
        crx = s.front().first; cry = s.front().second;
        s.pop();
        forn(i,4){
            if ( (crx+dx[i])>=0 && (crx+dx[i])<n && (cry+dy[i])>=0 && (cry+dy[i])<m  ){
                if ( !tr[crx+dx[i]][cry+dy[i]] ){
                    tr[crx+dx[i]][cry+dy[i]] = 1;
                    s.push({crx+dx[i],cry+dy[i]});
                    sz--;
                }
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	filecode;
	in >> n >> m;
	sz = n*m;
	int k;
	in >> k;
	sz-=k;
	int a,b;
	forn(i,k){
        in >> a >> b;
        s.push({a-1,b-1});
        tr[a-1][b-1] = 1;
	}
	bfs();
	out << ansx << " " << ansy << endl;

}
