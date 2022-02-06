#include "pch.h"

string EncodeBase64(string input) {

	string base64Symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	string to_ret = "";

	unsigned char holder, holderSize;

	holderSize = 0;
	holder = 0;

	for (int i = 0; i < input.length();i++) {
		holder += input[i] >> holderSize;
		to_ret += (base64Symbols[holder >> 2]);
		holderSize += 2;
		holder = input[i] << (8 - holderSize);
		if (holderSize == 6) {
			to_ret += (base64Symbols[holder >> 2]);
			holder = 0;
			holderSize = 0;
		}
	}

	if (holderSize > 0) {
		to_ret += (base64Symbols[holder >> 2]);
		while (holderSize < 6) {
			holderSize += 2;
			to_ret += '=';
		}
	}
	return to_ret;
}

string DecodeBase64(string input) {

	string to_ret="";

	int count= 0;
	unsigned char holder,temp1, holderSize;

	bool hadEqSign = false;
	bool Error = false;
	int EqSigns = 0;

	holderSize = 0;
	holder = 0;

	for (int i = 0; i < input.length();i++) {
		temp1 = findInArray(input[i]);
		if (temp1 != 64) {
			holder += temp1 << 2 >> holderSize;
			holderSize += 6;
			if (holderSize > 8) {
				to_ret += holder;
				holderSize -= 8;
				holder = temp1 << (8 - holderSize);
			}
			count += 6;
			count %= 8;
		}
		else if(temp1 == 64){
			EqSigns ++;
			hadEqSign = true;
			count += 2;
			count %= 8;
		}
		else{
			Error = true;
		}
	}

	if(EqSigns > 2){
		Error = true;
	}

	if(Error){


		to_ret = "ERROR There Are some Garbage bits .... !!!!....(This is Not Base64 code)";
	}
	else{

		if (holderSize > 0 && !hadEqSign) {
			to_ret += holder;
		}

	}
return  to_ret;
}

unsigned char findInArray(char finding) {
	unsigned char to_ret = 0;
	if (finding >= 'A' && finding <= 'Z') {
		to_ret = finding - 'A';
	}
	else if (finding >= 'a' && finding <= 'z') {
		to_ret = 26 + finding - 'a';
	}
	else if (finding >= '0' && finding <= '9') {
		to_ret = 52 + finding - '0';
	}
	else {
		if (finding == '+') {
			to_ret = 62;
		}
		else if (finding == '/') {
			to_ret = 63;
		}
		else if(finding == '='){
			to_ret = 64;
		}
		else {
			to_ret = 65;
		}
	}
	return to_ret;
}

string ReadFile(string fileName) {
	ifstream fin;
	fin.open(fileName);

	char reader;
	string to_ret = "";

	while (fin >> reader) {
		to_ret += reader;
	}

	fin.close();

	return to_ret;
}

void FillFile(string fileName, string info) {
	ofstream fout;
	fout.open(fileName);

	for (int i = 0; i < info.length(); i++) {
		fout << info[i];
	}

	fout.close();
}
