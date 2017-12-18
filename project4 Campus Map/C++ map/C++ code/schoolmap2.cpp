#define __USE_MINGW_ANSI_STDIO 0
#include "schoolmap.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
using namespace std;
school_map::school_map(){
    memset(change, 'n', sizeof(change));
}
school_map::~school_map(){}
void school_map::init(int node_num, int side_num){
    map_node toInit;
    for(int i = 0; i <= node_num; i++){
        node_info[i] = toInit;
    }
}
void school_map::read(){
    fstream read_stream;
    read_stream.open("map.txt", ios::in);
    read_stream >> node_size >> side_size;
    //cout << "node_size " << node_size << "side_size " << side_size << endl;
    string buffer;
    //cin >> buffer;
    for(int i = 1; i <= node_size; i++){
        int tmp_id;
        string tmp_name, tmp_description;
        string test2;
        //read_stream >> tmp_id >> tmp_name;
        read_stream >> tmp_id;
        getline(read_stream, test2);//got the \n
        getline(read_stream, tmp_name);
        //getline(read_stream, test2);
        getline(read_stream, tmp_description);
        reference[tmp_name] = tmp_id;
       /* cout << "test no exist" << endl;
        cout << reference["yali"] << endl;*/
        /*cout << "tmp_id: " << tmp_id << endl;
        cout << "tmp_name: " << tmp_name << endl;
        cout << "tmp_description: " << tmp_description << endl;
        cout << "test2: " << test2 << endl;*/
        //cin >> buffer;
        map_node one(tmp_id, tmp_name, tmp_description);
        node_info[i] = one;
    }
    for(int i = 1; i <= side_size; i++){
        int a, b, tmp_length;
        bool tmp_autocar;
        string tmp_name;
        string test3;
        read_stream >> a >> b >> tmp_length >> tmp_autocar;
        getline(read_stream, test3);
        getline(read_stream, tmp_name);
        map_side one(a, b, tmp_length, tmp_autocar, tmp_name);
        side_info[a][b] = one;
        side_info[b][a] = one;
    }
    /*cout <<"I am angry" << endl;
    cout << side_info[13][10].get_length() << endl;*/
    read_stream.close();
    
}
bool school_map::delete_side(int a_spot, int b_spot){
    if(a_spot <= 0 || a_spot > node_size || b_spot <= 0 || b_spot > node_size){
        return false;
    }
    //no connection from the begin
    if(side_info[a_spot][b_spot].get_length() == MAX){return false;}
    map_side empty_one;
    side_info[a_spot][b_spot] = empty_one;
    side_info[b_spot][a_spot] = empty_one;
    side_size--;
    memset(change, 'y', sizeof(change));
    return true;
}

bool school_map::delete_side(string a_spot, string b_spot){
    if(!reference[a_spot] || !reference[b_spot]){
        return false;
    }
    return delete_side(reference[a_spot], reference[b_spot]);
}

void school_map::input() {
    /*fstream read_stream;
    read_stream.open("map.txt", ios::in);*/
    cout << "Please input the number of vertex and edge" << endl;
    cin >> node_size >> side_size;
    //init(node_size, side_size);
    //input the info of all nodes
    for(int i = 1; i <= node_size; i++){
        /*cout << "set node info" << endl;
        cout << "id: " << i << endl;
        
        
        cout << "Please input the name of the spot:" << endl;
        string tmp_name;
        cin >> tmp_name;
        cout << "Please input the description of the spot:" << endl;
        string tmp_des;
        cin >> tmp_des;*/
        //map_node one(i, tmp_name, tmp_des);
        map_node one(i, "", "");
        node_info[i] = one;


    }
    cout << "---------Set edges info below---------" << endl; 
    cout << "format: a_spot b_spot name length autocar(bool)" << endl;
    for(int i = 1; i <= side_size; i++){
        //input: a_spot b_spot name length autocar(bool)
        int a, b, length;
        bool car;
        string tmp_name;
        cin >> a >> b >> tmp_name >> length >> car;
        map_side one(a, b, length, car, tmp_name);
        side_info[a][b] = one;
        side_info[b][a] = one;



    }


}

