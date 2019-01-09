#include "stdafx.h"

int N, result, cnt;

void up(vector<vector<int>> map);
void down(vector<vector<int>> map);
void left(vector<vector<int>> map);
void right(vector<vector<int>> map);

void up(vector<vector<int>> map) {
	cnt++;
	if (cnt > 5) {
		cnt--;
		return;
	}

	vector<int> noZeroArray;
	int idx = 1;

	for (int i = 1; i < N + 1; i++) {
		noZeroArray.clear();
		idx = 1;
		for (int j = 1; j < N + 1; j++) {
			if (map[j][i] != 0) {
				noZeroArray.push_back(map[j][i]);
				map[j][i] = 0;
			}
		}
		if (!noZeroArray.empty()) {
			for (int j = 0; j < noZeroArray.size() - 1; j++) {
				if (noZeroArray[j] == 0)
					continue;
				if (noZeroArray[j] == noZeroArray[j + 1]) {
					noZeroArray[j] *= 2;
					noZeroArray[j + 1] = 0;
				}
				map[idx][i] = noZeroArray[j];
				idx++;
			}
			map[idx][i] = noZeroArray[noZeroArray.size() - 1];
		}
	}

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			result = max(result, map[i][j]);
	

	up(map);
	cnt--;
	down(map);
	cnt--;
	right(map);
	cnt--;
	left(map);
	cnt--;

	return;
}

void down(vector<vector<int>> map) {
	cnt++;
	if (cnt > 5) {
		cnt--;
		return;
	}

	vector<int> noZeroArray;
	int idx = N;

	for (int i = N; i > 0; i--) {
		noZeroArray.clear();
		idx = N;
		for (int j = N; j > 0; j--) {
			if (map[j][i] != 0) {
				noZeroArray.push_back(map[j][i]);
				map[j][i] = 0;
			}
		}
		if (!noZeroArray.empty()) {
			for (int j = 0; j < noZeroArray.size() - 1; j++) {

				if (noZeroArray[j] == 0)
					continue;
				if (noZeroArray[j] == noZeroArray[j + 1]) {
					noZeroArray[j] *= 2;
					noZeroArray[j + 1] = 0;
				}
				map[idx][i] = noZeroArray[j];
				idx--;
			}
			map[idx][i] = noZeroArray[noZeroArray.size() - 1];

		}
	}


	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			result = max(result, map[i][j]);

	up(map);
	cnt--;
	down(map);
	cnt--;
	right(map);
	cnt--;
	left(map);
	cnt--;

	return;
}

void right(vector<vector<int>> map) {
	cnt++;
	if (cnt > 5) {
		cnt--;
		return;
	}

	vector<int> noZeroArray;
	int idx = N;

	for (int i = N; i > 0; i--) {
		noZeroArray.clear();
		idx = N;
		for (int j = N; j > 0; j--) {
			if (map[i][j] != 0) {
				noZeroArray.push_back(map[i][j]);
				map[i][j] = 0;
			}
		}
		if (!noZeroArray.empty()) {
			for (int j = 0; j < noZeroArray.size() - 1; j++) {

				if (noZeroArray[j] == 0)
					continue;
				if (noZeroArray[j] == noZeroArray[j + 1]) {
					noZeroArray[j] *= 2;
					noZeroArray[j + 1] = 0;
				}
				map[i][idx] = noZeroArray[j];
				idx--;
			}
			map[i][idx] = noZeroArray[noZeroArray.size() - 1];

		}
	}


	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			result = max(result, map[i][j]);

	up(map);
	cnt--;
	down(map);
	cnt--;
	right(map);
	cnt--;
	left(map);
	cnt--;

	return;


}

void left(vector<vector<int>> map) {
	cnt++;
	if (cnt > 5) {
		cnt--;
		return;
	}

	vector<int> noZeroArray;
	int idx = 1;

	for (int i = 1; i < N + 1; i++) {
		noZeroArray.clear();
		idx = 1;
		for (int j = 1; j < N + 1; j++) {
			if (map[i][j] != 0) {
				noZeroArray.push_back(map[i][j]);
				map[i][j] = 0;
			}
		}
		if (!noZeroArray.empty()) {
			for (int j = 0; j < noZeroArray.size() - 1; j++) {
				if (noZeroArray[j] == 0)
					continue;
				if (noZeroArray[j] == noZeroArray[j + 1]) {
					noZeroArray[j] *= 2;
					noZeroArray[j + 1] = 0;
				}
				map[i][idx] = noZeroArray[j];
				idx++;
			}
			map[i][idx] = noZeroArray[noZeroArray.size() - 1];

		}
	}

	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			result = max(result, map[i][j]);

	up(map);
	cnt--;
	down(map);
	cnt--;
	right(map);
	cnt--;
	left(map);
	cnt--;

	return;

}

int main() {
	
	bool empty = false;
	cin >> N;

	result = 0;
	
	vector<vector<int>> map(N + 1, vector<int>(N + 1));

	

	for (int i = 1; i < N + 1; i++) 
		for (int j = 1; j < N + 1; j++) 
			cin >> map[i][j];
	
	cnt = 0;
	up(map);
	cnt = 0;
	down(map);
	cnt = 0;
	left(map);
	cnt = 0;
	right(map);

	cout << result << endl;

	return 0;
}