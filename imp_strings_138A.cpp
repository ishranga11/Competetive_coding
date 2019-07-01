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

string inp[4];
int k;

int check ( ){

    string bcks[4];
    forn(i,4){
        int st = inp[i].length();
        int vw = 0;
        while ( 1 ){
            if ( inp[i][st]=='a' || inp[i][st]=='e' || inp[i][st]=='i' || inp[i][st]=='o' || inp[i][st]=='u' ) vw++;
            if ( vw==k ) break;
            if ( st<0 ) return -1;
            st--;
        }
        bcks[i] = inp[i].substr(st);
    }
    if ( bcks[0]==bcks[1] && bcks[1]==bcks[2] && bcks[2]==bcks[3] ) return 0;
    if ( bcks[0]==bcks[1] && bcks[2]==bcks[3] ) return 1;
    if ( bcks[0]==bcks[2] && bcks[1]==bcks[3] ) return 2;
    if ( bcks[0]==bcks[3] && bcks[1]==bcks[2] ) return 3;
    return -1;

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);cin >> k;
    int ans = -1;
    forn ( i,n ){

        forn(i,4){
            cin >> inp[i];
        }
        int scm = check();
        if ( !scm ){
            if ( ans==-1 ) ans = 0;
            continue;
        }
        if ( scm == -1 ) { ans=-1; break; }
        else {
            if ( ans>0 && ans!=scm ) { ans = -1; break; }
            ans = scm;
        }

    }
    if ( ans==-1 ) cout << "NO" << endl;
    else {
        if ( ans==0 ) cout << "aaaa" << endl;
        if ( ans==1 ) cout << "aabb" << endl;
        if ( ans==2 ) cout << "abab" << endl;
        if ( ans==3 ) cout << "abba" << endl;
    }

}