bool school_map:: write() {
    fstream write_stream;
    write_stream.open("map.txt", ios::out);
    write_stream << node_size << " " << side_size << endl;
    for(int i = 1; i <= node_size; i++){
        write_stream << node_info[i].get_id() << endl;
        write_stream << node_info[i].get_name() << endl;
        write_stream << node_info[i].get_description() << endl;
    }
    
    for(int i = 1; i <= node_size; i++){
        for(int j = 1; j <= node_size; j++){
            if(side_info[i][j].get_length() != MAX){
                map_side empty_one;
                write_stream << side_info[i][j].get_startid() << " ";
                write_stream << side_info[i][j].get_endid() << " ";
                write_stream << side_info[i][j].get_length() << " ";
                write_stream << side_info[i][j].get_autocar() << endl;
                write_stream << side_info[i][j].get_name() << endl;
                //avoid double output
                side_info[i][j] = empty_one;
                side_info[j][i] = empty_one;

            }
        }
    }

    write_stream.close();

}
bool school_map::check_exist(string in){
    if(!reference[in]){return false;}
    return true;
}

bool school_map::test(int id_in){
    if(node_info[id_in].get_id()){return 1;}
    return 0;
}

int school_map:: get_node_size() {
    return node_size;
}

int school_map:: get_side_size() {
    return side_size;
}


bool school_map::add_side(int a_spot, int b_spot, int length, string name, bool autocar_){
    if(side_size == MAX){return false;}
    if(side_info[a_spot][b_spot].get_length() != MAX || length <= 0 || a_spot <= 0 || a_spot > node_size || b_spot <= 0 || b_spot >node_size){return false;}
    map_side toAdd(a_spot, b_spot, length, autocar_, name);
    side_info[a_spot][b_spot] = toAdd;
    side_info[b_spot][a_spot] = toAdd;
    side_size++;
    //changed status
    memset(change, 'y', sizeof(change));
    return true;
} 
bool school_map::add_side(string a_spot, string b_spot, int length, string name, bool autocar_){
    if(!reference[a_spot] || !reference[b_spot]){return false;}
    return add_side(reference[a_spot], reference[b_spot], length, name, autocar_);
}
 
