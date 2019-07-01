#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;

#define ll long long int
#define in(n) int n; cin >> n;
#define inl(n) long long int n; cin >> n;
#define forn(i,n) for ( int i=0 ; i<n ; i++ )
#define forni(i,j,n) for ( int i=j ; i<n ; i++ )
#define fornn(i,n) for ( int i=n-1 ; i>=0 ; i-- )
#define forvec(num) for ( vector<int>::iterator it=num.begin(); it!=num.end(); it++ )
#define filecode ifstream in;ofstream out;in.open("input.txt");out.open("output.txt");
#define modN 1000000007
#define Arr(n) int arr[n]; forn(i,n) cin>>arr[i];

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(n);in(k);in(d);
    int dp[100][2];
    dp[0][0] = 1;
    dp[0][1] = 0;
    forni(i,1,n+1){
        dp[i][0] = dp[i][1] = 0;
        forni(j,1,k+1){
            if ( i-j<0 ) break;
            if ( j<d ){
                dp[i][0] += dp[i-j][0];
                if ( dp[i][0]> modN ) dp[i][0] -= modN;
                dp[i][1] += dp[i-j][1];
                if ( dp[i][1]> modN ) dp[i][1] -= modN;
            } else {
                dp[i][1] += dp[i-j][0];
                if ( dp[i][1]> modN ) dp[i][1] -= modN;
                dp[i][1] += dp[i-j][1];
                if ( dp[i][1]> modN ) dp[i][1] -= modN;
            }
        }
    }
    cout << dp[n][1] << endl;
}
