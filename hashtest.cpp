
#include <iostream>
#include <unordered_map>
#include <string>


using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;

class Person
{
  //private:
  //    string phone;
  //    string name;
public:
  string phone;
  string name;
  string address;

  explicit Person()
  {
  }

  explicit Person(string name, string phone, string address) : name(name), phone(phone), address(address)
  {
  }

  // overload operator==
  bool operator==(const Person& p)
  {
    return this->phone == p.phone && this->name == p.name
      && this->address == p.address;
  }

  inline friend std::ostream& operator<<(std::ostream& os, Person& p)
  {
    os << "[Person] -> (" << p.name << ", " << p.phone << ", "
      << p.address << ")";
    return os;
  }
};

// declare hash<Person>
namespace std
{
  template <>
  struct hash<Person>
  {
    std::size_t operator()(const Person& p) const
    {
      using std::size_t;
      using std::hash;
      using std::string;
      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:
      return ((hash<string>()(p.phone)
               ^ (hash<string>()(p.name) << 1)) >> 1)
        ^ (hash<string>()(p.address) << 1);
    }
  };
}

unordered_map<string, Person> phoneMap;

void selectByPhone()
{
  string phone;
  cout << "Input the phone number: "; cin >> phone;
  unordered_map<string, Person>::iterator it;
  int size = phoneMap.size();
  for ( int pc = 0; pc < size; pc++ )
  {
    if ( (it = phoneMap.find(phone)) != phoneMap.end() )
    {
      cout << "\033[32mQuery result: " << it->second << "\033[0m" << endl;
      return;
    }
  }
  cout << "\033[33mQuery result : target_not_found\033[0m" << endl;
}


int hashtest()
{
  //map.insert(std::make_pair(1, {"Scala","1234","4234 NW"});
  //map.insert(std::make_pair(2, "Haskell"));
  //map.insert(std::make_pair(3, "C++"));
  //map.insert(std::make_pair(6, "Java"));
  //map.insert(std::make_pair(14, "Erlang"));
  phoneMap["1"] = Person{"Fan","1","2"};
  phoneMap["2"] = Person { "FanD","2","3" };
  phoneMap["3"] = Person { "FanA","3","4" };

  selectByPhone();


  std::unordered_map<string, Person>::iterator it;
  if ( (it = phoneMap.find("1")) != phoneMap.end() )
  {
    std::cout << it->second << std::endl;
  }
  return 0;
}