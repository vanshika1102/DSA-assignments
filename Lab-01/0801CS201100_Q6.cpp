#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
  int n;
  cin>>n;
  vector<int>a(n+1);
  for(int i=0; i<n+1; i++) cin>>a[i];

  int sum=0;
  for(int i=0; i<n; i++)
  {
    sum+=a[i];
  }
  // avg is sum/no of elements
  cout<<sum/n<<"\n";
  return 0;
}