#include <iostream>
#define MAX_SIZE 100
/*----------------------------------------------------
map_node record the detail of each node include name ,
id, description and support to change its name and de
-scription but not id;

school_map record two grapgh(walk or autocar) 

The functions of read and write int .txt:
for each school_map ,the first line record how many
map_node(m) and how many side(n);for the next m lines,
each lines include the detail of each map_node;and for
the next n1 lines recode each side its start,end,length,
name,and autocar(y or n)
(It means for each school_map we have 1 + m + n lines
----------------------------------------------------*/



#include "map_node.h"
#include "map_side.h"
#include <map>
#include <string>
using namespace std;

class school_map {
private:
    map_node node_info[MAX_SIZE];
    map_side side_info[MAX_SIZE][MAX_SIZE];
    map<string, int> reference;
    int visited[MAX_SIZE];
    int node_size;
    int side_size;
    char change[MAX_SIZE];
    //bool change_flag;
public:
    school_map();
    ~school_map();
    void read();  // read the data from .txt
    void input();
    bool write(); // write the data into .txt
    void init(int node_num, int side_num);
    bool test(int id_in);
    int get_node_size();
    int get_side_size();
    bool add_side(int a_spot, int b_spot, int length, string name, bool autocar_);
    bool add_side(string a_spot, string b_spot, int length, string name, bool autocar_);
    bool delete_side(int a_spot, int b_spot);
    bool delete_side(string a_spot, string b_spot);
    bool find_least_way(int,int); //(mode == 0)->walk;(mode == 1)->autocar
    bool find_least_way(string,string); // find the least way and record their id into a int[] and return it
    void show_all_spot();
    bool show_one_description(int id);
    bool show_one_description(string name);
    bool check_exist(string in);
};