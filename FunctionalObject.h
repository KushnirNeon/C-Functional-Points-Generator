#include "FunctionalObject.h"

FunctionalObject::FunctionalObject (const pair <double, double> & x0, const vector <pair <double, double>> & basePoints)
: point(x0), basePoints_(basePoints), d(1, basePoints_.size()), e(random_device()()) {}

pair <double, double> FunctionalObject::operator()()
{
    int i_t = d(e);
    pair <double, double> result = make_pair((basePoints_[i_t - 1].first + point.first) / 2,
                                             (basePoints_[i_t - 1].second + point.second) / 2);
    point = result;
    return result;
}
