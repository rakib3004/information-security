#include<bits/stdc++.h>
using namespace std;
string secretMessage="", secretKey="";
bitset<8> secretMessageInBitSet[4][4];
bitset<8> secretKeyInBitSet[4][4];

void messageToHexaDecimal(string stringData, int k){

int matrix_size=4;

int i,j;

for(i=0;i<matrix_size;i++){
    for(j=0;j<matrix_size;j++){

        if(k==0){
secretMessageInBitSet[i][j] = (int)secretMessage[i*4+j];
        }
        else{
secretKeyInBitSet[i][j] = (int)secretKey[i*4+j];

        }

    }
}

}

void advanceDataEncryptionMethods(){
messageToHexaDecimal(secretMessage,0);
messageToHexaDecimal(secretKey,1);

}

int main(){



secretMessage="Thats my Kung Fu", secretKey="Two One Nine Two";


advanceDataEncryptionMethods();

return 0;
}
