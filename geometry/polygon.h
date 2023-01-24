#ifndef GEOMETRYCLASSES__POLYGON_H_
#define GEOMETRYCLASSES__POLYGON_H_

#include <iostream>
#include <vector>
#include "point.h"

namespace geometry {
class Polygon : public IShape {
 private:
  std::vector<Point> points_;
  size_t num_points_;

 public:
  Polygon();

  explicit Polygon(std::vector<Point> points);

  Polygon& Move(const Vector& vector) override;

  std::string ToString() const override;

  bool ContainsPoint(const Point& point) const override;

  bool CrossesSegment(const Segment& segment) const override;

  Polygon* Clone() const override;
};
}  // namespace geometry
#endif  // GEOMETRYCLASSES__POLYGON_H_
