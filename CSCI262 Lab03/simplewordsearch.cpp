int points(Vector<string> &player, Vector<string> &dictionary) {
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