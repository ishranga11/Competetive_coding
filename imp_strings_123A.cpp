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

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	string in;
	cin >> in;
	int len = in.length();
	int arr[26] = {};
	forn( i, len ){
        arr[(int)(in[i]-'a')]++;
	}
	int mx = 0,ch;
	forn(i,26){
        if ( arr[i]>mx ){
            mx = arr[i];
            ch = i;
        }
	}
	bool vis[len+1]={};
	char ans[len]={'\0'};
	int need = 0;
	forni(i,2,len/2+1){
        if ( !vis[i] ){
            int tp = 2*i;
            need ++;
            vis[i] = 1;
            ans[i-1] = (char)(ch+'a');
            while ( tp<=len ){
                if ( !vis[tp] ){
                    need++;
                    vis[tp] = 1;
                    ans[tp-1] = (char)(ch+'a');
                }
                tp += i;
            }
        }
	}
	if ( need>mx ) {
        cout << "NO" << endl;
	} else {
	    arr[ch] -= need;
        need = 0;
        cout << "YES" << endl;
        forn(i,len){
            while ( !arr[need] ) need++;
            if ( vis[i+1] ) {
                cout << ans[i];
                continue;
            }
            ans[i] = (char)(need+'a');
            arr[need]--;
            cout << ans[i];
        }
	}

}
