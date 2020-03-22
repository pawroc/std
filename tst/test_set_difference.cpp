#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <algorithms.hpp>
#include <vector>

#include <iostream>

TEST_CASE( "set_difference", "Algorithm should return difference between two sets") 
{
    SECTION("First set is empty")
    {
        std::vector<int> first{};
        std::vector<int> second{1, 2, 3, 4, 5, 7};
        std::vector<int> difference;
        std::vector<int> difference_std;

        std::vector<int> expected{};

        my::std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference));
        std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference_std));
        REQUIRE( difference == expected );
        REQUIRE( difference == difference_std );
    }

    SECTION("Second set is empty")
    {
        std::vector<int> first{1, 2, 4, 7, 8, 9};
        std::vector<int> second{};
        std::vector<int> difference;
        std::vector<int> difference_std;

        std::vector<int> expected(first);

        my::std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference));
        std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference_std));
        REQUIRE( difference == expected );
        REQUIRE( difference == difference_std );
    }

    SECTION("Both sets are empty")
    {
        std::vector<int> first{};
        std::vector<int> second{};
        std::vector<int> difference;
        std::vector<int> difference_std;

        std::vector<int> expected{};

        my::std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference));
        std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference_std));
        REQUIRE( difference == expected );
        REQUIRE( difference == difference_std );
    }

    SECTION("Two sets with same length")
    {
        std::vector<int> first{1, 2, 4, 7, 8, 9};
        std::vector<int> second{1, 2, 3, 4, 5, 7};
        std::vector<int> difference;
        std::vector<int> difference_std;

        std::vector<int> expected{8, 9};

        my::std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference));
        std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference_std));
        REQUIRE( difference == expected );
        REQUIRE( difference == difference_std );
    }

    SECTION("First set is larger than second one")
    {
        std::vector<int> first{1, 2, 4, 7, 8, 9, 10, 21, 100};
        std::vector<int> second{1, 2, 3, 4, 5, 7};
        std::vector<int> difference;
        std::vector<int> difference_std;

        std::vector<int> expected{8, 9, 10, 21, 100};

        my::std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference));
        std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference_std));

        REQUIRE( difference == expected );
        REQUIRE( difference == difference_std );
    }

    SECTION("Second set is larger than first one")
    {
        std::vector<int> first{1, 2, 3, 4, 5, 7};
        std::vector<int> second{1, 2, 4, 7, 8, 9, 10, 21, 100};
        std::vector<int> difference;
        std::vector<int> difference_std;

        std::vector<int> expected{3, 5};

        my::std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference));
        std::set_difference(begin(first), end(first), begin(second), end(second), std::back_inserter(difference_std));
        REQUIRE( difference == expected );
        REQUIRE( difference == difference_std );
    }
}