#include "HardCode.h"


#define WARD1 "ER"
#define WARD2 "ICU"
#define WARD3 "Rehabilitation"


#define DOC_1 "Doctor"
#define DOC_1Specilaty "All"


#define DOC_2 "Steve"
#define DOC_2Specilaty "ER"


#define DOC_3 "Alex"
#define DOC_3Specilaty "Rehabilitation"


#define NURSE_1 "Joy"
#define NURSE_1_EXP 9999


#define NURSE_2 "Clara"
#define NURSE_2_EXP 80


#define NURSE_3 "Margaret"
#define NURSE_3_EXP 70


#define PATIENT_1 "Tom"
#define PATIENT_1_Birth_YEAR 2000
#define PATIENT_1_Birth_MONTH 1
#define PATIENT_1_Birth_DAY 1
#define PATIENT_1_ID 123
#define PATIENT_1_gender 0


#define PATIENT_1_REASON_VISIT1 "Got a fish bone stuck in his throat"
#define PATIENT_1_DAY_VISIT1 1
#define PATIENT_1_MONTH_VISIT1 5
#define PATIENT_1_YEAR_VISIT1 2022

#define PATIENT_1_REASON_VISIT2 "Stabbed his toe"
#define PATIENT_1_DAY_VISIT2 1
#define PATIENT_1_MONTH_VISIT2 5
#define PATIENT_1_YEAR_VISIT2 2023


#define RESEARCHER_1 "Moshik"

#define ARTICLE_1_PUBILCATOR "News"
#define ARTICLE_1_NAME "Veggies"



void HardCoded(Hospital& hospital)
{
	Date date1(PATIENT_1_YEAR_VISIT1, PATIENT_1_MONTH_VISIT1, PATIENT_1_DAY_VISIT1);
	Date date2(PATIENT_1_YEAR_VISIT2, PATIENT_1_MONTH_VISIT2, PATIENT_1_DAY_VISIT2);
	Date birth(PATIENT_1_Birth_YEAR, PATIENT_1_Birth_MONTH, PATIENT_1_Birth_DAY);

	hospital.AddWard(WARD1);
	hospital.AddWard(WARD2);
	hospital.AddWard(WARD3);


	hospital.getWards()[0]->AddDoctor(DOC_1, DOC_1Specilaty);
	hospital.getWards()[0]->AddDoctor(DOC_2, DOC_2Specilaty);
	hospital.getWards()[2]->AddDoctor(DOC_3, DOC_3Specilaty);


	hospital.getWards()[0]->AddNurse(NURSE_1, NURSE_1_EXP);
	hospital.getWards()[2]->AddNurse(NURSE_2, NURSE_2_EXP);
	hospital.getWards()[2]->AddNurse(NURSE_3, NURSE_3_EXP);


	Patient* newPatient;

	newPatient = &hospital.addPatient(PATIENT_1, PATIENT_1_ID, birth, 0);

	Doctor* tmp = dynamic_cast<Doctor*>(hospital.getWards()[0]->getStaff()[0]);
	newPatient->AddVisit(date1, PATIENT_1_REASON_VISIT1, *tmp);

	hospital.getWards()[0]->AddPatient(*newPatient);

	tmp = dynamic_cast<Doctor*>(hospital.getWards()[0]->getStaff()[1]);
	newPatient->AddVisit(date2, PATIENT_1_REASON_VISIT2, *tmp);

	Researcher* researcher = new Researcher(RESEARCHER_1);
	hospital.getResearchCenter().AddResearcher(*researcher);
	

	Article* newOne = new Article(Date(1950, 5, 12), ARTICLE_1_PUBILCATOR, ARTICLE_1_NAME);

	hospital.getResearchCenter().getResearchers()[0]->addArticle(*newOne);

}

