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

#define filecode ifstream in;ofstream out;in.open("input.txt");out.open("output.txt");
#define Arr(n) int arr[n]={}; forn(i,n) cin>>arr[i];
#define setPrecision(n) cout << std::setprecision(n) << std::fixed;
#define outk(z,n) cout << "Case #" << z << ": " << n << endl;
#define deb cout << "Here" << endl;

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);
    double sum = 0;
    int arr[200001] = {};
    int last = 0,op,x,y, lsind=1;
    setPrecision(6);
    forn(i,n){
        cin >> op;
        if ( op==1 ){
            cin >> x >> y;
            if ( x>=lsind ){
                sum += lsind*y;
                last += y;
            } else {
                sum += x*y;
                arr[x] -= y;
            }
        } else if ( op==2 ){
            cin >> x;
            arr[lsind] = x-last;
            lsind++;
            last = x;
            sum += x;
        } else {
            sum -= last;
            lsind--;
            last -= arr[lsind];
        }
        cout << sum/lsind << edl;
    }

}
