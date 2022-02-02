#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <iostream>

#include "../src/matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expected_matrix = MatrixXd(3, 3);
    expected_matrix << 0.680375, 0.59688, -0.329554, -0.211234, 0.823295, 0.536459, 0.566198, -0.604897, -0.444451;
  }
  MatrixXd expected_matrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(m3)
{
  MatrixXd m = matrixIO::openData("../data/m3.csv", 3);
  BOOST_TEST(expected_matrix.isApprox(m));
};

BOOST_AUTO_TEST_SUITE_END()