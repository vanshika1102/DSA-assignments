#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
  int n;
  cin>>n;

  int ans=0;
  while(n)
  {
    ans+=(n%10); // adding unit digit
    n/=10;       // removing unit digit
  }
  cout<<ans<<"\n";

  return 0;
}