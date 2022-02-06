//
// pch.h
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

//Base64.h
string EncodeBase64(string input);
string DecodeBase64(string input);
unsigned char findInArray(char finding);
string ReadFile(string fileName);
void FillFile(string fileName, string info);
