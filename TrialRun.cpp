// TrialRun.cpp
// Our first program
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include "HashMap.h"

using namespace std;

class stringcomparison
{
	bool reverse;
public:
	stringcomparison(const bool& revparam = false) {
		reverse = revparam;
	}
	bool operator() (const string& lhs, const string& rhs) const {
		if (reverse) return (lhs.length() > rhs.length());
		else return (lhs.length() < rhs.length());
	}
};

int main()
{
	cout << "Some people think programming Windows"
		 << endl
		 << "is like nailing jello to the ceiling..."
		 << endl
		 << "Easy with the right kind of nails."
		 << endl << endl;




	std::vector<string> strings_vector;
	strings_vector.push_back("TestValue1");
	strings_vector.push_back("TestValue23");
	strings_vector.push_back("TestValue2");


	std::list<string> strings_list;
	strings_list.push_back("TestValue1");
	strings_list.push_back("TestValue2");

	std::deque<string> strings_deque;
	strings_deque.push_back("TestValue1");
	strings_deque.push_back("TestValue2");


	typedef std::priority_queue<string, std::vector<string>, stringcomparison> mypq_type;

	cout << "Priority queue" << endl;
	mypq_type pq(stringcomparison(true), strings_vector);
	while (!pq.empty()) {
		cout << ' ' << pq.top() << endl;
		pq.pop();
	}


	cout << endl << "std::queue" << endl;
	std::queue<string> strings_queue;
	strings_queue.push("TestValue1");
	strings_queue.push("TestValue23");
	strings_queue.push("TestValue2");
	while (!strings_queue.empty()) {
		cout << ' ' << strings_queue.front() << endl;
		strings_queue.pop();
	}

	cout << endl << "std::stack" << endl;
	std::stack<string> strings_stack;
	strings_stack.push("TestValue1");
	strings_stack.push("TestValue2");
	strings_stack.push("TestValue23");
	while (!strings_stack.empty()) {
		cout << ' ' << strings_stack.top() << endl;
		strings_stack.pop();
	}

	cout << endl << "std::map" << endl;
	std::map<string, string> strings_map;
	strings_map["key1"] = "TestValue1";
	strings_map["key2"] = "TestValue2";
	strings_map["key3"] = "TestValue23";
	for (std::map<string, string>::iterator it = strings_map.begin(); it != strings_map.end(); ++it) {
		cout << ' ' << it->first << " => " << it->second << endl;
	}

	containers::HashMap<std::string, int>* map = new containers::HashMap<std::string, int>();
	map->put("Use the force", 1);
	map->put("Use the force1", 2);
	map->put("Use the force2", 3);
	map->put("Use the force3", 4);
	map->put("Use the force4", 5);



	Iterator<int>* iterator = map->iterator();
	while (iterator->hasNext()) {
		cout << iterator->next() << endl;
	}


	cout << "Resize must occure" << endl;

	map->put("Use the force5", 6);
	map->put("Use the force6", 7);
	map->put("Use the force7", 8);
	map->put("Use the force8", 9);
	map->put("Use the force9", 10);
	map->put("Use the force10", 11);

	delete iterator;

	iterator = map->iterator();
	while (iterator->hasNext()) {
		cout << iterator->next() << endl;
	}

	delete iterator;
	delete map;


	//TODO: rewrite with array and resize method



	return 0;

}