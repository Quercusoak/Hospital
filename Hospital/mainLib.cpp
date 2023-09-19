#include "mainLib.h"
#include "CleanBuffer.h"

#define ERR_ID_TAKEN "id already in system"
#define ERR_NO_WARDS "No ward had been added to hospital yet, please enter a ward first."
#define ERR_NO_MATCH_DOCTORS_IN_WARD "Ward is understaffed, and therefore, cannot add patient to ward, please enter a matching doctor to ward first"
#define INCORRECT_DR_TYPE "Doctor type is invalid."
#define ERR_NOT_ENOUGH_RESEARCHERS "Too few reserachers."


int MenuOutPutInPut()
{
	int ret;

	cout << "---Main Menu---" << endl;
	cout << "(1)- Add" << endl;
	cout << "(2)- Show" << endl;
	cout << "(3)- Search patient using his ID" << endl;
	cout << "(4)- Compare two researchers" << endl;
	cout << "(5)- Sort Researchers in Research center" << endl;
	cout << "(0)- Exit program" << endl << endl;
	cout << "Please chose an option from the Menu: ";


	cin >> ret;

	cout << endl;

	return ret;
}

//----------------------------------------------------------------------------------------------------//
int MenuAdd()
{
	int ret;

	cout << "---Add Menu---" << endl
		<< "(1)- Add a new ward to hospital" << endl
		<< "(2)- Add nurse to hospital" << endl
		<< "(3)- Add doctor to hospital" << endl
		<< "(4)- Add researcher to hospital" << endl
		<< "(5)- Add article to researcher" << endl
		<< "(6)- Add patient visit" << endl
		<< "(0)- return to main menu." << endl << endl
		<< "Chose action to be done: ";

	cin >> ret;

	cout << endl;

	return ret;
}

//----------------------------------------------------------------------------------------------------//
int MenuPrint()
{
	int ret;

	cout << "---Print Menu---" << endl
		<< "(1)- Show all patients connected to a ward" << endl
		<< "(2)- Show all hospital workers" << endl
		<< "(3)- Show all hospital researchers" << endl
		<< "(4)- Show all researcher doctors" << endl
		<< "(0)- return to main menu." << endl << endl
		<< "Chose action to be done: ";

	cin >> ret;

	cout << endl;

	return ret;
}

//----------------------------------------------------------------------------------------------------//
int MenuResearcherSort()
{
	int ret;

	cout << "---Sort Menu---" << endl
		<< "(1)- Sort by Id." << endl
		<< "(2)- Sort by Name." << endl
		<< "(3)- Show all hospital researchers" << endl
		<< "(0)- return to main menu." << endl << endl
		<< "Chose action to be done: ";

	cin >> ret;

	cout << endl;

	return ret;
}


//----------------------------------------------------------------------------------------------------//
void addWard(Hospital& hospital)
{
	bool check = false;
	char name[MAX_NAME_LENGTH];
	cleanBuffer();
	
	while (!check)
	{
		try
		{
			cout << "Enter new ward: ";
			cin.getline(name, MAX_NAME_LENGTH);

			hospital.AddWard(name);
			check = true;
		}
		catch (const string e)
		{
			cout << e << endl;
		}
	}
	actionDone("Adding a new ward", name,"",check);
}

//----------------------------------------------------------------------------------------------------//
void addNurse(Hospital& hospital)
{
	float exp;
	char name[MAX_NAME_LENGTH];
	bool check = false;

	if (hospital.getWardsNum() > 0)
	{
		while (!check)
		{
			try
			{
				cout << "Enter new nurse's name: ";
				cleanBuffer();
				cin.getline(name, MAX_NAME_LENGTH);

				cout << "Enter nurse's years of experience: ";
				cin >> exp;

				chooseWard(hospital, name) += Nurse(name, exp);
				check = true;
			}
			catch (const string e)
			{
				cout << e << endl;
			}
		}
	}
	else
		name[0] = '\0';

	actionDone("Adding a new nurse", name, ERR_NO_WARDS, check);
}

