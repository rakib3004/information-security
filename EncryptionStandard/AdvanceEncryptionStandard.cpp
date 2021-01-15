#include<bits/stdc++.h>
using namespace std;
string secretMessage="", secretKey="";
bitset<8> secretMessageInBitSet[4][4];
bitset<8> secretKeyInBitSet[4][4];

bitset<32> wordInAES[44];
bitset<32> stateMatrix[4];

bitset<8> AES_Matrix[4][4]= {{2,3,1,1},
    {1,2,3,1},
    {1,1,2,3},
    {3,1,1,2}
};

bitset<8> s_box[16][16] =
{
    {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76},
    {0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0},
    {0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15},
    {0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75},
    {0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84},
    {0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF},
    {0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8},
    {0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2},
    {0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73},
    {0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB},
    {0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79},
    {0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08},
    {0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A},
    {0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E},
    {0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF},
    {0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16}
};







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



string bitSetToHexaDecimal(bitset<8> bitSetData)
{
    string stringData=bitSetData.to_string();
    //cout << s;
    string tensNumber=stringData.substr(0, 4);
    string onesNumber=stringData.substr(4, 4);
    return (binaryToHexaDecimal(tensNumber)+binaryToHexaDecimal(onesNumber));
}


string messageToHexaDecimal(bitset<32> stringA)
{
    string hexaDecimalData;
    for(int i=0;i<32;i=i+8)
    {
        bitset<8> unitBitSet;
        for(int j=i;j<i+8;j++)
        {
            if(stringA.test(j))
            {
                unitBitSet.set(j%8);
            }
        }
        hexaDecimalData=hexaDecimalData+bitSetToHexaDecimal(unitBitSet);
    }
    return hexaDecimalData;
}



int hexaDecimalToInteger(char charectar)
{
    if(charectar>='0' && charectar<='9')
    {
        return (int)(charectar-'0');
    }

    else
    {
        return (10+(int)(charectar-'A'));
    }
}


bitset<32> getSBoxValue(bitset<32> stringA)
{
    string hexaDecimalData=messageToHexaDecimal(stringA);
    bitset<32> getValueFromSBox;
    int positionValue=0;
    for(int i=0;i<hexaDecimalData.length();i=i+2)
    {
        int x, y;
        x=hexaDecimalToInteger(hexaDecimalData[i]);
        y=hexaDecimalToInteger(hexaDecimalData[i+1]);
        bitset<8> unitValueFromSBox=s_box[x][y];

        for(int j=0;j<8;j++)
        {
            if(unitValueFromSBox.test(j))
            {
                getValueFromSBox.set(positionValue);
            }
            positionValue++;
        }
    }
    return getValueFromSBox;
}


bitset<32> bitSetToWord(bitset<8> bitSet1, bitset<8> bitSet2, bitset<8> bitSet3, bitset<8> bitSet4)
{
    bitset<32> stringData;
    bitset<8> unitStringData;
    for(int i=0;i<32;i++)
    {
        if(i>=0 && i<=7)
        {
            unitStringData=bitSet1;
        }

        else if(i>=8 && i<=15)
        {
            unitStringData=bitSet2;
        }

        else if(i>=16 && i<=23)
        {
            unitStringData=bitSet3;
        }

        else
        {
            unitStringData=bitSet4;
        }
        if(unitStringData.test(i%8))
        {
            stringData.set(i);
        }
    }
    return stringData;
}


bitset<8> wordTobitSet(bitset<32> s, int l)
{
    bitset<8> unitColumnValue;
    for(int i=l*8;i<8*l+8;i++)
    {
        if(s.test(i))
        {
            unitColumnValue.set(i%8);
        }
    }
    //cout << bitset<8>ToHex(unitColumnValue) << " " << l << " " << wordToHex(s) << endl;
    return unitColumnValue;
}
void addRoundKey(int roundNumber)
{
    for(int i=0;i<4;i++)
    {
        stateMatrix[i]=stateMatrix[i]^wordInAES[4*roundNumber+i];
    }
}



