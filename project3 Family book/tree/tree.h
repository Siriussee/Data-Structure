#ifndef _TREE_H_
#define _TREE_H_
#include <string>
using std::string;
typedef struct node{
	bool sexual;
	string name;
	node* left;
	node* right;
	node* prev;
	int id;
	node():sexual(0),name(""),left(NULL), right(NULL), prev(NULL), id(0){}
}node;
class tree{
public:
	tree();
	~tree();
	void Delete(string name_in);
	void init(string name_in); //must be one man
	void clear();
	bool deleteNode();
	bool insertNode(string an, string name_in, bool sexual_in);
	node* searchNode(string name_in);
	void pre_order(node* &copy, node* root, string name_in, int count);
	void pre_show();
	void insertWifeNode(string hus, string name_in);
	void search(string name_in);
	void write();
	void labelNumber();
	void in_order_lable(node* root);
	void pre_order_write(node* root);
	bool read();
	bool check_duplicate(string name_in);
	bool check_existence(string name_in);
	void cal();

private:
	node* root;
	int size;
	int f_num;
	int m_num;
	int count = 0;
	void clear_helper(node* &root); // reference
	void pre_show_helper(node* root, int space, bool dir);
	

};
#endif