//----------------------------------------------------------------------------------------------------//
//Initializes new doctor and adds to doctors array in hospital, and then in selected ward (by ref) 
void addDoctor(Hospital& hospital)
{
	char specialty[MAX_STRING_INPUT];
	char name[MAX_NAME_LENGTH];
	bool check = false;
	unsigned int dr_type, input = 1;
	string error;

	if (hospital.getWardsNum() <= 0)
	{
		error = ERR_NO_WARDS;
		name[0] = '\0';
	}
	else
	{
		cleanBuffer();

		while (input)
		{
			try
			{
				cout << "Enter new doctor's name: ";
				cin.getline(name, MAX_NAME_LENGTH);
				StringException c(name);
				input = 0;
			}
			catch (string& e)
			{
				cout << "A person must have a name - " << e << endl;
			}
		}


		input = 1;
		while (input)
		{
			try
			{
				cout << "Enter new doctor's specialty: ";
				cin.getline(specialty, MAX_STRING_INPUT);
				StringException c(specialty);
				input = 0;
			}
			catch (string& e)
			{
				cout << "A person must have a name - " << e << endl;
			}
		}


		Ward& ward = chooseWard(hospital, name);


		cout << "Select for Dr " << name << ":\n1)Doctor \n2)Surgeon \n3)Researcher Doctor \n4)Researcher Surgeon" << endl;
		cin >> dr_type;


		switch (dr_type)
		{
			case (int)(AddDoctor::Doctor) :
				try
				{
					ward += Doctor(name, specialty);
					check = true;
				}
			catch (const string e)
				{
					error = e;
				}
			break;
			case (int)(AddDoctor::Surgeon) :
				try
				{
					ward += Surgeon(name, specialty);
					check = true;
				}
				catch (const string e)
					{
						error = e;
					}
				break;
			case (int)(AddDoctor::ResearcherDoctor) :
				try
				{
					ward += ResearcherDoctor(name, specialty);
					hospital.getResearchCenter().AddResearcher(*dynamic_cast<Researcher*>(*(--ward.getStaff().end())));
					check = true;
				}
				catch (const string e)
				{
					error = e;
				}
				break;
			case (int)(AddDoctor::SurgeonResearcher) :
				try
				{
					ward += SurgeonResearcher(name, specialty);
					hospital.getResearchCenter().AddResearcher(*dynamic_cast<Researcher*>(*(--ward.getStaff().end())));
					check = true;
				}
				catch (const string e)
				{
					error = e;
				}
				break;
			default:
				error = INCORRECT_DR_TYPE;
				break;
		}
	}
	actionDone("Adding a new doctor", name, error, check);
}

//----------------------------------------------------------------------------------------------------//
void addPatient(Hospital& hospital)
{
	unsigned int gender, id, input = 1;
	int _id;
	unsigned short year, month, day;
	char name[MAX_NAME_LENGTH];
	bool operation = false;
	cleanBuffer();

	while (input)
	{
		try
		{
			cout << "Enter patient's name: ";
			cin.getline(name, MAX_NAME_LENGTH);

			StringException c(name);
			input = 0;
		}
		catch (string& e)
		{
			cout << "A person must have a name - " << e << endl;
		}
	}

	input = 1;
	while (input) 
	{
		try
		{
			cout << "Enter patient's id: ";
			cin >> _id;
			IdException e(_id);
			input = 0;
		}
		catch (string exception)
		{
			cout << exception << " Please retry." << endl;
		}
	}
	id = _id;

	//Search if patient already exists:
	Patient* patient = hospital.searchPatientByID(id);

	//if patient new - add patient to hospital:
	if (patient == nullptr)
	{
		input = 1;
		while (input) 
		{
			try
			{
				cout << "Enter birth date in the format: year month day" << endl;
				cin >> year >> month >> day;
				DateExceptions check(year, month, day);
				input = 0;
			}
			catch (string exception)
			{
				cout << exception << " Please retry." << endl;
			}
		}

		input = 1;
		while (input) 
		{
			try
			{
				cout << "Choose gender: " << endl << "1 - male" << endl << "2 - female" << endl;
				cin >> gender;
				BoolException c(gender - 1);
				input = 0;
			}
			catch (string& exception)
			{
				cout << exception << endl;
			}
		}
	}

	//add visit to patient's card

	//Select ward to add patient to:
	bool check = hospital.getWardsNum() == 0;
	if (!check) {
		Ward& ward = chooseWard(hospital);


		while (!operation)
		{
			try
			{
				cout << "Is the visit for an operation?" << endl
					<< "1) No" << endl
					<< "2) Yes" << endl;

				cin >> input;
				BoolException c(input - 1);
				operation = true;
			}
			catch (string& exception)
			{
				cout << exception << " Please retry." << endl;
			}
		}

		operation = input - 1;


		//Patient can't be added to a ward without doctors in it:
		if (operation)
			check = ward.getSurgeonsNum() == 0;
		else
			check = ward.getDoctorsNum() == 0;


		if (!check) {
			if (patient == nullptr) 
				patient = hospital.addPatient(name, id, Date(year, month, day), gender - 1);

			if(operation)
				addOperationCard(*patient, ward);
			else
				addCard(*patient, ward);
			
		}

		actionDone("Adding new patient", name, ERR_NO_MATCH_DOCTORS_IN_WARD, !check);
	}
	else
		actionDone("Adding new patient", name,	ERR_NO_WARDS, !check);
}


