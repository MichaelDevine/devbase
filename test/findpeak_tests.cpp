#include <gtest/gtest.h>
#include "findpeak.hpp"

TEST(interview_library_tests, FindPeakTests) {
    EXPECT_TRUE(true);
}

TEST(interview_library_tests, FindPeakTests_One) {
    std::vector<int> test_1{ 3, 2, 1 };
    EXPECT_EQ(0, peak_index(test_1));

    // peak at odd index middle
    std::vector<int> test_2{ 1, 3, 1 };
    EXPECT_EQ(1, peak_index(test_2));

    // peak at even index end
    std::vector<int> test_3{ 1, 2, 3 };
    EXPECT_EQ(2, peak_index(test_3));

    // peak at even index middle
    std::vector<int> test_4{ 0, 1, 3, 2 };
    EXPECT_EQ(2, peak_index(test_4));

    // peak at even index end
    std::vector<int> test_5{ 0, 1, 2, 3 };
    EXPECT_EQ(3, peak_index(test_5));

    // no peak - result undefined, just making sure it doesn't blow up
    std::vector<int> test_6{ 3, 3, 3, 3, 3 };
    auto res = peak_index(test_6);

}
