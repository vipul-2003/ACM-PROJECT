#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void vernam_decrypt(string, string);

int main(void)
{
    string ciphertext;
    string key;
    do
    {
        cout << "Enter the ciphertext in form of pairs without including space and must be in small letters " << endl;
        getline(cin, ciphertext);

        cout << "Enter the key of " << ciphertext.size() << " length " << endl;
        getline(cin, key);

    } while (ciphertext.size() % 2 != 0 && key.size() % 2 != 0);

 vernam_decrypt(ciphertext, key);

    return 0;
}

void vernam_decrypt(string ciphertext, string key)
{
    string cipher_text;

    int sum = 0 ;

    for (int i = 0; i < ciphertext.size(); i++)
    {
        sum = ((ciphertext[i] - 97) - (key[i] - 97) );

        if (sum < 0) 
        {
            sum += 26;
        }
        sum += 97 ;
        cipher_text +=char(sum);

    }

    cout <<"Encrypted Text "<<endl;
    for (int i=0 ; i<ciphertext.size() ; i++)
    {
        cout <<cipher_text[i];
    }
}