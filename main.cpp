#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

struct User
{
    int id;
    string userName,  userPassword;
};

int userSignIn (vector <User> &currentUser, int currentUsersCount)
{
    string userName, userPassword;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> userName;
    int i = 0;

    while (i < currentUsersCount)
    {
        if (currentUser[i].userName == userName)
        {
            for (int attempts = 0; attempts < 3; attempts++)
            {
                cout << "Podaj haslo uzytkownika.Pozostalo prob " << 3 - attempts <<": ";
                cin >> userPassword;
                if (currentUser[i].userPassword == userPassword)
                {
                    cout << "Zalogowales sie.";
                    Sleep(1000);
                    return currentUser[i].id;
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

int userRegistration (vector <User> &currentUser, int currentUsersCount)
{
    string userName, userPassword;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> userName;
    int i = 0;

    while (i < currentUsersCount)
    {
        if (currentUser[i].userName == userName)
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

    User newUser;
    newUser.userName = userName;
    newUser.userPassword = userPassword;
    newUser.id = currentUsersCount + 1;

    currentUser.push_back(newUser);
    currentUsersCount++;

    cout << "Konto zostalo zalozone";
    Sleep(1000);

    return currentUsersCount;
}


void passwordChange (vector <User> &currentUser, int currentUsersCount, int loggedUserId)
{

    string userNewPassword;

    cout << "Podaj nowe userPassword: ";
    cin >> userNewPassword;

    for ( User &user : currentUser)
    {
        if (user.id == loggedUserId)
        {
            user.userPassword = userNewPassword;
            cout << "Haslo zostalo zmienione.";
            Sleep(1500);
            return;
        }
    }
}

int main()
{
    vector<User> currentUser;

    int loggedUserId = 0;
    int currentUsersCount = 0;

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
                currentUsersCount = userRegistration (currentUser,currentUsersCount);
            }
            else if (choice == '2')
            {
                loggedUserId = userSignIn (currentUser, currentUsersCount);
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
                passwordChange (currentUser, currentUsersCount, loggedUserId);
            }
            else if (choice == '2')
            {
                loggedUserId = 0;
            }
        }
    }
return 0;
}

