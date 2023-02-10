In this problem, it is necessary to implement a set of classes for solving geometric problems on the plane. All coordinates
are assumed to be integers.

Vector
Implement the Vector class for a vector on a plane with the necessary arithmetic operations (unary and binary
+/-, scalar multiplication/division, assigning versions of operations, comparison for equality).

Shape
Create a set of shape classes that inherit from the abstract base class IShape to work with two-dimensional
geometric primitives:


Point;

Segment;

Line;

Ray;

Polygon (a simple polygon is a part of a plane bounded by a closed polyline without self-intersections);

Circle.

In the base class IShape, provide purely virtual methods:

Move(const Vector&) - shift by a given vector, the method must change the state of the object and return a reference to itself
an object;

ContainsPoint(const Point&) - check (true/false) whether the figure (the inside of the figure) contains a point;

CrossesSegment(const Segment&) check (true/false) whether the figure (the border of the figure) intersects with the segment;

Clone() - copying an object (it is necessary to return a smart or regular pointer to a copy of the shape);

ToString() - string representation of the figure (see examples for format).

In derived classes - implement these methods. The difference of two points must return the displacement vector of one point in
another.
