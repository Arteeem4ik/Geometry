#ifndef GEOMETRYCLASSES__VECTOR_H_
#define GEOMETRYCLASSES__VECTOR_H_

#include "cmath"

namespace geometry {
class Vector {
 private:
  int64_t x_coord_;
  int64_t y_coord_;

 public:
  Vector();

  Vector(int64_t x, int64_t y);

  int64_t GetX() const;

  int64_t GetY() const;

  Vector operator+(const Vector& other);

  Vector operator-(const Vector& other);

  Vector operator+();

  Vector operator-();

  Vector operator*(int64_t number);

  Vector operator/(int64_t number);

  Vector& operator+=(const Vector& other);

  Vector& operator-=(const Vector& other);

  Vector& operator*=(int64_t number);

  Vector& operator/=(int64_t number);

  bool operator==(const Vector& other);

  friend int64_t ScalarMult(Vector first, Vector second);

  friend int64_t VectorMult(Vector first, Vector second);

  friend double Length(Vector vector);
};
}  // namespace geometry

#endif  // GEOMETRYCLASSES__VECTOR_H_
