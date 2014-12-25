/*
 * @file geosdb.cpp
 *
 * @author a.sanchez@uni-muenster.de
 *
 * @brief Shared library that loads some geospatial functions into SciDB.
 */
#include <vector>
#include <boost/assign.hpp>
#include <math.h>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>

#include "query/Operator.h"
#include "query/FunctionLibrary.h"
#include "query/FunctionDescription.h"
#include "query/TypeSystem.h"

using namespace std;
using namespace scidb;
using namespace boost::assign;
using namespace boost::geometry;

BOOST_GEOMETRY_REGISTER_BOOST_TUPLE_CS(cs::cartesian)

void checkispointinpolygon(const Value** args, Value* res, void*)
{
	double x = args[0]->getDouble();
	double y = args[1]->getDouble();
	std::string wktPolygon = args[2]->getString();

	model::polygon<model::d2::point_xy<double> > poly;
	boost::geometry::read_wkt(wktPolygon, poly);
	boost::tuple<double, double> p = boost::make_tuple(x, y);
	res->setBool(within(p, poly));
}


void checkisprime(const Value** args, Value* res, void*)
{
	int64_t i,n;
	int8_t r;
	stringstream ss;

    n = args[0]->getInt64();
	r = 0;
	ss << n;

	if(n>1)
		for(i=2;i<=sqrt(n);i++)
			if(n%i==0)
			{
				r = 1;
				break;
			}

	if(r==0 && n>1)
		ss << " :prime";
	else
 		ss << " :not prime";

    res->setString(ss.str().c_str());

}

REGISTER_FUNCTION(isprime, list_of("int64"), "string", checkisprime);
REGISTER_FUNCTION(ispointinpolygon, list_of("double")("double")("string"), "bool", checkispointinpolygon);



