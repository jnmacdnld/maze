#include <bitset>
#include <string>
#include <assert.h>

#define HORIZONTAL_WALL_LINE_LENGTH 33

using namespace std;

class MazeTextfileProcessor {
	public:
		static bitset<16> horizontalWallLineToBitset(string line) {
			checkIsValidHorizontalWallLine(line);

			bitset<16> wallBits;
			uint8_t wallBitsIndex = 0;
			uint8_t lineIndex = 1;

			while ( lineIndex < HORIZONTAL_WALL_LINE_LENGTH && wallBitsIndex < 16 ) {
				char wallChar = line.at(lineIndex);
				bool isWall = wallChar == '-';
				
				wallBits[wallBitsIndex] = isWall;

				wallBitsIndex++;
				lineIndex += 2;
			}

			return wallBits;
		}

	private:
		static void checkIsValidHorizontalWallLine(string line) {
			// Check correct line length
			assert(line.size() == HORIZONTAL_WALL_LINE_LENGTH);

			// Check plusses are at even indexes
			for (int i = 0; i < HORIZONTAL_WALL_LINE_LENGTH; i += 2) {
				assert(line.at(i) == '+');
			}

			//Check hyphens or spaces are at odd indexes
			for (int i = 1; i < HORIZONTAL_WALL_LINE_LENGTH; i += 2) {
				char wallChar = line.at(i);
				assert(wallChar == '-' || wallChar == ' ');
			}
			
		}
};