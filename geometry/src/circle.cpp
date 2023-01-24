#include "../circle.h"
#include "../segment.h"
#include "../vector.h"

namespace geometry {
Circle::Circle() = default;

Circle::Circle(Point point, int64_t radius) : centre_(point), radius_(radius) {
}

Circle& Circle::Move(const Vector& vector) {
  centre_.Move(vector);
  return *this;
}

std::string Circle::ToString() const {
  std::string answer;
  answer += "Circle(";
  answer += centre_.ToString();
  answer += ", ";
  answer += std::to_string(radius_);
  answer += ")";
  return answer;
}

bool Circle::ContainsPoint(const Point& point) const {
  Vector dist(point.GetX() - centre_.GetX(), point.GetY() - centre_.GetY());
  return (Length(dist) <= radius_);
}

bool Circle::CrossesSegment(const Segment& segment) const {
  if (segment.Distance(centre_) > radius_) {
    return false;
  }
  Vector first(centre_.GetX() - segment.GetStart().GetX(), centre_.GetY() - segment.GetStart().GetY());
  Vector second(centre_.GetX() - segment.GetEnd().GetX(), centre_.GetY() - segment.GetEnd().GetY());
  return (Length(first) >= radius_ || Length(second) >= radius_);
}

Circle* Circle::Clone() const {
  auto copy = new Circle(centre_, radius_);
  return copy;
}
}  // namespace geometry
