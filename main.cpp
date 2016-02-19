/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: reuben
 *
 * Created on 18 February, 2016, 7:51 PM
 */
#include "main.h"
#include "Authentication.h"

Authentication authenticate;

int main()
{
    mainMenu();
}

void makePartition()
{
    cout << "----------------------------------------------------------------";
    cout << endl;
}
int mainMenu()
{
    makePartition();
    cout << setw(50) << "Country Club Facilities Booking System" << endl;
    cout << setw(55) << "Please key in the following information to login" << endl;
    makePartition();
    cout << endl;
    string username, password;
    int counter = 0;
    int options;
    bool flag = true;
    do
    {
        if (flag == false && options == -1)
        {
            cout << "-----------------------------------------" << endl;
            cout << "Invalid username, please try again." << endl;
            cout << "WARNING!   " << counter << " of 3 tries" << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
        }
        else if (flag == false && options == -2)
        {
            cout << "-----------------------------------------" << endl;
            cout << "Wrong password, please try again" << endl;
            cout << "WARNING!   " << counter << " of 3 tries" << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
        }
        
        do
        {
            cout << "Username: ";
            cin >> username;   
        }while (username.empty());
        do
        {
            cout << "Password: ";
            cin >> password;
        }while (password.empty());
        cout << endl;
        options = authenticate.verify(username, password);
        flag = false;
    //go through authentication class for user and password and return 
    }while ((options == -1 || options == -2)  && counter++ < 2);
    
    if (counter == 3)
    {
        cout << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Invalid user/password entered for 3 times" << endl;
        cout << "Program will now terminate." << endl;
        cout << "-----------------------------------------" << endl;
        return 0;
    }
    
    switch (options)
    {
        case 1: adminMenu();
                break;
        case 2: memberMenu();
                break;
        default: cout << "Error" << endl;
    }
}
void adminMenu()
{
    makePartition();
    cout << setw(50) << "Country Club Facilities Booking System" << endl;
    cout << setw(49) << "+++++++  Club Manager's Menu  +++++++" << endl;   
    makePartition();
    cout << "    1.) Facilities Management Sub-system" << endl;
    cout << "    2.) Member Management Sub-system" << endl;
    cout << "    3.) Report Sub-system" << endl;
    cout << "    4.) Help" << endl;
    cout << "    9.) Quit" << endl;
    
    int options;
    do
    {
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: cout << "test" << endl;
                   break;
            case 2: cout << "test2" << endl;
                   break;
            case 3: cout << "test3" << endl;
                   break;
            case 4: cout << "test4" << endl;
                   break;     
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

void memberMenu()
{
    makePartition();
    cout << setw(50) << "Country Club Facilities Booking System" << endl;
    cout << setw(46) << "+++++++  Member's Menu  +++++++" << endl;
    makePartition();
    cout << "    1.) Update Particulars" << endl;
    cout << "    2.) Upgrade Ranking" << endl;
    cout << "    3.) Search Portal Sub-system" << endl;
    cout << "    4.) View Bookings" << endl;
    cout << "    5.) Delete Booking" << endl;
    cout << "    6.) Booking Preferences" << endl;
    cout << "    7.) Help" << endl;
    cout << "    9.) Quit" << endl;
    
    int options;
    do
    {
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: cout << "test" << endl;
                   break;
            case 2: cout << "test2" << endl;
                   break;
            case 3: cout << "test3" << endl;
                   break;
            case 4: cout << "test4" << endl;
                   break;
            case 5: cout << "test5" << endl;
                   break;   
            case 6: cout << "test4" << endl;
                   break;
            case 7: cout << "test5" << endl;
                   break; 
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}