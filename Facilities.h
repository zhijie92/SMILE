/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Facilities.h
 * Author: Amos Laptop
 *
 * Created on February 19, 2016, 4:44 PM
 */

#ifndef FACILITIES_H
#define FACILITIES_H
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Facilities {
public:
    Facilities();
    Facilities(const Facilities& orig);
    virtual ~Facilities();
    
    int GetFacilityID() const;
    void SetFacilityID(const int id);
    string GetFacilityName() const;
    void SetFacilityName(const string name);
    string GetFacilityDescription() const;
    void SetFacilityDescription(const string desc);
private:
    string facilityName, facilityDescription;
    int facilityID;
    double facilityRate;
    
    
};

#endif /* FACILITIES_H */

