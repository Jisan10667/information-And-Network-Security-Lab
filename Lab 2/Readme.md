# Lab 2: Attacking Classic Crypto Systems</p>

## Lab task 2 (Checkpoint 1)

### Question

The following cipher has been created using the Caesar cipher. Write a program to decipher it.

```bash
Cipher: odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo
```

Write a program to break it and display the result. Show it your teacher.

### Solution approach

- No key is given. So I need to show all the possible cases.
- Possible range of keys 0-25 (mod values of 26)

### Solution

```cpp
#include<iostream>


using namespace std;

// Function to shift characters in a string to the left by the specified key
string shiftLeft(string text, int shiftKey) {
    for(int index = 0; index < text.length(); index++) {
        // Adjust each character in the string by shifting to the left
        text[index] = (text[index] - 'a' - shiftKey + 26) % 26 + 'a';
    }
    return text;
}

// Function to shift characters in a string to the right by the specified key
string shiftRight(string text, int shiftKey) {
    for(int index = 0; index < text.length(); index++) {
        // Adjust each character in the string by shifting to the right
        text[index] = (text[index] - 'a' + shiftKey) % 26 + 'a';
    }
    return text;
}


int main() {
    string encodedText;
    encodedText = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";

    // Displaying decoded texts for each possible key from 1 to 25
    for(int key = 1; key < 26; key++) {
        cout << "Using Key = " << key << ": Decoded Text - " << shiftLeft(encodedText, key) << endl;
    }

    // Using a specific key to decode and then encode to demonstrate the process
    int correctKey = 10;
    string decodedText = shiftLeft(encodedText, correctKey);
    cout << "Correctly Decoded Text: " << decodedText << endl;
    cout << "Re-encoded Text: " << shiftRight(decodedText, correctKey) << endl;
    return 0;
}

```

### Output

<hr>

Using Key = 1:<br> Decoded Text - ncqnandvrbcqnknbcbvjaclxwcajlcyujcoxavxdccqnan<br>
Using Key = 2:<br> Decoded Text - mbpmzmcuqabpmjmabauizbkwvbzikbxtibnwzuwcbbpmzm<br>
Using Key = 3: <br>Decoded Text - laolylbtpzaolilzazthyajvuayhjawshamvytvbaaolyl<br>
Using Key = 4:<br> Decoded Text - kznkxkasoyznkhkyzysgxziutzxgizvrgzluxsuazznkxk<br>
Using Key = 5:<br> Decoded Text - jymjwjzrnxymjgjxyxrfwyhtsywfhyuqfyktwrtzyymjwj<br>
Using Key = 6:<br> Decoded Text - ixliviyqmwxlifiwxwqevxgsrxvegxtpexjsvqsyxxlivi<br>
Using Key = 7:<br> Decoded Text - hwkhuhxplvwkhehvwvpduwfrqwudfwsodwiruprxwwkhuh<br>
Using Key = 8: <br>Decoded Text - gvjgtgwokuvjgdguvuoctveqpvtcevrncvhqtoqwvvjgtg<br>
Using Key = 9:<br> Decoded Text - fuifsfvnjtuifcftutnbsudpousbduqmbugpsnpvuuifsf<br>
Using Key = 10: <br>Decoded Text - ethereumisthebestsmartcontractplatformoutthere<br>
Using Key = 11: <br>Decoded Text - dsgdqdtlhrsgdadrsrlzqsbnmsqzbsokzsenqlntssgdqd<br>
Using Key = 12:<br> Decoded Text - crfcpcskgqrfczcqrqkypramlrpyarnjyrdmpkmsrrfcpc<br>
Using Key = 13:<br> Decoded Text - bqebobrjfpqebybpqpjxoqzlkqoxzqmixqclojlrqqebob<br>
Using Key = 14:<br> Decoded Text - apdanaqieopdaxaopoiwnpykjpnwyplhwpbknikqppdana<br>
Using Key = 15:<br> Decoded Text - zoczmzphdnoczwznonhvmoxjiomvxokgvoajmhjpooczmzv
Using Key = 16:<br> Decoded Text - ynbylyogcmnbyvymnmgulnwihnluwnjfunzilgionnbyly<br>
Using Key = 17:<br> Decoded Text - xmaxkxnfblmaxuxlmlftkmvhgmktvmietmyhkfhnmmaxkx<br>
Using Key = 18:<br> Decoded Text - wlzwjwmeaklzwtwklkesjlugfljsulhdslxgjegmllzwjw<br>
Using Key = 19:<br> Decoded Text - vkyvivldzjkyvsvjkjdriktfekirtkgcrkwfidflkkyviv<br>
Using Key = 20: <br>Decoded Text - ujxuhukcyijxuruijicqhjsedjhqsjfbqjvehcekjjxuhu<br>
Using Key = 21:<br> Decoded Text - tiwtgtjbxhiwtqthihbpgirdcigprieapiudgbdjiiwtgt<br>
Using Key = 22: <br>Decoded Text - shvsfsiawghvspsghgaofhqcbhfoqhdzohtcfacihhvsfs<br>
Using Key = 23:<br> Decoded Text - rgurerhzvfgurorfgfznegpbagenpgcyngsbezbhggurer<br>
Using Key = 24: <br>Decoded Text - qftqdqgyueftqnqefeymdfoazfdmofbxmfradyagfftqdq<br>
Using Key = 25:<br> Decoded Text - pespcpfxtdespmpdedxlcenzyeclneawleqzcxzfeespcp<br><br>
Correctly Decoded Text: ethereumisthebestsmartcontractplatformoutthere
Re-encoded Text: odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo

<hr>

## Lab task 2 (Checkpoint 2)

### Question

The following two ciphers have been created using a substitution cipher with different keys.
Write a program to decipher each of them. Which input was easier to break? Explain your answer.
For your convenience, a frequency distribution of English characters is given in the next page.

```text
Cipher-1: af p xpkcaqvnpk pfg, af ipqe qpri, gauuikifc tpw, ceiri udvk tiki afgarxifrphni cd eaowvmd popkwn, hiqpvri du ear jvaql vfgikrcpfgafm du cei xkafqaxnir du xrwqedearcdkw pfg du ear aopmafpcasi xkdhafmr afcd fit pkipr. ac tpr qdoudkcafm cd lfdt cepc au pfwceafm epxxifig cd ringdf eaorinu hiudki cei opceiopcaqr du cei uaing qdvng hi qdoxnicinw tdklig dvcpfg edt rndtnw ac xkdqiigig, pfg edt odvfcpafdvr cei dhrcpqnir--ceiki tdvng pc niprc kiopaf dfi mddg oafg cepc tdvng qdfcafvi cei kiripkqe
```

```text
Cipher-2: aceah toz puvg vcdl omj puvg yudqecov, omj loj auum klu thmjuv hs klu zlcvu shv zcbkg guovz, upuv zcmdu lcz vuwovroaeu jczoyyuovomdu omj qmubyudkuj vukqvm. klu vcdluz lu loj avhqnlk aodr svhw lcz kvopuez loj mht audhwu o ehdoe eunumj, omj ck toz yhyqeoveg auecupuj, tlokupuv klu hej sher wcnlk zog, klok klu lcee ok aon umj toz sqee hs kqmmuez zkqssuj tckl kvuozqvu. omj cs klok toz mhk umhqnl shv sowu, kluvu toz oezh lcz yvhehmnuj pcnhqv kh wovpue ok. kcwu thvu hm, aqk ck zuuwuj kh lopu eckkeu ussudk hm wv. aonncmz. ok mcmukg lu toz wqdl klu zowu oz ok scskg. ok mcmukg-mcmu klug aunom kh doee lcw tuee-yvuzuvpuj; aqk qmdlomnuj thqej lopu auum muovuv klu wovr. kluvu tuvu zhwu klok zlhhr klucv luojz omj klhqnlk klcz toz khh wqdl hs o nhhj klcmn; ck zuuwuj qmsocv klok omghmu zlhqej yhzzuzz (oyyovumkeg) yuvyukqoe ghqkl oz tuee oz (vuyqkujeg) cmubloqzkcaeu tuoekl. ck tcee lopu kh au yocj shv, klug zocj. ck czm'k mokqvoe, omj kvhqaeu tcee dhwu hs ck! aqk zh sov kvhqaeu loj mhk dhwu; omj oz wv. aonncmz toz numuvhqz tckl lcz whmug, whzk yuhyeu tuvu tceecmn kh shvncpu lcw lcz hjjckcuz omj lcz nhhj shvkqmu. lu vuwocmuj hm pczckcmn kuvwz tckl lcz vueokcpuz (ubduyk, hs dhqvzu, klu zodrpceeu-aonncmzuz), omj lu loj womg juphkuj ojwcvuvz owhmn klu lhaackz hs yhhv omj qmcwyhvkomk sowcecuz. aqk lu loj mh dehzu svcumjz, qmkce zhwu hs lcz ghqmnuv dhqzcmz aunom kh nvht qy. klu uejuzk hs kluzu, omj aceah'z sophqvcku, toz ghqmn svhjh aonncmz. tlum aceah toz mcmukg-mcmu lu ojhykuj svhjh oz lcz lucv, omj avhqnlk lcw kh ecpu ok aon umj; omj klu lhyuz hs klu zodrpceeu- aonncmzuz tuvu scmoeeg jozluj. aceah omj svhjh loyyumuj kh lopu klu zowu acvkljog, zuykuwauv 22mj. ghq loj aukkuv dhwu omj ecpu luvu, svhjh wg eoj, zocj aceah hmu jog; omj klum tu dom dueuavoku hqv acvkljog-dhwshvkoae yovkcuz g khnukluv. ok klok kcwu svhjh toz zkcee cm lcz ktuumz, oz klu lhaackz doeeuj klu cvvuzyhmzcaeu ktumkcuz auktuum dlcejlhhj omj dhwcmn hs onu ok klcvkg-klvuu
```

