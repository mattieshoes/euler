// Each character on a computer is assigned a unique code and the preferred standard is ASCII 
// (American Standard Code for Information Interchange). For example, uppercase A = 65, 
// asterisk (*) = 42, and lowercase k = 107.
// 
// A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR 
// each byte with a given value, taken from a secret key. The advantage with the XOR function 
// is that using the same encryption key on the cipher text, restores the plain text; for 
// example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
// 
// For unbreakable encryption, the key is the same length as the plain text message, and the
// key is made up of random bytes. The user would keep the encrypted message and the encryption 
// key in different locations, and without both "halves", it is impossible to decrypt the message.
// 
// Unfortunately, this method is impractical for most users, so the modified method is to use 
// a password as a key. If the password is shorter than the message, which is likely, the key 
// is repeated cyclically throughout the message. The balance for this method is using a 
// sufficiently long password key for security, but short enough to be memorable.
// 
// Your task has been made easy, as the encryption key consists of three lower case characters. 
// Using cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted 
// ASCII codes, and the knowledge that the plain text must contain common English words, decrypt 
// the message and find the sum of the ASCII values in the original text.



#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main () {
    using namespace std::chrono;
    system_clock::time_point start = system_clock::now();

    vector<char> message = {(char)79,(char)59,(char)12,(char)2,(char)79,(char)35,(char)8,(char)28,(char)20,(char)2,(char)3,(char)68,(char)8,(char)9,(char)68,(char)45,(char)0,(char)12,(char)9,(char)67,(char)68,(char)4,(char)7,(char)5,(char)23,(char)27,(char)1,(char)21,(char)79,(char)85,(char)78,(char)79,(char)85,(char)71,(char)38,(char)10,(char)71,(char)27,(char)12,(char)2,(char)79,(char)6,(char)2,(char)8,(char)13,(char)9,(char)1,(char)13,(char)9,(char)8,(char)68,(char)19,(char)7,(char)1,(char)71,(char)56,(char)11,(char)21,(char)11,(char)68,(char)6,(char)3,(char)22,(char)2,(char)14,(char)0,(char)30,(char)79,(char)1,(char)31,(char)6,(char)23,(char)19,(char)10,(char)0,(char)73,(char)79,(char)44,(char)2,(char)79,(char)19,(char)6,(char)28,(char)68,(char)16,(char)6,(char)16,(char)15,(char)79,(char)35,(char)8,(char)11,(char)72,(char)71,(char)14,(char)10,(char)3,(char)79,(char)12,(char)2,(char)79,(char)19,(char)6,(char)28,(char)68,(char)32,(char)0,(char)0,(char)73,(char)79,(char)86,(char)71,(char)39,(char)1,(char)71,(char)24,(char)5,(char)20,(char)79,(char)13,(char)9,(char)79,(char)16,(char)15,(char)10,(char)68,(char)5,(char)10,(char)3,(char)14,(char)1,(char)10,(char)14,(char)1,(char)3,(char)71,(char)24,(char)13,(char)19,(char)7,(char)68,(char)32,(char)0,(char)0,(char)73,(char)79,(char)87,(char)71,(char)39,(char)1,(char)71,(char)12,(char)22,(char)2,(char)14,(char)16,(char)2,(char)11,(char)68,(char)2,(char)25,(char)1,(char)21,(char)22,(char)16,(char)15,(char)6,(char)10,(char)0,(char)79,(char)16,(char)15,(char)10,(char)22,(char)2,(char)79,(char)13,(char)20,(char)65,(char)68,(char)41,(char)0,(char)16,(char)15,(char)6,(char)10,(char)0,(char)79,(char)1,(char)31,(char)6,(char)23,(char)19,(char)28,(char)68,(char)19,(char)7,(char)5,(char)19,(char)79,(char)12,(char)2,(char)79,(char)0,(char)14,(char)11,(char)10,(char)64,(char)27,(char)68,(char)10,(char)14,(char)15,(char)2,(char)65,(char)68,(char)83,(char)79,(char)40,(char)14,(char)9,(char)1,(char)71,(char)6,(char)16,(char)20,(char)10,(char)8,(char)1,(char)79,(char)19,(char)6,(char)28,(char)68,(char)14,(char)1,(char)68,(char)15,(char)6,(char)9,(char)75,(char)79,(char)5,(char)9,(char)11,(char)68,(char)19,(char)7,(char)13,(char)20,(char)79,(char)8,(char)14,(char)9,(char)1,(char)71,(char)8,(char)13,(char)17,(char)10,(char)23,(char)71,(char)3,(char)13,(char)0,(char)7,(char)16,(char)71,(char)27,(char)11,(char)71,(char)10,(char)18,(char)2,(char)29,(char)29,(char)8,(char)1,(char)1,(char)73,(char)79,(char)81,(char)71,(char)59,(char)12,(char)2,(char)79,(char)8,(char)14,(char)8,(char)12,(char)19,(char)79,(char)23,(char)15,(char)6,(char)10,(char)2,(char)28,(char)68,(char)19,(char)7,(char)22,(char)8,(char)26,(char)3,(char)15,(char)79,(char)16,(char)15,(char)10,(char)68,(char)3,(char)14,(char)22,(char)12,(char)1,(char)1,(char)20,(char)28,(char)72,(char)71,(char)14,(char)10,(char)3,(char)79,(char)16,(char)15,(char)10,(char)68,(char)3,(char)14,(char)22,(char)12,(char)1,(char)1,(char)20,(char)28,(char)68,(char)4,(char)14,(char)10,(char)71,(char)1,(char)1,(char)17,(char)10,(char)22,(char)71,(char)10,(char)28,(char)19,(char)6,(char)10,(char)0,(char)26,(char)13,(char)20,(char)7,(char)68,(char)14,(char)27,(char)74,(char)71,(char)89,(char)68,(char)32,(char)0,(char)0,(char)71,(char)28,(char)1,(char)9,(char)27,(char)68,(char)45,(char)0,(char)12,(char)9,(char)79,(char)16,(char)15,(char)10,(char)68,(char)37,(char)14,(char)20,(char)19,(char)6,(char)23,(char)19,(char)79,(char)83,(char)71,(char)27,(char)11,(char)71,(char)27,(char)1,(char)11,(char)3,(char)68,(char)2,(char)25,(char)1,(char)21,(char)22,(char)11,(char)9,(char)10,(char)68,(char)6,(char)13,(char)11,(char)18,(char)27,(char)68,(char)19,(char)7,(char)1,(char)71,(char)3,(char)13,(char)0,(char)7,(char)16,(char)71,(char)28,(char)11,(char)71,(char)27,(char)12,(char)6,(char)27,(char)68,(char)2,(char)25,(char)1,(char)21,(char)22,(char)11,(char)9,(char)10,(char)68,(char)10,(char)6,(char)3,(char)15,(char)27,(char)68,(char)5,(char)10,(char)8,(char)14,(char)10,(char)18,(char)2,(char)79,(char)6,(char)2,(char)12,(char)5,(char)18,(char)28,(char)1,(char)71,(char)0,(char)2,(char)71,(char)7,(char)13,(char)20,(char)79,(char)16,(char)2,(char)28,(char)16,(char)14,(char)2,(char)11,(char)9,(char)22,(char)74,(char)71,(char)87,(char)68,(char)45,(char)0,(char)12,(char)9,(char)79,(char)12,(char)14,(char)2,(char)23,(char)2,(char)3,(char)2,(char)71,(char)24,(char)5,(char)20,(char)79,(char)10,(char)8,(char)27,(char)68,(char)19,(char)7,(char)1,(char)71,(char)3,(char)13,(char)0,(char)7,(char)16,(char)92,(char)79,(char)12,(char)2,(char)79,(char)19,(char)6,(char)28,(char)68,(char)8,(char)1,(char)8,(char)30,(char)79,(char)5,(char)71,(char)24,(char)13,(char)19,(char)1,(char)1,(char)20,(char)28,(char)68,(char)19,(char)0,(char)68,(char)19,(char)7,(char)1,(char)71,(char)3,(char)13,(char)0,(char)7,(char)16,(char)73,(char)79,(char)93,(char)71,(char)59,(char)12,(char)2,(char)79,(char)11,(char)9,(char)10,(char)68,(char)16,(char)7,(char)11,(char)71,(char)6,(char)23,(char)71,(char)27,(char)12,(char)2,(char)79,(char)16,(char)21,(char)26,(char)1,(char)71,(char)3,(char)13,(char)0,(char)7,(char)16,(char)75,(char)79,(char)19,(char)15,(char)0,(char)68,(char)0,(char)6,(char)18,(char)2,(char)28,(char)68,(char)11,(char)6,(char)3,(char)15,(char)27,(char)68,(char)19,(char)0,(char)68,(char)2,(char)25,(char)1,(char)21,(char)22,(char)11,(char)9,(char)10,(char)72,(char)71,(char)24,(char)5,(char)20,(char)79,(char)3,(char)8,(char)6,(char)10,(char)0,(char)79,(char)16,(char)8,(char)79,(char)7,(char)8,(char)2,(char)1,(char)71,(char)6,(char)10,(char)19,(char)0,(char)68,(char)19,(char)7,(char)1,(char)71,(char)24,(char)11,(char)21,(char)3,(char)0,(char)73,(char)79,(char)85,(char)87,(char)79,(char)38,(char)18,(char)27,(char)68,(char)6,(char)3,(char)16,(char)15,(char)0,(char)17,(char)0,(char)7,(char)68,(char)19,(char)7,(char)1,(char)71,(char)24,(char)11,(char)21,(char)3,(char)0,(char)71,(char)24,(char)5,(char)20,(char)79,(char)9,(char)6,(char)11,(char)1,(char)71,(char)27,(char)12,(char)21,(char)0,(char)17,(char)0,(char)7,(char)68,(char)15,(char)6,(char)9,(char)75,(char)79,(char)16,(char)15,(char)10,(char)68,(char)16,(char)0,(char)22,(char)11,(char)11,(char)68,(char)3,(char)6,(char)0,(char)9,(char)72,(char)16,(char)71,(char)29,(char)1,(char)4,(char)0,(char)3,(char)9,(char)6,(char)30,(char)2,(char)79,(char)12,(char)14,(char)2,(char)68,(char)16,(char)7,(char)1,(char)9,(char)79,(char)12,(char)2,(char)79,(char)7,(char)6,(char)2,(char)1,(char)73,(char)79,(char)85,(char)86,(char)79,(char)33,(char)17,(char)10,(char)10,(char)71,(char)6,(char)10,(char)71,(char)7,(char)13,(char)20,(char)79,(char)11,(char)16,(char)1,(char)68,(char)11,(char)14,(char)10,(char)3,(char)79,(char)5,(char)9,(char)11,(char)68,(char)6,(char)2,(char)11,(char)9,(char)8,(char)68,(char)15,(char)6,(char)23,(char)71,(char)0,(char)19,(char)9,(char)79,(char)20,(char)2,(char)0,(char)20,(char)11,(char)10,(char)72,(char)71,(char)7,(char)1,(char)71,(char)24,(char)5,(char)20,(char)79,(char)10,(char)8,(char)27,(char)68,(char)6,(char)12,(char)7,(char)2,(char)31,(char)16,(char)2,(char)11,(char)74,(char)71,(char)94,(char)86,(char)71,(char)45,(char)17,(char)19,(char)79,(char)16,(char)8,(char)79,(char)5,(char)11,(char)3,(char)68,(char)16,(char)7,(char)11,(char)71,(char)13,(char)1,(char)11,(char)6,(char)1,(char)17,(char)10,(char)0,(char)71,(char)7,(char)13,(char)10,(char)79,(char)5,(char)9,(char)11,(char)68,(char)6,(char)12,(char)7,(char)2,(char)31,(char)16,(char)2,(char)11,(char)68,(char)15,(char)6,(char)9,(char)75,(char)79,(char)12,(char)2,(char)79,(char)3,(char)6,(char)25,(char)1,(char)71,(char)27,(char)12,(char)2,(char)79,(char)22,(char)14,(char)8,(char)12,(char)19,(char)79,(char)16,(char)8,(char)79,(char)6,(char)2,(char)12,(char)11,(char)10,(char)10,(char)68,(char)4,(char)7,(char)13,(char)11,(char)11,(char)22,(char)2,(char)1,(char)68,(char)8,(char)9,(char)68,(char)32,(char)0,(char)0,(char)73,(char)79,(char)85,(char)84,(char)79,(char)48,(char)15,(char)10,(char)29,(char)71,(char)14,(char)22,(char)2,(char)79,(char)22,(char)2,(char)13,(char)11,(char)21,(char)1,(char)69,(char)71,(char)59,(char)12,(char)14,(char)28,(char)68,(char)14,(char)28,(char)68,(char)9,(char)0,(char)16,(char)71,(char)14,(char)68,(char)23,(char)7,(char)29,(char)20,(char)6,(char)7,(char)6,(char)3,(char)68,(char)5,(char)6,(char)22,(char)19,(char)7,(char)68,(char)21,(char)10,(char)23,(char)18,(char)3,(char)16,(char)14,(char)1,(char)3,(char)71,(char)9,(char)22,(char)8,(char)2,(char)68,(char)15,(char)26,(char)9,(char)6,(char)1,(char)68,(char)23,(char)14,(char)23,(char)20,(char)6,(char)11,(char)9,(char)79,(char)11,(char)21,(char)79,(char)20,(char)11,(char)14,(char)10,(char)75,(char)79,(char)16,(char)15,(char)6,(char)23,(char)71,(char)29,(char)1,(char)5,(char)6,(char)22,(char)19,(char)7,(char)68,(char)4,(char)0,(char)9,(char)2,(char)28,(char)68,(char)1,(char)29,(char)11,(char)10,(char)79,(char)35,(char)8,(char)11,(char)74,(char)86,(char)91,(char)68,(char)52,(char)0,(char)68,(char)19,(char)7,(char)1,(char)71,(char)56,(char)11,(char)21,(char)11,(char)68,(char)5,(char)10,(char)7,(char)6,(char)2,(char)1,(char)71,(char)7,(char)17,(char)10,(char)14,(char)10,(char)71,(char)14,(char)10,(char)3,(char)79,(char)8,(char)14,(char)25,(char)1,(char)3,(char)79,(char)12,(char)2,(char)29,(char)1,(char)71,(char)0,(char)10,(char)71,(char)10,(char)5,(char)21,(char)27,(char)12,(char)71,(char)14,(char)9,(char)8,(char)1,(char)3,(char)71,(char)26,(char)23,(char)73,(char)79,(char)44,(char)2,(char)79,(char)19,(char)6,(char)28,(char)68,(char)1,(char)26,(char)8,(char)11,(char)79,(char)11,(char)1,(char)79,(char)17,(char)9,(char)9,(char)5,(char)14,(char)3,(char)13,(char)9,(char)8,(char)68,(char)11,(char)0,(char)18,(char)2,(char)79,(char)5,(char)9,(char)11,(char)68,(char)1,(char)14,(char)13,(char)19,(char)7,(char)2,(char)18,(char)3,(char)10,(char)2,(char)28,(char)23,(char)73,(char)79,(char)37,(char)9,(char)11,(char)68,(char)16,(char)10,(char)68,(char)15,(char)14,(char)18,(char)2,(char)79,(char)23,(char)2,(char)10,(char)10,(char)71,(char)7,(char)13,(char)20,(char)79,(char)3,(char)11,(char)0,(char)22,(char)30,(char)67,(char)68,(char)19,(char)7,(char)1,(char)71,(char)8,(char)8,(char)8,(char)29,(char)29,(char)71,(char)0,(char)2,(char)71,(char)27,(char)12,(char)2,(char)79,(char)11,(char)9,(char)3,(char)29,(char)71,(char)60,(char)11,(char)9,(char)79,(char)11,(char)1,(char)79,(char)16,(char)15,(char)10,(char)68,(char)33,(char)14,(char)16,(char)15,(char)10,(char)22,(char)73};


    char key[3];
    char letter;
    bool fail;
    int sum;
    for(key[0] = 'a'; key[0] <= 'z'; key[0] += 1) {
        for(key[1] = 'a'; key[1] <= 'z'; key[1] += 1) {
            for(key[2] = 'a'; key[2] <= 'z'; key[2] += 1) {
                fail = false;
                sum = 0;
                for(unsigned int ii=0; ii<message.size(); ii++) {
                    letter = message[ii] ^ key[ii%3];
                    if(letter < ' '  || letter > 'z' || letter == '`') {
                        fail = true;
                        break;
                    }
                    sum += (int)letter;
                }
                if(!fail) {
                    cout << "Sum: " << sum << endl;
                    system_clock::time_point stop = system_clock::now();
                    duration<double> elapsed = duration_cast<duration<double>>(stop - start);
                    cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;
                    cout << "PW: " << key[0] << key[1] << key[2] << endl;
                    for(unsigned int i=0;i<message.size();i++)
                        cout << (char)(message[i] ^ key[i%3]);
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << "nothing found\n";
    return 0;
}