bitset<8> multiplybitSets(bitset<8> a, bitset<8> b)
{
    if(a==1)
    {
        return b;
    }

    else if(a==2)
    {
        int flag=0;
        if(b.test(7))
        {
            flag=1;
        }

        b<<=1;
        if(flag)
        {
            for(int i=0;i<=4;i++)
            {
                if(b.test(i))
                {
                    b[i]=0;
                }

                else
                {
                    b[i]=1;
                }
                if(i==1)
                {
                    i++;
                }
            }
        }
        return b;
    }

    else
    {
        bitset<8> ans=multiplybitSets(2, b);
        //cout << ans << endl;
        return (ans^b);
    }
}

void mixColumn(int roundNumber)
{
    bitset<8> unitColumnValue[4][4];

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                unitColumnValue[i][j]^=multiplybitSets(AES_Matrix[i][k],
                                        wordTobitSet(stateMatrix[j], k));
                //cout << bitset<8>ToHex(multiplybitset<8>s(predefinedMatrix[i][k],
                            //wordTobitset<8>(AES_Matrix[j], k))) << endl;
//cout << bitset<8>ToHex(predefinedMatrix[i][k]) << " "
 //<< bitset<8>ToHex(wordTobitset<8>(AES_Matrix[j], k)) << endl;
            }
            //cout << bitset<8>ToHex(unitColumnValue[i][j]) << " ";
        }
        //cout << "\n";
    }

    for(int i=0;i<4;i++)
    {
        stateMatrix[i]=bitSetToWord(unitColumnValue[0][i], unitColumnValue[1][i], unitColumnValue[2][i], unitColumnValue[3][i]);
    }
}

bitset<32> leftShift(bitset<32> s, int steps)
{
    steps=steps%4;
    bitset<32> unitColumnValue;

    for(int i=0;i<steps*8;i++)
    {
        if(s.test(i))
        {
            unitColumnValue.set(i);
        }
    }
    s>>=8*steps;

    for(int i=0;i<steps*8;i++)
    {
        if(unitColumnValue.test(i))
        {
            s.set(i+(32-steps*8));
        }
    }
    return s;
}





void substitutionbitSets(int roundNumber)
{
    for(int i=0;i<4;i++)
    {
        stateMatrix[i]=getSBoxValue(stateMatrix[i]);
    }
}

void shiftRow(int roundNumber)
{
    bitset<32> r[4];

    for(int i=0;i<4;i++)
    {
        r[i]=bitSetToWord(wordTobitSet(stateMatrix[0], i), wordTobitSet(stateMatrix[1], i),
                        wordTobitSet(stateMatrix[2], i), wordTobitSet(stateMatrix[3], i));
        //cout << wordToHex(r[i]) << endl;
    }

    for(int i=0;i<4;i++)
    {
        r[i]=leftShift(r[i], i);
    }

    for(int i=0;i<4;i++)
    {
        stateMatrix[i]=bitSetToWord(wordTobitSet(r[0], i), wordTobitSet(r[1], i),
                        wordTobitSet(r[2], i), wordTobitSet(r[3], i));
    }
}

void printAES_Matrix()
{
    for(int i=0;i<4;i++)
    {
        cout << messageToHexaDecimal(stateMatrix[i]) << endl;
    }
}

void printKey()
{
    for(int i=0;i<44;i++)
    {
        cout << "w[" << i << "] :" << messageToHexaDecimal(wordInAES[i]) << endl;
    }
}




void formSubkeys()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<32;j++)
        {
            int k=j%8;
            int p=j/8;

            if(secretKeyInBitSet[i][p].test(k))
            {
                //cout << i << " " << p << " " << k << endl;
                wordInAES[i].set(j);
            }
        }
        //cout << w[i] << endl;
    }
}

//--------------------------------------------------------------------------------------------------------

