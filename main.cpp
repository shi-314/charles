#include "vec3.h"

#include <iostream>

using namespace std;

typedef vec3<float> vec3f;
typedef vec3<double> vec3d;

int main() {
    int nx = 200;
    int ny = 200;

    cout << "P3\n" << nx << " " << ny << "\n255\n" << endl;
    for(int j = ny-1; j >= 0; j--) {
        for(int i = 0; i < nx; i++) {
            vec3f color(
                float(i) / float(nx),
                float(j) / float(ny),
                0.2f
            );
            color/=2;
            int ir = int(255.99 * color.r());
            int ig = int(255.99 * color.g());
            int ib = int(255.99 * color.b());
            cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
