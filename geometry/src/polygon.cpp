#include "../polygon.h"
#include "../segment.h"
#include "../vector.h"

namespace geometry {
Polygon::Polygon() = default;

Polygon::Polygon(std::vector<Point> points) : points_(points), num_points_(points.size()) {
}

Polygon& Polygon::Move(const Vector& vector) {
  for (size_t i = 0; i < num_points_; ++i) {
    points_[i].Move(vector);
  }
  return *this;
}

std::string Polygon::ToString() const {
  std::string answer;
  answer += "Polygon(";
  for (size_t i = 0; i < num_points_; ++i) {
    answer += points_[i].ToString();
    if (i != num_points_ - 1) {
      answer += ", ";
    }
  }
  answer += ")";
  return answer;
}

bool Polygon::ContainsPoint(const Point& point) const {
  const int64_t k_coord = 100000000;
  size_t counter = 0, number = num_points_;
  Point new_point(k_coord, point.GetY() + 1);
  Segment new_segment(point, new_point);
  for (size_t i = 0; i < num_points_; ++i) {
    Segment segment(points_[i], points_[(i + 1) % number]);
    if (segment.ContainsPoint(point)) {
      return true;
    }
    if (segment.CrossesSegment(new_segment)) {
      ++counter;
    }
  }
  return ((counter % 2) != 0);
}

bool Polygon::CrossesSegment(const Segment& segment) const {
  for (size_t i = 0; i < num_points_ - 1; ++i) {
    Segment pol_seg(points_[i + 1], points_[i]);
    if (segment.CrossesSegment(pol_seg)) {
      return true;
    }
  }
  Segment pol_seg(points_[0], points_[num_points_ - 1]);
  return (segment.CrossesSegment(pol_seg));
}

Polygon* Polygon::Clone() const {
  auto copy = new Polygon(points_);
  return copy;
}
}  // namespace geometry
