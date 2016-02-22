/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MemberManagement.h
 * Author: reuben
 *
 * Created on 19 February, 2016, 4:41 PM
 */

#ifndef MEMBERMANAGEMENT_H
#define MEMBERMANAGEMENT_H
#include "MemberProfile.h"
#include "Facilities.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class MemberManagement: public MemberProfile 
{
    
    public:
        MemberManagement();
        MemberManagement(const MemberManagement& orig);
        virtual ~MemberManagement();
        string getUser();
        string getPassword();
        int getRole();
        void setUser(string);
        void setPassword(string);
        void setRole(int);
        
        void addUser(string, string, int);
        void removeUser(string);
        void listMembers();
        void listManagers();
        
    private:
        string username;
        string password;
        int role;
};

#endif /* MEMBERMANAGEMENT_H */

