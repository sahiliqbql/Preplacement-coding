#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int a, b;
    cin >> a >> b;

    //coordinates of Kimberly, Bob, Jack, and Janet
    int kx, ky, bx, by, jx, jy, jax, jay;
    cin >> kx >> ky >> bx >> by >> jx >> jy >> jax >> jay;


    double bestX = 1e9, bestY = 1e9;
    bool found = false;

    for (int x = -1000; x <= 1000; ++x) {
        for (int y = -1000; y <= 1000; ++y) {

            double d1 = distance(x, y, bx, by);  // Distance to Bob
            double d2 = distance(x, y, jax, jay); // Distance to Janet
            double dK = distance(x, y, kx, ky);  // Distance to Kimberly
            double dJ = distance(x, y, jx, jy);  // Distance to Jack

            if (fabs(dK - a * d1) <= 1e-6 && fabs(dJ - b * d2) <= 1e-6) {
                found = true;
                if (x < bestX || (x == bestX && y < bestY)) {
                    bestX = x;
                    bestY = y;
                }
            }
        }
    }

    if (found) {
        cout << fixed << setprecision(2) << bestX << " " << bestY << endl;
    } else {
        cout << "Impossible!" << endl;
    }

    return 0;
}
