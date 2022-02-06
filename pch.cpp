#include "pch.h"

void EncodeBase64(string fileName, string outputFileName) {

	string base64Symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	ifstream fin;
	ofstream fout;
	fin.open(fileName);
	fout.open(outputFileName);

	unsigned char reader, holder, temp, holderSize;

	holderSize = 0;
	holder = 0;

	while (fin >> reader) {
		temp = reader;
		holder += temp >> holderSize;
		fout << (base64Symbols[holder >> 2]);
		holderSize += 2;
		holder = reader << (8 - holderSize);
		if (holderSize == 6) {
			fout << (base64Symbols[holder >> 2]);
			holder = 0;
			holderSize = 0;
		}
	}

	if (holderSize > 0) {
		fout << (base64Symbols[holder >> 2]);
		while (holderSize < 6) {
			holderSize += 2;
			fout << '=';
		}
	}

	fin.close();
	fout.close();
}

void DecodeBase64(string fileName, string outputFileName) {

	ifstream fin;
	ofstream fout;
	fin.open(fileName);
	fout.open(outputFileName);

	int count= 0;
	char reader;
	unsigned char holder, temp1, holderSize;

	bool hadEqSign = false;
	bool Error = false;
	int EqSigns = 0;

	holderSize = 0;
	holder = 0;

	while (fin >> reader) {
		temp1 = findInArray(reader);
		if (temp1 != 64) {
			holder += temp1 << 2 >> holderSize;
			holderSize += 6;
			if (holderSize > 8) {
				fout << holder;
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
		fout.close();

		fout.open(outputFileName);

		fout<<"ERROR There Are some Garbage bits .... !!!!....(This is Not Base64 code)";
	}
	else{

		if (holderSize > 0 && !hadEqSign) {
			fout << holder;
		}

	}

	fin.close();
	fout.close();
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