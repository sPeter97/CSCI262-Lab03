#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int points(vector<string> &player, vector<string> &dictionary) {
	bool* used = new bool[dictionary.size()];
	for (int i = 0; i < dictionary.size(); i++)
		used[i] = false;

	int score = 0;
	for (string pWord : player) {
		for (int i = 0; i < dictionary.size(); i++) {
			if (dictionary[i].compare(pWord) == 0) {
				if (!used[i]) {
					used[i] = true;
					score += pWord.length() * pWord.length();
				}
				break;
			}
		}
	}
	return score;
}

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
			if (find(jerks.begin(), jerks.end(), m) == jerks.end())
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

int main() {
	return 0;
}