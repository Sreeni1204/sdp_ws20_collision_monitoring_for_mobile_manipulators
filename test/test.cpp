// Pulled from https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
//#include "kinova_arm.h"
#include "primitives.h"
#include "obstacle.h"
#include "vector"

// unsigned int Factorial( unsigned int number ) {
//     return number <= 1 ? number : Factorial(number-1)*number;
// }

// TEST_CASE( "Factorials are computed", "[factorial]" ) {
//     REQUIRE( Factorial(1) == 1 );
//     REQUIRE( Factorial(2) == 2 );
//     REQUIRE( Factorial(3) == 6 );
//     REQUIRE( Factorial(10) == 3628800 );
// }

TEST_CASE("Obstacle generation and pose", "[obstacle]") {
    double radius_1 = 10;
    double length_1 = 70.710678118654755;
    Eigen::Matrix4d pose_1;
    pose_1 << 0.89455844, -0.14058875,  0.42426407,  0,
                -0.14058875,  0.81254834,  0.56568542,  0,
                -0.42426407, -0.56568542,  0.70710678,  0,
                0,          0,          0,          1;

    Eigen::Matrix4d pose_2;
    pose_2 << 0.76552284, -0.18758173, -0.61545745,  50,
                -0.18758173,  0.84993462, -0.49236596,  0,
                0.61545745,  0.49236596,  0.61545745,  0,
                0,          0,          0,          1;

    // Cylinder Link_1 = new Cylinder(pose_1, length_1, radius_1);
    // std::vector primitives = new std::vector<Obstacle>;
    // primitives->insert(Link_1);
    // Obstacle obstacle = new Obstacle(pose_1, primitives);
    // REQUIRE(obstacle->pose == pose_1);
    // obstacle->updatePose(pose_2);
    // REQUIRE(obstacle->pose == pose_2);
}