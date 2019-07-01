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
	string in;
	cin >> in;
	int len = in.length();
	stack <int> s;
	int c[len]={};
	int ansl = 0, anst = 1, curr=0;
	forn(i,len){
        if ( in[i]=='(' ) s.push(i);
        else {
            if ( s.empty() ) continue;
            c[s.top()] = i-s.top()+1;
            s.pop();
        }
	}
	int i=0;
	while ( i<len ){
        if ( c[i] ){
            curr += c[i];
            i += c[i];
        } else {
            if ( curr>ansl ){
                ansl = curr;
                anst = 1;
            } else if ( curr==ansl ) anst++;
            curr = 0;
            i++;
        }
	}
	if ( curr>ansl ){
        ansl = curr;
        anst = 1;
    } else if ( curr==ansl ) anst++;
	if ( !ansl ) anst = 1;
    cout << ansl << " " << anst << edl;
}
