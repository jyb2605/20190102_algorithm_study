#include "stdafx.h"

int N, S[21][21];
bool visited[21];
vector<int> stack;
int depth, startTeam, linkTeam, minDiff;

// prototype
void calc();

void visit(int idx) {
	depth++;
	visited[idx] = true;
	stack.push_back(idx);

	for (int i = 0; i < stack.size(); i++) {
		startTeam += S[stack[i]][idx];
		startTeam += S[idx][stack[i]];
	}

	if (depth >= (N / 2)) {
		calc();
		minDiff = min(minDiff, abs(startTeam - linkTeam));
		depth--;
		visited[idx] = false;
		stack.pop_back();

		for (int i = 0; i < stack.size(); i++) {
			startTeam -= S[stack[i]][idx];
			startTeam -= S[idx][stack[i]];
		}

		return;
	}

	for (int i = idx + 1; i < N + 1; i++)
		visit(i);

	
	depth--;
	visited[idx] = false;
	stack.pop_back();

	for (int i = 0; i < stack.size(); i++) {
		startTeam -= S[stack[i]][idx];
		startTeam -= S[idx][stack[i]];
	}

	return;
}

void calc() {
	linkTeam = 0;

	for (int i = 1; i < N + 1; i++) {
		if (visited[i])
			continue;
		for (int j = 1; j < N + 1; j++) {
			if (visited[j])
				continue;
			linkTeam += S[i][j];
		}
	}
}

int main() {

	cin >> N;

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> S[i][j];
		}
		visited[i] = false;
	}

	startTeam = 0;
	linkTeam = 0;
	minDiff = 1e9;

	depth = 0;

	for (int i = 1; i < N + 1; i++) {
		visit(i);
	}

	cout << minDiff << endl;

	return 0;
}