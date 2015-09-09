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

	//cout << map->get("Use the force") << endl;
	//cout << map->get("Use");
	return 0;

}