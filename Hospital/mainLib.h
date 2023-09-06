#ifndef __MAIN_LIB_H
#define __MAIN_LIB_H

#include "Hospital.h"

#define MAX_NAME_LENGTH 100
#define MAX_STRING_INPUT 120
#define CURRENT_YEAR 2023
#define LOWEST_YEAR 1900
#define NUM_OF_MONTHS 12
#define MAX_DAYS 31




int MenuOutPutInPut();


int MenuAdd();


int MenuPrint();





void addWard(Hospital& hospital);


void addNurse(Hospital& hospital);


void addDoctor(Hospital& hospital);


void addPatient(Hospital& hospital);


void addCard(Patient& patient, Ward& ward);


void addOperationCard(Patient& patient, Ward& ward);


void addResearcher(Hospital& hospital);


void addResearcherArticle(Hospital& hospital);




Ward& chooseWard(Hospital&);


Doctor& chooseDoctor(Ward&);


Surgeon& chooseSurgeon(Ward& ward);


Researcher& chooseResearcher(ResearchCenter& research_center, Researcher* chosen);




void showWards(Hospital& hospital);


void showDoctors(Ward& ward);


void showSurgeons(Ward& ward);


void showPatients(Hospital& hospital);


void showStaff(Hospital& hospital); //


void showResearchers(ResearchCenter& research_center, Researcher* chosen); //


void showResearchers(Hospital& hospital); //


void PrintResearcherDoctors(Hospital& hospital);

void printDate(const Date& date); //

void printPatientCard(Patient& patient); //


void searchPatient(Hospital& hospital);


float getExperience();


void compareResearchers(Hospital& hospital);



void checkDate(unsigned short* year, unsigned short* month, unsigned short* day);


void actionDone(const char* actionName, const char* objectName, const char* reason = nullptr, bool check = true);

void returningToMenu();

#endif