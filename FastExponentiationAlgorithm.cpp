#include<bits/stdc++.h>
using namespace std;

int main(){


int a,b;

cin>>a>>b;

int f=1, T=a, E=b;
while(1){

if(E%2==1){
f =f*T;
}

E =E/2;
T= T*T;

if(E<=0){
cout<<"The output is: ";
cout<<f<<endl;
return 0;
}

}


return 0;

}

