#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000
class map_side {
private:
    string name;
    int length;
    bool autocar; // whether the road could drive
    int startid;
    int endid;
    int shortest_length;
    int shortest_length_auto;
    vector<int> path_point;
    vector<int> path_edge;
    string path_point_str;
    string path_point_str_auto;
    bool shortest;
public:
    map_side();
    map_side(int startid_, int endid_, int length_, bool car, string name_);
    ~map_side();
    string get_name();
    int get_length();
    bool get_autocar();
    int get_startid();
    int get_endid();
    bool check_shortest();
    void setString(string in);
    void setStringAuto(string in);
    void setShortest();
    void setShortestLength(int in);
    int getShortestLength();
    void setShortestLengthAuto(int in);
    int getShortestLengthAuto();
    string getString();
    string getStringAuto();
    vector<int> getPointVec();
};