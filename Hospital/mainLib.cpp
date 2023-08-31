#include "mainLib.h"
#include "CleanBuffer.h"

#define ERR_ID_TAKEN "id already in system"
#define ERR_NO_WARDS "No ward had been added to hospital yet, please enter a ward first."
#define ERR_NO_DOCTORS_IN_WARD "Ward is understaffed, and therefore, cannot add patient to ward, please enter a doctor to ward first"

int MenuOutPutInPut()
{
	int ret;

	cout << "Please chose an option from the Menu:" << endl;
	cout << " (0)- Exit program" << endl;
	cout << " (1)- Add a new ward to hospital" << endl;
	cout << " (2)- Add nurse to hospital" << endl;
	cout << " (3)- Add doctor to hospital" << endl;
	cout << " (4)- Add patient visit" << endl;
	cout << " (5)- Add researcher to hospital" << endl;
	cout << " (6)- Add article to researcher" << endl;
	cout << " (7)- Show all patients conntected to a ward" << endl;
	cout << " (8)- Show all hospital workers" << endl;
	cout << " (9)- Show all hospital reserachers" << endl;
	cout << "(10)- search patient using his ID" << endl;

	cin >> ret;

	cout << endl;

	return ret;
}

//----------------------------------------------------------------------------------------------------//
void addWard(Hospital& hospital)
{
	char name[MAX_NAME_LENGTH];
	cout << "Enter new ward: ";
	cleanBuffer();
	cin.getline(name, MAX_NAME_LENGTH);

	hospital.AddWard(name);
	actionDone("Adding a new ward", name);
}

//----------------------------------------------------------------------------------------------------//
//Initializes new nurse and adds to nurses array in hospital, and then in selected ward (by ref) 
void addNurse(Hospital& hospital)
{
	float exp;
	char name[MAX_NAME_LENGTH];

	cout << "Enter new nurse's name: ";
	cleanBuffer();
	cin.getline(name, MAX_NAME_LENGTH);

	cout << "Enter new nurse's years of experience: ";
	cin >> exp;


	cout << endl << "Assign " << name << " to a ward: " << endl;
	Ward& ward = chooseWard(hospital);

	
	hospital.AddNurse(name, exp, ward);

	actionDone("Adding a new nurse", name, "", true);
}


//----------------------------------------------------------------------------------------------------//
//Initializes new doctor and adds to doctors array in hospital, and then in selected ward (by ref) 
void addDoctor(Hospital& hospital)
{
	char specialty[MAX_STRING_INPUT];
	char name[MAX_NAME_LENGTH];

	cout << "Enter new doctor's name: ";
	cleanBuffer();
	cin.getline(name, MAX_NAME_LENGTH);

	cout << "Enter new doctor's specialty: ";
	cin.getline(specialty, MAX_STRING_INPUT);


	cout << endl << "Assign " << name << " to a ward: " << endl;
	Ward& ward = chooseWard(hospital);

	hospital.AddDoctor(name, specialty, ward);

	actionDone("Adding a new doctor", name, "", true);

}

//----------------------------------------------------------------------------------------------------//
//Creates and adds to hospital if new patient, if returning patient- only adds visit to patients card and in visited ward patien array
void addPatient(Hospital& hospital)
{
	unsigned int gender, id;
	unsigned short year, month, day;
	char purpose_of_visit[MAX_STRING_INPUT];
	char name[MAX_NAME_LENGTH];
	Date date;

	cout << "Enter patient's name: ";
	cleanBuffer();
	cin.getline(name, MAX_NAME_LENGTH);

	cout << "Enter patient's id: ";
	cin >> id;

	//Search if patient already exists:
	Patient* patient = hospital.searchPatientByID(id);

	//if patient new - add patient to hospital:
	if (patient == nullptr)
	{
		cout << "Enter birth date in the format: year month day" << endl;
		cin >> year >> month >> day;
		checkDate(&year, &month, &day); //check date validity
		date = Date(year, month, day);
		cout << "Choose gender: " << endl << "1 - male" << endl << "2 - female" << endl;
		cin >> gender;

	}

	//add visit to patient's card

	//Select ward to add patient to:
	bool check = hospital.getWardsNum() == 0;
	if (!check) {
		Ward& ward = chooseWard(hospital);

		//Patient can't be added to a ward without doctors in it:
		check = ward.getDoctorsNum() == 0;


		if (!check) {
			if (patient == nullptr)
				patient = hospital.addPatient(name, id, date, gender - 1);

			//visit date:
			cout << "Enter date of visit in the format: year month day" << endl;
			cin >> year >> month >> day;
			checkDate(&year, &month, &day); //check date validity
			date = Date(year, month, day);


			//visit purpose:
			cout << "Enter purpose of visit: ";
			cin.getline(purpose_of_visit, MAX_STRING_INPUT);


			//Select a doctor in selected ward:
			Doctor& doctor = chooseDoctor(ward);

			patient->AddVisit(date, purpose_of_visit, doctor);
			ward.AddPatient(*patient);

		}

		actionDone("Adding new patient", name,ERR_NO_DOCTORS_IN_WARD, !check);
	}
	else
		actionDone("Adding new patient", name,	ERR_NO_WARDS, !check);
}



