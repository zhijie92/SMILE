/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Booking.cpp
 * Author: Amos
 * 
 * Created on 21 February, 2016, 1:42 AM
 */

#include "Booking.h"

FacilitiesManagement fac;
MemberProfile mp;
int s = 0;

Booking::Booking()
{
    fileToArray ();
}

Booking::Booking(const Booking& orig)
{
}

Booking::~Booking()
{
}

void Booking::fileToArray ()
{
    s = 0;
    char rubbish;
    fstream afile;
    afile.open ("BookingDatesDB.txt", ios::in);
    
    while (getline(afile, bookingdates[s].facility.name, ','))
    {
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                afile >> bookingdates[s].dates[i][j];
                afile.get (rubbish);
                for (int k = 0; k < 10; k++)
                {
                    afile >> bookingdates[s].facility.timeslot[i][j][k];
                    afile.get(rubbish);
                }
            }
        }
        s++;
    }
    afile.close();
}

int Booking::checkExists (string fac_name)
{
    for (int i=0; i < s; i++)
    {
        if (bookingdates[i].facility.name == fac_name)
        {
            return 1;
        }
    }
    return 0;
}

void Booking::populate (string fac_name)
{
    fstream outfile;
    outfile.open("BookingDatesDB.txt",ios::out | ios::app);
    
    outfile << fac_name << ",";
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            outfile << "0" << "-";
            for (int k = 0; k < 10; k++)
            {
                outfile << "0" << "|";
            }
        }           
    }
    outfile << endl;   
    outfile.close();
  
    bookingdates[s].facility.name = fac_name; 
    for (int k = 0; k < 12; k++)
    {
        for (int m = 0; m < 31; m++)
        {
            bookingdates[s].dates[k][m] = 0;
            for (int j = 0; j < 10; j++)
                {
                    bookingdates[s].facility.timeslot[k][m][j] = 0;
                }
        }
    }
    s++;
}

int Booking::checkAlreadyBooked (string fac_name, int month, int day, int timeslot)
{
    for (int i=0; i < s; i++)
    {
        if (bookingdates[i].facility.name == fac_name)
        {
            if ((bookingdates[i].dates[month-1][day-1] == 1) && 
                (bookingdates[i].facility.timeslot[month-1][day-1][timeslot-1] == 1))
                return 1;
            else
                return 0;
        }
    }
}

int Booking::newBooking(string fac_name, int month, int day, string username, int timeslot)
{
    int check = fac.checkExists (fac_name);
    int check2 = checkExists (fac_name);
    
    if (check == 0)
        return -2;
    
    if (check2 == 0)
    {
        populate (fac_name);
    }
    int check3 = checkAlreadyBooked (fac_name, month, day, timeslot);
    if (check3 == 1)
        return -1;
    int location = mp.index(username);
    if (check == 1 && check3 == 0)
    {
        fstream outfile;
        outfile.open("BookingDatesDB.txt",ios::out | ios::trunc);

        for (int i=0; i < s; i++)
        {
            if (bookingdates[i].facility.name == fac_name)
            {
                bookingdates[i].dates[month-1][day-1] = 1;
                bookingdates[i].facility.timeslot[month-1][day-1][timeslot-1] = 1;
                int index1 = mp.getLastIndexBookedFacilites(username);
                int index2 = mp.getLastIndexDate(username);
                int index3 = mp.getLastIndexTimeslot (username);
                
                mp.memProfile[location].bookedFacility[index1+1].name = fac_name;
                mp.memProfile[location].bookedFacility[index1+1].description = bookingdates[i].facility.description;
                mp.memProfile[location].bookedFacility[index1+1].rates = bookingdates[i].facility.rates;
                mp.memProfile[location].bookedFacility[index1+1].timeslot[0][0][index3+1] = 1;
                mp.memProfile[location].bookedDates[index2+1].day = day;
                mp.memProfile[location].bookedDates[index2+1].month = month;
                
                for (int j=0; j < s; j++)
                {
                    outfile << bookingdates[j].facility.name << ","; 
                     for (int k = 0; k < 12; k++)
                     {
                         for (int m = 0; m < 31; m++)
                         {
                             outfile << bookingdates[j].dates[k][m] << "-";
                             for (int p = 0; p < 10; p++)
                            {
                                outfile << bookingdates[j].facility.timeslot[k][m][p] << "|";
                            }
                         }
                     }
                    outfile << endl;
                }
                
                outfile.close();
                return 0;
            }
        }
    }
}