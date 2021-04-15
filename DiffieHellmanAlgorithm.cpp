
#include<iostream>
#include<math.h>
#include <iostream>
#include <algorithm>
using namespace std;


long long int calculatePublicKey(long long int G,long long int a,long long int P){

long long int powerOfGa = pow(G,a);

return  powerOfGa%P;

}



bool coprime(long long int a, long long  int b) {

    if (__gcd(a, b) == 1)
        return true;
    else
        return false;
}

int main() {

 long long int P,G, X,Y, keyA, keyB, privateKeyA, privateKeyB;

 A:
 P=23;
 G=9;
cout<<"Enter P & G : ";
cin>>P>>G;

if(coprime(P,G)==false){
        cout<<"Try Again !!!"<<endl;
    goto A;
}

 privateKeyA=5;
 privateKeyB=7;

X= calculatePublicKey(G,privateKeyA,P);
Y= calculatePublicKey(G,privateKeyB,P);


cout<<"The value of P = "<<P<<endl;
cout<<"The value of G = "<<G<<endl;
cout<<"The value of private key a = "<<privateKeyA<<endl;
cout<<"The value of private key b = "<<privateKeyB<<endl;
cout<<"The value of X = "<<X<<endl;
cout<<"The value of Y = "<<Y<<endl;

keyA=calculatePublicKey(Y,privateKeyA,P);
keyB=calculatePublicKey(X,privateKeyB,P);

if(keyA==keyB){
    cout<<"Here, key a= "<<keyA<<" and key b= "<<keyB<<endl<<"So, both are same"<<endl;
}
else{
            cout<<"Here, key a= "<<keyA<<" and key b= "<<keyB<<endl<<"So, both are not same"<<endl;


}

}