//----------------------------------------------------------------------------------------------------//
Ward& chooseWard(Hospital& hospital)
{
	unsigned int ward_num, num_of_wards_in_hospital = hospital.getWardsNum();

	do
	{
		cout << "Select ward number from list: " << endl;
		showWards(hospital);
		cin >> ward_num;
	} while (ward_num < 1 || ward_num > num_of_wards_in_hospital);

	return *(hospital.getWards())[ward_num - 1];
}

//----------------------------------------------------------------------------------------------------//
void showWards(Hospital& hospital)
{
	int wardNum = hospital.getWardsNum();
	for (int i = 0; i < wardNum; i++)
		cout << (i + 1) << ") " << hospital.getWards()[i]->getName() << endl;
}


//----------------------------------------------------------------------------------------------------//
Doctor& chooseDoctor(Ward& ward)
{
	unsigned int num, num_of_staff_in_ward = ward.getNumStaff();

	do
	{
		cout << "Select doctor from list: " << endl;
		showDoctors(ward);
		cin >> num;
	} while (num < 1 || num > num_of_staff_in_ward);

	Doctor* tmp = dynamic_cast<Doctor*>(ward.getStaff()[num - 1]);
	return *tmp;
}

//----------------------------------------------------------------------------------------------------//
void showDoctors(Ward& ward)
{
	unsigned int num_doctors = ward.getNumStaff();

	for (unsigned int i = 0; i < num_doctors; i++)
	{
		if (dynamic_cast<Doctor*>(ward.getStaff()[i]))
			cout << (i + 1) << ") " << ward.getStaff()[i]->getName() << endl;
	}
}

//----------------------------------------------------------------------------------------------------//
Researcher& chooseResearcher(ResearchCenter& research_center)
{
	unsigned int num, num_researchers = research_center.getNum_researchers();

	do
	{
		cout << "Select a researcher from list: " << endl;
		showResearchers(research_center);
		cin >> num;
	} while (num < 1 || num > num_researchers);

	return *research_center.getResearchers()[num - 1];
}

//----------------------------------------------------------------------------------------------------//
void showResearchers(ResearchCenter& research_center)
{
	unsigned int num_researchers = research_center.getNum_researchers();

	for (unsigned int i = 0; i < num_researchers; i++)
	{
		cout << (i + 1) << ") " << research_center.getResearchers()[i]->getName() << endl;
	}
}

//----------------------------------------------------------------------------------------------------//
void addResearcher(Hospital& hospital)
{
	char name[MAX_NAME_LENGTH];

	cout << "Enter new researcher's name: ";
	cleanBuffer();
	cin.getline(name, MAX_NAME_LENGTH);


	hospital.getResearchCenter().AddResearcher(name);

	actionDone("Adding a new researcher", name, ERR_ID_TAKEN, true);

}

//----------------------------------------------------------------------------------------------------//
void addResearcherArticle(Hospital& hospital)
{

	char magazineName[MAX_NAME_LENGTH], articleName[MAX_NAME_LENGTH];
	unsigned short year, month, day;
	ResearchCenter& research_center = hospital.getResearchCenter();

	bool check = research_center.getNum_researchers() > 0;
	if (check) {
		Researcher& researcher = chooseResearcher(research_center);

		cout << "Please enter publication date, in format of \"year month day\":" << endl;
		cin >> year >> month >> day;
		checkDate(&year, &month, &day);

		cout << "Please enter Magazine Name: ";
		cin >> magazineName;
		cout << "Please enter Article Name: ";
		cin >> articleName;

		Date publicationDate(year, month, day);
		Article* article = new Article(publicationDate, magazineName, articleName);
		researcher.addArticle(*article);

		actionDone("Adding Article to researcher", articleName);
	}
	else
		actionDone("Adding Article to researcher", "There is no researcher in system",
			"No researcher had been added, please add new researcher and try again", check);
}


//----------------------------------------------------------------------------------------------------//
void searchPatient(Hospital& hospital)
{
	unsigned int id;
	cout << "Enter patient's ID: ";
	cleanBuffer();
	cin >> id;

	Patient* patient = hospital.searchPatientByID(id);

	//if no such patient in system:
	if (patient == nullptr)
	{
		cout << "No patient found." << endl;
		return;
	}

	//patient's name:
	cout << *patient << endl;


	//Patient's visits data from card:
	printPatientCard(*patient);

	returningMainMenu();

}

