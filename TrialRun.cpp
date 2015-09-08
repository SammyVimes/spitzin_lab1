// TrialRun.cpp
// Our first program
#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

int main()
{
	cout << "Some people think programming Windows"
		 << endl
		 << "is like nailing jello to the ceiling..."
		 << endl
		 << "Easy with the right kind of nails."
		 << endl << endl;
	containers::HashMap<std::string, int>* map = new containers::HashMap<std::string, int>();
	map->put("Use the force", 123);
	cout << map->get("Use the force") << endl;
	cout << map->get("Use");
	return 0;

}