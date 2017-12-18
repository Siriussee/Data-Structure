#include "map_node.h"
map_node::map_node(int id_, string name_, string description_){
    id = id_;
    name = name_;
    description = description_;
}
map_node::map_node():id(0), name(""), description(""){

}
map_node::~map_node(){}
string map_node:: get_name() {
    return name;
}

string map_node:: get_description() {
    return description;
}

int map_node:: get_id() {
    return id;
}

bool map_node:: change_name(string new_name) {
    if(!new_name.empty()) {
        name = new_name;
        return true;
    } else {
        return false;
    }
}

bool map_node:: change_description(string new_de) {
    if(!new_de.empty()) {
        description = new_de;
        return true;
    } else {
        return false;
    } 
}