#include <set>
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}

vector <PT> points;

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

int main()
{
    int tests;
    cin >> tests;

    for (int t = 1; t <= tests; t++)
    {
        int nPoints;
        cin >> nPoints;
        for(;nPoints > 0; nPoints--)
        {
            double a, b;
            cin >> a;
            cin >> b;

            bool ok = true;
            for (size_t i=0; i< points.size();i++)
            {
                if (a == points[i].x && b == points[i].y)
                    ok = false;
            }

            if(ok) points.push_back(PT(a,b));
        }

        int maxCnt = 0;
        for (size_t i = 0; i < points.size()-1;i++)
            for (size_t j = i+1; j < points.size(); j++)
            {
                int cnt = 2;
                for (size_t k = 0; k<points.size(); k++)
                {
                    if (k==i || k==j)
                        continue;

                    PT r = (ProjectPointLine(points[i], points[j], points[k]));
                    if (fabs(r.x - points[k].x) <= EPS && fabs(r.y - points[k].y) <= EPS)
                    {
                        cnt++;
                    }
                }
                if (cnt > maxCnt) maxCnt = cnt;
            }

        if(points.size() == 1)
            cout << "Data set #" << t << " contains a single gnu."<< endl;
        else
            cout << "Data set #" << t << " contains " << points.size() << " gnus, out of which a maximum of " << maxCnt << " are aligned."<<endl;

        points.clear();
    }
}
