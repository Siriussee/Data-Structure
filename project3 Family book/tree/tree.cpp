#include "tree.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
	tree::tree():size(0),f_num(0),m_num(0), root(NULL), count(0){

	}
	tree::~tree(){
		if(root != NULL){
			clear();	
		}
		
	}
	void tree::cal(){
		cout << "The number of the member in this family tree: " << f_num + m_num << endl;
		cout << "The number of female in this family tree: " << f_num << endl;
		cout << "The number of male in this family tree: " << m_num << endl;
		cout << "for convinience " << size << endl;

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
	/*new*/
	void tree::Delete(string name_in){

		bool left_flag = 0;

		node* target = searchNode(name_in);

		if(target == root){clear(); return;}
		node* store1 = target;
		if(target->sexual == 1){
			node* s1 = target;

			target->prev->right = target->right;
			if(target->right){
				target->right->prev = target->prev; 	
			}

			if(target->left != NULL){
				clear_helper(target->left);	
			}
			
			node* store = target;
			delete target;
			m_num--;

			size--;
			if(store->prev->sexual == 0 && store->prev->name == "()" && store->right == NULL){
				Delete(store->prev->name);
			}
			pre_show();
		}
		else{
			if(target->right != NULL){
				target->name = "()";	
				f_num--;
			}
			else if(target->name == "()"){
				target->prev->left = target->left;
				delete target;
				size--;
			}
			else{
				target->prev->left = target->left;
				delete target;
				size--;
				f_num--;
			}
			
		}
		

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
			//cout << root->id << " " << root->name << " " << root->sexual << endl;
			write_stream.close();
			//write fwrite? root->id root->name root->sex
			pre_order_write(root->left);
			pre_order_write(root->right);
		}

	}
	bool tree::read(){
		
		fstream read_stream;
		read_stream.open("tree.txt", ios::in);
		//open read the size
		read_stream >> size;
		if(size != 0){
			int t_id = 0;
		string t_name;
		bool t_sexual = 0;
		read_stream >> t_id >> t_name >> t_sexual;
		if(t_sexual){m_num++;}
		else{f_num++;}
		//cout << t_id << t_name << t_sexual << endl;
		root = new node;
		root->id = t_id;
		root->name = t_name;
		root->sexual = t_sexual;


		for(int i = 1; i < size; i++){
			node* temp = root;
			node* prev;
			node* one = new node;
			read_stream >> t_id >> t_name >> t_sexual;
			if(t_sexual){m_num++;}
			else if(t_sexual == 0 && t_name != "()"){f_num++;}
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

			


		}

		return 1;
		}

		return 0;

		//cout << "size " << size << endl;
		
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
		if(root == NULL){return;}
		clear_helper(root);
		f_num = 0;
		m_num = 0;
		size = 0;
	}
	void tree::clear_helper(node* &root){
		if(root->left != NULL){
			clear_helper(root->left);
		}
		if(root->right != NULL){
			clear_helper(root->right);
		}
		if(root->sexual == 0){f_num--;}
		else{m_num--;}
		delete root;
		root = NULL;
		size--;
	}
	bool tree::check_duplicate(string name_in){
		if(searchNode(name_in) != NULL || name_in == "()"){return 1;}
		return 0;
	}
	bool tree::check_existence(string name_in){
		if(searchNode(name_in) == NULL || name_in == "()"){return 1;}
		return 0;
	}
	bool tree::deleteNode(){} //transsexual?
	bool tree::insertNode(string an, string name_in, bool sexual_in){
		
		node* new_node = new node;
		new_node->name = name_in;
		new_node->sexual = sexual_in;
		node* insert_helper;
		insert_helper = searchNode(an);
		
		
		if(sexual_in == 1){//insert children
			
			if(insert_helper->sexual == 0){ // mother
				
				while(insert_helper->right != NULL){
					
					insert_helper = insert_helper->right;

				}

				insert_helper->right = new_node;
				
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
		
		if(root != NULL){
			if(root != NULL && root->name == name_in){
				//cout << "this" << endl;

				copy = root;
				//return root;
			}
			if(count == size){return;}
			/*copy = */ pre_order(copy, root->left, name_in, count+1);
			/*copy = */ pre_order(copy, root->right, name_in, count+1);
			//return copy;	
		}
		
		
	}

	node* tree::searchNode(string name_in){
		node* temp = root;
		node* copy = NULL;
		pre_order(copy, temp, name_in, 0);
		return copy;
		//return copy;


	}

	void tree::pre_show(){
		if(root == NULL){return;}
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
			if(root->sexual == 1){ //male 
				pre_show_helper(root->left, space, dir);////////////
				pre_show_helper(root->right, space, dir);/////////	
			}
			else{//female
				pre_show_helper(root->right, space, dir);////////////
				pre_show_helper(root->left, space, dir);/////////	

			}
			
			
		}
		
	}

	void tree::search(string name_in){
		node* target = searchNode(name_in);
		//bool bro = 0;
		vector<string> bro_name;
		vector<string> step_mother_name;
		
		if(target == root){//if the name is the ancestor's
			cout << name_in << " is the ancestor." << endl;
			return;
		}
		node* tmp = target;
		node* tmpb = target;
		cout << "-------------------" << endl;
		if(target->sexual == 1){
			tmp = tmp->prev;
			//if(tmp->sexual != 0){bro = 1; }
			while(tmp->sexual != 0){
				bro_name.push_back(tmp->name);
				tmp = tmp->prev;/*bro part*/
			
			}
			while(tmpb->right != NULL){
				bro_name.push_back(tmpb->right->name);
				tmpb = tmpb->right;/*bro part*/
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

			if(target->left != NULL){
				cout << "The person's wife is " << target->left->name << endl;
			}/*wife part*/
			vector<string> sons;
			node* tempson = target->left->right;
			while(tempson != NULL){
				sons.push_back(tempson->name);
				tempson = tempson->right;
			}
			if(sons.size()){
				cout << "The person has " << sons.size() << " son(s)" << endl;
				for(auto c : sons){
					cout << c << endl;
				}
			}


		}
		else{
			cout << "The person's husband: " << target->prev->name << endl;

			vector<string> sons;
			node* tempson = target->right;
			while(tempson != NULL){
				sons.push_back(tempson->name);
				tempson = tempson->right;
			}
			if(sons.size()){
				cout << "The person has " << sons.size() << " son(s)" << endl;
				for(auto c : sons){
					cout << c << endl;
				}
			}

		}

		cout << "---------------------------------" << endl;
		
		

	}