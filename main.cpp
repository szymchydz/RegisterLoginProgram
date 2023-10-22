#include <iostream>
#include <windows.h>

using namespace std;

struct User
{
    int id;
    string userName,  userPassword;
};

int userSignIn (User users[], int usersCount)
{
    string userName, userPassword;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> userName;
    int i = 0;

    while (i < usersCount)
    {
        if (users[i].userName == userName)
        {
            for (int attempts = 0; attempts < 3; attempts++)
            {
                cout << "Podaj haslo uzytkownika.Pozostalo prob " << 3 - attempts <<": ";
                cin >> userPassword;
                if (users[i].userPassword == userPassword)
                {
                    cout << "Zalogowales sie.";
                    Sleep(1000);
                    return users[i].id;
                }
            }
            cout << "Odczekaj 3 sekundy na odblokowanie." << endl;
            cout << "3s" << endl;
            Sleep(1000);
            cout << "2s" << endl;
            Sleep(1000);
            cout << "1s" << endl;
            Sleep(1000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika o takiej nazwie" << endl;
    Sleep(1500);
    return 0;
}

int userRegistration (User users[], int usersCount)
{
    string userName, userPassword;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> userName;
    int i = 0;

    while (i < usersCount)
    {
        if (users[i].userName == userName)
        {
            cout << "Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> userName;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    cout << "Podaj haslo: ";
    cin >> userPassword;

    users[usersCount].userName = userName;
    users[usersCount].userPassword = userPassword;
    users[usersCount].id = usersCount + 1;

    cout << "Konto zostalo zalozone";
    Sleep(1000);

    return usersCount + 1;
}


void passwordChange (User users[], int usersCount, int loggedUserId)
{

    string userNewPassword;

    cout << "Podaj nowe haslo: ";
    cin >> userNewPassword;

    for ( int i = 0; i < loggedUserId; i++)
    {
        if (users[i].id == loggedUserId)
        {
            users[i].userPassword = userNewPassword;
            cout << "Haslo zostalo zmienione.";
            Sleep(1500);
        }
    }
}

int main()
{
    User users[100];
    int loggedUserId = 0;
    int usersCount = 0;

    char choice;

    while (1)
    {
        if (loggedUserId == 0)
        {
            system ("cls");
            cout << "   >>> MENU GLOWNE <<< " << endl;
            cout << "........................" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout << "........................" << endl;
            cout << "Twoj wybor: ";
            cin >> choice;

            if (choice == '1')
            {
                usersCount = userRegistration (users,usersCount);
            }
            else if (choice == '2')
            {
                loggedUserId = userSignIn (users, usersCount);
            }
            else if (choice == '9')
            {
                exit(0);
            }
        }
        else
        {
            system ("cls");
            cout << "1. Zmiana hasla" << endl;
            cout << "2. Wylogowanie" << endl;
            cin >> choice;

            if (choice == '1')
            {
                passwordChange (users, usersCount, loggedUserId);
            }
            else if (choice == '2')
            {
                loggedUserId = 0;
            }
        }
    }
return 0;
}

