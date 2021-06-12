#include <iostream>
#include <vector>

using namespace std;

int measure(int height, int width, vector<int> blockHeights) {
	int pre_wall;
	int amountOfWater = 0;
	for (int waterHeight = 1; waterHeight <= height; waterHeight++) {
		pre_wall = -1;
		for (int thisBlock = 0; thisBlock < width; thisBlock++) {
			if (blockHeights[thisBlock] >= waterHeight) {
				if (pre_wall == -1) {
					pre_wall = thisBlock;
					continue;
				}
				else {
					amountOfWater += thisBlock - pre_wall - 1;
					pre_wall = thisBlock;
				}
			}
		}
	}
	return amountOfWater;
}

int main() {
	int height, width, input, ans;
	cin >> height >> width;
	vector<int> blockHeights;
	for (int i = 0; i < width; i++) {
		cin >> input;
		blockHeights.push_back(input);
	}

	ans = measure(height, width, blockHeights);
	cout << ans;

}

