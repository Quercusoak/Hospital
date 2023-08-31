#ifndef __MAIN_LIB_H
#define __MAIN_LIB_H

#include "Hospital.h"

#define MAX_NAME_LENGTH 100
#define MAX_STRING_INPUT 120
#define CURRENT_YEAR 2023
#define LOWEST_YEAR 1900
#define NUM_OF_MONTHS 12
#define MAX_DAYS 31


/*	0	- Exit program
	1	- Add a new ward to hospital
	2	- Add nurse to hospital
	3	- Add doctor to hospital
	4	- Add patient visit
	5	- Add researcher to hospital
	6	- Add article to researcher
	7	- Show all patients conntected to a ward
	8	- Show all hospital workers
	9	- Show all hospital reserachers
	10	- search patient using his ID*/

int MenuOutPutInPut();





void addWard(Hospital& hospital);


void addNurse(Hospital& hospital);


void addDoctor(Hospital& hospital);


void addPatient(Hospital& hospital);


void addResearcher(Hospital& hospital);


void addResearcherArticle(Hospital& hospital);






Ward& chooseWard(Hospital&);


Doctor& chooseDoctor(Ward&);


Researcher& chooseResearcher(ResearchCenter& research_center);




void showWards(Hospital& hospital);


void showDoctors(Ward& ward);


void showPatients(Hospital& hospital);


void showStaff(Hospital& hospital);


void showResearchers(ResearchCenter& research_center);


void showResearchers(Hospital& hospital);





void printDate(const Date& date);

void printPatient(Patient& patient);

void printPatientCard(Patient& patient);


void printStaff(Staff& staff);

void searchPatient(Hospital& hospital);

void printResearcher(Researcher& researcher);





void checkDate(unsigned short* year, unsigned short* month, unsigned short* day);


void actionDone(const char* actionName, const char* objectName, const char* reason = nullptr, bool check = true);

void returningMainMenu();

#endif