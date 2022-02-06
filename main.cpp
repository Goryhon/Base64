#include "pch.h"

int main() {
	EncodeBase64("input.txt", "encodeOutput.txt");
	DecodeBase64("encodeOutput.txt");
	return 0;
}