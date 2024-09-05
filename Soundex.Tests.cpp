#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, isPrevLetterHWYPass) {
    const std::string name = "TYMZAK";
    size_t i = 2;
    EXPECT_TRUE(isPrevLetterHWY(name, i));
}
