/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MemberProfile.cpp
 * Author: reuben
 * 
 * Created on 19 February, 2016, 10:30 PM
 */

#include "MemberProfile.h"
#include "User.h"

MemberProfile::MemberProfile()
{
}

MemberProfile::MemberProfile(const MemberProfile& orig)
{
}

MemberProfile::~MemberProfile()
{
}

void MemberProfile::memberToArray()
{
    fstream afile;
    afile.open("memberDB.txt",ios::in);
    
    if (!afile)
    {
        cout << "MemberDB Opened for reading fail" << endl;
    }
    
    int tempSize = 0;
    char rubbish;

    while (afile >> memProfile[tempSize].username)
    {
        afile.get(rubbish);
        
        getline(afile,memProfile[tempSize].name);
        getline(afile,memProfile[tempSize].nric);
        //dd-mm-yyyy
        
        afile >> memProfile[tempSize].dob.day;
        afile.get(rubbish);
        afile >> memProfile[tempSize].dob.month;
        afile.get(rubbish);
        afile >> memProfile[tempSize].dob.year;
        afile.get(rubbish);
        afile >> memProfile[tempSize].gender;
        afile.get(rubbish);
        getline(afile,memProfile[tempSize].address);
        getline(afile,memProfile[tempSize].bookingPreference);
        afile >> memProfile[tempSize].notification; 
        afile.clear ();
	afile.ignore (MAX, '\n');
        tempSize++;
    }
    
    this -> totalMember = tempSize;
}

int MemberProfile::index(string tempUser)
{
    memberToArray();
    for (int i = 0; i < this -> totalMember; i++)
    {
        if (tempUser == memProfile[i].username)
        {
            return i;
        }
    }
}

void MemberProfile::displayParticulars(string tempUser)
{
    int location = index(tempUser);
    
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Showing profile..." << endl;
    cout << "------------------------------------------------------" << endl;
   
    cout << setw(25) << left << "Username: " << memProfile[location].username << endl;
    
    cout << setw(25) << left << "Name: " << memProfile[location].name << endl;
    cout << setw(25) << left << "Nric: " << memProfile[location].nric << endl;
    if (memProfile[location].dob.day < 10)
    {
        if (memProfile[location].dob.month < 10)
        {
            if (memProfile[location].dob.year == 0)
            {
                cout << setw(25) << left << "Date of birth: " << "Not applicable" << endl;
            }
            else
            {
                cout << setw(25) << left << "Date of birth: " << "0" << memProfile[location].dob.day 
                     << "/0" << memProfile[location].dob.month 
                     << "/" << memProfile[location].dob.year << endl;
            }
        }
        else
        {
            cout << setw(25) << left << "Date of birth: " << "0" << memProfile[location].dob.day 
                 << "/" << memProfile[location].dob.month 
                 << "/" << memProfile[location].dob.year << endl;
        }
    }
    else
    {
        cout << setw(25) << left << "Date of birth: " << memProfile[location].dob.day 
             << "/" << memProfile[location].dob.month 
             << "/" << memProfile[location].dob.year << endl;
    }
    if (memProfile[location].gender == 'm')
    {
        cout << setw(25) << left << "Gender: " << "Male" << endl;
    }
    else if (memProfile[location].gender == 'f')
    {
        cout << setw(25) << left << "Gender: " << "Female" << endl;
    }
    else
    {
        cout << setw(25) << left << "Gender: " << "Not applicable" << endl;
    }
    cout << setw(25) << left << "Address: " << memProfile[location].address << endl;
    cout << setw(25) << left << "Booking preference: " << memProfile[location].bookingPreference << endl;
    if (memProfile[location].notification == 0)
    {
        cout << setw(25) << left << "Want notification?: " <<  "No" << endl;
    }
    else
    {
        cout << setw(25) << left << "Want notification?: " <<  "Yes" << endl;
    }
    cout << endl;
}

