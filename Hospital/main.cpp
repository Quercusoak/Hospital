#include "mainLib.h"
#include "HardCode.h"

int main()
{
	Hospital hospital;
	int intInput;
	int loopCheck = 1;

	cout << "Please enter hospital start:" << endl;
	cout << "(0) - Empty Hospital" << endl;
	cout << "(1) - HardCoded hospital" << endl;

	cin >> intInput;


	if (intInput)
		HardCoded(hospital);


	hospital.getWards()[0].AddStaff(Nurse("NURSE_3 free 35", 12));

	Article* newOne = new Article(Date(1955, 5, 12), "ARTICLE_1_PUBILCATOR", "ARTICLE_1_NAME");

	hospital.getResearchCenter().getResearchers()[0]->addArticle(*newOne);

	vector<Staff*>::const_iterator itr = hospital.getWards()[0].getStaff().begin();
	cout << **(itr) << endl;

	vector<Researcher*>::const_iterator itr2 = hospital.getResearchCenter().getResearchers().begin();
	cout << **(itr2) << endl;

	ofstream outFile("test.txt", ios::out);

	outFile << **itr << **itr2;
	outFile.close();

	ifstream inFile("test.txt");
	hospital.getWards()[0].AddStaff(Surgeon(inFile));
	Researcher* res = new Researcher(inFile);
	hospital.getResearchCenter().AddResearcher(*res);

	inFile.close();

	cout << endl << "---Welcome to the hospital---" << endl;
	while (loopCheck)
	{
		loopCheck = MenuOutPutInPut();

		switch (loopCheck) {
		case 0:
			cout << "Closing program..." << endl;
			break;
		

		case 1:
			while (loopCheck)
			{
				loopCheck = MenuAdd();
				switch (loopCheck) {
				case 0:
					cout << "Returning to main menu..." << endl;
					break;

				case 1:
					addWard(hospital);
					break;

				case 2:
					addNurse(hospital);
					break;

				case 3:
					addDoctor(hospital);
					break;

				case 4:
					addResearcher(hospital);
					break;

				case 5:
					addResearcherArticle(hospital);
					break;

				case 6:
					addPatient(hospital);
					break;

				default:
					actionDone("Chosing from menu", "User Input", "Entered data out of range", false);
					loopCheck = true;
					break;
				}
			}
			loopCheck = 1;
			break;

		case 2:
			while (loopCheck) {
				loopCheck = MenuPrint();
				switch (loopCheck) {
				case 0:
					cout << "Returning to main menu..." << endl;
					break;

				case 1:
					showPatients(hospital);
					break;

				case 2:
					showStaff(hospital);
					break;

				case 3:
					showResearchers(hospital);
					break;

				case 4:
					PrintResearcherDoctors(hospital);
					break;

				default:
					actionDone("Chosing from menu", "User Input", "Entered data out of range", false);
					loopCheck = true;
					break;
				}
			}
			loopCheck = 2;
			break;

		case 3:
			searchPatient(hospital);
			break;

		case 4:
			compareResearchers(hospital);
			break;

		default:
			actionDone("Chosing from menu", "User Input", "Entered data out of range", false);
			loopCheck = true;
			break;

		}
	}
}




