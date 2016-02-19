/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FacilitiesManagement.h
 * Author: Amos Laptop
 *
 * Created on February 19, 2016, 4:56 PM
 */

#ifndef FACILITIESMANAGEMENT_H
#define FACILITIESMANAGEMENT_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Facilities.h"

using namespace std;

class FacilitiesManagement {
public:
    FacilitiesManagement();
    FacilitiesManagement(const FacilitiesManagement& orig);
    virtual ~FacilitiesManagement();
    
    void addRecord(string fac_name, string fac_desc);
    void updateFacilityID(string id);
    void printAllAvailableRecords();
    void printSummaryRecords();
    void removeRecord(string tId);
    void printAllRecords();
    void editRecord(string facId,string fac_name, string fac_desc);
    void editFacility();
    void removeFacility();
    void addFacility();
    double roundOff(double s);
    bool tryParseInt(string testValue);
    void PopulateAvailableDateAndTime(string facId);
    string retrieveCurrentDate();
    bool FacilityIDExists(string id);
private:

};

#endif /* FACILITIESMANAGEMENT_H */

