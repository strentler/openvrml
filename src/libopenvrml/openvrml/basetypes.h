// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
// OpenVRML
//
// Copyright 2001  S. K. Bose
// Copyright 2003, 2004  Braden McDaniel
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

# ifndef OPENVRML_BASETYPES_H
#   define OPENVRML_BASETYPES_H

#   include <cassert>
#   include <cmath>
#   include <cstddef>
#   include <algorithm>
#   include <iosfwd>
#   include <vector>
#   include <sys/types.h>

namespace openvrml {

#   ifdef _WIN32
    typedef __int32 int32;
#   else
    typedef int32_t int32;
#   endif

    class color {
        float rgb[3];

    public:
        color() throw ();
        explicit color(const float (&rgb)[3]) throw ();
        color(float r, float g, float b) throw ();

        const float & operator[](size_t index) const throw ();

        float r() const throw ();
        float g() const throw ();
        float b() const throw ();

        void r(float value) throw ();
        void g(float value) throw ();
        void b(float value) throw ();

        void hsv(float (&result)[3]) const throw ();
        void hsv(float h, float s, float v) throw ();
    };

    bool operator==(const color & lhs, const color & rhs) throw ();
    bool operator!=(const color & lhs, const color & rhs) throw ();
    std::ostream & operator<<(std::ostream & out, const color & c);

    inline const float & color::operator[](const size_t index) const throw ()
    {
        assert(index < 3);
        return this->rgb[index];
    }

    inline float color::r() const throw ()
    {
        return this->rgb[0];
    }

    inline float color::g() const throw ()
    {
        return this->rgb[1];
    }

    inline float color::b() const throw ()
    {
        return this->rgb[2];
    }

    inline void color::r(const float value) throw ()
    {
        this->rgb[0] = value;
    }

    inline void color::g(const float value) throw ()
    {
        this->rgb[1] = value;
    }

    inline void color::b(const float value) throw ()
    {
        this->rgb[2] = value;
    }


    class vec2f {
        float vec[2];

    public:
        vec2f() throw ();
        explicit vec2f(const float (&vec)[2]) throw ();
        vec2f(float x, float y) throw ();

        vec2f & operator*=(float scalar) throw ();
        vec2f & operator/=(float scalar) throw ();
        vec2f & operator+=(const vec2f & vec) throw ();
        vec2f & operator-=(const vec2f & vec) throw ();

        const vec2f operator-() const throw ();

        const float & operator[](size_t index) const throw ();

        float x() const throw ();
        float y() const throw ();

        void x(float value) throw ();
        void y(float value) throw ();

        float dot(const vec2f & vec) const throw ();
        float length() const throw ();
        const vec2f normalize() const throw ();
    };

    const vec2f operator*(const vec2f & lhs, float rhs) throw ();
    const vec2f operator*(float lhs, const vec2f & rhs) throw ();
    const vec2f operator/(const vec2f & lhs, float rhs) throw ();
    const vec2f operator+(const vec2f & lhs, const vec2f & rhs) throw ();
    const vec2f operator-(const vec2f & lhs, const vec2f & rhs) throw ();
    bool operator==(const vec2f & lhs, const vec2f & rhs) throw ();
    bool operator!=(const vec2f & lhs, const vec2f & rhs) throw ();
    std::ostream & operator<<(std::ostream & out, const vec2f & v);

    inline const float & vec2f::operator[](const size_t index) const throw ()
    {
        assert(index < 2);
        return this->vec[index];
    }

    inline float vec2f::x() const throw ()
    {
        return this->vec[0];
    }

    inline float vec2f::y() const throw ()
    {
        return this->vec[1];
    }

    inline void vec2f::x(const float value) throw ()
    {
        //
        // Ensure value is not NaN.
        //
        assert(value == value);

        this->vec[0] = value;
    }

    inline void vec2f::y(const float value) throw ()
    {
        //
        // Ensure value is not NaN.
        //
        assert(value == value);

        this->vec[1] = value;
    }


    class mat4f;

    class vec3f {
        float vec[3];

    public:
        vec3f() throw ();
        explicit vec3f(const float (&vec)[3]) throw ();
        vec3f(float x, float y, float z) throw ();

        vec3f & operator*=(const vec3f & vec) throw ();
        vec3f & operator*=(const mat4f & mat) throw ();
        vec3f & operator*=(float scalar) throw ();
        vec3f & operator/=(float scalar) throw ();
        vec3f & operator+=(const vec3f & vec) throw ();
        vec3f & operator-=(const vec3f & vec) throw ();

