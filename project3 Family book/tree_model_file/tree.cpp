#include "tree.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
	tree::tree():size(0),f_num(0),m_num(0), root(NULL), count(0){

	}
	tree::~tree(){
		clear();
	}
	void tree::write(){
		//fopen size
		fstream write_stream;
		write_stream.open("tree.txt", ios::out);
		write_stream << size << endl;
		write_stream.close();
		labelNumber();
		node* temp = root;
		pre_order_write(temp);
	}
	void tree::labelNumber(){
		node* temp = root;
		count = 0;
		in_order_lable(temp);
	}
	void tree::in_order_lable(node* root){ //need yinyong?
		if(root != NULL){
			in_order_lable(root->left);
			//fstream write_stream;
			//write_stream.open("tree.txt", ios::out | ios::app);
			root->id = count++;
			//write_stream >> root->id >> root->name >> root->sexual >> endl;
			//write_stream.close();
			in_order_lable(root->right);
		}
	}
	void tree::pre_order_write(node* root){
		if(root != NULL){
			fstream write_stream;
			write_stream.open("tree.txt", ios::out | ios::app);
			write_stream << root->id << " " << root->name << " " << root->sexual << endl;
			cout << root->id << " " << root->name << " " << root->sexual << endl;
			write_stream.close();
			//write fwrite? root->id root->name root->sex
			pre_order_write(root->left);
			pre_order_write(root->right);
		}

	}
	void tree::read(){
		
		fstream read_stream;
		read_stream.open("tree.txt", ios::in);
		//open read the size
		read_stream >> size;
		cout << "size " << size << endl;
		int t_id = 0;
		string t_name;
		bool t_sexual = 0;
		read_stream >> t_id >> t_name >> t_sexual;
		cout << t_id << t_name << t_sexual << endl;
		root = new node;
		root->id = t_id;
		root->name = t_name;
		root->sexual = t_sexual;


		for(int i = 1; i < size; i++){
			node* temp = root;
			node* prev;
			node* one = new node;
			read_stream >> t_id >> t_name >> t_sexual;
			one->id = t_id;
			one->name = t_name;
			one->sexual = t_sexual;
			
			while(temp != NULL){
				prev = temp;
				temp = t_id > temp->id ? temp->right : temp->left;
			}

			if(t_id > prev->id){
				prev->right = one;
				one->prev = prev;
			}
			else{
				prev->left = one;
				one->prev = prev;
			}

			//temp = one;
			//size++; 


		}
	}
	void tree::init(string name_in){//must be one man
		root = new node;
		root->name = name_in;
		root->sexual = 1; 
		size = 1;
		m_num = 0;
		if(root == NULL){cout << "!!" << endl;}
	}
	void tree::clear(){
		clear_helper(root);
		f_num = 0;
		m_num = 0;
		size = 0;
	}
	void tree::clear_helper(node* root){
		if(root->left != NULL){
			clear_helper(root->left);
		}
		if(root->right != NULL){
			clear_helper(root->right);
		}
		delete root;
	}
	bool tree::deleteNode(){} //transsexual?
	bool tree::insertNode(string an, string name_in, bool sexual_in){
		if(searchNode(an) == NULL){cout << "ha?" << endl;return 0;}
		//node* ancestor = searchNode(an);
		node* new_node = new node;
		new_node->name = name_in;
		new_node->sexual = sexual_in;
		node* insert_helper;
		insert_helper = searchNode(an);
		if(insert_helper == NULL){cout << "kkk" << endl;}

		cout << "big-test" << endl;
		cout << insert_helper->name << endl;
		if(sexual_in == 1){//insert children
			cout << "insert_helper->sexual " << insert_helper->sexual << endl;
			if(insert_helper->sexual == 0){ // mother
				cout << "mom" << endl;
				while(insert_helper->right != NULL){
					cout << "test here" << endl;
					insert_helper = insert_helper->right;

				}

				insert_helper->right = new_node;
				cout << "hhh" << endl;
				new_node->prev = insert_helper;
			}
			else{ //father
				if(insert_helper->left == NULL){//single??
				//insert wift
					//insert_helper->left = new_node;
					return 0;
				}	
				else{// have wife
					insert_helper = insert_helper->left;//mother pointer
					while(insert_helper->left != NULL){
						insert_helper = insert_helper->left;
					}
					//insert to the newest wife
					while(insert_helper->right != NULL){
						insert_helper = insert_helper->right;
					}
					insert_helper->right = new_node;
					new_node->prev = insert_helper;
				}
			}
			m_num++;
			size++;
		}
		else{ //insert a wife
			while(insert_helper->left != NULL){
				insert_helper = insert_helper->left;

			}
			insert_helper->left = new_node;
			new_node->prev = insert_helper;
			f_num++;
			size++;


		}
		
		return 1;


	}
	void tree::pre_order(node* &copy, node* root, string name_in, int count){
		//how to find a node as fast as possible
		/*if(root != NULL && root->name == name_in){
			cout << "this" << endl;
			return root;
		}*/
		//if(count == size){return NULL;}
		if(root != NULL){
			if(root != NULL && root->name == name_in){
				cout << "this" << endl;

				copy = root;
				//return root;
			}
			if(count == size){return;}
			/*copy = */ pre_order(copy, root->left, name_in, count+1);
			/*copy = */ pre_order(copy, root->right, name_in, count+1);
			//return copy;	
		}
		/*if(count == 0){
			return NULL;''
		}*/
		
	}

	node* tree::searchNode(string name_in){
		node* temp = root;
		node* copy = NULL;
		pre_order(copy, temp, name_in, 0);
		return copy;
		//return copy;


	}

	void tree::pre_show(){
		node* temp = root;
		int space = 0;
		bool dir = 1;
		cout << "------------------------------" << endl;
		pre_show_helper(temp, space, dir);
		cout << "------------------------------" << endl;
		cout << endl;

	}

	void tree::pre_show_helper(node* root, int space, bool dir){

		if(root != NULL){
			if(dir != root->sexual){
				space += 2;
				dir = root->sexual;
			}
			for(int i = 0; i < space; i++){
				cout << " ";
			}
			cout << root->name << "(" << root->sexual << ")" << endl;
			
			pre_show_helper(root->left, space, dir);////////////
			pre_show_helper(root->right, space, dir);/////////
			
		}
		
	}

	void tree::search(string name_in){
		node* target = searchNode(name_in);
		//bool bro = 0;
		vector<string> bro_name;
		vector<string> step_mother_name;
		if(target == NULL){
			cout << "No such person" << endl;
			return;
		}
		node* tmp = target;
		cout << "-------------------" << endl;
		if(target->sexual == 1){
			tmp = tmp->prev;
			//if(tmp->sexual != 0){bro = 1; }
			while(tmp->sexual != 0){
				bro_name.push_back(tmp->name);
				tmp = tmp->prev;
			
			}
			cout << "The person's mom is " << tmp->name << endl;
			node* updownp = tmp;
			while(updownp->left != NULL){
				step_mother_name.push_back(updownp->left->name);
				updownp = updownp->left;
			}
			tmp = tmp->prev;
			while(tmp->sexual != 1){
				step_mother_name.push_back(tmp->name);
				tmp = tmp->prev;
			}
			cout << "The person's dad is " << tmp->name << endl;	
			if(bro_name.size()){
				cout << "The person has " << bro_name.size() << " bros:" << endl;
				for(auto c : bro_name){
					cout << c << endl;
				}
			}

			if(step_mother_name.size()){
				cout << "The person has " << step_mother_name.size() << " stepmother:" << endl;
				for(auto c : step_mother_name){
					cout << c << endl;
				}
			}


		}
		
		

	}