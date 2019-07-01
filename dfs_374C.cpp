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

char nm[1000][1000];
int scc[1000][1000];
int ans[1000][1000];
int curr;
bool inf=0;
int mx,temp,r,c;
char ch[4] = {'D','I','M','A'};

int trav ( int i, int j, int op ){

    scc[i][j] = curr;
    int t2=0,op2=(op+3)%4;
    //cout << "Reached " << i << " " << j << " " << nm[i][j] <<edl;
    if ( i<r-1 && nm[i+1][j]==ch[op2] ){
        if ( scc[i+1][j]==scc[i][j] ){
            inf = 1;
            return 0;
        } else if ( !scc[i+1][j] ){
            t2 = max ( t2,trav(i+1,j,op2) );
        } else t2 = max ( t2, ans[i+1][j] );
    }
    if ( j<c-1 && nm[i][j+1]==ch[op2] ){
        if ( scc[i][j+1]==scc[i][j] ){
            inf = 1;
            return 0;
        } else if ( !scc[i][j+1] ){
            t2 = max ( t2,trav(i,j+1,op2) );
        } else t2 = max ( t2, ans[i][j+1] );
    }
    if ( i>0 && nm[i-1][j]==ch[op2] ){
        if ( scc[i-1][j]==scc[i][j] ){
            inf = 1;
            return 0;
        } else if ( !scc[i-1][j] ){
            t2 = max ( t2,trav(i-1,j,op2) );
        }else t2 = max ( t2, ans[i-1][j] );
    }
    if ( j>0 && nm[i][j-1]==ch[op2] ){
        if ( scc[i][j-1]==scc[i][j] ){
            inf = 1;
            return 0;
        } else if ( !scc[i][j-1] ){
            t2 = max ( t2,trav(i,j-1,op2) );
        } else t2 = max ( t2, ans[i][j-1] );
    }
    if ( nm[i][j]=='D' ) t2++;
    ans[i][j] = t2;
    scc[i][j] += 100000;
    return t2;

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	cin >> r >> c;
	forn(i,r){
	    cin >> nm[i];
	}
	forn(i,r){
        forn(j,c){
            if ( nm[i][j]=='A' && !scc[i][j] ){
                curr++;
                temp = trav ( i,j,3 );
                mx = max ( mx, temp );
            }
            if ( inf ) break;
        }
        if ( inf ) break;
	}
	if ( inf ) cout << "Poor Inna!";
	else {
        if ( !mx ) cout << "Poor Dima!";
        else cout << mx << endl;
	}

}