        const vec3f operator-() const throw ();

        const float & operator[](size_t index) const throw ();

        float x() const throw ();
        float y() const throw ();
        float z() const throw ();

        void x(float value) throw ();
        void y(float value) throw ();
        void z(float value) throw ();

        float dot(const vec3f & vec) const throw ();
        float length() const throw ();
        const vec3f normalize() const throw ();
    };

    const vec3f operator*(const vec3f & lhs, const vec3f & rhs) throw ();
    const vec3f operator*(const vec3f & lhs, const float rhs) throw ();
    const vec3f operator*(const float lhs, const vec3f & rhs) throw ();
    const vec3f operator*(const vec3f & vec, const mat4f & mat) throw ();
    const vec3f operator*(const mat4f & mat, const vec3f & vec) throw ();
    const vec3f operator/(const vec3f & lhs, const float rhs) throw ();
    const vec3f operator+(const vec3f & lhs, const vec3f & rhs) throw ();
    const vec3f operator-(const vec3f & lhs, const vec3f & rhs) throw ();
    bool operator==(const vec3f & lhs, const vec3f & rhs) throw ();
    bool operator!=(const vec3f & lhs, const vec3f & rhs) throw ();
    std::ostream & operator<<(std::ostream & out, const vec3f & v);

    inline const float & vec3f::operator[](const size_t index) const throw ()
    {
        assert(index < 3);
        return this->vec[index];
    }

    inline float vec3f::x() const throw ()
    {
        return this->vec[0];
    }

    inline float vec3f::y() const throw ()
    {
        return this->vec[1];
    }

    inline float vec3f::z() const throw ()
    {
        return this->vec[2];
    }

    inline void vec3f::x(const float value) throw ()
    {
        //
        // Ensure value is not NaN.
        //
        assert(value == value);

        this->vec[0] = value;
    }

    inline void vec3f::y(const float value) throw ()
    {
        //
        // Ensure value is not NaN.
        //
        assert(value == value);

        this->vec[1] = value;
    }

    inline void vec3f::z(const float value) throw ()
    {
        //
        // Ensure value is not NaN.
        //
        assert(value == value);

        this->vec[2] = value;
    }


    class quatf;

    class rotation {
        float rot[4];

    public:
        rotation() throw ();
        explicit rotation(const float (&rot)[4]) throw ();
        rotation(float x, float y, float z, float angle) throw ();
        rotation(const vec3f & axis, float angle) throw ();
        rotation(const vec3f & from_vec, const vec3f & to_vec) throw ();
        explicit rotation(const quatf & quat) throw ();

        rotation & operator*=(const rotation & rot) throw ();

        const float & operator[](size_t index) const throw ();

        float x() const throw ();
        float y() const throw ();
        float z() const throw ();
        const vec3f axis() const throw ();
        float angle() const throw ();

        void x(float value) throw ();
        void y(float value) throw ();
        void z(float value) throw ();
        void axis(const vec3f & axis) throw ();
        void angle(float value) throw ();

        const rotation inverse() const throw ();
        const rotation slerp(const rotation & dest_rot, float t) const
            throw ();
    };

    const rotation operator*(const rotation & lhs, const rotation & rhs)
        throw ();
    bool operator==(const rotation & lhs, const rotation & rhs) throw ();
    bool operator!=(const rotation & lhs, const rotation & rhs) throw ();
    std::ostream & operator<<(std::ostream & out, const rotation & r);

    inline const float & rotation::operator[](const size_t index) const
        throw ()
    {
        assert(index < 4);
        return this->rot[index];
    }

    inline float rotation::x() const throw ()
    {
        return this->rot[0];
    }

    inline float rotation::y() const throw ()
    {
        return this->rot[1];
    }

    inline float rotation::z() const throw ()
    {
        return this->rot[2];
    }

    inline const vec3f rotation::axis() const throw ()
    {
        return vec3f(this->rot[0], this->rot[1], this->rot[2]);
    }

    inline float rotation::angle() const throw ()
    {
        return this->rot[3];
    }

    inline void rotation::angle(const float value) throw ()
    {
        this->rot[3] = value;
    }


    class mat4f {
        float mat[4][4];

