


#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string Cipher()

{

    //Greating message
    cout << "Enter the message that you want to cipher it: ";
    string message, keyword;
    getline(cin, message);
    int n_chars = 0;
    //check if the message is more than 80  characters or not
    for (int i = 0; i < message.size(); ++i)
    {

        if (isalpha(message[i]))
        {
            n_chars++;
        }
    }
    while (n_chars > 80)
    {
        cout << "please input message  less than 80 characters: ";
        getline(cin, message);
        n_chars = 0;
        for (int i = 0; i < message.size(); ++i)
        {
            if (isalpha(message[i]))
            {
                n_chars++;
            }
        }
    }
    //turn every small letter into capital letter
    for (int i = 0; i < message.size(); ++i)
    {
        if (islower(message[i]))
        {
            message[i] = toupper(message[i]);
        }
    }
    //Greating message to enter the keyword
    cout << "Enter the keyword: ";
    int n_kchars = 0;
    getline(cin, keyword);
    //check if keyword is less than  characters and if there is any an input that is not alphabetic
    for (int i = 0; i < keyword.size(); ++i)
    {
        if (isalpha(keyword[i]))
        {
            n_kchars++;
        }

    }

    for (int i = 0; i < keyword.size(); ++i)
    {
        while (!isalpha(keyword[i]) || n_kchars > 8)
        {
            int n_kchars = 0;
            for (auto s : keyword)
            {
                if (!isalpha(s))
                {
                    cout << "The keyword should have only alphabetic Enter a keyword again: ";
                    getline(cin, keyword);
                    break;
                }
                n_kchars++;
            }
            if (keyword.size() <= 8)
            {
                break;
            }
            else
            {
                cout << "Please input a keyword with less than 9 characters: ";
            }
            getline(cin, keyword);
        }
    }
    //turn every small letter into capital letter
    for (int i = 0; i < keyword.size(); ++i)
    {
        if (islower(keyword[i]))
        {
            keyword[i] = toupper(keyword[i]);
        }
    }

    //make the length of keyword the same length of the message

    while (size(message) > size(keyword))
    {

        for (int i = 0; i < size(message); ++i)
        {
            keyword.push_back(keyword[i]);
        }

    }


    char a, b, c;
    int s, z, sum;
    cout << "The encrypted message is: ";
    //print every space and number in the message
    for (int i = 0; i < message.size(); ++i)
    {
        if (isspace(message[i]) || isspace(keyword[i]))
        {
            cout << " ";
            continue;
        }
        if (isdigit(message[i]))
        {
            cout << message[i];
            continue;
        }
        if (isdigit(keyword[i]))
        {
            cout << keyword[i];
            continue;
        }
        //calculate the operation
        a = message[i];
        s = int(a);
        b = keyword[i];
        z = int(b);
        sum = ((s + z) % 26) + 65;
        cout << char(sum);
    }

}



//=====================================================

string discipher()

{
    //Greating message
    string keyword, discipher;
    cout << "Enter the encrypted message that you want to discipher it: ";
    getline(cin, discipher);
    int n_dchars = 0;
    for (int i = 0; i < discipher.size(); ++i)
    {
        if (isalpha(discipher[i]))
        {
            n_dchars++;
        }
    }
    //check if the encrypted message is more than 80  characters or not
    while (n_dchars > 80)
    {
        cout << "please input message  less than 80 characters: ";
        n_dchars = 0;
        getline(cin, discipher);
        for (int i = 0; i < discipher.size(); ++i)
        {
            if (isalpha(discipher[i]))
            {
                n_dchars++;
            }

        }
    }
    //turn every small letter into capital letter
    for (int i = 0; i < discipher.size(); ++i)
    {
        if (islower(discipher[i]))
        {
            discipher[i] = toupper(discipher[i]);
        }
    }
    //Greating message to enter the keyword

    cout << "Enter the keyword: ";
    int n_kchar = 0;
    getline(cin, keyword);
    for (int i = 0; i < keyword.size(); ++i)
    {
        if (isalpha(keyword[i]))
        {
            n_kchar++;
        }

    }
    //check if keyword is less than  characters and if there is any an input that is not alphabetic
    for (int i = 0; i < keyword.size(); ++i)
    {
        while (!isalpha(keyword[i]) || n_kchar > 8)
        {

            int n_kchar = 0;
            for (auto s : keyword)
            {
                if (!isalpha(s))
                {
                    cout << "The keyword should have only alphabetic Enter a keyword again: ";
                    getline(cin, keyword);
                    break;
                }
                n_kchar++;
            }
            if (keyword.size() <= 8)
            {
                break;
            }
            else
            {
                cout << "Please input a keyword with less than 9 characters: ";
            }
            getline(cin, keyword);
        }
    }

    //turn every small letter into capital letter
    cout << endl << keyword;
    for (int i = 0; i < keyword.size(); ++i)
    {
        if (islower(keyword[i]))
        {
            keyword[i] = toupper(keyword[i]);
        }

    }

    //make the length of keyword the same length of the message

    while (size(discipher) > size(keyword))
    {

        for (int i = 0; i < size(discipher); ++i)
        {
            keyword.push_back(keyword[i]);
        }

    }

    char a, b, c;
    int s, z, sum;
    cout << endl << "The message is: ";
    for (int i = 0; i < discipher.size(); ++i)
    {
        //print every space and number in the encrypted message
        if (isspace(discipher[i]) || isspace(keyword[i]))
        {
            cout << " ";
            continue;
        }
        if (isdigit(discipher[i]))
        {
            cout << discipher[i];
            continue;
        }
        if (isdigit(keyword[i]))
        {
            cout << keyword[i];
            continue;
        }
        //calculate the operation
        a = discipher[i];
        s = int(a);
        b = keyword[i];
        z = int(b);
        sum = ((((s - z) + 26)) % 26) + 65;
        cout << char(sum);
    }

}




int main()
{
    int num;
    cout << "To encrypt the message input number (1):" << endl;
    cout << "To decrypt the message input number (2): ";

    cin >> num;
    cin.ignore();

    if (num == 1)
    {
        Cipher();
    }
    else if (num == 2)
    {
        discipher();
    }
    else
    {
        cout << "Invalid input";
    }

    return 0;
}
