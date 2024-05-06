

#include<iostream>
using namespace std;
int main()
{
    string h1 = "a650c3f4ec41c556ff153c0a7abce54062e1c380fe38b5912d49144f6c4f338f";
    string h2 = "d995aa1ec2a04c8bc99a251ebbef7f93af7cde7b58e2399c3a65141fb8da13bf";
    int differentBits = 0;
    // Assuming h1 and h2 same lenght cause its from same hash algorithm.
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
// Number of different bits: 166
// Number of same bits: 346