#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

class CRYPTO
{
public:
    string PlainText; // use to encrypt the data
    string key;       // use to encrypt the data

    vector<char> CipherText; // use to encrypt the data

    string CipherText1;      // use to decrypt the data
    vector<char> PlainText1; // use to decrypt the data

    void GetDataToEncrypt(void)
    {
        cout << "ENTER THE MESSAGE TO ENCRYPT " << endl;
        getline(cin, PlainText); //  does not taking input from user .....??????????????????????????

        cout << "ENTER THE KEY " << endl;
        cin >> key;
    }

    void EncryptedDataToDisplay()
    {
        cout << "THE ENCRYPTED MESSAGE IS " << endl;

        for (auto &i : CipherText)
        {
            cout << CipherText[i];
        }
    }

    /* --------------------------------------------------------------------------------------*/
    void GetDataToDecrypt(void)
    {
        cout << "ENTER THE MESSAGE TO DECRYPT " << endl;
        getline(cin, CipherText1);

        cout << "ENTER THE KEY " << endl;
        cin >> key;
    }

    void DecryptedDataToDisplay()
    {
        cout << "THE DECRYPTED MESSAGE IS " << endl;

        for (auto &i : PlainText1)
        {
            cout << PlainText1[i];
        }
    }

    /* --------------------------------------------------------------------------------------*/

    void CeaserEncrpyt();
    void CeaserDecrpyt();

    /* --------------------------------------------------------------------------------------*/

    void KeywordEncrypt();
    void KeywordDecrypt();
    string GenerateKey(string key); // used to create a new key with repeating elements upto plaintext length

    /* --------------------------------------------------------------------------------------*/

    void VernamEncrypt();
    void VernamDecrypt();

    /* --------------------------------------------------------------------------------------*/

    string GenerateKey_Vegenere(string plaintext, string key);
    void VegenereEncrypt();
    void VegenereDecrypt();

    /* --------------------------------------------------------------------------------------*/
};

