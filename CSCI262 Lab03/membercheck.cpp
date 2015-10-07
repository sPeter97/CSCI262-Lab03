#include <algorithm>

Vector<string> whos_dishonest(Vector<string> &club1,
	Vector<string> &club2,
	Vector<string> &club3) {

	Vector<string> jerks;
	set<pair<string, int>> club;

	for (string m : club1) {
		if (club.find(pair<string, int>(m, 1)) == club.end()) {
			club.insert(pair<string, int>(m, 1));
		}
	}
	for (string m : club2) {
		if (club.find(pair<string, int>(m, 2)) == club.end()) {
			club.insert(pair<string, int>(m, 2));
		}
		if (club.find(pair<string, int>(m, 1)) != club.end()) {
			if(find(jerks.begin(), jerks.end(), m) == jerks.end())
				jerks.push_back(m);
		}
	}
	for (string m : club3) {
		if (club.find(pair<string, int>(m, 3)) == club.end()) {
			club.insert(pair<string, int>(m, 3));
		}
		if (club.find(pair<string, int>(m, 1)) != club.end()) {
			if (find(jerks.begin(), jerks.end(), m) == jerks.end())
				jerks.push_back(m);
		}
		if (club.find(pair<string, int>(m, 2)) != club.end()) {
			if (find(jerks.begin(), jerks.end(), m) == jerks.end())
				jerks.push_back(m);
		}
	}
	sort(jerks.begin(), jerks.end());
	return jerks;
}
