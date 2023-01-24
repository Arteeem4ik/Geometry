#include "../i_shape.h"
#include "../segment.h"
#include "../vector.h"

namespace geometry {

Point::Point(int64_t x_coord, int64_t y_coord) : x_coord_(x_coord), y_coord_(y_coord) {
}

int64_t Point::GetX() const {
  return x_coord_;
}

int64_t Point::GetY() const {
  return y_coord_;
}

void Point::SetX(int64_t num) {
  x_coord_ = num;
}

void Point::SetY(int64_t num) {
  y_coord_ = num;
}

Vector Point::operator-(Point other) const {
  return Vector(-other.GetX() + x_coord_, -other.GetY() + y_coord_);
}

Point& Point::Move(const Vector& vector) {
  x_coord_ += vector.GetX();
  y_coord_ += vector.GetY();
  return *this;
}

std::string Point::ToString() const {
  std::string answer;
  answer += "Point(";
  answer += std::to_string(x_coord_);
  answer += ", ";
  answer += std::to_string(y_coord_);
  answer += ")";
  return answer;
}

bool Point::ContainsPoint(const Point& point) const {
  return (x_coord_ == point.x_coord_ && y_coord_ == point.y_coord_);
}

bool Point::CrossesSegment(const Segment& segment) const {
  Vector first(x_coord_ - segment.GetStart().x_coord_, y_coord_ - segment.GetStart().y_coord_);
  Vector second(x_coord_ - segment.GetEnd().x_coord_, y_coord_ - segment.GetEnd().y_coord_);
  Vector seg_vect(segment.GetEnd().x_coord_ - segment.GetStart().x_coord_,
                  segment.GetEnd().y_coord_ - segment.GetStart().y_coord_);
  return ((ScalarMult(first, seg_vect) >= 0) && (ScalarMult(second, seg_vect) <= 0) &&
          (VectorMult(first, seg_vect) == 0));
}

Point* Point::Clone() const {
  auto copy = new Point(x_coord_, y_coord_);
  return copy;
}
}  // namespace geometry