    public:
        static const mat4f rotation(const openvrml::rotation & rot) throw ();
        static const mat4f rotation(const quatf & quat) throw ();
        static const mat4f scale(float s) throw ();
        static const mat4f scale(const vec3f & s) throw ();
        static const mat4f translation(const vec3f & t) throw ();
        static const mat4f transformation(const vec3f & t,
                                          const openvrml::rotation & r,
                                          const vec3f & s,
                                          const openvrml::rotation & sr,
                                          const vec3f & c) throw ();

        mat4f() throw ();
        mat4f(float f11, float f12, float f13, float f14,
              float f21, float f22, float f23, float f24,
              float f31, float f32, float f33, float f34,
              float f41, float f42, float f43, float f44) throw ();
        explicit mat4f(const float mat[16]) throw ();
        explicit mat4f(const float (&mat)[4][4]) throw ();

        // Use compiler-defined operator= and copy constructor.

        mat4f & operator*=(float scalar) throw ();
        mat4f & operator*=(const mat4f & mat) throw ();

        float (&operator[](const size_t index) throw ())[4];
        const float (&operator[](const size_t index) const throw ())[4];

        void transformation(vec3f & t, openvrml::rotation & r, vec3f & s) const
            throw ();
        void transformation(vec3f & t, openvrml::rotation & r, vec3f & s,
                            vec3f & shear) const
            throw ();

        const mat4f inverse() const throw ();
        const mat4f transpose() const throw ();
        float det() const throw ();
    };

    bool operator==(const mat4f & lhs, const mat4f & rhs) throw ();
    bool operator!=(const mat4f & lhs, const mat4f & rhs) throw ();

    inline float (&mat4f::operator[](size_t index) throw ())[4]
    {
        assert(index < 4);
        return this->mat[index];
    }

    inline const float (&mat4f::operator[](size_t index) const throw ())[4]
    {
        assert(index < 4);
        return this->mat[index];
    }

    const mat4f operator*(const mat4f & lhs, const mat4f & rhs) throw ();
    const mat4f operator*(const mat4f & mat, float scalar) throw ();
    const mat4f operator*(float scalar, const mat4f & mat) throw ();
    std::ostream & operator<<(std::ostream & out, const mat4f & mat);


    class quatf {
        float quat[4];

    public:
        quatf() throw ();
        quatf(float x, float y, float z, float w) throw ();
        explicit quatf(const float (&quat)[4]) throw ();
        explicit quatf(const rotation & rot) throw ();
        explicit quatf(const mat4f & mat) throw ();

        // use compiler-defined operator= and copy constructor.

        quatf & operator*=(const quatf & quat) throw ();
        quatf & operator*=(float scalar) throw ();
        quatf & operator/=(float scalar) throw ();
        quatf & operator+=(const quatf & quat) throw ();
        quatf & operator-=(const quatf & quat) throw ();

        const float & operator[](size_t index) const throw ();
        float & operator[](size_t index) throw ();

        float x() const throw ();
        float y() const throw ();
        float z() const throw ();
        float w() const throw ();

        void x(float value) throw ();
        void y(float value) throw ();
        void z(float value) throw ();
        void w(float value) throw ();

        const quatf conjugate() const throw ();
        const quatf inverse() const throw ();
        float norm() const throw ();
        const quatf normalize() const throw ();
    };

    const quatf operator*(const quatf & lhs, const quatf & rhs) throw ();
    const quatf operator*(const quatf & quat, const float scalar) throw ();
    const quatf operator*(const float scalar, const quatf & quat) throw ();
    const quatf operator/(const quatf & quat, const float scalar) throw ();
    const quatf operator+(const quatf & lhs, const quatf & rhs) throw ();
    const quatf operator-(const quatf & lhs, const quatf & rhs) throw ();
    bool operator==(const quatf & lhs, const quatf & rhs) throw ();
    bool operator!=(const quatf & lhs, const quatf & rhs) throw ();
    std::ostream & operator<<(std::ostream & out, const quatf & quat);

    inline const float & quatf::operator[](size_t index) const throw ()
    {
        assert(index < 4);
        return this->quat[index];
    }

    inline float & quatf::operator[](size_t index) throw ()
    {
        assert(index < 4);
        return this->quat[index];
    }

    inline float quatf::x() const throw ()
    {
        return this->quat[0];
    }

    inline float quatf::y() const throw ()
    {
        return this->quat[1];
    }

    inline float quatf::z() const throw ()
    {
        return this->quat[2];
    }

    inline float quatf::w() const throw ()
    {
        return this->quat[3];
    }

