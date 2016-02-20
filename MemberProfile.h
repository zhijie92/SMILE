/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MemberProfile.h
 * Author: reuben
 *
 * Created on 19 February, 2016, 10:30 PM
 */

#ifndef MEMBERPROFILE_H
#define MEMBERPROFILE_H

#include "User.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class MemberProfile: public User
{   
    public:
        MemberProfile();
        MemberProfile(const MemberProfile& orig);
        virtual ~MemberProfile();
       
        string getName();
        string getNric();
        char getGender();
        string getAddress();
        string getBookingPreference();
        bool getNotification();
        
        void setName(string);
        void setNric(string);
        void setGender(char);
        void setAddress(string);
        void setBookingPreference(string);
        void setNotification(bool);
        
        void displayParticulars(string);
        void updateParticulars(string); //takes in unique NRIC 
        void upgradeRanking();
        void accessSearchPortal();
        void amendBooking();

    protected:
        struct Date
        {
            int day;
            int month;
            int year;
        };
        string username;
        string name;
        string nric;
        Date dob;
        char gender; // m or f
        string address;
        string bookingPreference;
        bool notification;
};

#endif /* MEMBERPROFILE_H */