void calculateStateMatrix()
{
    for(int i=0;i<4;i++)
    {
        stateMatrix[i]=bitSetToWord(secretMessageInBitSet[i][0], secretMessageInBitSet[i][1],
                        secretMessageInBitSet[i][2], secretMessageInBitSet[i][3]);
    }
}


void calculateAES_Matrix()
{
    for(int i=0;i<4;i++)
    {
        stateMatrix[i]=bitSetToWord(secretMessageInBitSet[i][0], secretMessageInBitSet[i][1],
                        secretMessageInBitSet[i][2], secretMessageInBitSet[i][3]);
    }
}


void calculateRoundKey()
{

    for(int i=4;i<44;i=i+4) {
            cout<<i<<endl;
    bitset<8> qoobeeShiftedRow;
    bitset<32> shiftedRows;
    shiftedRows=wordInAES[i-1];
    for( int i=0;i<8;i++)
    {
        if(shiftedRows.test(i))
        {
            qoobeeShiftedRow.set(i);
        }
    }
    cout<<"Wrong Decision 4.a"<<endl;

    shiftedRows>>=8;

    for(int i=0;i<8;i++)
    {
        if(qoobeeShiftedRow.test(i))
        {
            shiftedRows.set(i+24);
        }
    }

        cout<<"Wrong Decision 4.b"<<endl;

    bitset<32> theSBoxNumber=getSBoxValue(shiftedRows);
    bitset<32> convertTheValue=((int)pow(2, i/4 -1)%229);
    theSBoxNumber^=convertTheValue;
    wordInAES[i]=wordInAES[i-4]^theSBoxNumber;
    wordInAES[i+1]=wordInAES[i]^wordInAES[i-3];
    wordInAES[i+2]=wordInAES[i+1]^wordInAES[i-2];
    wordInAES[i+3]=wordInAES[i+2]^wordInAES[i-1];

    }
}
void calculateSubKeys()
{

    int i,j,k,p;

    for(i=0; i<4; i++)
    {
        for(j=0; j<32; j++)
        {
            k=j%8;
            p=j/8;

            if(secretKeyInBitSet[i][p].test(k))
            {
                wordInAES[i].set(j);
            }
        }
    }
}

void printStateMatrix()
{
    for(int i=0;i<4;i++)
    {
        cout << messageToHexaDecimal(stateMatrix[i]) << endl;
    }
}

void messageToHexaDecimal(string stringData, int k)
{

    int matrix_size=4;

    int i,j;

    for(i=0; i<matrix_size; i++)
    {
        for(j=0; j<matrix_size; j++)
        {

            if(k==0)
            {
                secretMessageInBitSet[i][j] = (int)secretMessage[i*4+j];
            }
            else
            {
                secretKeyInBitSet[i][j] = (int)secretKey[i*4+j];

            }

        }
    }

}

void advanceDataEncryptionMethods()
{


    messageToHexaDecimal(secretMessage,0);
    cout<<"Wrong Decision 1"<<endl;
    messageToHexaDecimal(secretKey,1);
        cout<<"Wrong Decision 2"<<endl;

    calculateSubKeys();
        cout<<"Wrong Decision 3"<<endl;


calculateRoundKey();
    cout<<"Wrong Decision 4"<<endl;

calculateStateMatrix();
    cout<<"Wrong Decision 5"<<endl;

addRoundKey(0);
    cout<<"Wrong Decision 6"<<endl;




}

int main()
{



    secretMessage="Thats my Kung Fu", secretKey="Two One Nine Two";


    advanceDataEncryptionMethods();

int i;
for( i=1;i<=10;i++)
    {
    substitutionbitSets(1);
    //printStateMatrix();
    shiftRow(i);
    //printStateMatrix();
    if(i!=10)
    mixColumn(i);
    addRoundKey(i);
    cout << "After Round " << i << ": " << endl;
    printStateMatrix();
    cout << "\n\n";
    }

    cout << "Cipher text : ";

    for(int i=0;i<4;i++)
    {
        cout << messageToHexaDecimal(stateMatrix[i]) << " " ;
    }

    return 0;
}



