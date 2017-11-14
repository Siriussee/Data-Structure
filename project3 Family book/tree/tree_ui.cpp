#include "tree.h"
#include <iostream>
using namespace std;
bool check_1(string choose){
	if(choose.size() == 1 && (choose == "1" || choose == "2" || choose == "3" || choose == "4" || choose == "5" || choose == "6" || choose == "7")){
			return 1;
	}
	return 0;
}
int main(){
	bool first_flag = 0;
	tree test;
	bool read_flag = 0;
	string choose;
	cout << "Read the data? Y/N" << endl;
	cin >> choose;
	if(choose.size() == 1 && (choose == "Y" || choose == "y")){
		if(!test.read()){
			cout << "PLEASE INPUT THE ROOT NAME" << endl;
						string root_name;
						cin >> root_name;
						test.init(root_name);

		}
		
	}
	while(1){
			cout << "-------------------------" << endl;
			cout << "1--------insert" << endl;
			cout << "2--------delete" << endl;
			cout << "3--------search" << endl;
			cout << "4--------reset" << endl;
			cout << "5--------display" << endl;
			cout << "6--------cal" << endl;
			cout << "7--------exit" << endl;
			cout << "-------------------------" << endl;

			cin >> choose;
			while(!check_1(choose)){
				cout << "Invalid input! Please input again" << endl;
				cin >> choose;
			}

			switch(choose[0]){
				case '1' : {
					cout << "Please input the sexual" << endl;
					cout << "0------female" << endl;
					cout << "1------male" << endl;
					bool sexual_in;
					string sexual_str;
					cin >> sexual_str;
					while(sexual_str != "0" && sexual_str != "1"){
						cout << "Invalid input! Please input 0(female) or 1(male)" << endl;
						cin >> sexual_str;

					}
					sexual_in = sexual_str[0] - '0';
					cout << "Please input the name of the person you want to insert" << endl;
					string name_me;
					cin >> name_me;
					if(test.check_duplicate(name_me)){
						cout << "Duplicate/Invalid name is not allowed" << endl;
						break;
					}


					cout << "Please input the name of the person's husband or parent" << endl;
					string name_prev;
					cin >> name_prev;
					if(test.check_existence(name_prev)){
						cout << "The husband or parent is not exist" << endl;
						break;
					}
					if(test.insertNode(name_prev, name_me, sexual_in)){
						cout << "-------------------------------" << endl;
						cout << "Insert successfully" << endl;
						cout << "-------------------------------" << endl;
					}
					break;
				}
				case '2' : {
					cout << "Please input the name you want to delete" << endl;
					string name_in;
					cin >> name_in;
					if(test.check_existence(name_in)){
						cout << "------------------------------" << endl;
						cout << "No such person" << endl;
						cout << "------------------------------" << endl;
						break;
					}
					test.Delete(name_in);
					cout << "-----------------------------------" << endl;
					cout << "Delete successfully" << endl;
					cout << "-----------------------------------" << endl;
					break;
				}
				case '3' : {
					cout << "Please input the name you want to search" << endl;
					string name_in;
					cin >> name_in;
					if(test.check_existence(name_in)){
						cout << "------------------------------" << endl;
						cout << "No such person" << endl;
						cout << "------------------------------" << endl;
						break;
					}
					test.search(name_in);
					break;
				}
				case '4' : {
					cout << "Are you sure to reset the family tree? Y/N" << endl;
					string op;
					cin >> op;
					if(op == "Y" || op == "y"){
						test.clear();

						//first_flag = 0;
						//read_flag = 0;
						cout << "-------------------------" << endl;
						cout << "Reset successfully" << endl;
						cout << "-------------------------" << endl;
						cout << "PLEASE INPUT THE ROOT NAME" << endl;
						string root_name;
						cin >> root_name;
						test.init(root_name);
					}
					else{

						cout << "-----------------------------" << endl;
						cout << "Reset canceled" << endl;
						cout << "-----------------------------" << endl;
					}

					
					break;

				}

				case '5' : {
					test.pre_show();
					break;
				}

				case '6': {
					test.cal();
					break;
				}

				case '7' : {
					test.write();
					return 0;
				}

				default:break;
			}	
			string buffer;
			cout << "Press Enter to continue" << endl;
			getline(cin, buffer);
			getline(cin, buffer);


		}
		

		
return 0;	

}