//----------------------------------------------------------------------------------------------------//
void addCard(Patient& patient, Ward& ward)
{
	unsigned short year, month, day, input = 1;
	char purpose_of_visit[MAX_STRING_INPUT];


	//visit date:
	while (input)
	{
		try
		{
			cout << "Enter date of visit in the format: year month day" << endl;
			cin >> year >> month >> day;
			DateExceptions check(year, month, day);
			input = 0;
		}
		catch (string exception)
		{
			cout << exception << " Please retry." << endl;
		}
	}
	cleanBuffer();

	//visit purpose:
	input = 1;
	while (input)
	{
		try
		{
			cout << "Enter purpose of visit: ";
			cin.getline(purpose_of_visit, MAX_STRING_INPUT);
			StringException e(purpose_of_visit);
			input = 0;
		}
		catch (string& exception)
		{
			cout << "Must provide purpose for hospital visit - "  << exception << " Please retry." << endl;
		}
	}


	//Select a doctor in selected ward:
	Doctor& doctor = chooseDoctor(ward);

	patient.AddVisit(Date(year, month, day), purpose_of_visit, doctor);
	ward.AddPatient(patient);
}

//----------------------------------------------------------------------------------------------------//
void addOperationCard(Patient& patient, Ward& ward)
{
	unsigned short year, month, day;
	char purpose_of_visit[MAX_STRING_INPUT];
	unsigned int room_number, input = 1;
	bool fasting = false;

	//visit date:
	while (input)
	{
		try
		{
			cout << "Enter date of visit in the format: year month day" << endl;
			cin >> year >> month >> day;
			DateExceptions check(year, month, day);
			input = 0;
		}
		catch (string exception)
		{
			cout << exception << " Please retry." << endl;
		}
	}


	//visit purpose:
	input = 1;
	cleanBuffer();

	while (input)
	{
		try
		{
			cout << "Enter purpose of visit: ";
			cin.getline(purpose_of_visit, MAX_STRING_INPUT);
			StringException c(purpose_of_visit);
			input = 0;
		}
		catch (string& exception)
		{
			cout << "Must provide purpose for hospital visit - " << exception << " Please retry." << endl;
		}
	}


	//Select a doctor in selected ward:
	Surgeon& surgeon = chooseSurgeon(ward);


	cout << "Enter operation room: ";
	cin >> room_number;


	while (!fasting)
	{
		try
		{
			cout << "Was fasting necessary for operation?" << endl
				<< "1) No" << endl
				<< "2) Yes" << endl;

			cin >> input;
			BoolException c(input - 1);
			fasting = true;
		}
		catch (string& exception)
		{
			cout << exception << " Please retry." << endl;
		}
	}
	fasting = input - 1;


	patient.AddVisit(Date(year, month, day), purpose_of_visit, surgeon, room_number, fasting);
	ward.AddPatient(patient);
}

//----------------------------------------------------------------------------------------------------//
Ward& chooseWard(Hospital& hospital, const char* name)
{
	unsigned int ward_num, num_of_wards_in_hospital = hospital.getWardsNum();

	if (name != nullptr)
		cout << endl << "Assign " << name << " to a ward: " << endl;

	do
	{
		cout << "Select ward number from list: " << endl;
		showWards(hospital);
		cin >> ward_num;
	} while (ward_num < 1 || ward_num > num_of_wards_in_hospital);

	return hospital.getWards()[ward_num - 1];
}

//----------------------------------------------------------------------------------------------------//
void showWards(Hospital& hospital)
{
	int wardNum = hospital.getWardsNum();
	for (int i = 0; i < wardNum; i++)
		cout << (i + 1) << ") " << hospital.getWards()[i].getName() << endl;
}

//----------------------------------------------------------------------------------------------------//
Doctor& chooseDoctor(Ward& ward)
{
	unsigned int i, num, num_doctors = ward.getDoctorsNum();

	do
	{
		cout << "Select doctor from list: " << endl;
		showDoctors(ward);
		cin >> num;
	} while (num < 1 || num > num_doctors);


	vector<Staff*>::const_iterator itr = ward.getStaff().begin();
	for (i = 0; i < num; ++i, ++itr) {
		if (!dynamic_cast<Doctor*>(*itr))
			i--;
	}

	Doctor* tmp = dynamic_cast<Doctor*>(*(--itr));
	return *tmp;
}

