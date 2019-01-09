#include "stdafx.h"


int N, add, sub, mult, divi;
int A[12];
long long maxValue, minValue;

void addition(int idx, long long val);
void subtraction(int idx, long long val);
void multiplication(int idx, long long val);
void division(int idx, long long val);


void addition(int idx, long long val) {

	add--;
	
	if (idx >= N) {
		add++;
		maxValue = max(maxValue, val);
		minValue = min(minValue, val);
		return;
	}

	if (add < 0) {
		add++;
		return;
	}

	long long result = A[idx] + val;

	addition(idx + 1, result);
	subtraction(idx + 1, result);
	multiplication(idx + 1, result);
	division(idx + 1, result);

	add++;
	return;
}

void subtraction(int idx, long long val) {

	sub--;

	if (idx >= N) {
		sub++;
		maxValue = max(maxValue, val);
		minValue = min(minValue, val);
		return;
	}

	if (sub < 0) {
		sub++;
		return;
	}

	long long result = val - A[idx];

	addition(idx + 1, result);
	subtraction(idx + 1, result);
	multiplication(idx + 1, result);
	division(idx + 1, result);

	sub++;
	return;
}

void multiplication(int idx, long long val) {

	mult--;

	if (idx >= N) {
		mult++;
		maxValue = max(maxValue, val);
		minValue = min(minValue, val);
		return;
	}

	if (mult < 0) {
		mult++;
		return;
	}

	long long result = A[idx] * val;

	addition(idx + 1, result);
	subtraction(idx + 1, result);
	multiplication(idx + 1, result);
	division(idx + 1, result);

	mult++;
	return;
}

void division(int idx, long long val) {

	divi--;

	if (idx >= N) {
		divi++;
		maxValue = max(maxValue, val);
		minValue = min(minValue, val);
		return;
	}

	if (divi < 0) {
		divi++;
		return;
	}
	long long result;
	
	if (val >= 0) {
			result = val / A[idx];
	}
	else {
		result = abs(val) / A[idx];
		result *= -1;
	}

	addition(idx + 1, result);
	subtraction(idx + 1, result);
	multiplication(idx + 1, result);
	division(idx + 1, result);

	divi++;
	return;
}



int main() {

	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> add >> sub >> mult >> divi;
	
	maxValue = -1e9;
	minValue = 1e9;

	addition(1, A[0]);
	subtraction(1, A[0]);
	multiplication(1, A[0]);
	division(1, A[0]);

	cout << maxValue << endl << minValue << endl;

	return 0;
}