#include "../segment.h"
#include "../line.h"
#include "../vector.h"

namespace geometry {
Segment::Segment() = default;

Segment::Segment(Point first, Point second) : start_(first), end_(second) {
}

Point Segment::GetStart() const {
  return start_;
}

Point Segment::GetEnd() const {
  return end_;
}

double Segment::Distance(Point point) const {
  Vector first(point.GetX() - start_.GetX(), point.GetY() - start_.GetY());
  Vector second(point.GetX() - end_.GetX(), point.GetY() - end_.GetY());
  Vector seg_vect(end_.GetX() - start_.GetX(), end_.GetY() - start_.GetY());
  if ((ScalarMult(first, seg_vect) >= 0) && (ScalarMult(second, seg_vect) <= 0)) {
    Line line(start_, end_);
    return line.Distance(point);
  }
  return std::min(Length(first), Length(second));
}

bool Segment::Degenerate() const {
  return ((start_.GetX() == end_.GetX()) && (start_.GetY() == end_.GetY()));
}

Segment& Segment::Move(const Vector& vector) {
  start_.Move(vector);
  end_.Move(vector);
  return *this;
}

std::string Segment::ToString() const {
  std::string answer;
  answer += "Segment(";
  answer += start_.ToString();
  answer += ", ";
  answer += end_.ToString();
  answer += ")";
  return answer;
}

bool Segment::ContainsPoint(const Point& point) const {
  if (this->Degenerate()) {
    return point.ContainsPoint(start_);
  }
  return point.CrossesSegment(*this);
}

bool Segment::CrossesSegment(const Segment& segment) const {
  if (segment.Degenerate() && !(this->Degenerate())) {
    return ContainsPoint(segment.GetStart());
  }
  if (this->Degenerate() && !(segment.Degenerate())) {
    return segment.ContainsPoint(start_);
  }
  if (segment.Degenerate() && this->Degenerate()) {
    return start_.ContainsPoint(segment.GetStart());
  }
  Line second_line(start_, end_);
  Line first_line(segment.GetStart(), segment.GetEnd());

  if (first_line.CrossesSegment(*this) && second_line.CrossesSegment(segment)) {
    Vector first(this->end_.GetX() - this->start_.GetX(), this->end_.GetY() - this->start_.GetY());
    Vector sec(segment.GetEnd().GetX() - segment.GetStart().GetX(),
               segment.GetEnd().GetY() - segment.GetStart().GetY());
    if (VectorMult(first, sec) == 0) {
      int first_max_x = std::max(this->start_.GetX(), this->end_.GetX());
      int second_max_x = std::max(segment.GetStart().GetX(), segment.GetEnd().GetX());
      int first_min_x = std::min(this->start_.GetX(), this->end_.GetX());
      int second_min_x = std::min(segment.GetStart().GetX(), segment.GetEnd().GetX());
      int first_max_y = std::max(this->start_.GetY(), this->end_.GetY());
      int second_max_y = std::max(segment.GetStart().GetY(), segment.GetEnd().GetY());
      int first_min_y = std::min(this->start_.GetY(), this->end_.GetY());
      int second_min_y = std::min(segment.GetStart().GetY(), segment.GetEnd().GetY());
      bool first_condition = (first_max_x >= second_min_x && first_max_x <= second_max_x);
      bool second_condition = (second_max_x >= first_min_x && second_max_x <= first_max_x);
      bool third_condition = (first_max_y >= second_min_y && first_max_y <= second_max_y);
      bool fourth_condition = (second_max_y >= first_min_y && second_max_y <= first_max_y);
      return ((first_condition || second_condition) && (third_condition || fourth_condition));
    }
    return true;
  }
  return false;
}

Segment* Segment::Clone() const {
  auto copy = new Segment(start_, end_);
  return copy;
}
}  // namespace geometry
