#include <cstdio>
#include "pch.h"
#include "gtest/gtest.h"

namespace {

	TEST(TxtToBase64, Modulo0) {
		
		EXPECT_EQ("QWJDZEVm", EncodeBase64("AbCdEf"));

		EXPECT_EQ("QmFzZTY0SXNDb29s", EncodeBase64("Base64IsCool"));

		EXPECT_EQ("SUhhdGVDKys7", EncodeBase64("IHateC++;"));
	}

	TEST(TxtToBase64, ModuloNot0) {

		EXPECT_EQ("MUAzJDVeNyo=", EncodeBase64("1@3$5^7*"));

		EXPECT_EQ("SGVscE1lV2l0aEl0Oig=", EncodeBase64("HelpMeWithIt:("));

		EXPECT_EQ("X1dlbGxJR2l2ZVVwXw==", EncodeBase64("_WellIGiveUp_"));

		EXPECT_EQ("KCkoKSgpKCkoKSgpKCkoKQ==", EncodeBase64("()()()()()()()()"));
	}

	TEST(Base64ToTxt, Modulo0) {

		EXPECT_EQ("AbCdEf" , DecodeBase64("QWJDZEVm"));

		EXPECT_EQ("Base64IsCool", DecodeBase64("QmFzZTY0SXNDb29s"));

		EXPECT_EQ("IHateC++;", DecodeBase64("SUhhdGVDKys7"));
	}

	TEST(Base64ToTxt, ModuloNot0) {

		EXPECT_EQ("1@3$5^7*", DecodeBase64("MUAzJDVeNyo="));

		EXPECT_EQ("HelpMeWithIt:(", DecodeBase64("SGVscE1lV2l0aEl0Oig="));

		EXPECT_EQ("_WellIGiveUp_", DecodeBase64("X1dlbGxJR2l2ZVVwXw=="));

		EXPECT_EQ("()()()()()()()()", DecodeBase64("KCkoKSgpKCkoKSgpKCkoKQ=="));
	}
	
	TEST(Base64ToTxt, EmptyString) {

		EXPECT_EQ("", DecodeBase64(""));

		EXPECT_EQ("", EncodeBase64(""));
	}

	TEST(Base64ToTxt, Error){

		EXPECT_EQ("ERROR There Are some Garbage bits .... !!!!....(This is Not Base64 code)", DecodeBase64("MUAzJDVeNyo==="));

		EXPECT_EQ("ERROR There Are some Garbage bits .... !!!!....(This is Not Base64 code)", DecodeBase64("MUAzJDVeNyo"));
	}
}



