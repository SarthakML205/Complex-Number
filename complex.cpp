#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

#define PI 3.141593

class Complex{
    public:
        double real;
        double imag;

        void SetValues(double TempReal, double TempImag)
        {
            real = TempReal;
            imag = TempImag;
        }
};

Complex add(Complex A, Complex B){
    double a = A.real;
    double b = A.imag;
    double c = B.real;
    double d = B.imag;

    Complex ans;
    ans.SetValues(a+b, c+d);

    return ans;
}

Complex diff(Complex A, Complex B){
    double a = A.real;
    double b = A.imag;
    double c = B.real;
    double d = B.imag;

    Complex diffAns;
    diffAns.SetValues(a-b, c-d);

    return diffAns;
}

Complex multiply(Complex A, Complex B){
    double a = A.real;
    double b = A.imag;
    double c = B.real;
    double d = B.imag;

    double ac = a*c;
    double ad = a*d;
    double bc = b*c;
    double bd = b*d;

    Complex multAns;
    multAns.SetValues(ac-bd, ad+bc);

    return multAns;
}

Complex division(Complex A, Complex B){
    double a = A.real;
    double b = A.imag;
    double c = B.real;
    double d = B.imag;

    double ac = a*c;
    double ad = a*d;
    double bc = b*c;
    double bd = b*d;
    double sqrC = c*c;
    double sqrD = d*d;

    double real = (ac + bd)/(sqrC + sqrD);
    double imag = (bc - ad)/(sqrC + sqrD);

    Complex divAns;
    divAns.SetValues(real, imag);

    return divAns;
}

Complex conjugate(Complex A){
    double a = A.real;
    double b = A.imag;

    Complex conj;
    conj.SetValues(a,-b);

    return conj;
}

double modul(Complex A){
    double a = A.real;
    double b = A.imag;

    double sqrtA = a*a;
    double sqrtB = b*b;

    double sumAB = sqrtA + sqrtB;

    double moduli = sqrt(sumAB);

    return moduli;
}

void rectToPolar(Complex A){
    double a = A.real;
    double b = A.imag;

    int theta = atan(b/a)*180/PI;
    double moduli = modul(A);
    char i = 161; //iota Symbol ASCII Code
    char s = 251; //Sqaure root ASCII Code  
    if(moduli == floor(moduli)){ //checks if the imag  is INT type or not
        cout<<"The polar form of given Complex is \n"<<moduli<<"(cos("<<theta<<") + "<<i<<"sin("<<theta<<"))"<<endl;
    }else{
        double sqrtModuli = moduli*moduli;
        int sqr = round(sqrtModuli);
        cout<<"The polar form of given Complex is \n"<<s<<sqr<<"(cos("<<theta<<") + "<<i<<"sin("<<theta<<"))"<<endl;
    }
    
}

Complex polarToRect(double r, double t){

    double theta = t*PI/180;
    double cosine = cos(theta);
    double sine = sin(theta);

    double real = r*cosine;
    double imag = r*sine;

    Complex rect;
    rect.SetValues(real, imag);

    return rect;
}

void PrintComplex(Complex A){
    double a = A.real;
    double b = A.imag;
    char s = 251;

    if((a == floor(a)) && (b == floor(b))){
        cout<<"("<<a<<", "<<b<<")"<<endl;
    }
    else if((a == floor(a)) && (b != floor(b))){
        double sqr = b*b;
        int sqrB = round(sqr);
        cout<<"("<<a<<", "<<s<<sqrB<<")"<<endl;
    }else if((a != floor(a)) && (b == floor(b))){
        double sqr = a*a;
        int sqrA = round(sqr);
        cout<<"("<<s<<sqrA<<", "<<b<<")"<<endl;
    }else{
        double sqra = a*a;
        double sqrb = b*b;
        int sqrA = lround(sqra);
        int sqrB = lround(sqrb);
        if((sqrA == 1 || sqrA == 0) && (sqrB == 0 || sqrB == 1)){
            cout<<"("<<sqrA<<", "<<sqrB<<")"<<endl;
        }else if(sqrA == 1 || sqrA == 0){
            cout<<"("<<sqrA<<", "<<s<<sqrB<<")"<<endl;
        }else if(sqrB == 1 || sqrB == 0 ){
            cout<<"("<<s<<sqrA<<", "<<sqrB<<")"<<endl;
        }else{
            cout<<"("<<s<<sqrA<<", "<<s<<sqrB<<")"<<endl;
        }
        
    }
}

int main(){
    
    Complex C1;
    Complex C2;
    C1.SetValues(1.73205,2);
    C2.SetValues(2,1.41421);
    cout<<"C1 is: ";
    PrintComplex(C1);
    cout<<"C2 is: ";
    PrintComplex(C2);
    

    Complex sum = add(C1,C2);
    cout<<"Addition of C1 and C2 is ";
    PrintComplex(sum);

    Complex sub = diff(C1, C2);
    cout<<"Difference of C1 and C2 is ";
    PrintComplex(sub);

    Complex mult = multiply(C1, C2);
    cout<<"Multiplication of C1 and C2 is ";
    PrintComplex(mult);

    Complex div = division(C1, C2);
    cout<<"Division of C1 and C2 is ";
    PrintComplex(div);

    Complex conjC1 = conjugate(C1);
    cout<<"Conjugate of C1 is ";
    PrintComplex(conjC1);
    cout<<"Modulus of C1 is "<<modul(C1)<<endl;

    Complex C4;
    C4.SetValues(1,1);
    cout<<"Modulus of C3 is "<<modul(C4)<<endl;

    rectToPolar(C1);

    Complex ptr = polarToRect(2,60);
    PrintComplex(ptr);

}