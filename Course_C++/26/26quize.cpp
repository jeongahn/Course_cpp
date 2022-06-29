#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

class Team{
public:
  string name;
  int wins;
  Team(const string& n="X", int v=0): name(n), wins(v){}
friend ostream& operator<<(ostream& os, const Team& n){
        os << n.name << "(" << n.wins << ")" ;
        return os;
    }
};

template <class T>
void print_container(const T& container, string s=""){
  cout << s << "(" << container.size() << ") ";
  auto it = container.begin();
  for (; it != container.end(); it++) cout << *it << " ";
  cout << endl;
}

bool teamCmp_byName (const Team& a, const Team& b){ return a.name < b.name; }


struct TeamCmp_byVictory {
  bool operator() (const Team& a, const Team& b) const{ return a.wins < b.wins;}
};
#define N 3

int main(){
  Team t[] = {Team("Bulls",7), Team("Warriors", 5), Team("Spurs", 2)};
  vector<Team> v(&t[0], &t[N]);

  sort(v.begin(), v.end(), teamCmp_byName);
  print_container(v);

  sort(v.begin(), v.end(), TeamCmp_byVictory());
  print_container(v);

  priority_queue<Team, vector<Team>, TeamCmp_byVictory> p(t, &t[N]);
  p.push(Team("Lakers",3));
  while(!p.empty()){ // priority_queue는 empty()
     cout << p.top() << " ";
     p.pop();
  }
  cout << endl;

  return 0;
}
