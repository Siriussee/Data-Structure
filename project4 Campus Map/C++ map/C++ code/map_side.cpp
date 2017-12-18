#include "map_side.h"


    map_side::map_side():startid(0), endid(0), name(""), length(MAX), autocar(0), shortest_length(MAX), path_point_str(""), shortest(0){}
    map_side::map_side(int startid_, int endid_, int length_, bool car, string name_){
        startid = startid_;
        endid = endid_;
        name = name_;
        length = length_;
        autocar = car;

        /////
        shortest_length = MAX;
        path_point_str = "";
        shortest = 0;
    }
    map_side::~map_side(){}
    string map_side::get_name(){return name;}
    int map_side::get_length(){
        return length;
    }
    bool map_side::get_autocar(){
        return autocar;
    }
    int map_side::get_startid(){return startid;}
    int map_side::get_endid(){return endid;}
    vector<int> map_side::getPointVec(){}


    bool map_side::check_shortest(){
        return shortest;
    }

    void map_side::setString(string in){
        path_point_str = in;
    }

    void map_side::setStringAuto(string in){
        path_point_str_auto = in;
    }

    void map_side::setShortest(){
        shortest = 1;
    }

    void map_side::setShortestLength(int in){
        shortest_length = in;
    }

    string map_side::getString(){
        return path_point_str;
    }

    string map_side::getStringAuto(){
        return path_point_str_auto;
    }

    int map_side::getShortestLength(){
        return shortest_length;
    }

    int map_side::getShortestLengthAuto(){
        return shortest_length_auto;
    }

    void map_side::setShortestLengthAuto(int in){
        shortest_length_auto = in;
    }