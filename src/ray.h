#ifndef CHARLES_RAY_H
#define CHARLES_RAY_H

#include "vec3.h"

template <typename T>
class ray {
public:
    ray() { }
    ray(const vec3<T>& origin, const vec3<T>& direction)
        : m_origin(origin)
        , m_direction(direction) {
    }

    vec3<T> origin() const { return m_origin; }
    vec3<T> direction() const { return m_direction; }
    T at(T t) const { return m_origin + m_direction * t; }

private:
    vec3<T> m_origin;
    vec3<T> m_direction;
};

typedef ray<float> rayf;

#endif
