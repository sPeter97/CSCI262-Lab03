#include <map>
#include <set>

int count_pairs(Vector<string> &words) {
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
