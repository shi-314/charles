#include "vec3.h"
#include "ray.h"

#include <iostream>

using namespace std;

vec3f color(const rayf& r) {
    vec3f unit_direction = unit_vec(r.direction());
    float t = .5f * (unit_direction.y() + 1.0f);
    return (1.0f - t) * vec3f(1.0f, 1.0f, 1.0f) + t * vec3f(.5f, .7f, 1.0f);
}

int main() {
    int nx = 200;
    int ny = 100;

    cout << "P3\n" << nx << " " << ny << "\n255\n" << endl;

    vec3f lower_left_corner(-2.0f, -1.0f, -1.0f);
    vec3f horizontal(-4.0f, 0.0f, 0.0f);
    vec3f vertical(0.0f, 2.0f, 0.0f);
    vec3f origin(0.0f, 0.0f, 0.0f);

    for(int j = ny-1; j >= 0; j--) {
        for(int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);

            rayf r(origin, lower_left_corner + u * horizontal + v * vertical);

            vec3f hit_color(color(r));

            int ir = int(255.99 * hit_color.r());
            int ig = int(255.99 * hit_color.g());
            int ib = int(255.99 * hit_color.b());

            cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
