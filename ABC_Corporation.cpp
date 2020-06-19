#include <iostream>
#include <vector>
using namespace std;

/*Solution no.2
#include<vector> header added.
I used vector since vector by definition is a dynamic-sized array which has ability to resize itself, compared to an array
which makes things harder since you have to shift every element if you want to delete an element and you cannot assign elements directly, you need to initialize first. So using vectors makes things easier than using an array.

*I used system("CLS") to clear the console, just to make things cleaner and easier to see. (Only works on windows)
*I used system("pause") to get user input, just to have a confirmation before going to the menu (after adding, editing, deleting, searching, displaying data)
*/ 

struct employee
{
	char id[99];
	char name[40];
	char gender;
	float dailySalary;
	float daysWorked;
	float deductions;
};

void displayMenu()
{
	system("CLS"); //clear console
	cout << "===================================\n";
	cout << "ABC Corporation Employees' Records\n";
	cout << "==================================\n";
	cout << "[1] - Add Record\n";
	cout << "[2] - Delete Record\n";
	cout << "[3] - Edit Record\n";
	cout << "[4] - Display All Records (Sorted in ascending order according to net take-home pay)\n";
	cout << "[5] - Display employee record with highest and lowest net take-home pay\n";
	cout << "[6] - Search Employee Record by ID\n";
	cout << "=================================\n";
}

void addRecord(vector<employee> &e)
{
	employee n;
	system("CLS"); //clear console
	cout << "New Record Account\n";
	cout << "ID: "; cin >> n.id; 
	//Check if id is thesame
	string idg, idc = n.id; 
	for(int i = 0; i < e.size(); ++i){
		//Convert to string for comparing
		idg = e[i].id;
		if(idc == idg){
			cout << "Duplicate ID found! Account will not be recorded!\n";
			system("pause");
			//Do not go further since duplicate id is found.
			return;
		}
	}
	cout << "Name: ";
	string s, g;
	cin.ignore();
	getline(cin, s);
	//Check if character length is greater than maximum size, ask until valid.
	while(s.length() > 40){
		cout << "Name is too long! Please try again.\n";
		cout << "Name: ";
		cin.ignore();
		getline(cin, s);
	}
	//Apply string to character conversion.
	for(int i = 0; i < s.length(); ++i) n.name[i] = s[i];
	cout << "Gender: "; cin >> g;
	//Check if character length is greater than 1, ask until valid.
	while(g.length() > 1){
		cout << "Please type only one character (M or N or etc.).\n";
		cout << "Gender: "; cin >> g;
	}
	n.gender = g[0];
	cout << "Basic Daily Salary: "; cin >> n.dailySalary;
	cout << "Days Worked: "; cin >> n.daysWorked;
	cout << "Deductions: "; cin >> n.deductions;
	e.push_back(n);
	cout << "Record added!\n";
	system("pause"); //Just a short pause
}

void deleteRecord(vector<employee> &e)
{
	system("CLS"); //clear console
	string idg, idc;
	cout << "Enter ID to delete: "; cin >> idg;
	for(int i = 0; i < e.size(); ++i){
		//Convert to string for comparing
		idc = e[i].id;
		if(idc == idg){
			e.erase(e.begin()+i);
			cout << "Record Deleted!\n\n";
			system("pause");
			//Record found and deleted, no need to go further.
			return;
		}
	}
	cout << "ID not found!\n\n";
	system("pause");
}

void editRecord(vector<employee> &e)
{
	system("CLS"); //clear console
	string idg, idc;
	int i, con = 0, cmd = -1, index;
	cout << "Enter ID to edit: "; cin >> idg;
	for(i = 0; i < e.size(); ++i){
		//convert to string for comparing
		idc = e[i].id;
		if(idc == idg){
			//if found id, get index and ask for what to edit.
			con = 1;
			index = i;
			break;
		}
	}
	if(con == 0){
		cout << "ID not found!\n";
		system("pause");
		//Id is not found, no need to go further.
		return;
	}
	else{
		//Ask what to edit while command is not equal to 0 / Exit.
		while(cmd != 0){
			system("CLS");
			cout << "Select data to edit: \n[1] - Name\n[2] - Gender\n[3] - Daily Salary\n[4] - Days Worked\n[5] - Deductions\n[0] - Exit\n";
			cout << "Enter command: "; cin >> cmd;
			if(cmd == 1){
				for(int i = 0; i < 40; ++i) e[index].name[i] = '\0'; //reset the characters
				cout << "Enter New Name: ";
				string s;
				cin.ignore();
				getline(cin, s);
				//Ask until character length is valid.
				while(s.length() > 40){
					cout << "Name is too long! Please try again.\n";
					cout << "Name: ";
					cin.ignore();
					getline(cin, s);
				}
				//Apply string to character conversion.
				for(int i = 0; i < s.length(); ++i) e[index].name[i] = s[i];
				cout << "New name updated!\n";
				system("pause");
			}if(cmd == 2){
				cout << "Enter New Gender: "; 
				string g; cin >> g;
				//Ask until character length is valid.
				while(g.length() > 1){
					cout << "Please type only one character (M or N or etc.).\n";
					cout << "Enter New Gender: "; cin >> g;
				}
				e[index].gender = g[0];
				cout << "New gender updated!\n";
				system("pause");
			}if(cmd == 3){
				cout << "Enter New Daily Salary: "; cin >> e[index].dailySalary;
				cout << "New Daily Salary updated!\n";
				system("pause");
			}
			if(cmd == 4){
				cout << "Enter New Days Worked: "; cin >> e[index].daysWorked;
				cout << "New Days Worked updated!\n";
				system("pause");
			}
			if(cmd == 5){
				cout << "Enter New Deductions: "; cin >> e[index].deductions;
				cout << "New Days Worked updated!\n";
				system("pause");
			}
		}
	}
}

