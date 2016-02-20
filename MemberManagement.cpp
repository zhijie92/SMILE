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

int MemberManagement::addUser(string username, string password, int role)
{
    fstream outfile;
    outfile.open("userDB.txt",ios::out | ios::app);   
    
    if (!outfile)
    {
        cout << "userDB.txt opened for reading failed" << endl;
        return -1;
    }
    
    int size=0;
    char rubbish;
    
    outfile << role << ','
            << username << ','
            << password
            << endl;
    
    outfile.close();
    
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
        cout << endl;
        cout << "Role: Club member" << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << endl;
        cout << "...added succesfully..." << endl;
        cout << endl;
    }
    return 0;
}

int MemberManagement::removeUser(string, string)
{
//    Authentication a;
//    int flag = a.verify(username, password);
}
