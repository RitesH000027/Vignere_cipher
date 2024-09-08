//BHARGAV BABUBHAI JANI (MT24115)

#include<bits/stdc++.h>

using namespace std;

// function to generate the ciphertext using the vigenere cipher
string vigenereCipher(const string& plaintext, const string& key) {
    string ciphertext = "";
    string upperKey = key;


        //converting key to uppercase
    transform(upperKey.begin(), upperKey.end(), upperKey.begin(), ::toupper);

    int keyLength = upperKey.length();
    int keyIndex = 0;  // it is used to keep track of the position in the key

        // we are going to loop over each character in the plaintext
    for (char pChar : plaintext) {
        // used to skip spaces in the plaintext
        if (pChar == ' ') {
            continue;
        }

                // converting plaintext character to lowercase
        pChar = tolower(pChar);

            // Determine the corresponding character in the key
        char kChar = upperKey[keyIndex % keyLength];
        
            // calculating the cipher character using vigenere formula: Ci = (Pi + Ki) % 26
                // we are converting characters to uppercase alphabet index (A=0,---,Z=25)
        char cChar = ((pChar - 'a') + (kChar - 'A')) % 26 + 'A';

        // appending the cipher character to the ciphertext
        ciphertext += cChar;

        // it is used for moving to the next character in the key
        keyIndex++;
    }
    return ciphertext;
}

int main() {
    string key, plaintext;

                // taking the key and  the plaintext as input from the user
    cout << "Enter the key: ";
    getline(cin, key);


    cout << "Enter the plaintext: ";
    getline(cin, plaintext);


    string ciphertext = vigenereCipher(plaintext, key); // generating   the  cipher text using the vigenere Cipher

    // printing the generated ciphertext
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
