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
        afile.clear();
        afile.ignore(300,'\n');
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
    int location = index(username);
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
                int index1 = getLastIndexBookedFacilites(username);
                //int index2 = mp.getLastIndexDate(username);
                //int index3 = mp.getLastIndexTimeslot (username);
                
                memProfile[location].bookedFacility[index1+1].name = fac_name;
                memProfile[location].bookedFacility[index1+1].description = bookingdates[i].facility.description;
                memProfile[location].bookedFacility[index1+1].rates = bookingdates[i].facility.rates;
                //mp.memProfile[location].bookedFacility[index1+1].timeslot[0][0][index3+1] = 1;
                memProfile[location].bookedFacility[index1+1].timeslot[month-1][day-1][timeslot-1] = 1;
                //mp.memProfile[location].bookedDates[index2+1].day = day;
                //mp.memProfile[location].bookedDates[index2+1].month = month;
                
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
                updateMemberDB();
                return 0;
            }
        }
    }
}

int Booking::viewBooking(string username)
{
    int location = index(username);
    int lastIndex = getLastIndexBookedFacilites(username);
    int m = 0;
    int d = 0;
    int t = 0;
    for (int i = 0; i < lastIndex; i++)
    {
        cout << "Facility Name: " << memProfile[location].bookedFacility[i].name << endl;
        //mp.memProfile[location].bookedFacility[i].description;
        //mp.memProfile[location].bookedFacility[i].rates;
        for (m = 0; m < 12; m++)
        {
            for (d = 0; d < 31; d++)
            {
                for (t = 0; t < 10; t++)
                {
                    if (memProfile[location].bookedFacility[i].timeslot[m][d][t] == 1)
                    {
                        switch (t)
                        {
                            case 0 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 10am to 11am" << endl;
                            break;
                            case 1 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 11am to 12pm" << endl;
                            break;
                            case 2 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 12am to 1pm" << endl;
                            break;
                            case 3 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 1pm to 2pm" << endl;
                            break;
                            case 4 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 2pm to 3pm" << endl;
                            break;
                            case 5 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 3pm to 4pm" << endl;
                            break;
                            case 6 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 4pm to 5pm" << endl;
                            break;
                            case 7 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 5pm to 6pm" << endl;
                            break;
                            case 8 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 6pm to 7pm" << endl;
                            break;
                            case 9 : cout << "Date: " << d+1 << "/" << m+1 << endl;
                                     cout << "Timeslot: 7pm to 8pm" << endl;
                            break;
                        }
                    }
                        
                }
            }
        }
    }
}