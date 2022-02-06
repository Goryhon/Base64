#include "pch.h"

int main() {
	cout << EncodeBase64("input.txt") << endl;
	cout << DecodeBase64("encodeOutput.txt") << endl;
	return 0;
}
