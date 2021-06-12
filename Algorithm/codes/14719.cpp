#include <iostream>
#include <vector>

using namespace std;

int measure(int height, int width, vector<int> blockHeights) {
	int pre_block;
	int amountOfWater = 0;
	for (int waterHeight = 1; waterHeight <= height; waterHeight++) {
		pre_block = -1;
		for (int thisBlock = 0; thisBlock < width; thisBlock++) {
			if (blockHeights[thisBlock] >= waterHeight) {
				if (pre_block == -1) {
					pre_block = thisBlock;
					continue;
				}
				else {
					amountOfWater += thisBlock - pre_wall - 1;
					pre_block = thisBlock;
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

