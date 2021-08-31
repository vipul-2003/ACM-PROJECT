#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std ;

void hill_cipher(string , string);
string key_generate(string );

int main()
{
    cout <<"enter the text to encrypt  "<<endl ;
    string plaintext;
    getline(cin , plaintext);


    string key ;
    cout <<"enter the key (note :: it must be in small letters and in size of 1 , 4 , 9 , 16 and soon ...)";
    getline (cin , key );

    hill_cipher(plaintext , key);
    
    return 0;
}

void hill_cipher(string text, string key )
{
    int size_of_matrix = sqrt(key.size());

    int matrix [size_of_matrix][size_of_matrix];

    string matrix_key = key_generate(key );

}

string key_generate(string key , int matrix[][])
{

}