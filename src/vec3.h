#ifndef CHARLES_VEC3_H
#define CHARLES_VEC3_H

#include <iostream>
#include <math.h>

template <typename T>
class vec3 {
public:
    vec3() {}
    vec3(T e0, T e1 , T e2) {
        m_e[0] = e0;
        m_e[1] = e1;
        m_e[2] = e2;
    }


    inline T x() const { return m_e[0]; }
    inline T y() const { return m_e[1]; }
    inline T z() const { return m_e[2]; }
    inline T r() const { return m_e[0]; }
    inline T g() const { return m_e[1]; }
    inline T b() const { return m_e[2]; }


    inline const vec3& operator+() const { return *this; }
    inline vec3& operator-() const { return vec3(-m_e[0], -m_e[1], -m_e[2]); }
    inline T operator[](int i) const { return m_e[i]; }
    inline T& operator[](int i) { return m_e[i]; }


    inline vec3& operator+=(const vec3& v) {
        m_e[0] += v.m_e[0];
        m_e[1] += v.m_e[1];
        m_e[2] += v.m_e[2];
        return *this;
    }

    inline vec3& operator-=(const vec3& v) {
        m_e[0] -= v.m_e[0];
        m_e[1] -= v.m_e[1];
        m_e[2] -= v.m_e[2];
        return *this;
    }

    inline vec3& operator*=(const vec3& v) {
        m_e[0] *= v.m_e[0];
        m_e[1] *= v.m_e[1];
        m_e[2] *= v.m_e[2];
        return *this;
    }

    inline vec3& operator/=(const vec3& v) {
        m_e[0] /= v.m_e[0];
        m_e[1] /= v.m_e[1];
        m_e[2] /= v.m_e[2];
        return *this;
    }

    inline vec3& operator*=(const T& t) {
        m_e[0] *= t;
        m_e[1] *= t;
        m_e[2] *= t;
        return *this;
    }

    inline vec3& operator/=(const T& t) {
        m_e[0] /= t;
        m_e[1] /= t;
        m_e[2] /= t;
        return *this;
    }


    inline T length() const {
        return sqrt(squared_length());
    }

    inline T squared_length() const {
        return m_e[0] * m_e[0]  +  m_e[1] * m_e[1]  +  m_e[2] * m_e[2];
    }

    inline void normalize() {
        T k = length();
        m_e[0] /= k;
        m_e[1] /= k;
        m_e[2] /= k;
    }

private:
    T m_e[3];
};

template <typename T>
inline vec3<T> operator+(const vec3<T>& v1, const vec3<T>& v2) {
    return vec3<T>(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

template <typename T>
inline vec3<T> operator-(const vec3<T>& v1, const vec3<T>& v2) {
    return vec3<T>(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

template <typename T>
inline vec3<T> operator*(const vec3<T>& v1, const vec3<T>& v2) {
    return vec3<T>(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

template <typename T>
inline vec3<T> operator/(const vec3<T>& v1, const vec3<T>& v2) {
    return vec3<T>(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z());
}

template <typename T>
inline vec3<T> operator*(T k, const vec3<T>& v1) {
    return vec3<T>(v1.x() * k, v1.y() * k, v1.z() * k);
}

template <typename T>
inline vec3<T> operator/(const vec3<T>& v1, T k) {
    return vec3<T>(v1.x() / k, v1.y() / k, v1.z() / k);
}

template <typename T>
inline T dot(const vec3<T>& v1, const vec3<T>& v2) {
    return (v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z());
}

template <typename T>
inline vec3<T> cross(const vec3<T>& v1, const vec3<T>& v2) {
    return vec3<T>(
        v1.y() * v2.z() - v1.z() * v2.y(),
        -(v1.x() * v2.z() - v1.z() * v2.x()),
        (v1.x() * v2.y() - v1.y() * v2.x())
    );
}

template <typename T>
inline std::istream& operator>>(std::istream& is, vec3<T>& t) {
    is >> t[0] >> t[1] << t[2];
    return is;
}

template <typename T>
inline std::ostream& operator<<(std::ostream& os, const vec3<T>& t) {
    os <<  t[0] << " " << t[1] << " " << t[2];
    return os;
}

template <typename T>
inline vec3<T> unit_vec(const vec3<T>& v) {
    return (v / v.length());
}

#endif
