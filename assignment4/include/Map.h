#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


class City{
    string name;
    vector<pair<City*, int>> roads;
    vector<pair<City*, int>> airlines;

};

void addRoad(City* x, City* y, int dist){
    x.roads.add({y, dist});
    y.roads.add({x, dist});
}


City* Houston = new City();
City* Phoenix = new City();
