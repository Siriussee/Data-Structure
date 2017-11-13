#include "tree.h"
#include <iostream>
using namespace std;
int main(){
	tree test;
	/*cout << "THIS IS YALI'S FAMILY TREE" << endl;
	cout << "NOW PLEASE INPUT HOW MANY PEOPLE YOU WANT TO INSERT?" << endl;
	int num = 0;
	cin >> num;
	cout << "PLEASE INPUT THE ROOT NAME" << endl;
	string root_name;
	cin >> root_name;
	test.init(root_name);
	test.pre_show();
	for (int i = 1; i < num; i++){
		cout << "(your father/mother's name, your name. sex)" << endl;
		string an_in;
		string myname;
		bool sex_in;
		cin >> an_in >> myname >> sex_in;
		test.insertNode(an_in, myname, sex_in);
		test.pre_show();
	}*/
	cout << "****************read part*****************" << endl;
	test.read();
	test.pre_show();
	cout << "****************insert part****************" << endl;
	cout << "THIS IS YALI'S FAMILY TREE" << endl;
	cout << "NOW PLEASE INPUT HOW MANY PEOPLE YOU WANT TO INSERT?" << endl;
	int num = 0;
	cin >> num;
	/*cout << "PLEASE INPUT THE ROOT NAME" << endl;
	string root_name;
	cin >> root_name;
	test.init(root_name);
	test.pre_show();*/
	for (int i = 0; i < num; i++){
		cout << "(your father/mother's name, your name. sex)" << endl;
		string an_in;
		string myname;
		bool sex_in;
		cin >> an_in >> myname >> sex_in;
		test.insertNode(an_in, myname, sex_in);
		test.pre_show();
	}
	cout << "*************Search part***************" << endl;
	string totest;
	cin >> totest;
	test.search(totest);

	cout << "****************write part***************" << endl;
	test.write();

	return 0;
}