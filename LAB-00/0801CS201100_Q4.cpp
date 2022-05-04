#include<iostream>
using namespace std;
class Rectangle
{
    public:
    int a,b,c,d;//(a,b) and (c,d) are coordinates of diagonal of a rectangle within the given constraint 
    Rectangle()
    {
        cout<<"Enter coordinates (a,b) and (c,d) of diagonal of a rectangle with constraints 0<=a,b,c,d<=999, c>a,d>b"<<endl;
        cin>>a>>b>>c>>d;
    }
    Rectangle(int w,int x,int y,int z) 
    {
        a=w;
        b=x;
        c=y;
        d=z;
    }
    int getlength()
    {
        return c-a;
    }
    int getbrdth()
    {
        return d-b;
    }
   Rectangle interchange_row_column()
    {
        a=a+b;
        b=a-b;
        a=a-b;

        c=c+d;
        d=c-d;
        c=c-d;
        Rectangle r(a,b,c,d);
        return r;
    }


};
class blots
{
    int arr[1000][1000];
    int rand();
    public:
    void initialize()
    {
         for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        arr[i][j]=rand()%2;
    }
    }
    int searching_blot(Rectangle r)
    {
        int x=0;
        //checking along row
        for(int i=r.a;i<=r.c;i++)
        {
            for(int j=r.b;j<=r.d;j++)
            {
            if(x==10)
            {
                return 1;
            }
            if(arr[i][j]==0)
            x=0;
            else
            x++;
            }
        }
        return -1;

    }


};
int main() {
    Rectangle r1;
    blots b;
    b.initialize();
    int x=b.searching_blot(r1);
    int y=0;
    if(x==-1)
    {
    r1=r1.interchange_row_column();//so we can search in column with the same function searching_blot
    y=b.searching_blot(r1);
    }
    else
    cout<<"Blot is present in the User Input Rectangle of the Image"<<endl;
    if(y==-1)
    cout<<"No Blotis present in the User Input Rectangle of the Image"<<endl;
    else
    {
        if(y==1)
     cout<<"Blot is present in the User Input Rectangle of the Image"<<endl;
    }

    Rectangle r2(0,0,999,999);//biggest rectangle created to search if any blot is present in entire sheet or not
   x=b.searching_blot(r2);
   y=0;
   if(x==-1)
   {
    r2=r2.interchange_row_column();
   y=b.searching_blot(r2);   
   }
   else
    cout<<"Blot is present in the Image"<<endl;
    if(y==-1)
    cout<<"No Blot present in the Image"<<endl;
    else
    {
        if(y==1)
     cout<<"Blot is present in the Image"<<endl;
    }
    return 0;
}
