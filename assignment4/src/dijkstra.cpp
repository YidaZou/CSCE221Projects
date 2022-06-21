#include "heapsort.cpp"

//initialize all cities (vertexes)
City* Houston = new City("Houston");
City* Phoenix = new City("Phoenix");
City* Dallas = new City("Dallas");
City* Newark = new City("Newark");
City* LosAngeles = new City("Los Angeles");
City* Denver = new City("Denver");
City* SanFrancisco = new City("San Francisco");
City* SaltLakeCity = new City("Salt Lake City");
City* Seattle = new City("Seattle");
City* Minneapolis = new City("Minneapolis");
City* KansasCity = new City("Kansas City");
City* Chicago = new City("Chicago");
City* Boston = new City("Boston");

void addEdge(City* x, City* y, int dist){   //connects cities by distances
    x->edge.push_back({y, dist});
    y->edge.push_back({x, dist});
}

map<City*, int> dijkstra(vector<City*> cityMap, heap pq, City* source){ //dijkstra algorithm
    //vector<bool> visited (map.size(), 0); //index corresonds to city
    map<City*, int> dist;
    for(auto city : cityMap){
        dist[city] = INT_MAX;   //initialize distances to Houston with INT_MAX
    }
    dist[source] = 0;  //distance from Houston to Houston
    Node* node0 = new Node(source, 0); //source node
    pq.insert(node0);   //insert into heap
    while(!pq.isEmpty()){
        Node* front = pq.min();
        pq.removeMin();
        City* v = front->name;  //current city
        for(auto edge: v->edge){ //iterate through edges
            City* u = edge.first;   //connected cities of initial
            int distance = edge.second;
            if(dist[u] > dist[v] + distance){   //if path to u through v is shorter
                //update distance of u and insert to heap
                dist[u] = dist[v] + distance;
                Node* newNode = new Node(u, dist[u]);
                pq.insert(newNode);
            }
        }
    }
    return dist;
}

int main(int argc, char const *argv[])
{

    if(argc < 2){   //no input given
        cout << "Input can be either flight or road" << endl;
        return 0;
    }  
    string input = argv[1];

    if(input == "flight"){
        //Creating the graph
        addEdge(Houston, Phoenix, 1009);
        addEdge(Houston, Newark, 1400);
        addEdge(Phoenix, LosAngeles, 370);
        addEdge(Phoenix, Denver, 853);
        addEdge(LosAngeles, SanFrancisco, 337);
        addEdge(LosAngeles, SaltLakeCity, 590);
        addEdge(SanFrancisco, Seattle, 679);
        addEdge(SaltLakeCity, Seattle, 689);
        addEdge(Minneapolis, SaltLakeCity, 991);
        addEdge(Minneapolis, Denver, 680);
        addEdge(Dallas, Denver, 641);
        addEdge(Minneapolis, Chicago, 334);
        addEdge(Chicago, KansasCity, 403);
        addEdge(Boston, Chicago, 867);
        addEdge(Boston, Newark, 201);
        addEdge(Dallas, KansasCity, 461);

    }else if(input == "road"){
        //Creating the graph
        addEdge(Houston, Phoenix, 1176);
        addEdge(Houston, Dallas, 239);
        addEdge(Houston, Newark, 1618);
        addEdge(Phoenix, LosAngeles, 372);
        addEdge(Phoenix, Denver, 865);
        addEdge(LosAngeles, SanFrancisco, 383);
        addEdge(LosAngeles, SaltLakeCity, 688);
        addEdge(SanFrancisco, Seattle, 808);
        addEdge(SaltLakeCity, Seattle, 839);
        addEdge(SaltLakeCity, Denver, 371);
        addEdge(Minneapolis, Seattle, 1655);
        addEdge(Minneapolis, SaltLakeCity, 1245);
        addEdge(Minneapolis, Denver, 680);
        addEdge(Dallas, Denver, 794);
        addEdge(Dallas, KansasCity, 556);
        addEdge(Minneapolis, Chicago, 409);
        addEdge(Chicago, Denver, 1002);
        addEdge(Chicago, KansasCity, 510);
        addEdge(Newark, KansasCity, 1183);
        addEdge(Boston, Chicago, 983);
        addEdge(Boston, Newark, 225);

    }else{  //wrong input
        cout << "Input can be either flight or road" << endl;
        return 0;
    }

    vector<City*> cityMap = {Houston, Phoenix, Dallas, Newark, LosAngeles,
                        Denver, SanFrancisco, SaltLakeCity, Seattle, Minneapolis, 
                        KansasCity, Chicago, Boston};

    heap mapHeap;
    map<City*, int> out = dijkstra(cityMap, mapHeap, Houston);
    out.erase(Houston);    //erase houston from map for printing

    cout << "The minimum distance from Houston to" << endl;
    for(auto p : out){
        cout << p.first->name << " is " << p.second << endl;
    }

    return 0;
}
