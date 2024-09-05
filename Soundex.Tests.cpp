#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, isPrevLetterHWY_Pass) {
    const std::string name = "TYMZAK";
    size_t i = 2;
    EXPECT_TRUE(isPrevLetterHWY(name, i));
}

TEST(SoundexTest, isPrevLetterHWY_Fail) {
    const std::string name = "TYMZAK";
    size_t i = 3;
    EXPECT_FALSE(isPrevLetterHWY(name, i));
}


