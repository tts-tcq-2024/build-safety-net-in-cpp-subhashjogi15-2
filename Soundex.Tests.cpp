#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, isPrevLetterHWYPass) {
    const std::string name = "Tymczak";
    size_t i = 2;
    EXPECT_TRUE(isPrevLetterHWY(name, i));
}
