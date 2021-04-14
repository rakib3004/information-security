
#include<iostream>
#include<math.h>
using namespace std;


long long int calculatePublicKey(long long int G,long long int a,long long int P){

long long int powerOfGa = pow(G,a);

return  powerOfGa%P;

}

long long int primitive_root( long long int m){
	for(ll i=2;i<m;i++){
		if(__gcd(i,m)==1)
		return i;
	}
	return -1
}

int main() {

 long long int P,G, X,Y, keyA, keyB, privateKeyA, privateKeyB;

 P=29;
 G=16;

 privateKeyA=4;
 privateKeyB=3;

P=primitive_root(G);

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
            cout<<"Here, key a= "<<keyA<<" and key b= "<<keyB<<endl<<"So, both are no same same"<<endl;


}

}
