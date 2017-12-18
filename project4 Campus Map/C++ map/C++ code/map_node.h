#include <iostream>
using namespace std;
class map_node {
private:
    string name;
    int id;
    string description;
public:
    map_node();
    map_node(int id_, string name_, string description_);
    ~map_node();
    string get_name();
    string get_description();
    int set_id();
    int get_id();
    bool change_name(string);
    bool change_description(string);
};