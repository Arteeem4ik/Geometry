#include "../line.h"
#include "../segment.h"
#include "../vector.h"

namespace geometry {
Line::Line() = default;

Line::Line(Point start, Point end) : start_(start), end_(end) {
}

Line& Line::Move(const Vector& vector) {
  start_.Move(vector);
  end_.Move(vector);
  return *this;
}

int64_t Line::GetA() const {
  return -(end_.GetY() - start_.GetY());
}

int64_t Line::GetB() const {
  return (end_.GetX() - start_.GetX());
}

int64_t Line::GetC() const {
  return -(GetA() * start_.GetX() + GetB() * start_.GetY());
}

double Line::Distance(Point point) const {
  Vector first(point.GetX() - start_.GetX(), point.GetY() - start_.GetY());
  Vector second(start_.GetX() - end_.GetX(), start_.GetY() - end_.GetY());
  return abs(VectorMult(first, second)) / Length(second);
}

std::string Line::ToString() const {
  std::string answer;
  answer += "Line(";
  answer += std::to_string(GetA());
  answer += ", ";
  answer += std::to_string(GetB());
  answer += ", ";
  answer += std::to_string(GetC());
  answer += ")";
  return answer;
}

bool Line::ContainsPoint(const Point& point) const {
  return (point.GetX() * GetA() + point.GetY() * GetB() + GetC() == 0);
}

bool Line::CrossesSegment(const Segment& segment) const {
  int64_t first_num = GetA() * segment.GetStart().GetX() + GetB() * segment.GetStart().GetY() + GetC();
  int64_t second_num = GetA() * segment.GetEnd().GetX() + GetB() * segment.GetEnd().GetY() + GetC();
  return (first_num * second_num <= 0);
}

Line* Line::Clone() const {
  auto copy = new Line(start_, end_);
  return copy;
}
}  // namespace geometry
