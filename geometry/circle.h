#ifndef GEOMETRYCLASSES__CIRCLE_H_
#define GEOMETRYCLASSES__CIRCLE_H_

#include "i_shape.h"
#include "point.h"

namespace geometry {
class Circle : public IShape {
 private:
  Point centre_;
  int64_t radius_;

 public:
  Circle();

  Circle(Point, int64_t);

  Circle& Move(const Vector& vector) override;

  std::string ToString() const override;

  bool ContainsPoint(const Point& point) const override;

  bool CrossesSegment(const Segment& segment) const override;

  Circle* Clone() const override;
};
}  // namespace geometry

#endif  // GEOMETRYCLASSES__CIRCLE_H_
