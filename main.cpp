// Including Header Files
#include <iostream> // For Input-Output
#include <fstream> // reading and writing files 
#include <string> // To use String

using namespace std;

bool LoginCheck()
{
    string username, password;
    string un, pw; 

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(username + ".txt");  
    getline(read, un); 
    getline(read, pw);

    if (un == username && pw == password) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Registration: " << endl;
        cout << endl;
        cout << "Select a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;

        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        cout << "Welcome " << username << "!" << endl;
    }
    else if (choice == 2) 
    {
        bool status = LoginCheck();

        if (!status) 
        {
            system("cls");
            cout << endl;
            cout << "Invalid login!" << endl;
            main();
            return 0;
        }
        else 
        {
            cout << "Successfully logged in!" << endl;
            cout << endl;

            int choiceTwo;

            cout << "Welcome!" << endl;
            cout << "1. Sign Out" << endl;
            cout << "2. Back to main menu" << endl;
            cout << "Your choice: " << endl;
            cin >> choiceTwo;

            if (choiceTwo == 1)
            {
                system("exit"); // exits program 
            }
            else if (choiceTwo == 2)
            {
                main(); // returns to the beginning of the main() function
            }
            return 1;
        }
    }
}
