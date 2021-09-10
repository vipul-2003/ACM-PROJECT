/**
 * https://whimsical.com/cryptography-67Gfj8QufPBmgJDHY6fzoC  ( LINK FOR FLOW CHART ) 
 * git hub repo :: https://github.com/vipul-2003/ACM-PROJECT
 * @file main.cpp
 * @author VIPUL KUAMR SINGH  (vipulrjput@gmail.com)
 * @brief 
 * The ascii table is used https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
 * THIS IS THE IMPLEMENTATION OF THE DIFFERENT TEXT CRYPTOGRAPHY  (in c++ language )
 * 
 * 1.CEASER CIPHER
 * 2.KEYWORD CIPHER
 * 3.VERNAM CIPHER 
 * 4.VIGENERE CIPHER
 *  
 * @version 1.0
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
   All header file included in this required to run the programs  
*/
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <string>

using namespace std;

class CRYPTO
{
private:
    string PlainText; // use to encrypt the data
    string key;       // use to encrypt the data

    vector<char> CipherText; // use to encrypt the data

    string CipherText1;      // use to decrypt the data
    vector<char> PlainText1; // use to decrypt the data

public:
    /* --------------------------------------------------------------------------------------*/

    void GetDataToEncrypt(void) // this function is used to input from  user to encrypt in it
    {
        cout << "ENTER THE MESSAGE TO ENCRYPT " << endl;
        cin >> PlainText;

        cout << "ENTER THE KEY " << endl;
        cin >> key;
    }

    void EncryptedDataToDisplay() // this function is used to display the encrypted text
    {
        cout << "THE ENCRYPTED MESSAGE IS " << endl;

        for (int i = 0; i < CipherText.size(); i++)
        {
            cout << CipherText[i];
        }
        cout << "\n \n"
             << endl;
    }

    /* --------------------------------------------------------------------------------------*/
    void GetDataToDecrypt(void) // this function is used to get encrypted text from user to decrypt
    {
        cout << "ENTER THE MESSAGE TO DECRYPT " << endl;
        cin >> CipherText1;

        cout << "ENTER THE KEY " << endl;
        cin >> key;
    }

    void DecryptedDataToDisplay() // this function is used to display the deciphered(decrypted) text
    {
        cout << "THE DECRYPTED MESSAGE IS " << endl;

        for (int i = 0; i < PlainText1.size(); i++)
        {
            cout << PlainText1[i];
        }
        cout <<"\n\n"<<endl;
    }

    /* --------------------------------------------------------------------------------------*/

    void EmptyString() // this simply helps to delete or empty the string and vector elements
    {
        CipherText.clear(); // these two are string 
        PlainText1.clear();

        PlainText.erase(); // these two are vector 
        CipherText1.erase();
    }

    /* --------------------------------------------------------------------------------------*/

    void CeaserEncrpyt(); // function prototypes in class which is defined after the main function
    void CeaserDecrpyt();

    /* --------------------------------------------------------------------------------------*/

    void KeywordEncrypt();
    void KeywordDecrypt();
    string GenerateKey(string key);
    /* used to create a new key with repeating elements upto plaintext length
       this function works for the keyword encrypt function 
    */
    /* --------------------------------------------------------------------------------------*/

    void VernamEncrypt(); // function prototyping
    void VernamDecrypt();

    /* --------------------------------------------------------------------------------------*/

    void VigenereEncrypt();
    void VigenereDecrypt();
    string GenerateKey_Vigenere(string plaintext, string key);
    // this generatekey function helps in key for Vigenere key which is used to cipher or decipher the text
    /* --------------------------------------------------------------------------------------*/

    void RailFenceEncrypt(); // function prototypes in class which is defined after the main function
    void RailFenceDecrypt();
    
    /* --------------------------------------------------------------------------------------*/
};