void MemberProfile::updateParticularsMenu(string& tempUser)
{
    int options;
    int location = index(tempUser);
    do
    {
        cout << "--------------------------------------------------" << endl;
        cout << "Which particulars do you want to update/amend?" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << endl;
        cout << "     1) Update username" << endl;
        cout << "     2) Update password" << endl;
        cout << "     3) Update name" << endl;
        cout << "     4) Update nric" << endl;
        cout << "     5) Update date of birth" << endl;
        cout << "     6) Update gender " << endl;
        cout << "     7) Update address" << endl;
        cout << "     8) Update booking preference" << endl;
        cout << "     9) Want notification?" << endl;
        cout << "     10) Back to main menu" << endl;
        cout << endl;
        cout << "Options: ";
        cin >> options;
        cin.clear();
        cin.ignore(300,'\n');
        cout << endl;
        switch (options)
        {
            case 1: updateUsername(location, tempUser);
                    break;
            case 2: updatePassword(location);
                    break;    
            case 3: updateName(location);
                    break;    
            case 4: updateNric(location);
                    break;    
            case 5: updateDOB(location);
                    break;  
            case 6: updateGender(location);
                    break;    
            case 7: updateAddress(location);
                    break;    
            case 8: cout << "To be updated" << endl;;
                    break;    
            case 9: wantNotification(location);
                    break;    
            default: cout << "Please enter a valid option" << endl;                                                                  
        }
    } while (options != 10);
}

void MemberProfile::updateMemberDB()
{
    fstream afile;
    afile.open("memberDB.txt",ios::out);
    
    if (!afile)
    {
        cout << "MemberDB Opened for writing fail" << endl;
    }
    
    for (int i = 0; i < this -> totalMember; i++)
    {
        afile << memProfile[i].username << endl;
        afile << memProfile[i].name << endl;
        afile << memProfile[i].nric << endl;
        //dd-mm-yyyy
        afile << memProfile[i].dob.day << '-'
              << memProfile[i].dob.month << '-'
              << memProfile[i].dob.year << endl;
        afile << memProfile[i].gender << endl;
        afile << memProfile[i].address << endl;
        afile << memProfile[i].bookingPreference << endl;
        if (memProfile[i].notification == 0)
        {
            afile << "no" << endl;
        }
        else
        {
            afile << "yes" << endl;
        }
        afile << endl;
    }
    
    afile.close();
}

void MemberProfile::updateUsername(int location, string& tempUser)
{
    bool flag;
    do
    {
        flag = false;
        if (tempUser.length() < 6)
        {
            cout << endl;
            cout << "Error! Username needs to be at least 6 character long. " << endl;
            cout << endl;
        }
        cout << "Please enter a new username" << endl;
        cin >> tempUser;
        cin.clear();
        cin.ignore(300,'\n');
        for (int i = 0; i < this -> totalMember; i++)
        {
            if (tempUser == memProfile[i].username)
            {
                cout << endl;
                cout << "Error! Username taken, please enter a different username" << endl;
                cout << endl;
                flag = true;
            }
        }
    }while (tempUser.empty() || tempUser.length() < 6 || flag == true);
    
    change(1, memProfile[location].username, tempUser);
    memProfile[location].username = tempUser;
    updateMemberDB();
    
    cout << endl;
    cout << "Username updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
    
}

