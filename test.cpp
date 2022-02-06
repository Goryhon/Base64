#include <cstdio>
#include "pch.h"
#include "gtest/gtest.h"

namespace {

	TEST(TxtToBase64, Modulo0) {
		
		FillFile("testInput.txt","AbCdEf");
		EncodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("QWJDZEVm", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "Base64IsCool");
		EncodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("QmFzZTY0SXNDb29s", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "IHateC++;");
		EncodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("SUhhdGVDKys7", ReadFile("testOutput.txt"));

		remove("testInput.txt");
		remove("testOutput.txt");
	}

	TEST(TxtToBase64, ModuloNot0) {

		FillFile("testInput.txt", "1@3$5^7*");
		EncodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("MUAzJDVeNyo=", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "HelpMeWithIt:(");
		EncodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("SGVscE1lV2l0aEl0Oig=", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "_WellIGiveUp_");
		EncodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("X1dlbGxJR2l2ZVVwXw==", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "()()()()()()()()");
		EncodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("KCkoKSgpKCkoKSgpKCkoKQ==", ReadFile("testOutput.txt"));

		remove("testInput.txt");
		remove("testOutput.txt");
	}

	TEST(Base64ToTxt, Modulo0) {

		FillFile("testInput.txt", "QWJDZEVm");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("AbCdEf" , ReadFile("testOutput.txt"));

		FillFile("testInput.txt","QmFzZTY0SXNDb29s");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("Base64IsCool", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "SUhhdGVDKys7");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("IHateC++;", ReadFile("testOutput.txt"));

		remove("testInput.txt");
		remove("testOutput.txt");
	}

	TEST(Base64ToTxt, ModuloNot0) {

		FillFile("testInput.txt", "MUAzJDVeNyo=");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("1@3$5^7*", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "SGVscE1lV2l0aEl0Oig=");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("HelpMeWithIt:(", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "X1dlbGxJR2l2ZVVwXw==");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("_WellIGiveUp_", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "KCkoKSgpKCkoKSgpKCkoKQ==");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("()()()()()()()()", ReadFile("testOutput.txt"));

		remove("testInput.txt");
		remove("testOutput.txt");
	}

	TEST(Base64ToTxt, Error){

		FillFile("testInput.txt", "MUAzJDVeNyo===");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("ERROR There Are some Garbage bits .... !!!!....(This is Not Base64 code)", ReadFile("testOutput.txt"));

		FillFile("testInput.txt", "MUAzJDVeNyo");
		DecodeBase64("testInput.txt", "testOutput.txt");
		EXPECT_EQ("ERROR There Are some Garbage bits .... !!!!....(This is Not Base64 code)", ReadFile("testOutput.txt"));
	}
}