```text
Frequency distribution English characters
a: 8.05% b: 1.67% c: 2.23% d: 5.10%
e: 12.22% f: 2.14% g: 2.30% h: 6.62%
i: 6.28% j: 0.19% k: 0.95% l: 4.08%
m: 2.33% n: 6.95% o: 7.63% p: 1.66%
q: 0.06% r: 5.29% s: 6.02% t: 9.67%
u: 2.92% v: 0.82% w: 2.60% x: 0.11%
y: 2.04% z: 0.06%
```

### Solution Approach

**Using Frequency Approach**

- stored the given frequency in an unordered_map.
- calculated the frequency of given cipher text using unordered_map.
- inserted both of the maps into vector.
- sorted the vectors according to the frequency value.
- mapped both of the frequencies.
- iterated through the cipher text and decrypted.

**Using Key Approach**

- The possibility of the keys is 403x10^24 (factorial of 26). As it is a huge number I have got the key using an online decrypt website.
- Then mapped the alphabet and key.

### Solution(Cipher1)

```cpp
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

bool cmp(pair<char,double>x,pair<char,double>y)
{
    return x.second>=y.second;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<string>cipherArray;
    string cipher;
    map<char,int>freq;

    vector<int>v;

    int count = 0;
    // Input from File
    while(getline(cin,cipher))
    {
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                count++;
                freq[tolower(cipher[i])]++;
            }

        }
        cipherArray.push_back(cipher);
    }

    vector<pair<char,double>>cipherFreq,plainFreq;
   cout<<"--------- cipher letter Frequency ----------"<<endl;
    for(auto it : freq)
    {
        cout<<it.first<<"  "<<double((it.second*100.00)/count)<<setprecision(2)<<fixed<<" %"<<endl;
        cipherFreq.push_back({it.first,double((it.second*100.00)/count)});
    }
    map<char, double> freqDist = {
        {'a', 8.05},
        {'b', 1.67},
        {'c', 2.23},
        {'d', 5.1},
        {'e', 12.22},
        {'f', 2.14},
        {'g', 2.3},
        {'h', 6.62},
        {'i', 6.28},
        {'j', 0.19},
        {'k', 0.95},
        {'l', 4.08},
        {'m', 2.33},
        {'n', 6.95},
        {'o', 7.63},
        {'p', 1.66},
        {'q', 0.06},
        {'r', 5.29},
        {'s', 6.02},
        {'t', 9.67},
        {'u', 2.92},
        {'v', 0.82},
        {'w', 2.6},
        {'x', 0.11},
        {'y', 2.04},
        {'z', 0.06}
    };
    cout<<"--------- plain letter Frequency ----------"<<endl;
    for(auto it : freqDist)
    {
        cout<<" Plain letter Frequency --  "<<endl ;
        cout<<it.first<<"  "<<it.second<<setprecision(2)<<fixed<<" %"<<endl;
        plainFreq.push_back({it.first,it.second});
    }
    sort(plainFreq.begin(),plainFreq.end(),cmp);
    sort(cipherFreq.begin(),cipherFreq.end(),cmp);
    cout<<"--------- frequency compare ----------"<<endl;
    for(int i = 0; i < 26; i++)
    {

       //cout<< cipherFreq[i].first<<" ->  "<<plainFreq[i].first<<endl;

    }
//  Fir second cipher
map<char, char> sub = {
    {'a', 'I'},
    {'b', 'u'},
    {'c','T'} ,
    {'d','O'} ,
    {'e','H'} ,
    {'f', 'N'},
    {'g', 'D'},
    {'h', 'B'},
    {'i', 'E'},
    {'j', 'Q'},
    {'k', 'R'},
    {'l', 'K'},
    {'m', 'G'},
    {'n', 'L'},
    {'o', 'M'},
    {'p', 'A'},
    {'q', 'C'},
    {'r', 'S'},
    {'s', 'E'},
    {'t', 'W'},
    {'u', 'F'},
    {'v', 'U'},
    {'w', 'Y'},
    {'x', 'P'},
    {'y', 'd'},
    {'z', 'b'}
};

    for(int i = 0; i < 26; i++)
    {
        char c = char('a'+i);
        if(sub.find(c)!=sub.end())
            {
                cout<<"mapped - "<<char('a'+i)<<" -> "<<sub[char('a'+i)]<<endl;
            }
    }
      cout<<"--------- Decoding ----------"<<endl;
    for(int k = 0 ; k < cipherArray.size() ; k++)
    {
        cipher = cipherArray[k];
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if (sub.find(tolower(c))!=sub.end())
            {

                cipher[i] = (sub[tolower(c)]);
            }

        }
        cout<<cipher<<endl;
    }

}
```

