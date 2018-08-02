/**
 * Not solved yet.
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
#include <cmath>
#include <cfloat>

using namespace std;

const double radius = 1.0;
const double eps = 0.00005;

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0): x(x), y(y) {}
};

using Point = struct Point;

Point center(const Point &p, const Point &q)
{
    return Point((p.x + q.x) / 2, (p.y + q.y) / 2);
}

double distance(const Point &p, const Point &q)
{
    auto dx = p.x - q.y;
    auto dy = p.y - q.y;

    return sqrt(dx * dx + dy * dy);
}

Point nextUp(const Point &p, const Point &q) {
    auto d = center(p, q);
    auto a = (q.y - p.y) / (q.x - p.x);
    auto b = -1.0;
    auto c = p.y - a * p.x;

    auto x = (d.x * (a * a + b * b) + b * (a * d.y + d.x) + a * c) / (b + b * b);
    auto y = (x - d.x) * (q.x - p.x) / (p.y - q.y) + d.y;

    cout << "computed" << " " << x << " " << y << endl;

    return Point(x, y);
}

Point top(vector<Point> centers) {
    while (centers.size() > 1ul) {
        auto i = centers.begin();
        auto j = i + 1;
        vector<Point> tmp;

        while (j != centers.end()) {
            if (fabs(i->y - j->y) < eps) {
                auto d = distance(*i, *j);
                auto h = sqrt(4 * radius * radius - d / 2);
                tmp.emplace_back((i->x + j->x) / 2, i->y + h);
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
    }

    return 0;
}

