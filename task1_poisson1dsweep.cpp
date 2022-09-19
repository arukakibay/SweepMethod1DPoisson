#include <iostream>
#include<cmath>
#include<fstream>
using namespace std;
int main() {
    int n = 100;
    ofstream fout("task1.xls");
    double dx = 0.01,maxdif = 0.0;
    double A, B, C;
    double ua[101], u[101],a[101],b[101],D[101];
	A = 1.0 / (dx*dx);
    B = -2.0 / (dx*dx);
    C = 1.0 / (dx*dx);
    for (int i = 0; i <= n; i++) {
        ua[i] = (-dx*dx*i*i/4)- (cos(2*dx*i))/8 + (cos(2)-7)/8*dx*i + 9.0/8.0;
    }
    u[n] = 0.0;
    u[0] = 1.0;
    a[1] = 0.0;
    b[1] = 1.0;
 	for (int i = 0; i <= n; i++) {
        D[i] = -pow(sin(dx * i), 2);
    }
    for (int i = 1; i < n; i++) {
        a[i + 1] = -(A) / (B + a[i] * C);
        b[i + 1] = (D[i] - C * b[i]) / (B + C * a[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
       u[i] = a[i + 1] * u[i + 1] + b[i + 1];
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (maxdif < abs(u[i] - ua[i])) {
            maxdif = abs(u[i] - ua[i]);
        }
    }
    
    for (int i = 0; i <= n; i++) {
        cout << u[i] << "\t" << ua[i] << "\t" << endl;
        fout << u[i] << "\t" << ua[i]<< "\t"  << endl;
    }
	cout << "maxdif= " << maxdif << endl;

    system("pause");
    return 0;


}
