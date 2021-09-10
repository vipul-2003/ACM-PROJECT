#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

void vernam_encrypt(string, string);

int main(void)
{
    string plaintext;
    string key;
    do
    {
        cout << "Enter the plaintext in form of pairs without including space and must be in small letters " << endl;
        getline(cin, plaintext);

        cout << "Enter the key of " << plaintext.size() << " length " << endl;
        getline(cin, key);

    } while (plaintext.size() % 2 != 0 && key.size() % 2 != 0);

    vernam_encrypt(plaintext, key);

    return 0;
}

void vernam_encrypt(string plaintext, string key)
{
    string cipher_text;

    int sum = 0 ;

    for (int i = 0; i < plaintext.size(); i++)
    {
        sum = ((plaintext[i] - 97) + (key[i] - 97) );

        if (sum >26) 
        {
            sum -= 26;
        }
        sum += 97 ;
        cipher_text +=char(sum);

    }

    cout <<"Encrypted Text "<<endl;
    for (int i=0 ; i<plaintext.size() ; i++)
    {
        cout <<cipher_text[i];
    }
}