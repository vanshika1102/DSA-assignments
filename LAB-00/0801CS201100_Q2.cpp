#include <iostream>
using namespace std;

class shape{
    public:
    float getArea()
    { return -1.0;}
};
class circle: public shape{
    private:
    float radius;
    public:
    float getArea(){
        return 3.14*radius*radius;
    }
    circle(float r){
        radius=r;
    }
};
int main(){
    float n;
    cout<<"Enter the value of radius in float form:";
    cin>>n;
    circle c1(n);
    circle *p;
    p =&c1;
    cout<<"Area of Circle is "<<(*p).getArea()<<endl;
    return 0;
}


