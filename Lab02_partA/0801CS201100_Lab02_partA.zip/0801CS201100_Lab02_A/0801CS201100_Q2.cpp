#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

class HanoiTower
{
  public:
  int n=0; // no of disk
  stack<int>s,a,d; // source, auxillary, destination
  
  // constructor to initialize disk
  HanoiTower(int x)
  {
    n=x;
    for(int i=n; i>0; i--) s.push(i);
  }

  // tells the stack according to charcter input
  stack<int> whichStack(char c)
  {
    if(c=='a') return a;
    else if(c=='d') return d;
    else return s;
  }

  // move method
  void move(char x, char y)
  {
    stack<int> a=whichStack(x);
    stack<int> b=whichStack(y);
    // when b is empty
    if(b.empty())
    {
      b.push(a.top());
      a.pop();
    }
    //when a is empty
    else if(a.empty())
    {
      cout<<"invalid move";
    }
    else
    {
      // a has smaller disc
      if(b.top()>a.empty())
      {
        b.push(a.top());
        a.pop();
      }
      // a has bigger disc
      else
      {
        cout<<"invalid move";
      }
    }
  }

  // display method to print all towers
  void display()
  {
    stack<int>sd=s;
    cout<<"source:\n";
    while(!sd.empty()){cout<<sd.top()<<"\n"; sd.pop();}
    stack<int>ad=a;
    cout<<"auxillary:\n";
    while(!ad.empty()){cout<<ad.top()<<"\n"; ad.pop();}
    stack<int>dd=d;
    cout<<"destination:\n";
    while(!dd.empty()){cout<<dd.top()<<"\n"; dd.pop();}
  }

};

int main()
{
  int n;
  cin>>n;
  // creating an object
  HanoiTower h=HanoiTower(n);
  // can call multiple move fuction
  h.move('s', 'd');
  h.display();
  return 0;
}