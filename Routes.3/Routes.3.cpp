//C++ Libraries
#include <iostream>
#include <vector>
#include <set>
using namespace std;

//C libraries
#include <cstring>
#include <algorithm>
#include <ostream>

//Leg Class
class Leg {
  const char* const startCity;
  const char* const endCity;
  const int distance;
public:
  Leg(const char* const, const char* const, int);
  Leg& operator=(const Leg&);
  int getDistance() const { return distance; }
  void output(ostream&) const;
  friend class Route;
  friend class ShortestRoute;
};

//Route Class
class Route {
  vector<const Leg*> legs;
  const int totalDis;
public:
  Route(const Leg&);
  Route(const Route&, const Leg&);
  Route& operator=(const Route&);
  int getDistance() const { return totalDis; }
  void output(ostream&) const;
  friend bool operator<(const Route&, const Route&);
};

class ShortestRoute
{
  static const int legSize;
  static const Leg allLegs[];
public:
  static const Route anyRoute(const char* const, const char* const);
  static const Route shortestRoute(const char* const, const char* const);
};

//Legs Array Objects
const Leg ShortestRoute::allLegs[] = {
  Leg("San Francisco", "Los Angeles", 392),
  Leg("San Francisco", "Sacramento", 80),
  Leg("San Francisco", "Portland", 634),
  
  Leg("Los Angeles", "Las Vegas",270),
  Leg("Los Angeles", "Seattle", 1135),
  Leg("Sacramento", "Reno", 132),  
  Leg("Sacramento", "Las Vegas", 563),
  Leg("Portland", "Seattle", 174),
  Leg("Portland", "Reno", 530),
 
  Leg("Las Vegas", "Kingman", 107),
  Leg("Las Vegas", "Spokane", 1040),
  Leg("Reno", "Winnemucca", 166),
  Leg("Reno", "Kingman", 550),
  Leg("Seattle", "Spokane", 280),
  Leg("Seattle", "Winnemucca", 700),
  
  Leg("Kingman", "Holbrook", 236),
  Leg("Kingman", "Shelby", 600),
  Leg("Winnemucca", "West Wendover", 231),
  Leg("Winnemucca", "Holbrook", 365),
  Leg("Spokane", "Shelby", 420),
  Leg("Spokane", "West Wendover", 720),
  
  Leg("Holbrook", "Albuquerque", 233),
  Leg("Holbrook", "Glasgow", 1400),
  Leg("West Wendover", "Salt Lake City", 123),
  Leg("West Wendover", "Albuquerque", 720),
  Leg("Shelby", "Glasgow", 260),
  Leg("Shelby", "Salt Lake City", 720),
   
  Leg("Albuquerque", "Rosewell", 201),
  Leg("Albuquerque", "New Town", 1140),
  Leg("Salt Lake City", "Denver", 525),
  Leg("Salt Lake City", "Rosewell", 2203),
  Leg("Glasgow", "New Town", 216),
  Leg("Glasgow", "Denver", 690),

  Leg("Rosewell", "Fork Stockton", 215),
  Leg("Rosewell", "Devils Lake", 1300),
  Leg("Denver", "Kansas City", 600),
  Leg("Denver", "Fork Stockton", 725),
  Leg("New Town", "Devils Lake", 194),
  Leg("New Town", "Kansas City", 900),

  Leg("Fork Stockton", "San Antonio", 312),
  Leg("Fork Stockton", "Fargo", 1400),
  Leg("Kansas City", "St.Louis", 250),
  Leg("Kansas City", "San Antonio", 820),
  Leg("Devils Lake", "Fargo", 165),
  Leg("Devils Lake", "St.Louis", 400),

  Leg("San Antonio", "Houston", 200),
  Leg("San Antonio", "Minneapolis", 1250),
  Leg("St.Louis", "Springfield", 96), 
  Leg("St.Louis", "Houston", 800),
  Leg("Fargo", "Minneapolis", 235),
  Leg("Fargo", "Springfield", 240),

  Leg("Houston", "New Orleans", 350),
  Leg("Houston", "Chicago", 1100),
  Leg("Springfield", "Indianapolis", 213),
  Leg("Springfield", "New Orleans", 1250),
  Leg("Minneapolis", "Chicago", 410), 
  Leg("Minneapolis", "Indianapolis", 600),

  Leg("New Orleans", "Birmingham", 343),
  Leg("New Orleans", "Columbus", 910),
  Leg("Chicago", "Cleveland", 344),
  Leg("Chicago", "Birmingham", 660),
  Leg("Indianapolis", "Columbus", 176),
  Leg("Indianapolis", "Cleveland", 320),

  Leg("Birmingham", "Atlanta", 150),
  Leg("Birmingham", "Buffalo", 900),
  Leg("Columbus", "Pittsburgh", 185),
  Leg("Columbus", "Atlanta", 570),
  Leg("Cleveland", "Buffalo", 190),
  Leg("Cleveland", "Pittsburgh", 140),

  Leg("Atlanta", "Charlotte", 245),
  Leg("Atlanta", "Albany", 1000),
  Leg("Pittsburgh", "Lancaster", 305),
  Leg("Pittsburgh", "Charlotte", 450),
  Leg("Buffalo", "Albany", 292),
  Leg("Buffalo", "Lancaster", 320),

  Leg("Charlotte", "Washington", 400),
  Leg("Charlotte", "Philadelphia", 500),
  Leg("Lancaster", "Philadelphia", 80),
  Leg("Lancaster", "Washington", 120),
  Leg("Albany", "Washington", 90),
  Leg("Albany", "Philadelphia", 240),

  Leg("Washington", "New York City", 225),
  Leg("Philadelphia", "New York City", 95),
  Leg("San Francisco", "New York City", 21000),
};

