#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

//function to add no.s
double addThree(double a, double b, double c)
{
  return a+b+c;
}

int main()
{
  double a,b,c;
  cin>>a>>b>>c;
  cout<<addThree(a,b,c)<<"\n";

  return 0;
}