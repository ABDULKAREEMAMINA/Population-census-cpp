#include <iostream>
#include <fstream>
using namespace std;

int sumtotal = 0, age;
string fname, lname, gender2;
char gender[1];
fstream file;	


class Census {
public:
	void censusMenu();
	void addPerson();
	void displayPersons();
	void searchPerson();
};

void Census::censusMenu() {
	system("cls");
	cout << "----------------------------------" << endl;
	cout << "         Main Menu                " << endl;
	cout << "----------------------------------" << endl;
	cout << " 1 - Add Record." << endl;
	cout << " 2 - Dispaly All Records." << endl;
	cout << " 3 - Search For Record." << endl;
	cout << " 5 - Exit." << endl;
	cout << "----------------------------------" << endl;
}

void Census::addPerson() {
	system("cls");
	cout << "----------------------------------" << endl;
	cout << "       Add New Record." << endl;
	cout << "----------------------------------" << endl;
	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter Age: ";
	cin >> age;
	cout << "Enter Gender [M/F]: ";
	cin >> gender;
	file.open("censusdb.txt", ios::out | ios::app);
	file << fname << " " << lname << " " << age << " " << gender << endl; 
	file.close();
}

void Census::displayPersons() {
	system("cls");
	cout << "----------------------------------" << endl;
	cout << "       All Records." << endl;
	cout << "----------------------------------" << endl;
	cout << "" << endl;
	file.open("censusdb.txt", ios::in);
	if (!file)
	{
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "First Name\t\tLast Name\t\tAge\t\tGender" << endl;
		file >> fname >> lname >> age >> gender; 
		while(!file.eof()) {
			cout << fname << "\t\t\t" << lname << "\t\t\t" << age << "\t\t\t" << gender << endl; 
			file >> fname >> lname >> age >> gender; 
		}
		system("pause");
		file.close();
	}
} 



void Census::searchPerson() {
	int count = 0;
	string fname2;
	system("cls");
	cout << "----------------------------------" << endl;
	cout << "       Search Record." << endl;
	cout << "----------------------------------" << endl;
	cout << "" << endl;
	file.open("censusdb.txt", ios::in);
	if (!file) {
		cout << "Database Failed To Open!" << endl;
	} else {
		cout << "Enter Person's First Name: ";
		cin >> fname2;
		file >> fname >> lname >> age >> gender; 
		while(!file.eof()) {
			if (fname == fname2) {
				cout << "First Name: " << fname << endl;
				cout << "Last Name: " << lname << endl;
				cout << "Age: " << age << endl;
				cout << "Gender: " << gender << endl;
				count = 1;
				break;
			}
			file >> fname >> lname >> age >> gender; 
		}
		if (count == 0) {
			cout << "No Record Not Found!" << endl;
		}
		system("pause");
		file.close();
	}
}



Census census;

int main() {
	system("color f0");
	int option, rep = 1;
	char var;
	while(rep) {
		census.censusMenu();
		cout << "Enter Prefered Option: ";
		cin >> option;
		if (option == 1) {
			do {
				census.addPerson();
				cout << endl;
				cout << "Add Another Account [y/n]:";
				cin >> var ;
			} while(var == 'y');
		} else if (option == 2) {
			census.displayPersons();
		} else if (option == 3) {
			census.searchPerson();
		} else if (option == 5) {
			cout << endl;
			return 0;
		} else {
			cout << "Invalid Option Selected!" << endl;
			cout << endl;
		}
	}
	return 0;
}

