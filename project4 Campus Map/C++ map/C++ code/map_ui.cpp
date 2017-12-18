#include "schoolmap.h"
#include <iostream>
using namespace std;
bool check_1(string choose){
	if(choose.size() == 1 && (choose == "1" || choose == "2" || choose == "3" || choose == "4")){
			return 1;
	}
	return 0;
}
int main(){
	school_map test;
	test.read();
	bool flag_to_menu = 0;
	while(1){

		cout << "------------------MAP------------------" << endl;
		cout << "1---Get Info of Spot" << endl;
		cout << "2---Find Shortest Path" << endl;
		cout << "3---Modify the Map" << endl;	
		cout << "4---Exit" << endl;
		cout << "---------------------------------------" << endl;
		string choose;
		cin >> choose;
		while(!check_1(choose)){
			cout << "-----------------------------------" << endl;
				cout << "Invalid input! Please input again" << endl;
				cout << "-----------------------------------" << endl;
				cin >> choose;
		}

		switch(choose[0]){
			case '1':{
				test.show_all_spot();
				int return_flag = 0;
				while(1){
					//success_flag = 0;
					cout << "Please input the name of id(r to return and h to show list)" << endl;
					string input;
					string test2;
					getline(cin, input);
					//cout << "p1 input " << input << endl;
					while(input.empty()){
						getline(cin, input);
						//cout << "p2 input " << input << endl;	
					}
					bool num_flag = 1;
					for(int i = 0; i < input.size(); i++){
						if(!isdigit(input[i])){num_flag = 0;}
					}
					int input_num;
					//cin >> input;
					if(num_flag){
						
						bool success_flag = 0;
						sscanf(input.c_str(), "%d", &input_num);	
					}
					else{
						input_num = 0;
					}
					bool success_flag = 0;
					if(input == "r"){flag_to_menu = 1; break;}
					if(input == "h"){test.show_all_spot(); continue;}
					if(test.show_one_description(input) || test.show_one_description(input_num)){
							success_flag = 1;
					}//maybe some bug in input_num
					while(!success_flag){
						cout << "-----------------------------------" << endl;
						cout << "Invalid input, please input again" << endl;
						cout << "-----------------------------------" << endl;
						getline(cin, input);
						sscanf(input.c_str(), "%d", &input_num);
						if(input == "r"){flag_to_menu = 1; return_flag = 1;break;}
						if(test.show_one_description(input) || test.show_one_description(input_num)){
							success_flag = 1;
						}
					}
					if(return_flag){break;}

				}
				
				

				break;
			}
			case '2':{
				while(1){
					cout << "Find the shortest path" << endl;
					string a_spot;
					while(1){
						cout << "Please input the name of the start spot" << endl;
							
						getline(cin, a_spot);
						while(a_spot.empty()){
							getline(cin, a_spot);
						}
						if(a_spot == "r"){flag_to_menu = 1; break;}
						if(test.check_exist(a_spot)){break;}
						cout << "-----------------------------------" << endl;
						cout << "No such spot." << endl;	
						cout << "-----------------------------------" << endl;
					}
					if(flag_to_menu){break;}
					string b_spot;
					while(1){
						cout << "Please input the name of the end spot" << endl;
							
						getline(cin, b_spot);
						while(b_spot.empty()){
							getline(cin, b_spot);
						}
						if(b_spot == "r"){flag_to_menu = 1; break;}
						if(test.check_exist(b_spot)){break;}
						cout << "-----------------------------------" << endl;
						cout << "No such spot." << endl;
						cout << "-----------------------------------" << endl;
					}
					if(flag_to_menu){break;}
					test.find_least_way(a_spot, b_spot);
				}
				





				break;
			}
			case '3':{
				while(1){
					cout << "1----Add Edge" << endl;
					cout << "2----Delete Edge" << endl;
					string choose2;
					cin >> choose2;
					while(choose2 != "1" && choose2 != "2" && choose2 != "r"){
						cout << "-----------------------------------" << endl;
						cout << "Invalid input, please input again" << endl;
						cout << "-----------------------------------" << endl;
						cin >> choose2;
					}
					if(choose2 == "r"){flag_to_menu = 1; break;}
					bool flag_sub = 0;
					switch(choose2[0]){
						
						case '1': {
							string a_spot;
							while(1){
								cout << "Please input the name of the start spot" << endl;
								
								getline(cin, a_spot);
								while(a_spot.empty()){
									getline(cin, a_spot);
								}
								if(a_spot == "r"){flag_sub = 1; break;}
								if(test.check_exist(a_spot)){break;}
								cout << "-----------------------------------" << endl;
								cout << "No such spot." << endl;	
								cout << "-----------------------------------" << endl;
							}
							if(flag_sub){break;}
							string b_spot;
							while(1){
								cout << "Please input the name of the end spot" << endl;
								
								getline(cin, b_spot);
								while(b_spot.empty()){
									getline(cin, b_spot);
								}
								if(b_spot == "r"){flag_sub = 1; break;}
								if(test.check_exist(b_spot)){break;}
								cout << "-----------------------------------" << endl;
								cout << "No such spot." << endl;
								cout << "-----------------------------------" << endl;
							}
							if(flag_sub){break;}
							int num;
							while(1){
								int re_flag = 0;
								cout << "Please enter the length" << endl;
								string in_num;
								cin >> in_num;
								if(in_num == "r"){flag_sub = 1; break;}
								for(int i = 0; i < in_num.size(); i++){
									if(!isdigit(in_num[i])){re_flag = 1; break;}
								}	
								if(re_flag){
									cout << "-----------------------------------" << endl;
									cout << "Invalid! Please input num" << endl; 
									cout << "-----------------------------------" << endl;
									continue;}
								
								sscanf(in_num.c_str(), "%d", &num);
								break;

							}
							if(flag_sub){break;}
							string name_in;
							cout << "Please input the name of the road" << endl;
							getline(cin, name_in);
							while(name_in.empty()){
								getline(cin, name_in);
							}
							if(name_in == "r"){break;}
							bool auto_in;
							while(1){
								cout << "For auto or not?(1 for yes, 0 for not)" << endl;
								string auto_str;
								cin >> auto_str;
								if(auto_str == "r"){flag_sub = 1; break;}
								if(auto_str != "0" && auto_str != "1"){
									cout << "-----------------------------------" << endl;
									cout << "Invalid input, please input again" << endl;
									cout << "-----------------------------------" << endl;
									continue;
								}
								auto_in = auto_str[0] - '0';
								break;
							}
							if(flag_sub){break;}
							if(!test.add_side(a_spot, b_spot, num, name_in, auto_in)){
								cout << "error" << endl;
							}
							else{
								cout << "-----------------------------------" << endl;
								cout << "Add successfully" << endl;
								cout << "-----------------------------------" << endl;
							}


						


						
						break;
					}
					case '2': {
						string a_spot;
						while(1){
							cout << "Please input the name of the start spot" << endl;
							
							getline(cin, a_spot);
							while(a_spot.empty()){
								getline(cin, a_spot);
							}
							if(a_spot == "r"){flag_sub = 1; break;}
							if(test.check_exist(a_spot)){break;}
							cout << "-----------------------------------" << endl;
							cout << "No such spot." << endl;	
							cout << "-----------------------------------" << endl;
						}
						if(flag_sub){break;}
						string b_spot;
						while(1){
							cout << "Please input the name of the end spot" << endl;
							
							getline(cin, b_spot);
							while(b_spot.empty()){
								getline(cin, b_spot);
							}
							if(b_spot == "r"){flag_sub = 1; break;}
							if(test.check_exist(b_spot)){break;}
							cout << "-----------------------------------" << endl;
							cout << "No such spot." << endl;
							cout << "-----------------------------------" << endl;
						}
						if(flag_sub){break;}
						if(!test.delete_side(a_spot, b_spot)){
							cout << "-----------------------------------" << endl;
							cout << "There is no road between them" << endl;
							cout << "-----------------------------------" << endl;
						}
						else{
							cout << "-----------------------------------" << endl;
							cout << "Delete successfully!" << endl;
							cout << "-----------------------------------" << endl;
						}
						break;
					}
					default: break;
				}

				}
				
				break;
			}
			case '4': {test.write(); return 0;}





			default:break;
		}
	

		if(!flag_to_menu){
			string buffer;
			cout << "Press Enter to continue" << endl;
			getline(cin, buffer);	
		}
		flag_to_menu = 0;
		
		//getline(cin, buffer);
	}
	

}