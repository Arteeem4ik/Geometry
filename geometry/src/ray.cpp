#include "../ray.h"
#include "../segment.h"
#include "../line.h"
#include "../vector.h"

namespace geometry {
Ray::Ray() = default;

Ray::Ray(Point first, Point second) : start_(first), end_(second) {
}

Ray& Ray::Move(const Vector& vector) {
  start_.Move(vector);
  end_.Move(vector);
  return *this;
}

std::string Ray::ToString() const {
  std::string answer;
  answer += "Ray(";
  answer += start_.ToString();
  answer += ", Vector(";
  answer += std::to_string(end_.GetX() - start_.GetX());
  answer += ", ";
  answer += std::to_string(end_.GetY() - start_.GetY());
  answer += "))";
  return answer;
}

bool Ray::ContainsPoint(const Point& point) const {
  Line line(start_, end_);
  Vector first(end_.GetX() - start_.GetX(), end_.GetY() - start_.GetY());
  Vector second(point.GetX() - start_.GetX(), point.GetY() - start_.GetY());
  return (line.ContainsPoint(point) && ScalarMult(first, second) >= 0);
}

bool Ray::CrossesSegment(const Segment& segment) const {
  if (segment.ContainsPoint(start_)) {
    return true;
  }
  Vector seg_vec(segment.GetEnd().GetX() - segment.GetStart().GetX(),
                 segment.GetEnd().GetY() - segment.GetStart().GetY());
  Vector ray_vec(end_.GetX() - start_.GetX(), end_.GetY() - start_.GetY());
  Vector vector(start_.GetX() - segment.GetStart().GetX(), start_.GetY() - segment.GetStart().GetY());
  return (VectorMult(vector, seg_vec) * VectorMult(ray_vec, seg_vec) <= 0);
}

Ray* Ray::Clone() const {
  auto copy = new Ray(start_, end_);
  return copy;
}
}  // namespace geometry