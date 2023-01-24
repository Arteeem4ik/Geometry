#ifndef GEOMETRYCLASSES__I_SHAPE_H_
#define GEOMETRYCLASSES__I_SHAPE_H_

#include <string>
#include <iostream>

namespace geometry {
class Segment;
class Vector;
class Point;

class IShape {
 public:
  virtual ~IShape() = default;

  virtual IShape& Move(const Vector&) = 0;

  virtual bool ContainsPoint(const Point&) const = 0;

  virtual bool CrossesSegment(const Segment&) const = 0;

  virtual IShape* Clone() const = 0;

  virtual std::string ToString() const = 0;
};
}  // namespace geometry

#endif  // GEOMETRYCLASSES__I_SHAPE_H_
