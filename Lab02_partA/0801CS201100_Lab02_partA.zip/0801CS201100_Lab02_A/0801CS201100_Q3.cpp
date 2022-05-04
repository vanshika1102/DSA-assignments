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
  bool move(char x, char y)
  {
    stack<int> a=whichStack(x);
    stack<int> b=whichStack(y);
    // when b is empty
    if(b.empty())
    {
      b.push(a.top());
      a.pop();
      return true;
    }
    //when a is empty
    else if(a.empty())
    {
      a.push(b.top());
      b.pop();
      return false;
    }
    else
    {
      // a has smaller disc
      if(b.top()>a.empty())
      {
        b.push(a.top());
        a.pop();
        return true;
      }
      // a has bigger disc
      else
      {
        a.push(b.top());
        b.pop();
        return false;
      }
    }
  }

  //algorithm to simulate all moves
  void simulate()
  {
    int x=pow(2,n)-1; // total no of moves
    //for even
    if(n%2==0)
    {
      int i=1;
      while(i<=x)
      {
        if(i%3==1)
        {
          if(move('s','a')) cout<<"move disk"<<a.top()<<"from source to auxillary\n";
          else              cout<<"move disk"<<s.top()<<"from auxillary to source\n";
        }
        else if(i%3==2)
        {
          if(move('s','d')) cout<<"move disk"<<d.top()<<"from source to destination\n";
          else              cout<<"move disk"<<s.top()<<"from destination to source\n"; 
        }
        else
        {
          if(move('a','d')) cout<<"move disk"<<d.top()<<"from auxillary to destination\n";
          else              cout<<"move disk"<<a.top()<<"from destination to auxillary\n";
        }
        i--;
      }
    }

    //for odd
    else
    {
      int i=1;
      while(i<=x)
      {
        if(i%3==1)
        {
          if(move('s','d')) cout<<"move disk"<<d.top()<<"from source to destination\n";
          else              cout<<"move disk"<<s.top()<<"from destination to source\n";
        }
        else if(i%3==2)
        {
          if(move('s','a')) cout<<"move disk"<<a.top()<<"from source to auxillary\n";
          else              cout<<"move disk"<<s.top()<<"from auxillary to source\n";
        }
        else
        {
          if(move('d','a')) cout<<"move disk"<<d.top()<<"from destination to auxillary\n";
          else              cout<<"move disk"<<a.top()<<"from auxillary to destination\n";
        }
        i--;
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
  // can call multiple function
  
  return 0;
}