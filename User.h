/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   User.h
 * Author: reuben
 *
 * Created on 20 February, 2016, 4:29 PM
 */

#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>

const int MAX = 500;
using namespace std;

class User 
{
    friend class Authentication;
    public:
        User();
        User(const User& orig);
        virtual ~User();
        int storeData();
        int accessData(string);
        
    private:
            
    protected:
       int size;
       struct UserDB //store all the role, user and pass from the DB
       {
            int role; //1 for club manager - 2 for club member
            string user;
            string pass;         
       } access[MAX];
};

#endif /* USER_H */

