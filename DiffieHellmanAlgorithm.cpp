
#include<iostream>
#include<math.h>
using namespace std;
// find gcd

int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

int main() {

   double p = 59, q =61;
   double n=p*q;
   double phi = (p-1)*(q-1);

   double e=2;
   // 1 < e < phi(n) and gcd(e, phi(n)) = 1
   while(e<phi) {
      if(gcd(e,phi)==1)
         break;
      else
         e++;
   }

   // d*e = 1 mod phi
   double d=1/e;
   d=fmod(d,phi);
   double text = 80;

   double c ;
   double m;
   c=fmod(pow(text,e),n);

   cout<<"Text = "<<text << endl;
   cout<<"n = " <<n << endl;
   cout<<"phi = "<<phi << endl;
   cout<<"e = "<<e << endl;
   cout<<"d = "<<d << endl;
   cout<<"Encrypted text = "<<c << endl;

   m=fmod(pow(text,e*d),n);

   cout<<"Decrypted text = "<<m;
   return 0;
}
