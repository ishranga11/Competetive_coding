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

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    string inp;
    getline ( cin, inp );
    int len = inp.length();
    int gend = 0,it=0;
    bool adj,n,v;
    adj = n = 1;
    v = 0;
    int cnt = 0;
    while ( 1 ){

        while ( it<len && inp[it]!=' ' ) it++;
        if ( inp[it-4]=='l'&&inp[it-3]=='i'&&inp[it-2]=='o'&&inp[it-1]=='s' ){
            if ( gend==2 || !adj ){
                cout << "NO" << endl;
                return 0;
            }
            gend = 1;
        }
        else if ( inp[it-5]=='l'&&inp[it-4]=='i'&&inp[it-3]=='a'&&inp[it-2]=='l'&&inp[it-1]=='a' ){
            if ( gend==1 || !adj ){
                cout << "NO" << endl;
                return 0;
            }
            gend = 2;
        }
        else if ( inp[it-3]=='e'&&inp[it-2]=='t'&&inp[it-1]=='r' ){
            if ( gend==2 || !n ){
                cout << "NO" << endl;
                return 0;
            }
            gend = 1;
            adj = n = 0;
            v = 1;
        }
        else if ( inp[it-4]=='e'&&inp[it-3]=='t'&&inp[it-2]=='r'&&inp[it-1]=='a' ){
            if ( gend==1 || !n ){
                cout << "NO" << endl;
                return 0;
            }
            gend = 2;
            adj = n = 0;
            v = 1;
        }
        else if ( inp[it-6]=='i'&&inp[it-5]=='n'&&inp[it-4]=='i'&&inp[it-3]=='t'&&inp[it-2]=='i'&&inp[it-1]=='s' ){
            if ( gend==2 || (!v&&!(cnt==0&&it==len)) ){
                cout << "NO" << endl;
                return 0;
            }
            gend = 1;
        }
        else if ( inp[it-6]=='i'&&inp[it-5]=='n'&&inp[it-4]=='i'&&inp[it-3]=='t'&&inp[it-2]=='e'&&inp[it-1]=='s' ){
            if ( gend==1 || (!v&&!(cnt==0&&it==len)) ){
                cout << "NO" << endl;
                return 0;
            }
            gend = 2;
        } else {
            cout << "NO" << endl;
            return 0;
        }
        cnt++;
        it++;
        if ( it>=len ) break;

    }
    if ( !v && cnt>1 ) cout << "NO" << endl;
    else cout << "YES" << endl;

}