//----------------------------------------------------------------------------------------------------//
//Shows all patients who visited selected ward.
void showPatients(Hospital& hospital)
{
	Ward& ward = chooseWard(hospital);
	unsigned int num_of_patients = ward.getPatientsNum();
	Patient* patient;

	if (num_of_patients == 0)
	{
		cout << "No patients in selected ward." << endl;
		return;
	}

	cout << "Patients in selected ward: " << endl;

	for (unsigned int i = 0; i < num_of_patients; i++)
	{
		patient = ward.getPatients()[i];
		cout << *patient;
		//printPatient(*patient);
	}

	returningMainMenu();

}

//----------------------------------------------------------------------------------------------------// TO BE DEL
void printPatient(Patient& patient)
{
	cout << patient.getName() << ", " << patient.getGender() << ", ID: " << patient.getID() << endl;
}

//----------------------------------------------------------------------------------------------------//
void printPatientCard(Patient& patient)
{
	PatientCard* card;
	for (unsigned int i = 0; i < patient.getNumVisits(); i++)
	{
		card = patient.getPatientCard()[i];
		cout << "Visit date: " << card->getDate().getDay() << "." << card->getDate().getMonth() << "." << card->getDate().getYear();
		cout << ", cause: " << card->getPurpose() << ", attended by doctor " << card->getDoctor().getName() << endl;
	}
}


//----------------------------------------------------------------------------------------------------//
void showStaff(Hospital& hospital)
{
	unsigned int i,j, num_wards = hospital.getWardsNum(), num_staff;


	if (num_wards > 0)
	{
		cout << "Current Staff members: " << endl;
		for (i = 0; i < num_wards; i++)
		{
			Ward& ward(*hospital.getWards()[i]); 
			num_staff = ward.getNumStaff();

			if (num_staff > 0)
			{
				cout << ward.getName() << ":" << endl;
				for (j = 0; j < num_staff; j++)
					cout << *ward.getStaff()[j] << endl;
					//printStaff(*ward.getStaff()[j]);
			}
		}
	}

	returningMainMenu();

}


//----------------------------------------------------------------------------------------------------// TO BE DEL
void printStaff(Staff& staff)
{	
	Nurse* temp = dynamic_cast<Nurse*>(&staff);
	if (temp)
	{
		cout << *temp;
	}
	else  
	{		
		Doctor* temp = dynamic_cast<Doctor*>(&staff);
		cout << (*temp);
	}
}


//----------------------------------------------------------------------------------------------------//
void showResearchers(Hospital& hospital)
{
	ResearchCenter& research_center = hospital.getResearchCenter();
	unsigned int numToPrint = research_center.getNum_researchers();

	cout << "Current Researchers: " << endl;

	for (unsigned int i = 0; i < numToPrint; i++)
		cout << *((research_center.getResearchers())[i]);
		//printResearcher(*((research_center.getResearchers())[i]));

	returningMainMenu();

}

//----------------------------------------------------------------------------------------------------//
/*void printResearcher(Researcher& researcher)
{
	int num_articles = researcher.getNumArticles();

	cout << "Researcher " << researcher.getName() << ", worker ID: " << researcher.getWorkerID()
		<< ", number of written Articles: " << num_articles << endl;

	if (num_articles == 0)
		return;


	cout << "Articles:" << endl;

	for (int i = 0; i < num_articles; i++) {
		//cout << i + 1 << ")" << "\n"
			//<< "Magazine Name - " << researcher.getArticle(i)->getMagazineName() << "\n"
			//<< "Article Name - " << researcher.getArticle(i)->getArticleName() << "\n"
			//<< "Date - ";
		//printDate(researcher.getArticle(i)->getDate());
	}
	cout << endl;
}*/

//----------------------------------------------------------------------------------------------------// TO BE DEL
void printDate(const Date& date)
{
	cout << date << endl;
}

//----------------------------------------------------------------------------------------------------//
void actionDone(const char* actionName, const char* objectName, const char* reason, bool check)
{
	if (check)
		cout << "\n"
		<< "Action - " << actionName << "\n"
		<< "had been successful for - " << objectName << "\n";

	else
		cout << "\n"
		<< "Action - " << actionName << "\n"
		<< "had been unsuccessful for - " << objectName << "\n"
		<< "reason - " << reason << "\n";

	returningMainMenu();
}

//----------------------------------------------------------------------------------------------------//
//Print returning to main menu msg.
void returningMainMenu()
{
	cout << "Returning to main menu...\n\n"
		<< "---Hospital Menu---" << endl;
}

//----------------------------------------------------------------------------------------------------//
//Checks validity of date input for each date element.
void checkDate(unsigned short* year, unsigned short* month, unsigned short* day)
{

	while (*year > CURRENT_YEAR || *year < LOWEST_YEAR) //Expected card date to be current or previous date
	{
		cout << "Year invalid. Retry: ";
		cin >> *year;
	}

	while (*month > NUM_OF_MONTHS || *month < 1)
	{
		cout << "Month invalid. Retry.";
		cin >> *month;
	}

	while (*day > MAX_DAYS || *day < 1)
	{
		cout << "Day invalid. Retry.";
		cin >> *day;
	}

	cleanBuffer();

}