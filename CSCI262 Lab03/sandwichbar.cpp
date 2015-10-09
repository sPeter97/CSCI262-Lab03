#include <sstream>
#include <string>

using namespace std;

int which_order(Vector<string> &ingredients, Vector<string> &orders) {
	bool done = false;
	string item;

	for (int i = 0; i < orders.size() - 1; i++) {
		done = true;
		istringstream sandwich(orders[i]);
		while (sandwich >> item) {
			if (find(ingredients.begin(), ingredients.end(), item) == ingredients.end()) {
				done = false;
				break;
			}
		}
		if (done)
			return i;
	}
	return -1;
}