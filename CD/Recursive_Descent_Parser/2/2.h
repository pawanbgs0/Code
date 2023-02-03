#include <bits/stdc++.h>
using namespace std;

	// E -> TEdash
	// Edash -> +TEdash/#
	// T -> FTdash
	// Tdash -> *FTdash/#
	// F -> (E)/id                 

void E(string input, int &index, bool &valid);
void Edash(string input, int &index, bool &valid);
void T(string input, int &index, bool &valid);
void Tdash(string input, int &index, bool &valid);
void F(string input, int &index, bool &valid);