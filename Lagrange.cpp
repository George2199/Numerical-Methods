include <iostream>

using namespace std;

void main() {

const int n = 5;

double a[2][n] =

{

{0.27, 0.93, 1.46, 2.11, 2.87},

{2.6, 2.43, 2.06, 0.25, -2.6}

};

double x = 1.02;

double P = 0;

double L = 0;

for (int i = 0; i < n; i++) {

P = a[1][i];

for (int j = 0; j < n; j++) {

if (i != j) {

P = P * ((x - a[0][j]) / (a[0][i] - a[0][j]));

}

}

L = L + P;

}

cout « L;

}