int main(void)
{

    int ch;

    cout << "-------WELCOME , THERE -------" << endl;
    cout << " 1. CEASER CIPHER" << endl;
    cout << " 2. KEYWORD CIPHER" << endl;
    cout << " 3. VERNAM CIPHER" << endl;
    cout << " 4. VEGENERE CIPHER" << endl;
    cout << " 5.        EXIT       " << endl;
    cout << "  !!! INVALID CHOICE !!!     " << endl;
    cout << "ENTER THE CHOICE TO GO WITH " << endl;
    int choice;

    cin >> choice;

    while (true)
    {

        switch (choice)
        {
        case 1:

            cout << "YOU HAVE SELECTED CEASER CIPHER " << endl;
            cout << " 1. CEASER ENCRYPTION " << endl;
            cout << " 2. CEASER DECRYPTION " << endl;
            cout << "ENTER THE CHOICE TO GO WITH " << endl;

            cin >> ch;

            if (ch == 1)
            {
                cout << "YOU HAVE SELECTED CEASER ENCRYPTION " << endl;
                CRYPTO encryption;
                encryption.GetDataToEncrypt();

                encryption.CeaserEncrpyt();

                encryption.EncryptedDataToDisplay();
            }

            else if (ch == 2)
            {
                cout << "YOU HAVE SELECTED CEASER DECRYPTION " << endl;
                CRYPTO decryption;
                decryption.GetDataToDecrypt();

                decryption.CeaserDecrpyt();

                decryption.DecryptedDataToDisplay();
            }

            else
            {
                cout << "  !!! INVALID CHOICE !!!     " << endl;
            }

            break;

            /* --------------------------------------------------------------------------------------*/

        case 2:
            cout << "YOU HAVE SELECTED KEYWORD CIPHER " << endl;
            cout << " 1. KEYWORD ENCRYPTION " << endl;
            cout << " 2. KEYWORD DECRYPTION " << endl;
            cout << "ENTER THE CHOICE TO GO WITH " << endl;

            cin >> ch;

            if (ch == 1)
            {
                cout << "YOU HAVE SELECTED KEYWORD ENCRYPTION " << endl;
                CRYPTO encryption;
                encryption.GetDataToEncrypt();

                encryption.KeywordEncrypt();
                encryption.EncryptedDataToDisplay();
            }

            else if (ch == 2)
            {
                cout << "YOU HAVE SELECTED KEYWORD DECRYPTION " << endl;
                CRYPTO decryption;
                decryption.GetDataToDecrypt();

                decryption.KeywordDecrypt();
                decryption.DecryptedDataToDisplay();
            }

            else
            {
                cout << "  !!! INVALID CHOICE !!!     " << endl;
            }

            break;

            /* --------------------------------------------------------------------------------------*/

        case 3:

            cout << "YOU HAVE SELECTED VERNAM CIPHER " << endl;
            cout << " 1. VERNAM ENCRYPTION " << endl;
            cout << " 2. VERNAM DECRYPTION " << endl;
            cout << "ENTER THE CHOICE TO GO WITH " << endl;

            cin >> ch;

            if (ch == 1)
            {
                cout << "YOU HAVE SELECTED VERNAM ENCRYPTION " << endl;
                CRYPTO encryption;
                encryption.GetDataToEncrypt();

                encryption.VernamEncrypt();
                encryption.EncryptedDataToDisplay();
            }

            else if (ch == 2)
            {
                cout << "YOU HAVE SELECTED VERNAM DECRYPTION " << endl;
                CRYPTO decryption;
                decryption.GetDataToDecrypt();

                decryption.VernamDecrypt();
                decryption.DecryptedDataToDisplay();
            }

            else
            {
                cout << "  !!! INVALID CHOICE !!!     " << endl;
            }

            break;

            /* --------------------------------------------------------------------------------------*/

        case 4:

            cout << "YOU HAVE SELECTED VEGENERE CIPHER " << endl;
            cout << " 1. VEGENERE RYPTION " << endl;
            cout << " 2. VEGENERE DECRYPTION " << endl;
            cout << "ENTER THE CHOICE TO GO WITH " << endl;

            cin >> ch;

            if (ch == 1)
            {
                cout << "YOU HAVE SELECTED VEGENERE ENCRYPTION " << endl;
                CRYPTO encryption;
                encryption.GetDataToEncrypt();

                encryption.VegenereEncrypt();
                encryption.EncryptedDataToDisplay();
            }

            else if (ch == 2)
            {
                cout << "YOU HAVE SELECTED VEGENERE DECRYPTION " << endl;
                CRYPTO decryption;
                decryption.GetDataToDecrypt();

                decryption.VegenereDecrypt();
                decryption.DecryptedDataToDisplay();
            }

            else
            {
                cout << "  !!! INVALID CHOICE !!!     " << endl;
            }

            break;

            /* --------------------------------------------------------------------------------------*/

        case 5:
            cout << " 5.        EXIT       " << endl;
            exit(0);

            /* --------------------------------------------------------------------------------------*/

        default:
            cout << "  !!! INVALID CHOICE !!!     " << endl;

            /* --------------------------------------------------------------------------------------*/
        }
    }
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::CeaserEncrpyt()
{

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
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::CeaserDecrpyt()
{
    int new_key = stoi(key);
    int size = CipherText1.length(); // it is used to get the length of text inputted

    for (int i = 0; i < size; i++)
    {
        if (isupper(CipherText1[i]))
        {
            PlainText1.push_back(char(int(CipherText[i] - new_key - 65) % 26 + 65));
        }

        else if (islower(CipherText[i]))
        {
            PlainText1.push_back(char(int(CipherText[i] - new_key - 97) % 26 + 97));
        }

        else
        {
            PlainText1.push_back(char(CipherText[i]));
        }
    }
}

/* ------------------------------------------------------------------------------------------------------------*/
/*

this function is used by keyword encrypt and decrypt function 
to create a key of same length as that of plaintext or cipher text 

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

            for (int k = 0; k < 5; k++)
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

    return encrypt;
}
/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::KeywordEncrypt()
{
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
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::KeywordDecrypt()
{
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
                if (PlainText[i] == new_key[j])
                {
                    CipherText1.push_back(char(j + 97));
                    break;
                }
            }
        }

        else
        {
            CipherText1.push_back((PlainText[i]));
        }
    }
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::VernamEncrypt()
{
    int sum = 0;

    for (int i = 0; i < PlainText.size(); i++)
    {
        sum = ((PlainText[i] - 97) + (key[i] - 97));

        if (sum > 26)
        {
            sum -= 26;
        }
        sum += 97;
        CipherText[i] += char(sum);
    }
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::VernamDecrypt()
{
    int sum = 0;

    for (int i = 0; i < CipherText1.size(); i++)
    {
        sum = ((CipherText1[i] - 97) - (key[i] - 97));

        if (sum < 0)
        {
            sum += 26;
        }
        sum += 97;
        CipherText1 += char(sum);
    }
}

/* ------------------------------------------------------------------------------------------------------------*/
string CRYPTO ::GenerateKey_Vegenere(string plaintext, string key)
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

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::VegenereEncrypt()
{
    string new_key = GenerateKey_Vegenere(PlainText, key);

    for (int i = 0; i < PlainText.size(); i++)
    {
        CipherText.push_back(char(int((PlainText[i] - 97) + (new_key[i] - 97)) % 26) + 97); // 97 is done to converrt into small letters
    }
}

/* ------------------------------------------------------------------------------------------------------------*/

void CRYPTO ::VegenereDecrypt()
{
    string new_key = GenerateKey_Vegenere(CipherText1, key);

    for (int i = 0; i < CipherText1.size(); i++)
    {
        PlainText1.push_back(char(int((CipherText1[i] - 97) - (new_key[i] - 97)) % 26) + 97); // 97 is done to converrt into small letters
    }
}

/* ------------------------------------------------------------------------------------------------------------*/
