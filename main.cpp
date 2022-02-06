#include "pch.h"

int main() {
	cout << EncodeBase64("input.txt") << endl;
        cout << DecodeBase64(EncodeBase64("input.txt")) << endl;
	return 0;
}