bool school_map::find_least_way(int a_spot, int b_spot){
    if(a_spot > node_size || a_spot <= 0 || b_spot > node_size || b_spot <= 0){return false;}
    memset(visited, 0, sizeof(visited));
    //memset(visited2, 0, sizeof(visited2));

    if(side_info[a_spot][b_spot].check_shortest() && change[a_spot] == 'n'){
       // return side_info[a_spot][b_spot].getPointVec();
        //cout << "Already have!" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "WALK" << endl;
        cout << side_info[a_spot][b_spot].getString() << endl;
        cout << "length: " << side_info[a_spot][b_spot].getShortestLength() << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "AUTO CAR" << endl;
        if(side_info[a_spot][b_spot].getStringAuto().empty()){
            cout << "Can't go from " << a_spot << " to " << b_spot << " by car." << endl;
        }
        else{
          cout << side_info[a_spot][b_spot].getStringAuto() << endl;  
          cout << "length: " << side_info[a_spot][b_spot].getShortestLengthAuto() << endl;
        }
        cout << "------------------------------------------------------------------------------" << endl;
        return true;
    }

    int source = a_spot;
    //cout << "check my change arr" << endl;
    //cout << change[source] << endl;
    int target = b_spot;

    //string route = to_string(source); //dont know if it's this method
    string route = node_info[source].get_name();

    int dis[MAX];
    int dis2[MAX];
    int visited2[MAX];
    memset(visited2, 0, sizeof(visited2));

    for(int i = 1; i <= node_size; i++){
        dis[i] = side_info[source][i].get_length();
        //cout << "dis[" << i << "] " << dis[i] << endl;
        if(!side_info[source][i].get_autocar()){
            dis2[i] = MAX;
        }
        else{
            dis2[i] = dis[i];
        }
    }
    visited[source] = 1;
    visited2[source] = 1;
    int rec = 0;
    int rec2 = 0;
    //int min2 = 0;
    for(int i = 1; i <= node_size; i++){
        int min = MAX;
        int min2 = MAX;
        for(int j = 1; j <= node_size; j++){
            if(!visited[j] && dis[j] < min){
                min = dis[j];
                rec = j;


            }
            //add auto class
            if(!visited2[j] && dis2[j] < min2){
                min2 = dis2[j];
                rec2 = j;
            }
        }
        //cout << "rec " << rec << endl;
        //cout << "rec2 " << rec2 << endl;
        //get the min
        visited[rec] = 1;
        visited2[rec2] = 1;
        
        //cout << "1 5?" << endl;
        //cout << side_info[1][5].get_length() << endl;
        if(!side_info[source][rec].check_shortest() && side_info[source][rec].get_length() != MAX){
            string tmp_string;
            /*tmp_string += to_string(source);
            tmp_string += "->";
            tmp_string += to_string(rec);*/
            tmp_string += node_info[source].get_name();
            tmp_string += "->";
            tmp_string += node_info[rec].get_name();
            
            side_info[source][rec].setString(tmp_string); 
            ////cout << "side_info[source][" << rec << "].string = " << tmp_string << endl;
            side_info[source][rec].setShortest();  
            side_info[source][rec].setShortestLength(side_info[source][rec].get_length()); 

        }
        //cout << "check auto " << endl;
        //cout << "side_info[" << source << "][" << rec2 << "]:" << side_info[source][rec2].get_autocar() << endl;
        if(side_info[source][rec2].get_length() != MAX && side_info[source][rec2].getStringAuto().empty()){
                string tmp_string_a;
                /*tmp_string_a += to_string(source);
                tmp_string_a += "->";
                tmp_string_a += to_string(rec2);*/

                tmp_string_a += node_info[source].get_name();
                tmp_string_a += "->";
                tmp_string_a += node_info[rec].get_name();
                //cout << "side_info[source][" << rec2 << "].string = " << tmp_string_a << endl;
                side_info[source][rec2].setStringAuto(tmp_string_a);
                side_info[source][rec2].setShortestLengthAuto(side_info[source][rec2].get_length());
        }


        for(int i = 1; i <= node_size; i++){
            if(!visited[i] && dis[i] > min + side_info[rec][i].get_length()){
                string tmp_string2;
                tmp_string2 = side_info[source][rec].getString();
                tmp_string2 += "->";
                tmp_string2 += node_info[i].get_name();


                side_info[source][i].setString(tmp_string2);
                ////cout << "---songchi---" << endl;
                ////cout << "side_info[source][" << i << "].string = " << tmp_string2 << endl;
                ////cout << "-------------" << endl;
                side_info[source][i].setShortest();

                dis[i] = min + side_info[rec][i].get_length();
                side_info[source][i].setShortestLength(dis[i]);

                


            }
            if(!visited2[i] && dis2[i] > min2 + side_info[rec2][i].get_length() && side_info[rec2][i].get_autocar()){
                string tmp_string_a_2;
                tmp_string_a_2 = side_info[source][rec2].getStringAuto();
                tmp_string_a_2 += "->";
                //cout << "aaaa " << to_string(i);
                tmp_string_a_2 += node_info[i].get_name();
                side_info[source][i].setStringAuto(tmp_string_a_2);
                dis2[i] = min2 + side_info[rec2][i].get_length();
                //cout << "side_info[source][" << i << "].string = " << tmp_string_a_2 << endl;
                side_info[source][i].setShortestLengthAuto(dis2[i]);
            }
        }


        

    }
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "WALK" << endl;
    cout << side_info[source][target].getString() << endl;
    cout << "length: " << side_info[source][target].getShortestLength() << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "AUTO CAR" << endl;
    if(side_info[source][target].getStringAuto().empty()){
        cout << "Can't go from " << source << " to " << target << " by car." << endl;
    }
    else{
      cout << side_info[source][target].getStringAuto() << endl;  
      cout << "length: " << side_info[source][target].getShortestLengthAuto() << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;
    change[source] = 'n';
    return true;



}   




bool school_map::find_least_way(string a_spot, string b_spot){
    if(!reference[a_spot] || !reference[b_spot]){return false;}
    return find_least_way(reference[a_spot], reference[b_spot]);
} 

void school_map::show_all_spot(){
    string seperate;
    cout << endl;
    cout << "--------------------------------------------" << endl;
    seperate = "--------------------";
    for(int i = 1; i <= node_size; i++){
        //cout << left;
        if(i >= 100){seperate = "------------------";}
        else if(i >= 10){seperate = "-------------------";}
        cout << left <<  node_info[i].get_id() << seperate << node_info[i].get_name() << endl;
    }
    cout << "--------------------------------------------" << endl;
}

bool school_map::show_one_description(int id){
    if(id <= 0 || id > node_size){return false;}
    cout << "--------------------------------------------" << endl;
    cout << "name: " << node_info[id].get_name() << endl;
    cout << "description: ";
    cout << node_info[id].get_description() << endl;
    cout << "--------------------------------------------" << endl;
    return true;
}

bool school_map::show_one_description(string name){
    if(!reference[name]){return false;}
    return show_one_description(reference[name]);
}





