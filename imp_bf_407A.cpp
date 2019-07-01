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

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
	in(a);in(b);
	int ax=-1,ay=-1,bx=-1,by=-1;
	int tp=a,tp2=b;
	a = min(tp,tp2);
	b = max(tp,tp2);
	bool done = 0;
	forni(i,1,1000){
        forni(j,i+1,1000){
            tp = i*i+j*j;
            if ( tp==a*a ){
                ax = i;
                ay = j;
                if ( (ay*b)%a==0 && (ax*b)%a==0 ){
                    bx = (ay*b)/a;
                    by = -(ax*b)/a;
                    done = 1;
                    break;
                }
            }
        }
        if ( done ) break;
	}
	if ( done ){
        cout << "YES" << edl << "0 0" << edl;
        cout << ax << " " << ay << edl << bx << " " << by << edl;
	} else cout << "NO" << edl;
}
