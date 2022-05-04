#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

bool isOperator(char c)
{
  if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') return true;
  return false;
}

bool isRightAssociactive(char c)
{
  if(c=='^') return true;
  return false;
}

int getOperatorWeight(char c)
{
  int weight=-1;
  switch(c)
  {
    case '+': 
    case '-': weight=1;
    case '*':
    case '/': weight=2;
    case '^': weight=3;
  }
  return weight;
}

bool hasHigherPrecedence(char op1, char op2)
{
  int op1wt=getOperatorWeight(op1);
  int op2wt=getOperatorWeight(op2);
  if(op1wt==op2wt)
  {
    if(isRightAssociactive(op1)) return false;
    return true;
  }
  if(op1wt>op2wt) return true;
  return false;
}

int main()
{
  string infix;
  cin>>infix;

  string postfix="";
  stack<char>s;
  for(int i=0; i<infix.size(); i++)
  {
    if(isOperator(infix[i])) 
    {
      while(!s.empty() && hasHigherPrecedence(s.top(),infix[i]))
      {
        postfix+=s.top();
        s.pop();
      }
      s.push(infix[i]); //push current operator also
    }
    else if(infix[i]=='(')
    {
      s.push(infix[i]);
    }
    else if(infix[i]==')')
    {
      while(!s.empty() && s.top()!='(')
      {
        postfix+=s.top();
        s.pop();
      }
      s.pop(); // remove ( alse
    }
    else
    {
      postfix+=infix[i];
    }
  }
   while(!s.empty())
   {
     postfix+=s.top();
     s.pop();
   }

  cout<<postfix<<"\n";
  return 0;
}