#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/***************************************************************
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
***************************************************************/

/***************************************************
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
***************************************************/

string encrypt(string message) {
	map<char, char> encode;
	map<char, char>::iterator index;

	char c = 'a';
	string encrypted(message);

	for (int i = 0; i < message.length(); i++) {
		index = encode.find(message[i]);
		if (index == encode.end()) {
			encode.insert(pair<char, char>(message[i], c));
			encrypted[i] = c;
			c++;
		}
		else {
			encrypted[i] = encode[message[i]];
		}
	}

	return encrypted;
}

int count_pairs(vector<string> &words) {
	int count = 0;
	map<char, char> iso;
	set<char> used;

	for (int i = 0; i < words.size() - 1; i++)
		for (int j = i + 1; j < words.size(); j++) {
			iso.clear();
			used.clear();

			for (int k = 0; k < words[i].size(); k++) {
				if (iso.find(words[i][k]) == iso.end()) {
					if (used.find(words[j][k]) != used.end())
						break;
					else {
						iso.insert(pair<char, char>(words[i][k], words[j][k]));
						used.insert(words[j][k]);
					}
				}
				else if (iso[words[i][k]] != words[j][k]) {
					break;
				}
				if (k == words[i].size() - 1) {
					count++;
				}
			}
		}

	return count;
}

int which_order(vector<string> &ingredients, vector<string> &orders) {
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

int main() {
	return 0;
}