//Size of legSize
const int ShortestRoute::legSize = sizeof(ShortestRoute::allLegs) / sizeof(ShortestRoute::allLegs[0]); 

int main()
{
  // Identification output Code Block
  cout << "Programmer: Fulati Aizihaer\n";
  cout << "Programmer's ID: 1716403\n";
  cout << "File: " << __FILE__ << endl;

  cout << endl;
  cout << "Any route: " << endl;
  const Route route1 = ShortestRoute::anyRoute("San Francisco", "New York City");
  route1.output(cout);
  cout << endl;
  cout << "Shortest route: " << endl;
  const Route route2 = ShortestRoute::shortestRoute("San Francisco", "New York City");
  route2.output(cout);

  return 0;
}

//LEG:

//Leg Constructor
Leg::Leg(const char* const startCity, const char* const endCity, int distance):startCity(startCity), endCity(endCity), distance(distance) {}

//Leg Operator
Leg& Leg::operator=(const Leg& copyThis) {
  Leg& host = *this;
  if (this != &copyThis) {
    const_cast<const char*&>(host.startCity) = copyThis.startCity;
    const_cast<const char*&>(host.endCity) = copyThis.endCity;
    const_cast<int&>(host.distance) = copyThis.distance;
  }
  return host;
}

//Output Getter
void Leg::output(ostream& out) const {
  out << "Leg: " << startCity << " to " << endCity << ", " << distance << " miles" << endl;
}

//ROUTE:

//Route Constructors
Route::Route(const Leg& l) :totalDis(l.distance) {
  legs.push_back(&l);
}

Route::Route(const Route& r, const Leg& l) :legs(r.legs), totalDis(strcmp(legs.back()->endCity, l.startCity) == 0 ? r.totalDis + l.distance : r.totalDis) {
  try {
    if (strcmp(legs.back()->endCity, l.startCity) != 0) {
      throw "Cities don't match!";
    }
    legs.push_back(&l);
  }
  catch (const char* ex)
  {
    cout << ex << endl;
  }
}

//Route Operator
Route& Route::operator=(const Route& copyThis) {
  Route& host = *this;
  if (this != &copyThis) {
    host.legs = copyThis.legs;
    const_cast<int&>(host.totalDis) = copyThis.totalDis;
  }
  return host;
}

//Output Getter
void Route::output(ostream& out) const {
  out << "Route: " << legs[0]->startCity;
  for (unsigned int i = 0; i < legs.size(); i++)
  {
    out << " to " << legs[i]->endCity;
  }
  out << ", " << totalDis << " miles" << endl;
}

//Route friend bool Operator<
bool operator<(const Route& r1, const Route& r2){
  return r1.totalDis < r2.totalDis;
}

//SHORTESTROUTE: 

//anyRoute Function
const Route ShortestRoute::anyRoute(const char* const from, const char* const to) {
  for (unsigned int i = 0; i < ShortestRoute::legSize; i++) 
  {
    if (strcmp(ShortestRoute::allLegs[i].endCity, to) == 0)
    {
      if (strcmp(ShortestRoute::allLegs[i].startCity, from) == 0)
      {
        return Route(ShortestRoute::allLegs[i]);
      }
      else 
      {
        return Route(ShortestRoute::anyRoute(from, ShortestRoute::allLegs[i].startCity), ShortestRoute::allLegs[i]);
      }
    }
  }
  throw "Can't find any route!";
}

//shortestRoute Function
const Route ShortestRoute::shortestRoute(const char* const from, const char* const to) {
  set<Route> routes;

  for (unsigned int i = 0; i < ShortestRoute::legSize; i++)
  {
    if (strcmp(ShortestRoute::allLegs[i].endCity, to) == 0)
    {
      if (strcmp(ShortestRoute::allLegs[i].startCity, from) == 0)
      {
        routes.insert(Route(ShortestRoute::allLegs[i]));
      }
      else
      {
        routes.insert(Route(ShortestRoute::shortestRoute(from, ShortestRoute::allLegs[i].startCity), ShortestRoute::allLegs[i]));
      }
    }
  }
  if (routes.empty()) 
  {
    throw "Can't find the shortest route!";
  }
  else 
  {
    return *(routes.begin());
  }
}