//----------------------------------------------------------------------------------------------------//
void showDoctors(Ward& ward)
{
	unsigned int num_doctors = ward.getDoctorsNum();

	unsigned int ret = 0;
	vector<Staff*>::const_iterator itr = ward.getStaff().begin();

	for (; ret < num_doctors; ret++, ++itr)
	{
		if (dynamic_cast<Doctor*>((*itr)))
			cout << (ret + 1) << ") " << (*itr)->getName() << endl;
		else
			ret--;
	}
}

//----------------------------------------------------------------------------------------------------//
Surgeon& chooseSurgeon(Ward& ward)
{
	unsigned int i, num, num_surgeons = ward.getSurgeonsNum();

	do
	{
		cout << "Select surgeon from list: " << endl;
		showSurgeons(ward);
		cin >> num;
	} while (num < 1 || num > num_surgeons);


	vector<Staff*>::const_iterator itr = ward.getStaff().begin();
	for (i = 0; i < num; i++, ++itr) {
		if (!dynamic_cast<Surgeon*>(*itr))
			i--;
	}

	Surgeon* tmp = dynamic_cast<Surgeon*>(*--itr);
	return *tmp;
}

//----------------------------------------------------------------------------------------------------//
void showSurgeons(Ward& ward)
{
	unsigned int num_surgeon = ward.getSurgeonsNum();

	unsigned int ret = 0;
	vector<Staff*>::const_iterator itr = ward.getStaff().begin();
	for (; ret < num_surgeon; ret++, ++itr)
	{
		if (dynamic_cast<Surgeon*>(*itr))
			cout << (ret + 1) << ") " << (*itr)->getName() << endl;
		else
			ret--;
	}
}

//----------------------------------------------------------------------------------------------------//
Researcher& chooseResearcher(ResearchCenter& research_center, Researcher* chosen)
{
	unsigned int num, num_researchers = research_center.getResearchers().size();
	if (chosen) num_researchers--;
	do
	{
		cout << "Select a researcher from list: " << endl;
		showResearchers(research_center, chosen);
		cin >> num;
	} while (num < 1 || num > num_researchers);

	int chose = 0;
	for (unsigned int i = 0; i < num; i++, chose++) {
		if (research_center.getResearchers()[chose] == chosen)
			i--;
	}

	return *research_center.getResearchers()[chose - 1];
}

//----------------------------------------------------------------------------------------------------//
void showResearchers(ResearchCenter& research_center, Researcher* chosen)
{
	unsigned int num_researchers = research_center.getResearchers().size();

	for (unsigned int i = 0, k = 0; i < num_researchers; k++, i++)
	{
		if (research_center.getResearchers()[i] == chosen)
			k--;
		else
			cout << (k + 1) << ") " << research_center.getResearchers()[i]->getName() << endl;
	}
}

//----------------------------------------------------------------------------------------------------//
void addResearcher(Hospital& hospital)
{
	char name[MAX_NAME_LENGTH];

	cout << "Enter new researcher's name: ";
	cleanBuffer();
	cin.getline(name, MAX_NAME_LENGTH);

	Researcher* researcher = new Researcher(name);
	hospital.getResearchCenter().AddResearcher(*researcher);

	actionDone("Adding a new researcher", name, ERR_ID_TAKEN, true);

}

