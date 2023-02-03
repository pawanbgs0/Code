#include <bits/stdc++.h>
using namespace std;

	// E -> TEdash
	// Edash -> +TEdash/#
	// T -> FTdash
	// Tdash -> *FTdash/#
	// F -> (E)/id                 

void E(string input, int &index );
void Edash(string input, int &index );
void T(string input, int &index );
void Tdash(string input, int &index );
void F(string input, int &index );