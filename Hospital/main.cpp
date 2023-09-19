#include "mainLib.h"
#include "HardCode.h"

int main()
{
	Hospital hospital;
	int intInput;
	int loopCheck = 1;


	cout << endl << "---Welcome to the hospital---" << endl;

	hospital.loadHospital("saved.txt");

	//HardCoded(hospital);

	hospital.getResearchCenter().sortResearchers(BY_ID);
	
	while (loopCheck)
	{
		loopCheck = MenuOutPutInPut();

		switch (loopCheck) {
		case (int)(MainMenu::Exit):
			cout << "Closing program..." << endl;
			break;
		

			case (int)(MainMenu::Add):
			while (loopCheck)
			{
				loopCheck = MenuAdd();
				switch (loopCheck) {
					case (int)(MenuAdd::Back) :
						returningToMenu();
						break;

					case (int)(MenuAdd::Ward) :
						addWard(hospital);
						break;

					case (int)(MenuAdd::Nurse):
						addNurse(hospital);
						break;

					case (int)(MenuAdd::Doctor):
						addDoctor(hospital);
						break;

					case (int)(MenuAdd::Researcher):
						addResearcher(hospital);
						break;

					case (int)(MenuAdd::Article):
						addResearcherArticle(hospital);
						break;

					case (int)(MenuAdd::Patient):
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

		case (int)(MainMenu::show):
			while (loopCheck) {
				loopCheck = MenuPrint();
				switch (loopCheck) {
					case (int)(MenuPrint::Back):
						returningToMenu();
						break;

					case (int)(MenuPrint::WardPatients):
						showPatients(hospital);
						break;

					case (int)(MenuPrint::Workers):
						showStaff(hospital);
						break;

					case (int)(MenuPrint::Reserachers):
						showResearchers(hospital);
						break;

					case (int)(MenuPrint::ResearcherDoctors):
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

		case (int)(MainMenu::SearchById):
			searchPatient(hospital);
			break;

		case (int)(MainMenu::CompareTowResearcher):
			compareResearchers(hospital);
			break;

		case (int)(MainMenu::SortResearchers):
			while (loopCheck) {
				loopCheck = MenuResearcherSort();
				switch (loopCheck) {
					case (int)(MenuResearcherSort::Back) :
						returningToMenu();
						break;

					case (int)(MenuResearcherSort::ID) :
						hospital.getResearchCenter().sortResearchers(BY_ID);
						actionDone("Sorting Researchers by Id", "Research Center", "", true);
						break;

					case (int)(MenuResearcherSort::Name) :
						hospital.getResearchCenter().sortResearchers(BY_NAME);
						actionDone("Sorting Researchers by Name", "Research Center", "", true);
						break;

					case (int)(MenuResearcherSort::Reserachers) :
						showResearchers(hospital);
						break;

					default:
						actionDone("Chosing from menu", "User Input", "Entered data out of range", false);
						loopCheck = true;
						break;

				}
			}
		default:
			actionDone("Chosing from menu", "User Input", "Entered data out of range", false);
			loopCheck = true;
			break;

		}
	}

	hospital.saveHospital("saved.txt");
	
}




