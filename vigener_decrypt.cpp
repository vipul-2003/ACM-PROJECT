#include <iostream>
#include <stdio.h>

using namespace std;

void vigenere_decrypt(string, string); // function prototyping
string generate_key(string, string);  // function prototyping

int main(void)
{
    cout << "enter the message without including space in between them " << endl;
    string plaintext;
    getline(cin, plaintext);

    cout << "enter the key " << endl;
    string key;
    getline(cin, key);

    vigenere_decrypt(plaintext, key);

    return 0;
}

void vigenere_decrypt(string plaintext, string key)
{
    string new_key = generate_key(plaintext, key);
    string decrypt_text ="";

    for (int i = 0; i < plaintext.size() ; i++)
    {
        decrypt_text.push_back(char ((plaintext[i] + new_key[i]) % 26) + 97 ); // 97 is done to converrt into small letters 
    }


    cout <<"the decrypted text is "<<endl;

    for ( int i = 0 ; i < decrypt_text.size() ; i++)
    {
        cout <<decrypt_text[i];
    }

    
}

string generate_key(string plaintext, string key)
{
    int size_of_plaintext = plaintext.size() - key.size();
    int j = 0;


    for (int i = 0; i < size_of_plaintext; i++)
    {
        
        if (key.size() == plaintext.size())
        {
            break; // key length and plaintext(message) length is same
        }
        
        else
        {
            key.push_back(key[j]);
            j++;
        }

        if (j == key.size())
        {
            j = 0;
        }
    }
    
    return key;
}