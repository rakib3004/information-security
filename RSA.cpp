#include<bits/stdc++.h>
using namespace std;

int greatestCommonDivisor(int a, int b){
//if(a<b) swap(a,b);

if(a%b==0) return b;

return greatestCommonDivisor(b,a%b);

}


int implementRSA(int phaiN,int e){

int i,j;

for(i=1;i<1000;i++){
    for(j=1;j<1000;j++){

        int x=i*phaiN;
        int y=j*e;

        if(x-y==1){
         return phaiN-j;
        }
    }
}

return 0;
}

int main(){


    int p,q;

p=17;
q=11;

cin>>p>>q;
int n;

n=p*q;

int phaiN = (p-1)*(q-1);


int e=7;

cin>>e;

int d = implementRSA(phaiN,e);


long double messages;

//cout<<"Enter message: ";
cin>>messages;


long double encrypted,decrypted;
encrypted=0;
decrypted=0;

encrypted = pow(messages,e);
encrypted = fmod(encrypted,n);
cout<<"Encryption: "<<encrypted<<endl;

decrypted = pow(encrypted,d);
decrypted = fmod(decrypted,n);

cout<<"Decryption: "<<decrypted<<endl;




return 0;
}
