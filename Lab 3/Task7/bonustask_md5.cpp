#include<iostream>
using namespace std;
int main()
{
    string h1 = "ae03a9da1fbedfa8f8e143404c08f2ea";
    string h2 = "43de23f6451cd2568d515415591fef90";
    int differentBits = 0;
    // Assuming h1 and h2 same length cause its from same hash algorithm.
    // every character represented in 8 bits.
    for(int i=0;i<h1.size();i++)
    {
        int h1Ascii = int(h1[i]);
        int h2Ascii = int(h2[i]);
        // xor the two ascii values to find the different bits. and differentBits++ for each 1.
        int xorResult = h1Ascii^h2Ascii;
        while(xorResult>0)
        {
            if(xorResult%2==1)
            {
                differentBits++;
            }
            xorResult/=2;
        }
    }
    cout<<"Number of different bits: "<<differentBits<<endl;
    int sameBits = h1.size()*8-differentBits;
    cout<<"Number of same bits: "<<sameBits<<endl;

}



 //result
// Number of different bits: 90
// Number of same bits: 166