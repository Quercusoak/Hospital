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




