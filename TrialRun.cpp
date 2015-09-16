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
#include "Shapes.h"

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

	//Testing std::vector
	std::vector<string> strings_vector;
	strings_vector.push_back("TestValue1");
	strings_vector.push_back("TestValue23");
	strings_vector.push_back("TestValue2");

	cout << endl << "std::vector<string> iterator" << endl;
	for (std::vector<string>::iterator it = strings_vector.begin(); it != strings_vector.end(); ++it) {
		cout << ' ' << *(it) << endl;
	}

	//Testing std::list
	std::list<string> strings_list;
	strings_list.push_back("TestValue1");
	strings_list.push_back("TestValue2");
	cout << endl << "std::list<string> iterator" << endl;
	for (std::list<string>::iterator it = strings_list.begin(); it != strings_list.end(); ++it) {
		cout << ' ' << *(it) << endl;
	}

	//Testing std::deque
	std::deque<string> strings_deque;
	strings_deque.push_back("TestValue1");
	strings_deque.push_back("TestValue2");
	strings_deque.push_front("TestValue3");
	cout << endl << "std::deque<string> iterator" << endl;
	for (std::deque<string>::iterator it = strings_deque.begin(); it != strings_deque.end(); ++it) {
		cout << ' ' << *(it) << endl;
	}

	//Testing std::priority_queue
	typedef std::priority_queue<string, std::vector<string>, stringcomparison> mypq_type;
	cout << "std::priority_queue<string>" << endl;
	mypq_type pq(stringcomparison(true), strings_vector);
	while (!pq.empty()) {
		cout << ' ' << pq.top() << endl;
		pq.pop();
	}

	//Testing std::queue
	cout << endl << "std::queue<string>" << endl;
	std::queue<string> strings_queue;
	strings_queue.push("TestValue1");
	strings_queue.push("TestValue23");
	strings_queue.push("TestValue2");
	while (!strings_queue.empty()) {
		cout << ' ' << strings_queue.front() << endl;
		strings_queue.pop();
	}

	//Testing std::stack
	cout << endl << "std::stack<string>" << endl;
	std::stack<string> strings_stack;
	strings_stack.push("TestValue1");
	strings_stack.push("TestValue2");
	strings_stack.push("TestValue23");
	while (!strings_stack.empty()) {
		cout << ' ' << strings_stack.top() << endl;
		strings_stack.pop();
	}

	//Testing std::map
	cout << endl << "std::map<string, string>" << endl;
	std::map<string, string> strings_map;
	strings_map["key1"] = "TestValue1";
	strings_map["key2"] = "TestValue2";
	strings_map["key3"] = "TestValue23";
	for (std::map<string, string>::iterator it = strings_map.begin(); it != strings_map.end(); ++it) {
		cout << ' ' << it->first << " => " << it->second << endl;
	}

	//Testing std::vector (loop and iterator browsing)
	cout << endl << "std::vector<int> for loop" << endl;
	std::vector<int> int_vector;
	int_vector.push_back(1);
	int_vector.push_back(2);
	int_vector.push_back(3);
	int_vector.push_back(4);
	int_vector.push_back(5);
	for (int i = 0; i < int_vector.size(); i++) {
		cout << ' ' << int_vector[i] << endl;
	}
	cout << endl << "std::vector<int> iterator" << endl;
	for (std::vector<int>::iterator it = int_vector.begin(); it != int_vector.end(); ++it) {
		cout << ' ' << *(it) << endl;
	}

	//Testing own hash-map (using strings)
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

	//Testing own hash-map (using Shapes)
	containers::HashMap<int, Shape*>* shapes_map = new containers::HashMap<int, Shape*>();
	shapes_map->put(1, new Circle(2.5, 1, 3, 3));
	shapes_map->put(2, new DoubleCircle(3, 2, 2, 5, 5));
	shapes_map->put(3, new CircleText(10, 2, "the text in the circle", 2, 10, 10));
	shapes_map->put(4, new Text(10, "an usual text", 2, 15, 15));
	
	Iterator<Shape*>* shapes_iterator = shapes_map->iterator();
	while (shapes_iterator->hasNext()) {
		Shape* curr = shapes_iterator->next();
		cout << *curr << endl;
	}
	delete shapes_map;
	delete shapes_iterator;

	system("pause");
	return 0;
}