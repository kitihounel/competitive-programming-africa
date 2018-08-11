/**
 * This solution does not work.
 * We will try to fix it later (or remove this file).
 * Use the solution provided by the judges: 'cylinders.official.c'.
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>
#include <cfloat>

using namespace std;

const double radius = 1.0;
const double eps = 0.00001;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0): x(x), y(y) {}
};

using Point = struct Point;

Point center(const Point &p, const Point &q)
{
    return Point((p.x + q.x) / 2.0, (p.y + q.y) / 2.0);
}

double distance(const Point &p, const Point &q)
{
    auto dx = p.x - q.x;
    auto dy = p.y - q.y;

    return sqrt(dx * dx + dy * dy);
}

double slope(const Point &p, const Point &q)
{
    return (p.y - q.y) / (p.x - q.x);
}

Point nextUpV2(const Point &p, const Point &q) {
    auto a = slope(p, q);
    auto d = distance(p, q);
    auto h = sqrt(4.0 * radius * radius - (d * d / 4.0));
    auto b = p.y - a * p.x;

    auto k = b + h * sqrt(1 + a * a);
    auto x = (p.x + q.x) / 2.0;

    return Point(x, a * x + k);
}

Point nextUp(const Point &p, const Point &q) {
    auto xd  = (p.x + q.x) / 2.0;
    auto yd  = (p.y + q.y) / 2.0;

    auto a1 = (p.y - q.y) / (p.x - q.x);
    auto b1 = p.y - a1 * p.x;
    auto a2 = -1.0 / a1;
    auto b2 = yd - a2 * xd;

    auto xu = q.x - p.x;
    auto yu = q.y - p.y;

    auto xc = ((xu * xd) + yu * (yd - b2)) / (xu + yu * a2);
    auto yc = a2 * xc + b2;

    return Point(xc, yc);
}

Point top(vector<Point> centers) {
    while (centers.size() > 1ul) {
        auto i = centers.begin();
        auto j = i + 1;
        vector<Point> tmp;

        while (j != centers.end()) {
            if (fabs(i->y - j->y) < eps) {
                auto d = distance(*i, *j);
                auto h = sqrt(4.0 * radius * radius - (d * d / 4.0));
                tmp.emplace_back((i->x + j->x) / 2.0, (i->y + j->y) / 2.0 + h);
            } else {
                tmp.push_back(nextUp(*i, *j));
            }
            ++i;
            ++j;
        }
        centers = tmp;
    }
    
    return centers[0];
}

int main()
{
    int t, n;
    double x;
    vector<Point> centers;

    scanf("%d", &t);
    for (int k = 1; k <= t; ++k) {
      scanf("%d", &n);
      for (int j = 0; j < n; ++j) {
          scanf("%lf", &x);
          centers.emplace_back(x, 1.0);
      }

      auto r = top(centers);

      printf("%d: %.4lf %.4lf\n", k, r.x, r.y);
      centers.clear();
    }

    return 0;
}

