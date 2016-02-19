/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FacilitiesManagement.cpp
 * Author: Amos Laptop
 * 
 * Created on February 19, 2016, 4:56 PM
 */

#include "FacilitiesManagement.h"

FacilitiesManagement::FacilitiesManagement()
{
}

FacilitiesManagement::FacilitiesManagement(const FacilitiesManagement& orig)
{
}

FacilitiesManagement::~FacilitiesManagement()
{
}

void FacilitiesManagement::addRecord(string fac_name, string fac_desc)
{
    fstream outfile;
    outfile.open("facilitiesDB.txt",ios::out | ios::app);
    
    outfile << fac_name << "," << fac_desc << endl;
}
/*
void FacilitiesManagement::removeRecord(string facId)
{
    string sql = "Delete from OCCFBS.Facilities where facility_id='"+ facId + "'";

    dc.deleteRecord(sql, "Facility", true);

    sql = "Delete from OCCFBS.CheckAvailability where facility_id='"+ facId + "'";

    dc.deleteRecord(sql, "Related Available Booking", true);

    sql = "Delete from OCCFBS.Booking where facility_booked='"+ facId + "'";

    dc.deleteRecord(sql, "Related Confirmed Booking", true);
}

void FacilitiesManagement::editRecord(string facId, string fac_name, string fac_desc)
{
    string sql = "Update OCCFBS.Facilities set facility_name='"+ fac_name + "', facility_description='"+ fac_desc + "' where facility_id='"+ facId + "'";
    dc.updateRecord(sql, "Facility", true);
}

void FacilitiesManagement::addFacility()
{
    string facility_name, facility_desc;

    cout << "Please enter the facility name: ";
    cin >> facility_name;

    cout << "Please enter the facility description: ";
    cin >> facility_desc;

    fac.SetFacilityName(facility_name);
    fac.SetFacilityDescription(facility_desc);

    addRecord(fac.GetFacilityName(), fac.GetFacilityDescription());
}

void FacilitiesManagement::removeFacility()
{
    printAllRecords();
    string input, facId;

    cout << "Please enter the Facility ID to be removed: ";
    cin >> input;

    if(FacilityIDExists(input))
        removeRecord(input);

    else
        cout << "No such Facility ID" << endl;

}

void FacilitiesManagement::editFacility()
{
    printAllRecords();
    string input, facName, facDesc;

    cout << "Please enter the Facility ID to be edited: ";
    cin >> input;

    if(FacilityIDExists(input))
    {
        cout << "Please enter the facility name: ";
        cin >> facName;

        cout << "Please enter the facility description: ";
        cin >> facDesc;

        fac.SetFacilityName(facName);
        fac.SetFacilityDescription(facDesc);
        editRecord(input,fac.GetFacilityName(), fac.GetFacilityDescription());
    }
    else
        cout << "No such Facility ID" << endl;
}

void FacilitiesManagement::printAllRecords()
{
    system("clear");

    //Retrieve Statement
    string sql = "SELECT facility_id, facility_name, facility_description FROM OCCFBS.Facilities as f";

    dc.viewRecord(sql, "Facilities", "Facility ID", "Facility Name", "Facility Description","","","");
}

bool FacilitiesManagement::FacilityIDExists(string id)
{
    string sql = "Select count(*) from OCCFBS.Facilities where facility_Id='"+ id + "'";

    int count = dc.ConvertStringToInt(dc.getValue(sql));

    if(count != 0 )
        return true;

    else
        return false;
}

void FacilitiesManagement::printAllAvailableRecords()
{
    system("clear");

    //Retrieve Statement
    string sql = "SELECT checkavailability_id,facility_id, facility_name, facility_description, date, timeslot FROM OCCFBS.Facilities as f natural join OCCFBS.CheckAvailability";

    dc.viewRecord(sql, "Available Facilities", "Available ID", "Facility ID", "Facility Name", "Facility Description","Available Date","Available TimeSlot");
}

void FacilitiesManagement::printSummaryRecords()
{
    string sql = "select p.username, if(bookingid is not null, bookingid, '(No Bookings)') as bookingid, if(facility_name is not null, facility_name, '(No Bookings)') as facid, if(facility_date is not null, facility_date, '(No Bookings)') as facdate, if(facility_timeSlot is not null, facility_timeSlot, '(No Bookings)') as facTimeslot FROM OCCFBS.Booking as b natural join OCCFBS.Facilities as f right join OCCFBS.Personnel as p on (b.username= p.username) Where role='member' order by username, bookingid";
    dc.viewRecord(sql, "Booking Status","User Name", "Booking ID" ,"Facility Name", "Booked Date", "Booked Time","");
}

string FacilitiesManagement::retrieveCurrentDate()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,80,"%d-%b-%y", timeinfo);

    return buffer;
}

void FacilitiesManagement::PopulateAvailableDateAndTime(string facId)
{
    int time = 1000;

    string sql = "";
    string date = retrieveCurrentDate();

    while(true)
    {
        string timeS = dc.ConvertIntToString(time);
        sql = "insert into OCCFBS.CheckAvailability (facility_id, date, timeslot) values ('" + facId + "','" + date + "','" + timeS + "')";
        dc.insertRecord(sql,"",false );

        if(time > 1900)
            break;

        time += 100;
    }
}
 */