### Output

```text
--------- cipher letter Frequency ----------
a  7.63547 %
c  8.13 %
d  8.87 %
e  5.42 %
f  7.39 %
g  4.68 %
h  1.48 %
i  11.33 %
j  0.25 %
k  4.68 %
l  0.74 %
m  1.72 %
n  3.94 %
o  2.71 %
p  7.88 %
q  3.69 %
r  5.67 %
s  0.25 %
t  2.71 %
u  3.20 %
v  3.20 %
w  1.97 %
x  2.46 %
--------- plain letter Frequency ----------
 Plain letter Frequency --
a  8.05 %
 Plain letter Frequency --
b  1.67 %
 Plain letter Frequency --
c  2.23 %
 Plain letter Frequency --
d  5.10 %
 Plain letter Frequency --
e  12.22 %
 Plain letter Frequency --
f  2.14 %
 Plain letter Frequency --
g  2.30 %
 Plain letter Frequency --
h  6.62 %
 Plain letter Frequency --
i  6.28 %
 Plain letter Frequency --
j  0.19 %
 Plain letter Frequency --
k  0.95 %
 Plain letter Frequency --
l  4.08 %
 Plain letter Frequency --
m  2.33 %
 Plain letter Frequency --
n  6.95 %
 Plain letter Frequency --
o  7.63 %
 Plain letter Frequency --
p  1.66 %
 Plain letter Frequency --
q  0.06 %
 Plain letter Frequency --
r  5.29 %
 Plain letter Frequency --
s  6.02 %
 Plain letter Frequency --
t  9.67 %
 Plain letter Frequency --
u  2.92 %
 Plain letter Frequency --
v  0.82 %
 Plain letter Frequency --
w  2.60 %
 Plain letter Frequency --
x  0.11 %
 Plain letter Frequency --
y  2.04 %
 Plain letter Frequency --
z  0.06 %
--------- frequency compare ----------
mapped - a -> I
mapped - b -> u
mapped - c -> T
mapped - d -> O
mapped - e -> H
mapped - f -> N
mapped - g -> D
mapped - h -> B
mapped - i -> E
mapped - j -> Q
mapped - k -> R
mapped - l -> K
mapped - m -> G
mapped - n -> L
mapped - o -> M
mapped - p -> A
mapped - q -> C
mapped - r -> S
mapped - s -> E
mapped - t -> W
mapped - u -> F
mapped - v -> U
mapped - w -> Y
mapped - x -> P
mapped - y -> d
mapped - z -> b
--------- Decoding ----------
IN A PARTICULAR AND, IN EACH CASE, DIFFERENT WAY, THESE FOUR WERE INDISPENSABLE TO HIM-
-YUGO AMARYL, BECAUSE OF HIS QUICK UNDERSTANDING OF THE PRINCIPLES OF PSYCHOHISTORY AND
OF HIS IMAGINATIEE PROBINGS INTO NEW AREAS. IT WAS COMFORTING TO KNOW THAT IF ANYTHING
HAPPENED TO SELDON HIMSELF BEFORE THE MATHEMATICS OF THE FIELD COULD BE COMPLETELY WORKED OUT-
-AND HOW SLOWLY IT PROCEEDED, AND HOW MOUNTAINOUS THE OBSTACLES--THERE WOULD AT LEAST REMAIN ONE
GOOD MIND THAT WOULD CONTINUE THE RESEARCH

```

