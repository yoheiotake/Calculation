#include <iostream>
using namespace std;


class Euler{
private:
    double x;
    double n;
    double delta_x;
protected:
    void EulerMethod_X(double yn,double zn);
    double EulerMethod_Z(double zn,double yn);
public:
    Euler(double px,double pn);
    ~Euler();
    void EulerMethod();
};


Euler::Euler(double px,double pn){
    x = 0;
    n = pn;
    delta_x = px / pn;
}

Euler::~Euler(){
    
}

void Euler::EulerMethod(){
    EulerMethod_X(1,1);
}

void Euler::EulerMethod_X(double yn,double zn){
    if(x++ == n) return;
    double y = yn + delta_x * zn;
    cout <<"y"<< x <<" : "<< y << endl;
    EulerMethod_X(y,EulerMethod_Z(zn,yn));
}

double Euler::EulerMethod_Z(double zn,double yn){
    return zn - 2 * delta_x * yn;
}

int main(){

    double x,n;
    cout <<"Input X"<< endl;
    cin >> x;
    cout <<"Input N"<< endl;
    cin >> n;
    
    if(!cin){
        cout <<"Invalid Number"<< endl;
        return -1;
    }
    
    Euler y(x,n);
    y.EulerMethod();
    
    return 0;
}