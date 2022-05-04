#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0; i<n; i++) cin>>a[i];

  int ans=INT_MIN;
  for(int i=0; i<n; i++)
  {
    //standard function to find maximum
    ans=max(ans,a[i]);
  }
  cout<<ans<<"\n";
  return 0;
}