int main(void)
{

    int ch;

    CRYPTO encryption; // it helps to use the function of class CRYPTO 
    CRYPTO decryption;

    cout << "-------WELCOME , THERE -------" << endl;

    int choice;

    while (true)
    {
        /*
        In while loop , simply we have implemented  functions choice within choice  
        */
        cout << " 1. CEASER CIPHER" << endl;
        cout << " 2. CEASER DECIPHER" << endl;
        cout << " 3. KEYWORD CIPHER" << endl;
        cout << " 4. KEYWORD DECIPHER" << endl;
        cout << " 5. VERNAM CIPHER" << endl;
        cout << " 6. VERNAM DECIPHER" << endl;
        cout << " 7. VIGENERE CIPHER" << endl;
        cout << " 8. VIGENERE DECIPHER" << endl;
        cout << " 9. RAIL FENCE CIPHER" << endl;
        cout << " 10. RAIL FENCE DECIPHER" << endl;
        cout << " 11.        EXIT       " << endl;

        cout << "ENTER THE CHOICE TO GO WITH " << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "YOU HAVE SELECTED CEASER CIPHER " << endl;
            encryption.CeaserEncrpyt(); // function call

            break;

            /* --------------------------------------------------------------------------------------*/

        case 2:
            cout << "YOU HAVE SELECTED CEASER DECIPHER" << endl;
            decryption.CeaserDecrpyt();

            break;

            /* --------------------------------------------------------------------------------------*/

        case 3:
            cout << "YOU HAVE SELECTED KEYWORD CIPHER" << endl;
            encryption.KeywordEncrypt();

            break;

            /* --------------------------------------------------------------------------------------*/

        case 4:
            cout << "YOU HAVE SELECTED KEYWORD DECIPHER" << endl;
            decryption.KeywordDecrypt();

            break;

            /* --------------------------------------------------------------------------------------*/

        case 5:
            cout << "YOU HAVE SELECTED VERNAM CIPHER " << endl;
            encryption.VernamEncrypt();

            break;

        case 6:
            cout << "YOU HAVE SELECTED VERNAM DECIPHER " << endl;
            decryption.VernamDecrypt();

            break;

        case 7:
            cout << "YOU HAVE SELECTED VIGENERE CIPHER" << endl;
            encryption.VigenereEncrypt();

            break;

        case 8:
            cout << "YOU HAVE SELECTED VIGENERE CIPHERR" << endl;
            decryption.VigenereDecrypt();

            break;

        case 9:
            cout<<"YOU HAVE SELECTED RAIL FENCE CIPHER"<<endl;
            encryption.RailFenceEncrypt();
            break;
        
        case 10:
            cout <<"YOU HAVE SELECTED RAIL FENCE DECIPHER"<<endl;
            decryption.RailFenceDecrypt();
            break;

        case 11:

            cout << "      ((:  EXITED  :))       " << endl;
            exit(0);

        default:
            cout << "  !!! INVALID CHOICE !!!     " << endl;
        }
    }
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::CeaserEncrpyt() // function declaration of member function of class CRYPT
{
    GetDataToEncrypt();

    int new_key = stoi(key);

    int size = PlainText.length(); // it is used to get the length of text inputted

    for (int i = 0; i < size; i++)
    {
        if (isupper(PlainText[i]))
        {
            CipherText.push_back(char(int(PlainText[i] + new_key - 65) % 26 + 65));
        }

        else if (islower(PlainText[i]))
        {
            CipherText.push_back(char(int(PlainText[i] + new_key - 97) % 26 + 97));
        }

        else
        {
            CipherText.push_back(char(PlainText[i]));
        }
    }

    EncryptedDataToDisplay(); // to display the encrypted message
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::CeaserDecrpyt() //function declaration of member function of class CRYPT
{
    GetDataToDecrypt();
    int new_key = stoi(key);
    /* 
    stoi is basically string to integer function and predefined , accept key(string types ) as parameter than convert into integer type

    new_key simply used to store explicit type conversion data
    (string) to (int)  

    this function is used to convert string into integer as all key are accepted by user in string datatypes 
    i.e, we have to convert in integer as integer is required as key from the user
   
    */

    int size = CipherText1.length(); // it is used to get the length of text inputted

    for (int i = 0; i < size; i++)
    {
        if (isupper(CipherText1[i]))
        {
            PlainText1.push_back(char(int(CipherText[i] - new_key - 65) % 26 + 65));
        }

        else if (islower(CipherText1[i]))
        {
            PlainText1.push_back(char(int(abs(CipherText1[i] - new_key - 97) % 26 + 97)));
        }

        else
        {
            PlainText1.push_back(char(CipherText1[i]));
        }
    }
    DecryptedDataToDisplay();
    EmptyString();
}
/* ------------------------------------------------------------------------------------------------------------*/
/*

this function is used by keyword encrypt and decrypt function 
to create a key of same length as that of plaintext or cipher text 

this function basically create a 26 character key from the user inputted key and use it cipher or decipher 
but the key inputted must be unique and does not two same characters 

*/

string CRYPTO ::GenerateKey(string key)
{
    bool array[26] = {false};

    char encrypt[26];
    int size = key.length(); // used to get the length of the string :: key

    for (int i = 0; i < size; i++)
    {
        if (array[i] == false)
        {
            encrypt[i] = key[i];
            array[i] = true;
        }
    }

    int j = 97;

    for (int i = size; i < 26; i++)
    {
        if (array[i] == false)
        {
            encrypt[i] = char(j);

            for (int k = 0; k < size; k++)
            {
                if (encrypt[i] == key[k])
                {
                    ++j;

                    encrypt[i] = char(j);
                    k = -1;
                }
            }

            array[i] = true;

            ++j;
        }
    }

    //  for ( int i = 0 ; i <26 ; i++)
    // {
    //     cout <<encrypt[i];
    // }

    return encrypt;
}
/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::KeywordEncrypt() //function declaration of member function of class CRYPT
{
    GetDataToEncrypt();

    string new_key = GenerateKey(key); // reference with the keyword generate key function to return new key
    int size = PlainText.size();

    for (int i = 0; i < size; i++)
    {
        if (isupper(PlainText[i]))
        {
            CipherText.push_back(new_key[PlainText[i] - 65]);
        }

        else if (islower(PlainText[i]))
        {
            CipherText.push_back(new_key[PlainText[i] - 97]);
        }

        else
        {
            CipherText.push_back(PlainText[i]);
        }
    }

    EncryptedDataToDisplay();
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::KeywordDecrypt()
{
    GetDataToDecrypt();

    string new_key = GenerateKey(key);

    int size = CipherText1.size();

    for (int i = 0; i < size; i++)
    {
        if (isupper(CipherText1[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (CipherText1[i] == new_key[j])
                {
                    PlainText1.push_back(char(j + 65));
                    break;
                }
            }
        }

        else if (islower(CipherText1[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (CipherText1[i] == new_key[j])
                {
                    PlainText1.push_back(char(j + 97));
                    break;
                }
            }
        }

        else
        {
            PlainText1.push_back((CipherText1[i]));
        }
    }
    DecryptedDataToDisplay();
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/
/*

to run this program input and key length is same and equal
such as input is "vipulkumar" and key is "abcdefghij"
then we get the desired encrypted text 

*/
void CRYPTO ::VernamEncrypt()
{
    GetDataToEncrypt();

    int sum = 0;

    for (int i = 0; i < PlainText.size(); i++)
    {
        sum = ((PlainText[i] - 97) + (key[i] - 97));

        if (sum > 26)
        {
            sum -= 26;
        }
        sum += 97;
        CipherText.push_back(char(sum));
    }
    EncryptedDataToDisplay();
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::VernamDecrypt() //function declaration of member function of class CRYPT
{
    GetDataToDecrypt();
    int sum = 0;

    for (int i = 0; i < CipherText1.size(); i++)
    {
        sum = ((CipherText1[i] - 97) - (key[i] - 97));

        if (sum < 0)
        {
            sum += 26;
        }
        sum += 97;
        PlainText1.push_back(char(sum));
    }
    DecryptedDataToDisplay();
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/
string CRYPTO ::GenerateKey_Vigenere(string plaintext, string key)
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

            if (j == key.size())
            {
                j = 0;
            }
        }
    }

    return key;
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::VigenereEncrypt() //function declaration of member function of class CRYPT
{
    GetDataToEncrypt();

    string new_key = GenerateKey_Vigenere(PlainText, key);

    for (int i = 0; i < PlainText.size(); i++)
    {
        CipherText.push_back(char(int((PlainText[i] - 97) + (new_key[i] - 97)) % 26) + 97); // 97 is done to converrt into small letters
    }

    EncryptedDataToDisplay();
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::VigenereDecrypt() //function declaration of member function of class CRYPT
{
    GetDataToDecrypt();

    string new_key = GenerateKey_Vigenere(CipherText1, key);

    for (int i = 0; i < CipherText1.size(); i++)
    {
        PlainText1.push_back(char(int((CipherText1[i] - 97) - (new_key[i] - 97)) % 26) + 97); // 97 is done to converrt into small letters
    }

    DecryptedDataToDisplay();
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO :: RailFenceEncrypt()
{
    GetDataToEncrypt();

    int new_key = stoi(key); // to convert string to integer

    int row = new_key; // to represent the no. of rows

    int column = PlainText.length(); // to represent the no. of columns and columns equals to length of plaintext 

    char RailFence[row][column]; 

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            RailFence[i][j] = '%'; //filling blank space to the rail fence matrix
        }
    }

    bool directionChange = false; // used to go downward in the RailFence matrix

    int i = 0; //used for the row
    int j = 0; //used for the column

    for (int k = 0; k < column; k++)
    {

        if (i == 0 || i == new_key - 1)
        {
            directionChange = !directionChange;
        }

        RailFence[i][j] = PlainText[k];

        if (directionChange == false)
        {
            --i;
        }
        else
        {
            ++i;
        }
        j++; //always increase the column in the RailFence
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (RailFence[i][j] != '%')
            {
                CipherText.push_back(RailFence[i][j]);
            }
        }
    }

    EncryptedDataToDisplay();
    EmptyString();
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO :: RailFenceDecrypt()
{
    GetDataToDecrypt();

    int new_key = stoi(key);

    int row = new_key;

    int column = CipherText1.length();

    char RailFence[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            RailFence[i][j] = '_'; //filling blank space to the rail fence matrix
        }
    }
    
  
    bool directionChange = false; // used to go downward in the RailFence matrix

    int i = 0; //used for the row
    int j = 0; //used for the column

    for (int k = 0; k < column; k++)
    {

        if (i == 0 || i == new_key - 1)
        {
            directionChange = !directionChange;
        }

        RailFence[i][j] = '*';

        if (directionChange == false)
        {
            --i;
        }
        else
        {
            ++i;
        }
        j++; //always increase the column in the RailFence
    }
    
  
    int k = 0;
    while (k < CipherText1.length())
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (RailFence[i][j] == '*')
                {
                    RailFence[i][j] = CipherText1[k];
                    k++;
                }
            }
        }
    }
    
 
 directionChange = false ; // set direction to false as  it changes at first and last row 
i = 0 , j = 0; // to move with in matrix 
    for (int k = 0; k < column; k++)
    {

        if (i == 0 || i == new_key - 1)
        {
            directionChange = !directionChange;
        }

        PlainText1.push_back(RailFence[i][j]);

        if (directionChange == false)
        {
            --i;
        }
        else
        {
            ++i;
        }
        j++; //always increase the column in the RailFence
    }
    DecryptedDataToDisplay();
    EmptyString();
}
/* ------------------------------------------------------------------------------------------------------------*/

