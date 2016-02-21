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
#include <iomanip>
#include <cstdlib>
#include "Facilities.h"
#include "Booking.h"

using namespace std;
class MemberProfile: public User
{   
    public:
        friend class Booking;
        MemberProfile();
        MemberProfile(const MemberProfile& orig);
        virtual ~MemberProfile();    
        
        int index(string);
        void memberToArray();
        void displayParticulars(string);
        void updateParticulars(string); //takes in unique NRIC 
        void upgradeRanking();
        void accessSearchPortal();
        void amendBooking();
        int getLastIndexDate (string);
        int getLastIndexBookedFacilites (string);
        int getLastIndexTimeslot (string);

    protected:
        int totalMember;
        
        //dd-mm-yyyy
        struct Date
        {
            int day;
            int month;
            int year;
        };
        
        struct Profile
        {
            string username;
            string name;
            string nric;
            Date dob;
            char gender; // m or f
            string address;
            string bookingPreference;
            bool notification;
            Facilities bookedFacility[10];
            Date bookedDates[10];
        }memProfile[MAX];
};

#endif /* MEMBERPROFILE_H */

