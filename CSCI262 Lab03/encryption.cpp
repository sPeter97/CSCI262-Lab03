#include <cstring>
#include <map>

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
