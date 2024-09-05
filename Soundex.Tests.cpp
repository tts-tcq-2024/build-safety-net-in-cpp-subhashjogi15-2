#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, isPrevLetterHWYPass) {
    const std::string name = "Tymczak";
    size_t i = 3;
    EXPECT_TRUE(isPrevLetterHWY(name, i));
}
