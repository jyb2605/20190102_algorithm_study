#include "stdafx.h"

int map[504][504];

//type 1

int I1(int xPos, int yPos) {
	// I
	// I
	// I
	// I
	
	return map[xPos][yPos] + map[xPos + 1][yPos] + map[xPos + 2][yPos] + map[xPos + 3][yPos];
}

// type 2

int I2(int xPos, int yPos) {
	// ！！！！
	return map[xPos][yPos] + map[xPos][yPos + 1] + map[xPos][yPos + 2] + map[xPos][yPos + 3];
}

// type 3

int O(int xPos, int yPos) {
	// ！！！
	// |	|
	// ！！！
	return map[xPos][yPos] + map[xPos][yPos + 1] + map[xPos + 1][yPos] + map[xPos + 1][yPos + 1];
}

// type 4

int L1(int xPos, int yPos) {
	// |
	// |
	// |！
	
	return map[xPos][yPos] + map[xPos + 1][yPos] + map[xPos + 2][yPos] + map[xPos + 2][yPos + 1];
}

int L2(int xPos, int yPos) {
	// ！|
	//	 |
	//   |
	
	return map[xPos][yPos] + map[xPos][yPos + 1] + map[xPos + 1][yPos + 1] + map[xPos + 2][yPos + 1];
}

int J1(int xPos, int yPos) {
	//	 |
	//	 |
	// ！|

	return map[xPos][yPos + 1] + map[xPos + 1][yPos + 1] + map[xPos + 2][yPos + 1] + map[xPos + 2][yPos];
}

int J2(int xPos, int yPos) {
	// |！
	// |
	// |
	
	return map[xPos][yPos] + map[xPos + 1][yPos] + map[xPos + 2][yPos] + map[xPos][yPos + 1];
} 

int Z1(int xPos, int yPos) {
	//    __|
	//   |

	return map[xPos][yPos + 1] + map[xPos + 1][yPos] + map[xPos + 1][yPos + 1] + map[xPos + 2][yPos];
}

int S1(int xPos, int yPos) {
	//  |__
	//	   |
	
	return map[xPos][yPos] + map[xPos + 1][yPos] + map[xPos + 1][yPos + 1] + map[xPos + 2][yPos + 1];
}

int T1(int xPos, int yPos) {
	//  |
	//  |---
	//  |

	return map[xPos][yPos] + map[xPos + 1][yPos] + map[xPos + 1][yPos + 1] + map[xPos + 2][yPos];
}

int T2(int xPos, int yPos) {
	//		|
	//   ---|
	//		|

	return map[xPos][yPos + 1] + map[xPos + 1][yPos + 1] + map[xPos + 1][yPos] + map[xPos + 2][yPos + 1];
}

// type 5

int L3(int xPos, int yPos) {
	//		 |
	// ______|

	return map[xPos][yPos + 2] + map[xPos + 1][yPos] + map[xPos + 1][yPos + 1] + map[xPos + 1][yPos + 2];
}

int L4(int xPos, int yPos) {
	// |------
	// |

	return map[xPos][yPos] + map[xPos + 1][yPos] + map[xPos][yPos + 1] + map[xPos][yPos + 2];
}

int J3(int xPos, int yPos) {
	// |
	// |______

	return map[xPos][yPos] + map[xPos + 1][yPos] + map[xPos + 1][yPos + 1] + map[xPos + 1][yPos + 2];
}

int J4(int xPos, int yPos) {
	// ------|
	//		 |

	return map[xPos][yPos] + map[xPos + 1][yPos + 2] + map[xPos][yPos + 1] + map[xPos][yPos + 2];
}

int Z2(int xPos, int yPos) {
	//   ---| 
	//		|___ 

	return map[xPos][yPos] + map[xPos][yPos + 1] + map[xPos + 1][yPos + 1] + map[xPos + 1][yPos + 2];
}

int S2(int xPos, int yPos) {
	//	   |---
	//	___|

	return map[xPos + 1][yPos] + map[xPos + 1][yPos + 1] + map[xPos][yPos + 1] + map[xPos][yPos + 2];
}

int T3(int xPos, int yPos) {
	//  _________
	//		|

	return map[xPos][yPos] + map[xPos + 1][yPos + 1] + map[xPos][yPos + 1] + map[xPos][yPos + 2];
}

int T4(int xPos, int yPos) {
	//		|
	//  _________
	

	return map[xPos][yPos + 1] + map[xPos + 1][yPos + 1] + map[xPos + 1][yPos] + map[xPos + 1][yPos + 2];
}




int main() {
	int N, M, maxValue = 0;
	cin >> N >> M;


	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			// type 1
			if (i + 3 <= N)
				maxValue = max(maxValue, I1(i, j));
			
			// type 2
			if (j + 3 <= M)
				maxValue = max(maxValue, I2(i, j));
		
			// type 3
			if (i + 1 <= N && j + 1 <= M)
				maxValue = max(maxValue, O(i, j));
		
			// type 4
			if (i + 2 <= N && j + 1 <= M) {
				maxValue = max(maxValue, L1(i, j));
				maxValue = max(maxValue, L2(i, j));
				maxValue = max(maxValue, J1(i, j));
				maxValue = max(maxValue, J2(i, j));
				maxValue = max(maxValue, T1(i, j));
				maxValue = max(maxValue, T2(i, j));
				maxValue = max(maxValue, S1(i, j));
				maxValue = max(maxValue, Z1(i, j));
			}
			// type 5
			if (i + 1 <= N && j + 2 <= M) {
				maxValue = max(maxValue, L3(i, j));
				maxValue = max(maxValue, L4(i, j));
				maxValue = max(maxValue, J3(i, j));
				maxValue = max(maxValue, J4(i, j));
				maxValue = max(maxValue, T3(i, j));
				maxValue = max(maxValue, T4(i, j));
				maxValue = max(maxValue, S2(i, j));
				maxValue = max(maxValue, Z2(i, j));
				
			}
		}
	}


	cout << maxValue << endl;


	
	return 0;
}