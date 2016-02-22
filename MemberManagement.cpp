/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MemberManagement.cpp
 * Author: reuben
 * 
 * Created on 19 February, 2016, 4:41 PM
 */

#include "MemberManagement.h"

MemberManagement::MemberManagement()
{
    memberToArray();
}

MemberManagement::MemberManagement(const MemberManagement& orig)
{
}

MemberManagement::~MemberManagement()
{
}

string MemberManagement::getUser()
{
    return username;
}

string MemberManagement::getPassword()
{
    return password;
}

int MemberManagement::getRole()
{
    return role;
}
void MemberManagement::setUser(string username)
{
    username = username;
}
void MemberManagement::setPassword(string password)
{
    password = password;
}

void MemberManagement::setRole(int role)
{
    role = role;
}

void MemberManagement::addUser(string username, string password, int role)
{
    access[size].role = role;
    access[size].user = username;
    access[size].pass = password;
    size+=1;
    if (role == 1)
    {
        cout << endl;
        cout << "Role: Club manager" << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << endl;
        cout << "...added succesfully..." << endl;
        cout << endl;
    }
    else if (role == 2)
    {
        memProfile[totalMember].username = username;
        memProfile[totalMember].name = "Not applicable";
        memProfile[totalMember].nric = "Not applicable";
        memProfile[totalMember].dob.day = 0;
        memProfile[totalMember].dob.month = 0;
        memProfile[totalMember].dob.year = 0;
        memProfile[totalMember].gender = '-';
        memProfile[totalMember].address = "Not applicable";
        memProfile[totalMember].bookingPreference = "Not applicable";
        memProfile[totalMember].notification = 0;

        totalMember+=1;
        
        updateMemberDB();
         
        cout << endl;
        cout << "Role: Club member" << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << endl;
        cout << "...added succesfully..." << endl;
        cout << endl;
    }
    updateUserDB();
}

void MemberManagement::removeUser(string username)
{
    int index = accessData(username);
    int role = access[index].role;
    
    // 1 = club manager, 2 = club member
    if (role == 1)
    {
        for (int i = index; i < this -> size; i++)
        {
            access[i].role = access[i+1].role;
            access[i].user = access[i+1].user;
            access[i].pass = access[i+1].pass;
        }
        
        cout << "Club manager " << username << "'s account removed. " << endl;
        size-=1;
        updateUserDB(); // int in case 1 or 2,
    }
    else if (role == 2)
    {
        for (int i = index; i < this -> size; i++)
        {
            access[i].role = access[i+1].role;
            access[i].user = access[i+1].user;
            access[i].pass = access[i+1].pass;
        }
        size-=1;
        updateUserDB();
        
        for (int i = index; i < this -> totalMember; i++)
        {
            memProfile[i].username = memProfile[i+1].username;
            memProfile[i].name = memProfile[i+1].name;
            memProfile[i].nric = memProfile[i+1].nric;
            memProfile[i].dob.day = memProfile[i+1].dob.day;
            memProfile[i].dob.month = memProfile[i+1].dob.month;
            memProfile[i].dob.year = memProfile[i+1].dob.year;
            memProfile[i].gender = memProfile[i+1].gender;
            memProfile[i].address = memProfile[i+1].address;
            memProfile[i].bookingPreference = memProfile[i+1].bookingPreference;
            memProfile[i].notification =  memProfile[i+1].notification;
        }
        totalMember-=1;
        updateMemberDB();
        
        cout << "Club member " << username << "'s data removed. " << endl;
    }
}

void MemberManagement::listMembers()
{
    for (int i = 0; i < totalMember; i++)
    {
        cout << endl;
        cout << "Member " << i+1 << ") " << memProfile[i].username << endl;
        cout << endl;
    }
}

void MemberManagement::listManagers()
{
    int counter = 1;
    for (int i = 0; i < size; i++)
    {
        if (access[i].role == 1)
        {
            cout << endl;
            cout << "Manager " << counter << ") " << access[i].user << endl;
            cout << endl;
            counter++;
        }
    }
}