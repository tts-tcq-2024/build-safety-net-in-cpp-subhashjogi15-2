TEST(SoundexTest, ReturnSoundexEmptyIfInputEmpty) {
	EXPECT_EQ(generateSoundex(""), "");
}

//Test case to drop the occurances of a, e, i, o, u, y, h, w and replace all consonents with numbers
TEST(SoundexTest, replaceConsonentsWithNumbers) {
	EXPECT_EQ(generateSoundex("Robert"), "R163");
}

TEST(SoundexTest, appendWithZerosIfSoundexLengthLessThanFour) {
	EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

//Test case to test two or more letters with the same number are adjacent, only retain the first letter
TEST(SoundexTest, retainFirstLetterIfTwoOrMoreLettersAdjacent) {
	EXPECT_EQ(generateSoundex("Rubbbbin"), "R150");
}

//Test case to test two letters with the same number separated by 'h', 'w' or 'y' are coded as a single number
TEST(SoundexTest, codeSingleNumberIfTwoLetterswithSameNumberSeparatedByHWY) {
	EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}

//Test case to test two letters with the same number separated by vowel are coded twice
TEST(SoundexTest, codeSeparateNumberIfTwoLetterswithSameNumberSeparatedByVowel) {
	EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

//Test case to test first two letters have the same number and are coded once as single letter
TEST(SoundexTest, codeSingleLetterIfFirstTwoLettersWithSameNumbers) {
	EXPECT_EQ(generateSoundex("Pfister"), "P236");
}
