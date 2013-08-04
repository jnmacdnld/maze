#include <string>
#include <iostream>
#include <bitset>

#include "MazeTextfileProcessor.cpp"

using namespace std;

int main( int argc, const char* argv[] )
{
	bitset<16> bits = MazeTextfileProcessor::horizontalWallLineToBitset("+-+-+ + +-+-+-+-+-+-+ + +-+ +-+ +");
	
	for (int i = 0; i < bits.size(); i++) {
		cout << bits[i];
	}
}