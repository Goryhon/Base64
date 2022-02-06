//
// pch.h
//

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Base64.h
void EncodeBase64(string fileName, string outputFileName = "encodeOutput.txt");
void DecodeBase64(string fileName, string outputFileName = "decodeOutput.txt");
unsigned char findInArray(char finding);
string ReadFile(string fileName);
void FillFile(string fileName, string info);