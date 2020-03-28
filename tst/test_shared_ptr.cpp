#include <catch.hpp>
#include <shared_ptr.hpp>
#include <iostream>

struct DummyStruct
{
    DummyStruct() { std::cout << __FUNCTION__ << std::endl; }
    ~DummyStruct() { std::cout << __FUNCTION__ << std::endl; }

    DummyStruct(DummyStruct&&) { std::cout << "Moving DummyStruct\n"; }
    DummyStruct(const DummyStruct&) { std::cout << "Copying DummyStruct\n"; }

    DummyStruct& operator=(DummyStruct&&) { std::cout << "Moving DummyStruct\n"; return *this; }
    DummyStruct& operator=(const DummyStruct&) { std::cout << "Copying DummyStruct\n"; return *this; }
};

TEST_CASE("shared_ptr construction", "Different ways of constructing")
{
    SECTION("One shared_ptr is created")
    {
        my::std::shared_ptr<DummyStruct> sp(new DummyStruct); 
        REQUIRE(sp.ref_count() == 1);
    }

    SECTION("Two separeted shared_ptrs are created")
    {
        my::std::shared_ptr<DummyStruct> sp1(new DummyStruct);
        my::std::shared_ptr<DummyStruct> sp2(new DummyStruct);
        REQUIRE(sp1.ref_count() == 1);
        REQUIRE(sp2.ref_count() == 1);
    }

    SECTION("One shared_ptr is created by copying another")
    {
        my::std::shared_ptr<DummyStruct> sp1(new DummyStruct);
        {
            my::std::shared_ptr<DummyStruct> sp2(sp1);

            REQUIRE(sp1.ref_count() == 2);
            REQUIRE(sp2.ref_count() == 2);
        }
        REQUIRE(sp1.ref_count() == 1);
    }

    SECTION("One shared_ptr is moved to another")
    {
        my::std::shared_ptr<DummyStruct> sp1(new DummyStruct);
        my::std::shared_ptr<DummyStruct> sp2 = std::move(sp1);

        REQUIRE(sp1.ref_count() == 0);
        REQUIRE(sp2.ref_count() == 1);
    }

    SECTION("Shared pointer is created as a copy of another")
    {
        my::std::shared_ptr<DummyStruct> sp1(new DummyStruct);
        my::std::shared_ptr<DummyStruct> sp2;

        REQUIRE(sp1.ref_count() == 1);
        REQUIRE(sp2.ref_count() == 0);

        sp2 = sp1;

        REQUIRE(sp1.ref_count() == 2);
        REQUIRE(sp2.ref_count() == 2);
    }

    SECTION("Shared pointer is moved to another")
    {
        my::std::shared_ptr<DummyStruct> sp1(new DummyStruct);
        my::std::shared_ptr<DummyStruct> sp2;

        sp2 = std::move(sp1);

        REQUIRE(sp1.ref_count() == 0);
        REQUIRE(sp2.ref_count() == 1);
    }

    SECTION("Self assignment")
    {
        my::std::shared_ptr<DummyStruct> sp1;
        REQUIRE(sp1.ref_count() == 0);

        sp1 = sp1;
        REQUIRE(sp1.ref_count() == 0);
    }
}