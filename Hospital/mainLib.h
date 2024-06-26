#ifndef __MAIN_LIB_H
#define __MAIN_LIB_H

#include "Hospital.h"

#define MAX_NAME_LENGTH 100
#define MAX_STRING_INPUT 120

#define MAX_DAYS 31


enum class MainMenu { Exit, Add, show, SearchById, CompareTowResearcher, SortResearchers };

enum class MenuAdd { Back, Ward, Nurse, Doctor, Researcher, Article, Patient };

enum class MenuPrint { Back, WardPatients, Workers, Reserachers, ResearcherDoctors };

enum class MenuResearcherSort { Back, ID, Name, Reserachers };

enum class AddDoctor { Doctor = 1, Surgeon, ResearcherDoctor, SurgeonResearcher };


int MenuOutPutInPut();


int MenuAdd();


int MenuPrint();


int MenuResearcherSort();




void addWard(Hospital& hospital);


void addNurse(Hospital& hospital);


void addDoctor(Hospital& hospital);


void addPatient(Hospital& hospital);


void addCard(Patient& patient, Ward& ward);


void addOperationCard(Patient& patient, Ward& ward);


void addResearcher(Hospital& hospital);


void addResearcherArticle(Hospital& hospital);




Ward& chooseWard(Hospital& hospital, const char* name = nullptr);


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



void compareResearchers(Hospital& hospital);





void actionDone(const string actionName, const string objectName, const string reason = nullptr, bool check = true);


void returningToMenu();

#endif