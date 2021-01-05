#include<bits/stdc++.h>
using namespace std;
string hexaDecimalToBinary(string hexaDecimalText)
{
    map<char,string> byteMapping;
    string binaryText="";
    byteMapping['0']="0000";
    byteMapping['1']="0001";
    byteMapping['2']="0010";
    byteMapping['3']="0011";
    byteMapping['4']="0100";
    byteMapping['5']="0101";
    byteMapping['6']="0110";
    byteMapping['7']="0111";
    byteMapping['8']="1000";
    byteMapping['9']="1001";
    byteMapping['A']="1010";
    byteMapping['B']="1011";
    byteMapping['C']="1100";
    byteMapping['D']="1101";
    byteMapping['E']="1110";
    byteMapping['F']="1111";
    int i=0;

    for(i=0; i<hexaDecimalText.size(); i++)
    {
        if(hexaDecimalText[i]<='z'||hexaDecimalText[i]>='a'){
            hexaDecimalText[i] = hexaDecimalText[i]+32;
        }
        binaryText = binaryText+ byteMapping[hexaDecimalText[i]];
    }
    return binaryText;

}

string binaryToHexaDecimal(string binaryText)
{
    map<string,string> bitsMapping;
    string hexaDecimalText="";
    bitsMapping["0000"]="0";
    bitsMapping["0001"]="1";
    bitsMapping["0010"]="2";
    bitsMapping["0011"]="3";
    bitsMapping["0100"]="4";
    bitsMapping["0101"]="5";
    bitsMapping["0110"]="6";
    bitsMapping["0111"]="7";
    bitsMapping["1000"]="8";
    bitsMapping["1001"]="9";
    bitsMapping["1010"]="A";
    bitsMapping["1011"]="B";
    bitsMapping["1100"]="C";
    bitsMapping["1101"]="D";
    bitsMapping["1110"]="E";
    bitsMapping["1111"]="F";
    int i=0;
    for(i=0; i<binaryText.length(); i=i+4)
    {
         string hexaChar="";

        hexaChar+= binaryText[i];
        hexaChar+= binaryText[i+1];
        hexaChar+= binaryText[i+2];
        hexaChar+= binaryText[i+3];
        hexaDecimalText += bitsMapping[hexaChar];
      //  cout<<hexaDecimalText<<endl;
    }
    return hexaDecimalText;
}
void advanceEncryptionStandardSystem(){

string plainText ="54776F204F6E65204E696E652054776F";
string key="5468617473206D79204B756E67204675";


string wordArray[4][4];
string keyArray[4][4];
int arrayRow=4;
int iterator,jterator=0;
int splitIter=0;
for(iterator=0;iterator<plainText.size();iterator=iterator+8){

  for(jterator=0;jterator<arrayRow;jterator++){
//cout<<plainText.substr(splitIter,splitIter+2)<<endl;
        wordArray[iterator/8][jterator]=plainText.substr(splitIter,2);
splitIter= splitIter+2;
//cout<<wordArray[iterator][jterator]<<" ";
  }
//    cout<<endl;

}
splitIter=0;

    for(iterator=0;iterator<plainText.size();iterator=iterator+8){

        for(jterator=0;jterator<arrayRow;jterator++){
//cout<<plainText.substr(splitIter,splitIter+2)<<endl;
            keyArray[iterator/8][jterator]=key.substr(splitIter,2);
            splitIter= splitIter+2;
//cout<<wordArray[iterator][jterator]<<" ";
        }
//    cout<<endl;

    }

    cout<<"Word Array : "<<endl;
for(iterator=0;iterator<arrayRow;iterator++){
    for(jterator=0;jterator<arrayRow;jterator++){
        cout<<wordArray[iterator][jterator]<<" ";
    }
    cout<<endl;
}

cout<<"Key Array : "<<endl;
for(iterator=0;iterator<arrayRow;iterator++){
    for(jterator=0;jterator<arrayRow;jterator++){
        cout<<keyArray[iterator][jterator]<<" ";
    }
    cout<<endl;
}


string temp = keyArray[3][0];
for(iterator=0;iterator<3;iterator++){
    keyArray[3][iterator]= keyArray[3][iterator+1];
}
    keyArray[3][3]=temp;


    cout<<"Key Array shift : "<<endl;
    for(iterator=0;iterator<arrayRow;iterator++){
        for(jterator=0;jterator<arrayRow;jterator++){
            cout<<keyArray[iterator][jterator]<<" ";
        }
        cout<<endl;
    }

}



int main(){
advanceEncryptionStandardSystem();
}
