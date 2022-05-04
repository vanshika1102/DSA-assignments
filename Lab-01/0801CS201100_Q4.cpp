#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
  int n;
  cin>>n;

  //by Brian Kernighans algo
  int ans=0;
  while(n)
  {
    n&=(n-1);
    ans++;
  }

  return 0;
}