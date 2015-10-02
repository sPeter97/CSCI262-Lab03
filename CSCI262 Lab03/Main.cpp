#include <map>
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

vector<string> whos_dishonest(vector<string> &club1,
	vector<string> &club2,
	vector<string> &club3) {

	vector<string> jerks;
	map<string, int> club;
	map<string, int>::iterator i;

	for (string m : club1) {
		if (club.find(m) == club.end()) {
			club.insert(new pair<string, int>(m, 1));
		}
	}
}

int main() {
	return 0;
}