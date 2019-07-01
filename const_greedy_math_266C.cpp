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

int rowcnt[1000];

bool comp ( ii a, ii b ){

    return rowcnt[a.second]<rowcnt[b.second];

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	in(n);
	int ro,co;
	ii r[n],c[n],inp[n];
	int row[n],col[n],atr[n],atc[n];
	forn (i,n){
        r[i] = {0,i}; c[i] = {0,i};
        row[i] = i; col[i] = i;
        atr[i] = i; atc[i] = i;
	}
	forn(i,n-1){
        cin >> ro >> co;
        inp[i] = {ro,co};
        r[ro-1].first++;c[co-1].first++;
	}
	sort ( c,c+n );
	reverse(c,c+n);
	vector<ii>ansc;
    forn(i,n){
        if ( atc[i] == c[i].second ) continue;
        int c1sw = col[c[i].second];
        int cat1 = c[i].second;
        col[c[i].second] = i;
        col[atc[i]] = c1sw;
        atc[c1sw] = atc[i];
        atc[i] = cat1;
        ansc.pb({i,c1sw});
    }
    forn(i,n-1){
        rowcnt[inp[i].first-1] = max ( rowcnt[inp[i].first-1], col[inp[i].second-1]+1 );
    }
	sort ( r,r+n,comp );
    vector<ii>ansr;
    forn(i,n){
        if ( atr[i] == r[i].second ) continue;
        int r1sw = row[r[i].second];
        int rat1 = r[i].second;
        row[r[i].second] = i;
        row[atr[i]] = r1sw;
        atr[r1sw] = atr[i];
        atr[i] = rat1;
        ansr.pb({i,r1sw});
    }
    cout << ansr.size() + ansc.size() << edl;
    forn(i,ansc.size()){
        cout << "2 " << ansc[i].first+1 << " " << ansc[i].second+1 << edl;
    }
    forn(i,ansr.size()){
        cout << "1 " << ansr[i].first+1 << " " << ansr[i].second+1 << edl;
    }

}
