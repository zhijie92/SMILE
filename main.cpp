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
#include "MemberManagement.h"
#include "Facilities.h"
#include "FacilitiesManagement.h" 
#include "User.h"
#include "MemberProfile.h"
#include "Booking.h"

Authentication authenticate;
MemberManagement memManage;
FacilitiesManagement facManage;
Booking booking;
User u;

MemberProfile memProf;
int main()
{
    mainMenu();
}

void makePartition()
{
    cout << "----------------------------------------------------------------";
    cout << endl;
}

void pressEnter()
{
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
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
        case 1: clubManagerMenu(username);
                break;
        case 2: memberMenu(username);
                break;
        default: cout << "Error" << endl;
    }
}
void clubManagerMenu(string username)
{   
    int options;
    do
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
       
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: facilitiesManagement();
                   break;
            case 2: memberManagement(username);
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

void memberMenu(string username)
{   
    int options;
    do
    {
        memProf.storeIndex(username);
        makePartition();
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(46) << "+++++++  Member's Menu  +++++++" << endl;
        makePartition();
        cout << "    1.) View profile" << endl;
        cout << "    2.) Update Particulars" << endl;
        cout << "    3.) Upgrade Ranking" << endl;
        cout << "    4.) Search Portal Sub-system" << endl;
        cout << "    5.) Bookings Menu" << endl;
        cout << "    6.) Help" << endl;
        cout << "    9.) Quit" << endl;
        
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: memProf.displayParticulars(username);
                    pressEnter();
                    break;
            case 2: memProf.updateParticularsMenu(username);
                    break;
            case 3: memProf.upgradeRanking(username);
                    break;
            case 4: cout << "test4" << endl;
                   break;
            case 5: bookingMenu(username);
                   break;   
            case 6: helpMenu(username);
                   break; 
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

/*--------------------------------------------------------------------------------*/
// CLUB MANAGER FUNCTIONS
/*--------------------------------------------------------------------------------*/

void facilitiesManagement()
{
    int options;
    do
    {
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(49) << "++ Facilities Management Sub-system ++" << endl;   
        makePartition();
        cout << "    1.) Add facilities" << endl;
        cout << "    2.) Delete facilities" << endl;
        cout << "    3.) Update facilities" << endl;
        cout << "    4.) View facilities" << endl;
        cout << "    9.) Back to main menu" << endl;

        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        string name, description, new_name;
        double rates;
        int check;
        switch (options)
        {
            case 1: cout << "Facility Name: ";
                    getline (cin, name);
                    cout << "Facility Description: ";
                    getline (cin, description);
                    cout << "Facility Rates: $";
                    cin >> rates;
                    cin.clear();
                    cin.ignore(300,'\n');
                    check = facManage.addFacility(name, description, rates);
                    if (check == -1)
                    {
                        cout << name << " already exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 2: cout << "Facility Name: ";
                    getline (cin, name);
                    check = facManage.removeFacility(name);
                    if (check == -1)
                    {
                        cout << name << " does not exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 3: updateFacilitiesMenu ();
                   break;
            case 4: facManage.printAllFacilities();
                    pressEnter();
                   break;     
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

void updateFacilitiesMenu ()
{
    int options, check;
    string name, new_name, description;
    double rates;
    
    do
    {
        makePartition();
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(46) << "+++++++  Update Facilities Menu  +++++++" << endl;
        makePartition();
        cout << "    1.) Update Facilities Name" << endl;
        cout << "    2.) Update Facilities Description" << endl;
        cout << "    3.) Update Facilities Rates" << endl;
        cout << "    9.) Quit" << endl;
        
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        { 
            case 1: cout << "Facility Name: ";
                    getline (cin, name);
                    cout << "New Facility name: ";
                    getline (cin, new_name);
                    check = facManage.editFacility(1, name, new_name, description, rates);
                    if (check == -1)
                    {
                        cout << name << " does not exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 2: cout << "Facility Name: ";
                    getline (cin, name);
                    cout << "new Facility Description: ";
                    getline (cin, description);
                    check = facManage.editFacility(2, name, new_name, description, rates);
                    if (check == -1)
                    {
                        cout << name << " does not exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 3: cout << "Facility Name: ";
                    getline (cin, name);
                    cout << "new Facility rates: $";
                    cin >> rates;
                    cin.clear();
                    cin.ignore(300,'\n');
                    check = facManage.editFacility(3, name, new_name, description, rates);
                    if (check == -1)
                    {
                        cout << name << " does not exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

void memberManagement(string username)
{
    memProf.storeIndex(username);
    int options;
    string newUser="123456";
    string newPassword;
    int newRole;
    int isExist;
    bool check = false;
    
    do
    {
        isExist = 0;
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(49) << "++++ Member Management Sub-system ++++" << endl;   
        makePartition();
        cout << "    1.) Add member" << endl;
        cout << "    2.) Delete member" << endl;
        cout << "    3.) List all Club Member" << endl;
        cout << "    4.) List all Club Manager" << endl;
        cout << "    9.) Back to main menu" << endl;

        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        {
            case 1: do
                    {
                        newPassword = "";
                        
                        if (newUser.length() < 6)
                        {
                            cout << endl;
                            cout << "Error! Username needs to be at least 6 character long. " << endl;
                            cout << endl;
                        }
                        
                        if (isExist == -2)
                        {
                            cout << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Username: " << newUser << " already exists. " << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << endl;
                        }
                        
                        do
                        {
                            cout << "Username: ";
                            cin >> newUser;
                        }while (newUser.empty());
                        
                        // check for existing username
                        isExist = authenticate.verify(newUser, newPassword);
                    } while (isExist == -2 || newUser.length() < 6);
                    
                    newPassword="123456";
                    do
                    {
                        if (newPassword.length() < 6)
                        {
                            cout << endl;
                            cout << "Error! Password needs to be at least 6 character long. " << endl;
                            cout << endl;
                        }
                        
                        cout << "Password: ";
                        cin >> newPassword;
                    }while (newPassword.empty() || newPassword.length() < 6);
                    
                    do
                    {
                        cout << endl;
                        cout << "For club manager account type, key in 1" << endl;
                        cout << "For club member account type, key in 2" << endl;
                        cout << "Role: ";
                        cin >> newRole;
                        cin.clear();
                        cin.ignore(300,'\n');
                    }while (newRole != 1 && newRole != 2);
                    
                    memManage.addUser(newUser, newPassword, newRole);
                    pressEnter();
                   break;
            case 2: check = false;
                    do
                    {
                        newPassword = "";
                        
                        if (isExist != -2 && check == true)
                        {
                            cout << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Username: " << newUser << " does not exists. " << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << endl;              
                        }
                      
                        do
                        {  
                            cout << "Username: ";
                            cin >> newUser;
                            cin.clear();
                            cin.ignore(300,'\n');
                        }while (newUser.empty());
                        
                        // check for existing username
                        isExist = authenticate.verify(newUser, newPassword);
                        if (newUser == username)
                        {
                            cout << endl;
                            cout << "Error! cannot delete account: " << newUser << "!" << endl;
                            cout << "Account currently logged in!" << endl;
                            isExist = 0;
                        }
                        check = true;
                    } while (isExist != -2 || newUser.length() < 6);
                    
                    memManage.removeUser(newUser);
                    pressEnter();
                    break;
            case 3: memManage.listMembers();
                    pressEnter();
                    break;
            case 4: memManage.listManagers();
                    pressEnter();
                    break;     
            case 9:
                    break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

/*--------------------------------------------------------------------------------*/
// CLUB MEMBER FUNCTIONS
/*--------------------------------------------------------------------------------*/

void viewProfile(string username)
{
    memProf.displayParticulars(username);
    pressEnter();
}

void bookingMenu(string username)
{   
    string name;
    int options, month, day, check, timeslot;
    do
    {
        makePartition();
        cout << setw(50) << "Country Club Facilities Booking System" << endl;
        cout << setw(46) << "+++++++  Booking Menu  +++++++" << endl;
        makePartition();
        cout << "    1.) Make Booking" << endl;
        cout << "    2.) View Booking" << endl;
        cout << "    3.) Cancel Booking" << endl;
        cout << "    9.) Quit" << endl;
        
        cout << "Option :";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        switch (options)
        { 
            case 1: cout << "Facility Name: ";
                    getline (cin, name);
                    cout << "Day (e.g. 8 for 8th): ";
                    cin >> day;
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Month (e.g. 12 for December): ";
                    cin >> month;
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "1.) 10am to 11am | 2.) 11am to 12pm | 3.) 12pm to 1pm | 4.) 1pm to 2pm | 5.) 2pm to 3pm" << endl;
                    cout << "6.) 3pm to 4pm   | 7.) 4pm to 5pm   | 8.) 5pm to 6pm  | 9.) 6pm to 7pm | 10.) 7pm to 8pm" << endl;
                    cout << "Time slot (e.g. 5 for 2pm to 3pm): ";
                    cin >> timeslot;
                    cin.clear();
                    cin.ignore(100, '\n');
                    check = booking.newBooking(name, month, day, username, timeslot);
                    pressEnter();
                    if (check == -1)
                    {
                        cout << name << " on " << day << "/" << month << " at Time slot " << timeslot << " has already been booked!" << endl;
                        pressEnter();
                    }
                    else if (check == -2)
                    {
                        cout << name << " does not exist!" << endl;
                        pressEnter();
                    }    
                   break;
            case 2: booking.viewBooking(username);
                   break;
            case 3: cout << "Facility Name: ";
                    getline (cin, name);
                    cout << "Day (e.g. 8 for 8th): ";
                    cin >> day;
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Month (e.g. 12 for December): ";
                    cin >> month;
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "1.) 10am to 11am | 2.) 11am to 12pm | 3.) 12pm to 1pm | 4.) 1pm to 2pm | 5.) 2pm to 3pm" << endl;
                    cout << "6.) 3pm to 4pm   | 7.) 4pm to 5pm   | 8.) 5pm to 6pm  | 9.) 6pm to 7pm | 10.) 7pm to 8pm" << endl;
                    cout << "Time slot (e.g. 5 for 2pm to 3pm): ";
                    cin >> timeslot;
                    cin.clear();
                    cin.ignore(100, '\n');
                    check = booking.cancelBooking(name, month, day, username, timeslot);
                    pressEnter();
                    if (check == -1)
                    {
                        cout << "You have not booked " << name << " on " << day << "/" << month << " at Time slot " << timeslot << "!" << endl;
                        pressEnter();
                    }
                    else if (check == -2)
                    {
                        cout << name << " does not exist!" << endl;
                        pressEnter();
                    }
                   break;
            case 9:
                   break;
            default: cout << "Please enter a valid option" << endl;
        }
    }while (options != 9);
}

void helpMenu(string username)
{
   
    int options;
    do
    {
        makePartition();
        cout << "Welcome to the CCFBS Help System." << endl;
        cout << "    1) Need help regarding member profile/membership ranking" << endl;
        cout << "    2) Need help regarding booking of facility" << endl;
        cout << "    9) Back to main menu" << endl;
        makePartition();

        cout << "Option: ";
        cin >> options;

        switch (options)
        {
            case 1: memberProfRankHelp(username);
                   break;
             case 2:
                    break;
             case 9:
                    break;
            default: cout << "Please enter a valid option. " << endl;
        }
    }while (options != 9);
}

void memberProfRankHelp(string username)
{
    cout << "--------------------------------------------" << endl;
    cout << "Member profile/ membership ranking Help page" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  a) Display membership rankings. " << endl;
    cout << "  b) How to upgrade my membership? " << endl;
    cout << "  c) How to view my profile? " << endl;
    cout << "  d) How to change my profile particulars? " << endl;
}
