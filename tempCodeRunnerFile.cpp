/*
   KEYWORD ( MONOALPHABETIC ENCRYPTION )
*/

// user inputted key must be alphabetic not alphanumeric

#include "iostream"
#include "stdio.h"
#include <ctype.h>
#include <vector>

using namespace std;

string encrypt(string key);
int keyword_encrypt(string text, string key);

int main(void)
{
    cout << "Enter the message to decrypt " << endl;
    string cipher_text;

    getline(cin, cipher_text);

    string key;
    cout << "Enter the key ";
    getline(cin, key );

    keyword_decrypt(cipher_text, key);

    return 0;
}


string encrypt(string key)
{
    bool array[26] = {false};

    string encrypt = "";
    int size = key.length(); // used to get the length of the string :: key

    for (int i = 0; i < size; i++)
    {
        if (array[i] == false)
        {
            if (isupper(key[i]))
            {
                encrypt += key[i];
                array[i] = true;
            }

            else if (islower(key[i]))
            {
                encrypt += key[i]-32;
                array[i] = true;
            }
        }
    }

    
    for (int i = size ; i<26 ; i++)
    {
        if (array[i] == false)
        {
            encrypt += char(i + 65);
            
        }
    }

    return encrypt ;

}

int keyword_decrypt(string text, string encrypt)
{
    vector <char> coded_text;

    int size = text.size();

    for (int i = 0 ; i< size ; i++)
    {
        if (isupper(text[i]))
        {
            coded_text.push_back(encrypt[text[i]-65]);
        }

        else if (islower(text[i]))
        {
            coded_text.push_back(encrypt[text[i]-97]);
        }

        else
        {
            coded_text.push_back(text[i]);
        }
    }
    return 0;
}