### Solution(Cipher2)

```cpp

#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;
bool cmp(pair<char,double>x,pair<char,double>y)
{
    return x.second>=y.second;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<string>cipherArray;
    string cipher;
    map<char,int>freq;

    vector<int>v;

    int count = 0;
    // Input from File
    while(getline(cin,cipher))
    {
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                count++;
                freq[tolower(cipher[i])]++;
            }

        }
        cipherArray.push_back(cipher);
    }



    vector<pair<char,double>>cipherFreq,plainFreq;
   cout<<"--------- cipher letter Frequency ----------"<<endl;
    for(auto it : freq)
    {
        cout<<it.first<<"  "<<double((it.second*100.00)/count)<<setprecision(2)<<fixed<<" %"<<endl;
        cipherFreq.push_back({it.first,double((it.second*100.00)/count)});
    }
    map<char, double> freqDist = {
        {'a', 8.05},
        {'b', 1.67},
        {'c', 2.23},
        {'d', 5.1},
        {'e', 12.22},
        {'f', 2.14},
        {'g', 2.3},
        {'h', 6.62},
        {'i', 6.28},
        {'j', 0.19},
        {'k', 0.95},
        {'l', 4.08},
        {'m', 2.33},
        {'n', 6.95},
        {'o', 7.63},
        {'p', 1.66},
        {'q', 0.06},
        {'r', 5.29},
        {'s', 6.02},
        {'t', 9.67},
        {'u', 2.92},
        {'v', 0.82},
        {'w', 2.6},
        {'x', 0.11},
        {'y', 2.04},
        {'z', 0.06}
    };
        cout<<"--------- plain letter Frequency ----------"<<endl;
    for(auto it : freqDist)
    {
         cout<<"Plain letter Frequency ---"<<endl;
        cout<<it.first<<"  "<<it.second<<setprecision(2)<<fixed<<" %"<<endl;
        plainFreq.push_back({it.first,it.second});
    }
    sort(plainFreq.begin(),plainFreq.end(),cmp);
    sort(cipherFreq.begin(),cipherFreq.end(),cmp);
  cout<<"--------- frequency compare ----------"<<endl;
    for(int i = 0; i < 26; i++)
    {

       //cout<< cipherFreq[i].first<<" ->  "<<plainFreq[i].first<<endl;

    }

map<char, char> sub = {
    {'a', 'B'},
    {'b', 'X'},
    {'c','I'} ,
    {'d','C'} ,
    {'e','L'} ,
    {'f', 'N'},
    {'g', 'Y'},
    {'h', 'O'},
    {'i', 'E'},
    {'j', 'D'},
    {'k', 'T'},
    {'l', 'H'},
    {'m', 'N'},
    {'n', 'G'},
    {'o', 'A'},
    {'p', 'V'},
    {'q', 'U'},
    {'r', 'K'},
    {'s', 'F'},
    {'t', 'W'},
    {'u', 'E'},
    {'v', 'R'},
    {'w', 'M'},
    {'x', 'P'},
    {'y', 'P'},
    {'z', 'S'}
};

    for(int i = 0; i < 26; i++)
    {
        char c = char('a'+i);
        if(sub.find(c)!=sub.end())
            {
                cout<<"mapped - "<<char('a'+i)<<" -> "<<sub[char('a'+i)]<<endl;
            }
    }
      cout<<"--------- Decoding ----------"<<endl;
    for(int k = 0 ; k < cipherArray.size() ; k++)
    {
        cipher = cipherArray[k];
        for(int i = 0; i < cipher.size(); i++)
        {
            char c = cipher[i];
            if (sub.find(tolower(c))!=sub.end())
            {

                cipher[i] = (sub[tolower(c)]);
            }

        }
        cout<<cipher<<endl;
    }

}

```

