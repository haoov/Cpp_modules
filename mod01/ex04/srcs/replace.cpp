#include "sed.h"

void replace(std::string &content, char *pattern, char *replacement) {
	size_t pos = 0;
	while (pos != std::string::npos) {
		pos = content.find(pattern, pos);
		if (pos != std::string::npos) {
			content.erase(pos, std::string(pattern).length());
			content.insert(pos, replacement);
		}
	}
}