void displayRecords(vector<employee> e)
{
	system("CLS"); //clear console
	cout << endl;
	int i, j;
	//sort by net take home pay using bubble sort algorithm
	for (i = 0 ; i < e.size() ; i++) {    
	    for(j = 0; j < e.size(); j++){ 
	    	float hp1, hp2;
	    	hp1 = (e[i].dailySalary * e[i].daysWorked) - e[i].deductions;
	    	hp2 = (e[j].dailySalary * e[j].daysWorked) - e[j].deductions;
	        if(hp1 > hp2) swap(e[i], e[j]);
	    }
	}

	//Display to console
	cout << "===ID===NAME===GENDER===DAILYSALARY===DAYSWORKED===DEDUCTIONS\n\n";
	for(i = 0; i < e.size(); ++i){
		cout << "   " << e[i].id << "\t" << e[i].name << "\t" << e[i].gender << "\t" << e[i].dailySalary << "\t" << e[i].daysWorked << "\t" << e[i].deductions << endl; 
	}
	cout << endl;
	system("pause");
}

void displayRecordHighLow(vector<employee> e)
{
	system("CLS"); //clear console
	float hp, h = 0, l;
	int i, hInd, lInd;
	//search for highest net take home pay
	for(i = 0; i < e.size(); ++i){
		hp = (e[i].dailySalary * e[i].daysWorked) - e[i].deductions;
		if(hp > h){
			h = hp;
			hInd = i;
		}
	}
	l = h;
	//seach for lowest net take home pay
	for(i = 0; i < e.size(); ++i){
		hp = (e[i].dailySalary * e[i].daysWorked) - e[i].deductions;
		if(hp < l){
			l = hp;
			lInd = i;
		}
	}

	//Display to console
	cout << "========================HIGHEST==============================\n";
	cout << "===ID===NAME===GENDER===DAILYSALARY===DAYSWORKED===DEDUCTIONS\n\n";
	cout << "   " << e[hInd].id << "\t" << e[hInd].name << "\t" << e[hInd].gender << "\t" << e[hInd].dailySalary << "\t" << e[hInd].daysWorked << "\t" << e[hInd].deductions << "\n\n"; 
	cout << "========================LOWEST==============================\n";
	cout << "   " << e[lInd].id << "\t" << e[lInd].name << "\t" << e[lInd].gender << "\t" << e[lInd].dailySalary << "\t" << e[lInd].daysWorked << "\t" << e[lInd].deductions << "\n\n";
	system("pause"); 
	
}

void searchRecord(vector<employee> &e)
{
	system("CLS");
	string idg, idc;
	cout << "Enter ID to search: "; cin >> idg;
	for(int i = 0; i < e.size(); ++i){
		//Convert to string for comparing
		idc = e[i].id;
		if(idc == idg){
			//If id is found, display data to console.
			cout << "==================RECORD-FOUND==============================\n";
			cout << "===ID===NAME===GENDER===DAILYSALARY===DAYSWORKED===DEDUCTIONS\n\n";
			cout << "   " << e[i].id << "\t" << e[i].name << "\t" << e[i].gender << "\t" << e[i].dailySalary << "\t" << e[i].daysWorked << "\t" << e[i].deductions << "\n\n"; 
			system("pause");
			//No need to go further
			return;
		}
	}
	cout << "ID not found!\n\n";
	system("pause");
}

int main()
{
	vector<employee> e;
	bool ml = true; //MainLoop
	int cmd;
	
	while(ml){
		displayMenu();
		cout << "Enter your choice: "; cin >> cmd;
	
		if(cmd == 1) addRecord(e);
		else if(cmd == 2) deleteRecord(e);
		else if(cmd == 3) editRecord(e); 
		else if(cmd == 4) displayRecords(e);
		else if(cmd == 5) displayRecordHighLow(e);
		else if(cmd == 6) searchRecord(e);
		else if(cmd == 0) ml = false;
		else{
			cout << "Invalid command! \n";
			system("pause");
		}
	}
	return 0;
}