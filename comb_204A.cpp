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
#define toi(ch) (int)(ch-'a')

#define filecode ifstream in;ofstream out;in.open("input.txt");out.open("output.txt");
#define Arr(n) int arr[n]={}; forn(i,n) cin>>arr[i];
#define setPrecision(n) cout << std::setprecision(n) << std::fixed;
#define outk(z,n) cout << "Case #" << z << ": " << n << endl;
#define MOD 1000000009
#define PI 3.14159265

ll solve ( string a ){

    int len = a.length();
    ll tp = 0;
    if ( len==1 ) tp = (int)(a[0]-'0');
    else if ( len==2 ){
        if ( a[1]>=a[0] ){
            tp = 9+(int)(a[0]-'0');
        } else tp = 9+(int)(a[0]-'0')-1;
    } else {
        forni( i,1,len-1 ){
            tp *= 10;
            tp += (int)(a[i]-'0');
        }
        if ( a[len-1]>=a[0] ) tp++;
        tp += 18;
        ll tn = 10;
        forni ( i,1,len-2 ){
            tp+= 1ll*tn*9;
            tn*= 1ll*10;
        }
        tp += 1ll*tn*((int)(a[0]-'0')-1);
    }
    return tp;

}

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    string in1,in2;
    cin >> in1 >> in2;
    ll low,hgh;
    low = solve ( in1 );
    hgh = solve ( in2 );
    ll ans = hgh-low;
    if ( in1[0]==in1[in1.length()-1] ) ans++;
    cout << ans << edl;

}