//----------------------------------------------------------------------------------------------------//
void addResearcherArticle(Hospital& hospital)
{

	char magazineName[MAX_NAME_LENGTH], articleName[MAX_NAME_LENGTH];
	unsigned short year, month, day, input = 1;
	ResearchCenter& research_center = hospital.getResearchCenter();

	bool check = research_center.getResearchers().size() > 0;
	if (check) {
		Researcher& researcher = chooseResearcher(research_center, NULL);

		while (input)
		{
			try
			{
				cout << "Please enter publication date, in format of \"year month day\":" << endl;
				cin >> year >> month >> day;
				DateExceptions check(year, month, day);
				input = 0;
			}
			catch (string exception)
			{
				cout << exception << " Please retry." << endl;
			}
		}

		cleanBuffer();
		input = 1;

		while (input)
		{
			try
			{
				cout << "Please enter Magazine Name: ";
				cin.getline(magazineName, MAX_NAME_LENGTH);
				StringException c(magazineName);
				input = 0;
			}
			catch (string& exception)
			{
				cout << exception << " Please retry." << endl;
			}
		}


		input = 1;

		while (input)
		{
			try
			{
				cout << "Please enter Article Name: ";
				cin.getline(articleName, MAX_NAME_LENGTH);
				StringException c(articleName);
				input = 0;
			}
			catch (string& exception)
			{
				cout << exception << " Please retry." << endl;
			}
		}


		Article* article = new Article(Date(year, month, day), magazineName, articleName);
		researcher.addArticle(*article);

		actionDone("Adding Article to researcher", articleName, "", true);
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
	for (unsigned int i = 0; i < patient->getNumVisits(); i++)
		cout << *(patient->getPatientCard()[i]) << endl;

	returningToMenu();

}

//----------------------------------------------------------------------------------------------------//
//Shows all patients who visited selected ward.
void showPatients(Hospital& hospital)
{
	Ward& ward = chooseWard(hospital);
	unsigned int num_of_patients = ward.getPatientsNum();

	if (num_of_patients == 0)
	{
		cout << "No patients in selected ward." << endl;
		return;
	}

	cout << "Patients in selected ward: " << endl;


	const vector<Patient*> patients = ward.getPatients();

	vector<Patient*>::const_iterator itr = patients.begin();
	vector<Patient*>::const_iterator end = patients.end();

	for (; itr != end; ++itr)
	{
		cout << *(*itr) << endl;
	}


	returningToMenu();

}

//----------------------------------------------------------------------------------------------------// TO BE DEL
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
			Ward& ward(hospital.getWards()[i]); 
			num_staff = ward.getNumStaff();

			cout << "------------------------------------------------------------" << endl
				<< ward.getName() << " ward:" << endl;

			if (num_staff > 0)
			{
				vector<Staff*>::const_iterator itr = ward.getStaff().begin();
				for (j = 0; j < num_staff; ++j, ++itr)
					cout << *(*itr) << endl;
			}
			else
				cout << "No Staff In Ward" << endl;
		}
	}

	cout << "------------------------------------------------------------";

	returningToMenu();
}

//----------------------------------------------------------------------------------------------------//
void showResearchers(Hospital& hospital)
{
	ResearchCenter& research_center = hospital.getResearchCenter();
	unsigned int numToPrint = research_center.getResearchers().size();

	cout << "Current Researchers: " << endl;

	for (unsigned int i = 0; i < numToPrint; i++)
		cout << *((research_center.getResearchers())[i]) << endl;

	returningToMenu();

}

//----------------------------------------------------------------------------------------------------// TO BE DEL
void printDate(const Date& date)
{
	cout << date << endl;
}

//----------------------------------------------------------------------------------------------------//
void actionDone(const string actionName, const string objectName, const string reason, bool check)
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

	returningToMenu();
}

//----------------------------------------------------------------------------------------------------//
//Print returning to main menu msg.
void returningToMenu()
{
	cout << endl << "Returning to menu..." << endl << endl;
}


//----------------------------------------------------------------------------------------------------//
void compareResearchers(Hospital& hospital)
{
	ResearchCenter& RC = hospital.getResearchCenter();
	int num_researchers = RC.getResearchers().size();
	bool check = true;
	if (num_researchers > 1)
	{
		cout << "Select researchers to compare: " << endl;
		cout << "First researcher: ";
		Researcher& first = chooseResearcher(RC, NULL);

		cout << "Second researcher: ";
		Researcher& second = chooseResearcher(RC, &first);


		int res = first > second;
		if (res > 0)
			cout << "Researcher " << first.getName() << " has written more articles." << endl;
		else if (res < 0)
			cout << "Researcher " << second.getName() << " has written more articles." << endl;
		else
			cout << "Both researchers wrote " << first.getNumArticles() << " articles." << endl;
	}
	else
		check = false;


	actionDone("Comparing researchers", "Research Center", ERR_NOT_ENOUGH_RESEARCHERS, check);
}


//----------------------------------------------------------------------------------------------------//
void PrintResearcherDoctors(Hospital& hospital)
{
	ResearchCenter& research_center = hospital.getResearchCenter();
	unsigned int num_researchers = research_center.getResearchers().size();
	
	if (num_researchers < 1)
	{
		cout << "No Researcher Doctors" << endl;
		return;
	}
	
	
	vector<Researcher*> researchers = research_center.getResearchers();

	cout << "Researcher Doctors: " << endl;

	for (unsigned int i = 0; i < num_researchers; i++)
	{
		if (dynamic_cast<Doctor*>(researchers[i]))
			cout << *(researchers[i]) << endl;
	}

	returningToMenu();
	
}

//----------------------------------------------------------------------------------------------------//
