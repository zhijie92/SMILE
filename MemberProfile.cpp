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
    
    int size = 0;
    char rubbish;
    
    while (afile >> memProfile[size].username)
    {
        afile.get(rubbish);
        getline(afile,memProfile[size].name);
        getline(afile,memProfile[size].nric);
        //dd-mm-yyyy
        afile >> memProfile[size].dob.day;
        afile.get(rubbish);
        afile >> memProfile[size].dob.month;
        afile.get(rubbish);
        afile >> memProfile[size].dob.year;
        afile.get(rubbish);
        getline(afile,memProfile[size].address);
        getline(afile,memProfile[size].bookingPreference);
        afile >> memProfile[size].notification;
        afile.get(rubbish);
        afile.get(rubbish);
    
        size++;
    }
    
    cout << memProfile[0].name << endl;
     cout << setw(25) << left << "Username: " << memProfile[1].username << endl;
    
    cout << setw(25) << left << "Name: " << memProfile[1].name << endl;
    cout << setw(25) << left << "Nric: " << memProfile[1].nric << endl;
    cout << setw(25) << left << "Date of birth: " << memProfile[1].dob.day 
                             << "/" << memProfile[1].dob.month 
                             << "/" << memProfile[1].dob.year << endl;
    cout << setw(25) << left << "Address: " << memProfile[1].address << endl;
    cout << setw(25) << left << "Booking preference: " << memProfile[1].bookingPreference << endl;
    cout << setw(25) << left << "Want notification?: " <<  memProfile[1].notification << endl;
    afile.close();
    this -> totalMember = size+1;
    
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
    cout << setw(25) << left << "Date of birth: " << memProfile[location].dob.day 
                             << "/" << memProfile[location].dob.month 
                             << "/" << memProfile[location].dob.year << endl;
    cout << setw(25) << left << "Address: " << memProfile[location].address << endl;
    cout << setw(25) << left << "Booking preference: " << memProfile[location].bookingPreference << endl;
    cout << setw(25) << left << "Want notification?: " <<  memProfile[location].notification << endl;
    cout << endl;
}