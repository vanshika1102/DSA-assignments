#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

//function to get no of one in an integer
int noOfOne(int n)
{
  int cnt=0;
  while(n)
  {
    n&=(n-1);
    cnt++;
  }
  return cnt;
}

int main()
{
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0; i<n; i++) cin>>a[i];

  int ans=0, maxOne=0;
  for(int i=0; i<n; i++)
  {
    if(maxOne<noOfOne(a[i]))
    {
      maxOne=noOfOne(n);
      ans=n;
    }
  }
  cout<<ans<<"\n";

  return 0;
}