    inline void quatf::x(const float value) throw ()
    {
        this->quat[0] = value;
    }

    inline void quatf::y(const float value) throw ()
    {
        this->quat[1] = value;
    }

    inline void quatf::z(const float value) throw ()
    {
        this->quat[2] = value;
    }

    inline void quatf::w(const float value) throw ()
    {
        this->quat[3] = value;
    }


    class image {
        size_t x_;
        size_t y_;
        size_t comp_;
        std::vector<unsigned char> array_;

    public:
        image() throw ();
        image(size_t x, size_t y, size_t comp) throw (std::bad_alloc);
        image(size_t x, size_t y, size_t comp,
              const std::vector<unsigned char> & array) throw (std::bad_alloc);
        template <typename InputIterator>
        image(size_t x, size_t y, size_t comp,
              InputIterator array_begin, InputIterator array_end)
            throw (std::bad_alloc);

        // Use compiler-defined operator= and copy constructor.

        size_t x() const throw ();
        void x(size_t value) throw (std::bad_alloc);

        size_t y() const throw ();
        void y(size_t value) throw (std::bad_alloc);

        void resize(size_t x, size_t y) throw (std::bad_alloc);

        size_t comp() const throw ();
        void comp(size_t value) throw (std::bad_alloc);

        const std::vector<unsigned char> & array() const throw ();
        void array(const std::vector<unsigned char> & value) throw ();
        template <typename InputIterator>
        void array(InputIterator begin, InputIterator end) throw ();

        int32 pixel(size_t index) const throw ();
        void pixel(size_t index, int32 value) throw ();
        int32 pixel(size_t x, size_t y) const throw ();
        void pixel(size_t x, size_t y, int32 value) throw ();
    };

    bool operator==(const image & lhs, const image & rhs) throw ();
    bool operator!=(const image & lhs, const image & rhs) throw ();

    template <typename InputIterator>
    image::image(const size_t x,
                 const size_t y,
                 const size_t comp,
                 InputIterator array_begin,
                 InputIterator array_end)
        throw (std::bad_alloc):
        x_(x),
        y_(y),
        comp_(comp),
        array_(array_begin, array_end)
    {
        using std::iterator_traits;
        using std::distance;
        typedef typename iterator_traits<InputIterator>::difference_type
            difference_type;
        assert(distance(array_begin, array_end)
               <= difference_type(x * y * comp));
    }

    inline size_t image::x() const throw ()
    {
        return this->x_;
    }

    inline size_t image::y() const throw ()
    {
        return this->y_;
    }

    inline size_t image::comp() const throw ()
    {
        return this->comp_;
    }

    inline const std::vector<unsigned char> & image::array() const throw ()
    {
        return this->array_;
    }

    inline void image::array(const std::vector<unsigned char> & value) throw ()
    {
        assert(value.size() <= (this->x_ * this->y_ * this->comp_));
        std::copy(value.begin(), value.end(), this->array_.begin());
    }

    template <typename InputIterator>
    void image::array(InputIterator begin, InputIterator end) throw ()
    {
        assert(std::distance(begin, end) <= this->x_ * this->y_ * this->comp_);
        std::copy(begin, end, this->array_.begin());
    }

    inline int32 image::pixel(const size_t index) const throw ()
    {
        assert(index < this->x_ * this->y_);
        int32 retval = 0x00000000;
        for (size_t component = this->comp_, i = index * this->comp_;
             component > 0;
             --component, ++i) {
            retval |= int32(this->array_[i]) << (8 * component);
        }
        return retval;
    }

    inline void image::pixel(const size_t index, const int32 value) throw ()
    {
        assert(index < this->x_ * this->y_);
        for (size_t component = this->comp_, i = index * this->comp_;
             component > 0;
             --component, ++i) {
            this->array_[i] =
                static_cast<unsigned char>(
                    (value >> (8 * (component - 1))) & 0x000000ff);
        }
    }

    inline int32 image::pixel(const size_t x, const size_t y) const throw ()
    {
        assert((x * y) < this->array_.size());
        return this->pixel(y * this->x_ + x);
    }

    inline void image::pixel(const size_t x, const size_t y, const int32 value)
        throw ()
    {
        assert((x * y) < this->array_.size());
        this->pixel(y * this->x_ + x, value);
    }

    std::ostream & operator<<(std::ostream & out, const image & img);

} // namespace openvrml

# endif // OPENVRML_BASETYPES_H
