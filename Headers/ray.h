#ifndef GEOMETRYCLASSES__RAY_H_
#define GEOMETRYCLASSES__RAY_H_

#include "i_shape.h"
#include "point.h"

namespace geometry {
class Ray : public IShape {
 private:
  Point start_;
  Point end_;

 public:
  Ray();

  Ray(Point first, Point second);

  Ray& Move(const Vector& vector) override;

  std::string ToString() const override;

  bool ContainsPoint(const Point& point) const override;

  bool CrossesSegment(const Segment& segment) const override;

  Ray* Clone() const override;
};
}  // namespace geometry

#endif  // GEOMETRYCLASSES__RAY_H_
