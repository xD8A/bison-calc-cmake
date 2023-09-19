#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <iostream>
#include "parser/driver.hh"


BOOST_AUTO_TEST_CASE(Test1) 
{
    driver drv;

    std::string s =
        "toto := 1\n"
        "toto";

    int res = drv.parse_string(s);
    BOOST_CHECK_EQUAL(res, 0);
    BOOST_CHECK_EQUAL(drv.result, 1);
}

BOOST_AUTO_TEST_CASE(Test2) 
{
    driver drv;

    std::string s =
        "a := 1\n"
        "b := 2\n"
        "c := 3\n"
        "d := a + b * c\n"
        "d";

    int res = drv.parse_string(s);
    BOOST_CHECK_EQUAL(res, 0);
    BOOST_CHECK_EQUAL(drv.result, 7);
}

BOOST_AUTO_TEST_CASE(Test3) 
{
    driver drv;

    std::string s =
        "a := 1\n"
        "b := 2\n"
        "c := 3\n"
        "d := (a + b) * c\n"
        "d";

    int res = drv.parse_string(s);
    BOOST_CHECK_EQUAL(res, 0);
    BOOST_CHECK_EQUAL(drv.result, 9);
}

BOOST_AUTO_TEST_CASE(Test4) 
{
    driver drv;

    std::string s =
        "a := 1\n"
        "d := a + b * c";

    int res = drv.parse_string(s);
    BOOST_CHECK_EQUAL(res, 1);
}