```text
--------- cipher letter Frequency ----------
a  3.03814 %
b  0.26 %
c  6.59 %
d  1.87 %
e  4.59 %
g  1.81 %
h  7.30 %
j  4.78 %
k  8.53 %
l  6.27 %
m  6.14 %
n  2.39 %
o  8.47 %
p  1.42 %
q  2.71 %
r  0.45 %
s  2.46 %
t  2.20 %
u  12.80 %
v  5.49 %
w  2.46 %
y  1.81 %
z  6.14 %
--------- plain letter Frequency ----------
Plain letter Frequency ---
a  8.05 %
Plain letter Frequency ---
b  1.67 %
Plain letter Frequency ---
c  2.23 %
Plain letter Frequency ---
d  5.10 %
Plain letter Frequency ---
e  12.22 %
Plain letter Frequency ---
f  2.14 %
Plain letter Frequency ---
g  2.30 %
Plain letter Frequency ---
h  6.62 %
Plain letter Frequency ---
i  6.28 %
Plain letter Frequency ---
j  0.19 %
Plain letter Frequency ---
k  0.95 %
Plain letter Frequency ---
l  4.08 %
Plain letter Frequency ---
m  2.33 %
Plain letter Frequency ---
n  6.95 %
Plain letter Frequency ---
o  7.63 %
Plain letter Frequency ---
p  1.66 %
Plain letter Frequency ---
q  0.06 %
Plain letter Frequency ---
r  5.29 %
Plain letter Frequency ---
s  6.02 %
Plain letter Frequency ---
t  9.67 %
Plain letter Frequency ---
u  2.92 %
Plain letter Frequency ---
v  0.82 %
Plain letter Frequency ---
w  2.60 %
Plain letter Frequency ---
x  0.11 %
Plain letter Frequency ---
y  2.04 %
Plain letter Frequency ---
z  0.06 %
--------- frequency compare ----------
mapped - a -> B
mapped - b -> X
mapped - c -> I
mapped - d -> C
mapped - e -> L
mapped - f -> N
mapped - g -> Y
mapped - h -> O
mapped - i -> E
mapped - j -> D
mapped - k -> T
mapped - l -> H
mapped - m -> N
mapped - n -> G
mapped - o -> A
mapped - p -> V
mapped - q -> U
mapped - r -> K
mapped - s -> F
mapped - t -> W
mapped - u -> E
mapped - v -> R
mapped - w -> M
mapped - x -> P
mapped - y -> P
mapped - z -> S
--------- Decoding ----------
BILBO WAS VERY RICH AND VERY PECULIAR, AND HAD BEEN THE WONDER OF THE SHIRE FOR
SIXTY YEARS, EVER SINCE HIS REMARKABLE DISAPPEARANCE AND UNEXPECTED RETURN. THE
RICHES HE HAD BROUGHT BACK FROM HIS TRAVELS HAD NOW BECOME A LOCAL LEGEND, AND IT WAS
POPULARLY BELIEVED, WHATEVER THE OLD FOLK MIGHT SAY, THAT THE HILL AT BAG END WAS FULL OF
TUNNELS STUFFED WITH TREASURE. AND IF THAT WAS NOT ENOUGH FOR FAME, THERE WAS ALSO HIS
PROLONGED VIGOUR TO MARVEL AT. TIME WORE ON, BUT IT SEEMED TO HAVE LITTLE EFFECT ON
MR. BAGGINS. AT NINETY HE WAS MUCH THE SAME AS AT FIFTY. AT NINETY-NINE THEY BEGAN TO
CALL HIM WELL-PRESERVED; BUT UNCHANGED WOULD HAVE BEEN NEARER THE MARK. THERE WERE SOME
THAT SHOOK THEIR HEADS AND THOUGHT THIS WAS TOO MUCH OF A GOOD THING; IT SEEMED UNFAIR THAT
ANYONE SHOULD POSSESS (APPARENTLY) PERPETUAL YOUTH AS WELL AS (REPUTEDLY)
INEXHAUSTIBLE WEALTH. IT WILL HAVE TO BE PAID FOR, THEY SAID. IT ISN'T NATURAL, AND TROUBLE
WILL COME OF IT! BUT SO FAR TROUBLE HAD NOT COME; AND AS MR. BAGGINS WAS GENEROUS WITH
HIS MONEY, MOST PEOPLE WERE WILLING TO FORGIVE HIM HIS ODDITIES AND HIS GOOD FORTUNE. HE
REMAINED ON VISITING TERMS WITH HIS RELATIVES (EXCEPT, OF COURSE, THE SACKVILLEBAGGINSES), AND HE HAD MANY DEVOTED ADMIRERS AMONG THE HOBBITS OF POOR AND
UNIMPORTANT FAMILIES. BUT HE HAD NO CLOSE FRIENDS, UNTIL SOME OF HIS YOUNGER COUSINS
BEGAN TO GROW UP. THE ELDEST OF THESE, AND BILBO'S FAVOURITE, WAS YOUNG FRODO BAGGINS.
WHEN BILBO WAS NINETY-NINE HE ADOPTED FRODO AS HIS HEIR, AND BROUGHT HIM TO LIVE AT BAG
END; AND THE HOPES OF THE SACKVILLE- BAGGINSES WERE FINALLY DASHED. BILBO AND FRODO
HAPPENED TO HAVE THE SAME BIRTHDAY, SEPTEMBER 22ND. YOU HAD BETTER COME AND LIVE HERE,
FRODO MY LAD, SAID BILBO ONE DAY; AND THEN WE CAN CELEBRATE OUR BIRTHDAY-PARTIES
COMFORTABLY TOGETHER. AT THAT TIME FRODO WAS STILL IN HIS TWEENS, AS THE HOBBITS CALLED THE
IRRESPONSIBLE TWENTIES BETWEEN CHILDHOOD AND COMING OF AGE AT THIRTY-THREE



```

<hr>
