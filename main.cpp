#include <iostream>
#include <cstdio>
using namespace std;
// - - - - - - - - - - - - - - -
void PostChoiceDecider(int lastFunc);
int IDIndex(int desirID); // returns -1, if not found;

void Insert();
void Search();
void Replace();
void Delete();
void Display();
void BackupCompair();

// - - - - - - - - - -

int IDs[20];
int fullIDs = 0;

bool Quit = false;

// - - - - - - - - - - - - - - -

int main()
{
    if (Quit == true) { // just to quit
        return 0;
    }


    int selection = 0;
    cout << "- - - - - - - [ Choices ] - - - - - -";
    cout << "\n   1 - Insert";
    cout << "\n   2 - Search";
    cout << "\n   3 - Replace";
    cout << "\n   4 - Delete";
    cout << "\n   5 - Display";
    cout << "\n   6 - Backup & Compair";

    selector:
        cout << "\n\n"; cin >> selection;

        switch(selection) {
            case 1:
                Insert(); break;

            case 2:
                Search(); break;

            case 3:
                Replace(); break;

            case 4:
                Delete(); break;

            case 5:
                Display(); break;

            case 6:
                BackupCompair(); break;

            default:
                cout << "Your Input Is Invalid, Select Another \n";
                goto selector;
        }


}

// - - - - - - - - - - - - - - -

void Insert()
{
    int desirID = 0;

    cout << "- - - - - - [ INSERTER ] - - - - - -";
    cout << "\n   ID To Insert :"; cin >> desirID;

    if (fullIDs == 20) { // IDs are at 20, don't add anymore

        cout << "   Could Not Enter ID, ID Storage At Full Capacity";
    }
    else if (IDIndex(desirID) != -1) {

        cout << "   Could Not Enter ID, ID Already Exists";
    }
    else {

        IDs[fullIDs] = desirID;
        cout << "   ID Inserted To Index " << fullIDs + 1; //dont start counting at 0 :)
        fullIDs++;
    }

    PostChoiceDecider(1);
}

void Search()
{
    int desirID = 0;

    cout << "- - - - - - [ SEARCHER ] - - - - - -";
    cout << "\n   ID To Search :"; cin >> desirID;

    if (fullIDs == 0) {

        cout << "   ID List Is Empty!";
    }
    else if (IDIndex(desirID) != -1) {

        cout << "   ID Found At Index " << IDIndex(desirID) + 1;
    }
    else {

        cout << "   ID Not Found";
    }

    PostChoiceDecider(2);
}

void Replace()
{
    int desirID = 0;

    cout << "- - - - - - [ REPLACER ] - - - - - -";
    cout << "\n   ID To Replace :"; cin >> desirID;

    if (IDIndex(desirID) != -1) {

        int newID = 0;

        cout << "   ID Found At Index " << IDIndex(desirID) + 1 << ", New ID :"; cin >> newID;

        IDs[IDIndex(desirID)] = newID; // sets old ID to new ID
        cout << "   ID Replaced ";
    }
    else {
        cout << "   Could Not Find ID To Replace";
    }
    PostChoiceDecider(3);
}

void Delete()
{
    int desirID = 0;

    cout << "- - - - - - [ DELETER ] - - - - - -";
    cout << "\n   ID To Delete :"; cin >> desirID;

    if (IDIndex(desirID) != -1) {

        int confirm = 0;

        cout << "   ID Found At Index " << IDIndex(desirID) + 1 << ", Type ID To Confirm :"; cin >> confirm;
        if (confirm == desirID) {
            cout << "   ID Deleted";

            int index = IDIndex(desirID); // to start from (deleted ID's index)

            for (int i = index; i < fullIDs; i++) {

                IDs[i] = IDs[i + 1]; // copies the element on its "right"
            }

            fullIDs--;
        }
        else {

            cout << "   Deletion Canceled";
        }
    }
    else {
        cout << "   Could Not Find ID To Delete";
    }

    PostChoiceDecider(4);
}

void Display()
{
    if (fullIDs == 0) {
        cout << "   No IDs To Display";
    }
    else {
        for (int i = 0; i < fullIDs; i++) {

            if (i != 0) { // just creates new line for viewing’s sake
                cout << "\n";
            }
            cout << "   Index " << i + 1 << " -> " << IDs[i];
        }
    }

    PostChoiceDecider(5);
}

void BackupCompair()
{
    // copy
    int BackupIDs[fullIDs];

    if (fullIDs == 0) {
        cout << "   No IDs To Check";
    }
    else {
        for (int i = 0; i < fullIDs; i++) {

            BackupIDs[i] = IDs[i];
        }

        // compair
        for (int i = 0; i < fullIDs; i++) {

            if (IDIndex(BackupIDs[i]) == -1) {
                cout << " Backup IDs Are Different Than Stored IDs";
                break;
            }
        }

        cout << " Backup IDs Are Valid";
    }

    PostChoiceDecider(6);
}

// - - - - - - - - - - - - - - -

void PostChoiceDecider(int lastFunc)
{

    string funcName;

    switch(lastFunc) {
        case 1:
            funcName = "Inserter"; break;
        case 2:
            funcName = "Searcher"; break;
        case 3:
            funcName = "Replacer"; break;
        case 4:
            funcName = "Deleter"; break;
        case 5:
            funcName = "Display"; break;
        case 6:
            funcName = "Backup & Compairer"; break;
        default:
            funcName = "Error"; break;
    }

    cout << "\n\n\n- - - - - - [ Would You Like To ] - - - - -";
    cout << "\n   1 - Use The " << funcName << " Again";
    cout << "\n   2 - Choose Another Function";
    cout << "\n   3 - Quit";

    int selection = 0;

    selector:

        cout << "\n\n"; cin >> selection;

        Quit = selection == 3;

        if (selection == 1) {
            selection = lastFunc;

            switch(selection) {
                case 1:
                    Insert();
                case 2:
                    Search();
                case 3:
                    Replace();
                case 4:
                    Delete();
                case 5:
                    Display();
                case 6:
                    BackupCompair();
                default:
                    cout << "Your Input Is Invalid, Select Another \n";
                    goto selector;
            }
        }

        main();
}

// - - - - - - - - - -

int IDIndex(int desirID)
{
    for (int i = 0; i < fullIDs; i++) { // enumerates between everything in the ID list

        if (IDs[i] == desirID) {

            return i;
        }
    }

    return -1;
}