void MemberProfile::updatePassword(int location)
{
    string tempPassword = memProfile[location].username;
    do
    {
        if (tempPassword.length() < 6)
        {
            cout << endl;
            cout << "Error! Password needs to be at least 6 character long. " << endl;
            cout << endl;
        }
        cout << "Please enter a new password" << endl;
        cin >> tempPassword;
        cin.clear();
        cin.ignore(300,'\n');
        
    }while (tempPassword.empty() || tempPassword.length() < 6);
    
    change(2, memProfile[location].username, tempPassword);
    
    cout << endl;
    cout << "Password updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

void MemberProfile::updateName(int location)
{
    string tempName = memProfile[location].name;
    do
    {
        cout << "Please enter your new name" << endl;
        getline(cin,tempName);
    }while (tempName.empty());
    
    memProfile[location].name = tempName;
    updateMemberDB();
    
    cout << endl;
    cout << "Name updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

void MemberProfile::updateNric(int location)
{
    string tempNric = "123456789";
    bool flag;
    do
    {
        flag = false;
        if (tempNric.length() != 9)
        {
            cout << endl;
            cout << "Error! NRIC needs to be 9 character long. " << endl;
            cout << endl;
        }
        cout << "Please enter your new NRIC" << endl;
        cin >> tempNric;
        cin.clear();
        cin.ignore(300,'\n');
        for (int i = 0; i < this -> totalMember; i++)
        {
            if (tempNric == memProfile[i].nric)
            {
                cout << endl;
                cout << "Error! please enter YOUR unique NRIC" << endl;
                cout << endl;
                flag = true;
            }
        }
    }while (tempNric.empty() || tempNric.length() != 9 || flag == true);

    memProfile[location].nric = tempNric;
    updateMemberDB();
    
    cout << endl;
    cout << "NRIC updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

void MemberProfile::updateDOB(int location)
{
    int tempDay = memProfile[location].dob.day;
    int tempMonth = memProfile[location].dob.month;
    int tempYear = memProfile[location].dob.year;
    
    bool flag = false;
    
    do
    {
        if (flag == true)
        {
            cout << endl;
            cout << "Error! Please enter a valid day 1 - 30" << endl;
            cout << endl;
        }
        cout << "Please enter new Day" << endl;
        cin >> tempDay;
        cin.clear();
        cin.ignore(300,'\n');
        flag = true;
    }while(cin.fail() || tempDay < 1 || tempDay > 31);
        
    flag = false;
        
    do
    {
        if (flag == true)
        {
            cout << endl;
            cout << "Error! Please enter a valid month 1 - 12" << endl;
            cout << endl;
        }
        cout << "Please enter new Month" << endl;
        cin >> tempMonth;
        cin.clear();
        cin.ignore(300,'\n');
        flag = true;
    }while(cin.fail() || tempMonth < 1 || tempMonth > 12);
        
    flag = false;
        
    do
    {
        if (flag == true)
        {
            cout << endl;
            cout << "Error! Please enter a valid year 'yyyy'" << endl;
            cout << endl;
        }
        cout << "Please enter new Year" << endl;
        cin >> tempYear;
        cin.clear();
        cin.ignore(300,'\n');
        flag = true;
    }while(cin.fail() || tempYear < 1000 || tempYear > 9999);
       
    flag = false;
    memProfile[location].dob.day = tempDay;
    memProfile[location].dob.month = tempMonth;
    memProfile[location].dob.year = tempYear;
    updateMemberDB();
    
    cout << endl;
    cout << "DOB updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

void MemberProfile::updateGender(int location)
{
    char tempGender = memProfile[location].gender;
    bool flag = false;
    do
    {
        if (flag == true)
        {
            cout << "Please enter either m/f" << endl;
        }
        
        cout << "Please enter your new gender (m/f)" << endl;
        cin.get(tempGender);
        cin.clear();
        cin.ignore(300,'\n');
        flag = true;
    }while (tempGender != 'm' && tempGender != 'f');
    
    memProfile[location].gender = tempGender;
    updateMemberDB();
    
    cout << endl;
    cout << "Gender updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

void MemberProfile::updateAddress(int location)
{
    string tempAddress = memProfile[location].address;

    do
    {
        cout << "Please enter your new address" << endl;
        getline(cin,tempAddress);
        
    }while (tempAddress.empty());

    memProfile[location].address = tempAddress;
    updateMemberDB();
    
    cout << endl;
    cout << "Address updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

/* to be updated 
void MemberProfile::updateBookingPreference(int location)
{
    string tempAddress = memProfile[location].address;

    do
    {
        cout << "Please enter your new address" << endl;
        getline(cin,tempAddress);
        
    }while (tempAddress.empty());

    memProfile[location].address = tempAddress;
    updateMemberDB();
    
    cout << endl;
    cout << "Address updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}*/

void MemberProfile::wantNotification(int location)
{
    string tempAddress = memProfile[location].address;
    char input;
    do
    {
        cout << "Would you like to receive notifications? (yY/nN)" << endl;
        cin.get(input);
        cin.clear();
        cin.ignore(300,'\n');
    }while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');

    if (input == 'y' || input == 'Y')
    {
        memProfile[location].notification = true;
    }
    else 
    {
        memProfile[location].notification = false;
    }

    updateMemberDB();
    
    cout << endl;
    cout << "Notification status updated. " << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore(300,'\n');
}

int MemberProfile::getLastIndexDate (string tempUser)
{
    int location = index(tempUser);
    
    int i = 0;
    while (memProfile[location].bookedDates[i].month != 0)
    {
        i++;
    }
    return i-1;
}

int MemberProfile::getLastIndexBookedFacilites (string tempUser)
{
    int location = index(tempUser);
    
    int i = 0;
    while (memProfile[location].bookedFacility[i].name != "")
    {
        i++;
    }
    return i-1;
}

int MemberProfile::getLastIndexTimeslot (string tempUser)
{
    int location = index(tempUser);
    
    int i = 0;
    bool check;
    while (check)
    {
        for (int j = 0; j < 10; j++)
        {
            if(memProfile[location].bookedFacility[i].timeslot[j] != 0)
                check = false;
        }
        i++;
    }
    return i-1;
}
