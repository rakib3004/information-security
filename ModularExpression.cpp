#include<bits/stdc++.h>
using namespace std;



int main()
{


   int i;
   int e=9;
   int n=352;



   for(i=10;i<=2450;i++){


        if((e*i)%n==1){
                cout<<e*i<<" "<<(e*i)%n<<endl;
            cout<<"d is: "<<i<<endl;
            return 0;
        }
        cout<<e*i<<" "<<(e*i)%n<<endl;

   }
    return 0;

}
