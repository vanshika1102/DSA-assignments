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

  int ans=0;
  for(int i=0; i<n; i++)
  {
    if(a[i]==1)
    {
      int cnt=0;
      while(a[i]==1)
      {
        cnt++;
      }
      ans=max(cnt,ans);
    }
    cout<<ans<<"\n";
  }

  return 0;
}