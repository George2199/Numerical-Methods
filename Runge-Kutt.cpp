#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f(double x, double y) {
  return (3/x) - (y/x);
}

void Простой_Метод_Эйлера(double x, double y, double h, double b) {

  while (x <= b+h) {

    cout << setw(15) << left << x << setw(15) << left << y << endl;
    y = y + h * f(x, y);
    x = x + h;
    
  }

}

void Уточненный_Метод_Эйлера(double x, double z, double h, double b) {

  double* y{ new double[(b - x) / h] {} };
  y[0] = z;

  cout << setw(15) << left << x << setw(15) << left << y[0] << endl;

  double y_h = y[0] + (h / 2) * f(1, 0);
  y[1] = y[0] + h * f(x + (h / 2), y_h);
  x = x + h;

  for (int i = 1; x <= b + h; i++) {

    cout << setw(15) << x << setw(15) << y[i] << endl;
    y[i+1] = y[i-1] + 2*h * f(x, y[i]);
    x = x + h;

  }

}

void Метод_Рунге_Кутта_2(double x, double z, double h, double b) {

  float dy = 0;
  double a = 0.25;
  float k1 = 0;
  float k2 = 0;
  float* y{ new float[((b - x) / h) + 1] {} };
  y[0] = z;

  if (a != 0){

    for (int i = 0; x <= b + h; i++) {
      
      k1 = f(x, y[i]);
      k2 = f( x + (h / ( 2 * a )), y[i] + (h*k1 / ( 2 * a )) );
      dy = h * ((1 - a) * k1 + a * k2);
      cout << setw(5) << left << i << setw(5) << left << x << setw(13) << left << y[i] << setw(13) << left << k1 << setw(13) << left << k2 << setw(13) << left << dy << endl;
      y[i + 1] = y[i] + dy;
      x = x + h;

    }

  }

}

void Метод_Рунге_Кутта_4(double x, double z, double h, double b) {

  float dy = 0;
  float k1 = 0;
  float k2 = 0;
  float k3 = 0;
  float k4 = 0;
  float* y{ new float[((b - x) / h) + 1] {} };
  y[0] = z;

    for (int i = 0; x <= b + h; i++) {

      k1 = f(x, y[i]);
      k2 = f(x + (h / 2), y[i] + (h * k1 / 2));
      k3 = f(x + (h / 2), y[i] + (h * k2 / 2));
      k4 = f(x + h, y[i] + (h * k3));
      dy = (h / 6) * (k1 + 2*k2 + 2*k3 + k4);
      cout << setw(5) << left << i << setw(5) << left << x << setw(13) << left << y[i] << setw(13) << left << k1 << setw(13) << left << k2 << setw(13) << left << k3 << setw(13) << left << k4 << setw(13) << left << dy << endl;
      y[i + 1] = y[i] + dy;
      x = x + h;

    }

}

void main() {
  setlocale(LC_ALL, "RUS");

  double x = 1;
  double y = 0;
  double h = 0.1;
  double b = 2;

  Метод_Рунге_Кутта_4(x, y, h, b);
}
