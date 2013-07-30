#pragma once

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <string>

#include "strPrint.h"

using namespace std;

void strPrint(string s) {
	char *a = new char[s.size()+1];
	a[s.size()] = 0;
	memcpy(a,s.c_str(), s.size());

	Serial.print(a);
}

void strPrintln(string s) {
	char *a = new char[s.size()+1];
	a[s.size()] = 0;
	memcpy(a,s.c_str(), s.size());

	Serial.println(a);
}
