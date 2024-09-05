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

TEST(SoundexTest, getSoundexCode_pass) {
   char c = 'A';
   EXPECT_EQ(getSoundexCode(c), '0');
}

TEST(SoundexTest, getSoundexCode_pass) {
   const std::string name = "BOB";
   char c = 'R';
   EXPECT_EQ(getSoundexCode(c), '2');
}

TEST(SoundexTest, generateSoundexIfPrevLetterHWY_Pass) {
    const std::string name = "BOB";
    size_t i = 2;
    std::string soundex = "1";
    char lastCode = '1'
    EXPECT_EQ(generateSoundexIfPrevLetterHWY(c , '6');
}

TEST(SoundexTest, GenerateSoundexIfPrevLetterHWY) {
    std::string name = "HWY";
    size_t index = 2;
    std::string soundex;
    char lastCode = '0';
    generateSoundexIfPrevLetterHWY(name, index, soundex, lastCode);
    EXPECT_EQ(soundex, "");
}
 
TEST(SoundexTest, GenerateSoundexIfPrevLetterNotHWY) {
    std::string name = "ABCD";
    size_t index = 1;
    std::string soundex;
    char previousCode = '0';
    generateSoundexIfPrevLetterNotHWY(name, index, soundex, previousCode);
    EXPECT_EQ(soundex, "1");
    index = 2;
    previousCode = '1';
    generateSoundexIfPrevLetterNotHWY(name, index, soundex, previousCode);
    EXPECT_EQ(soundex, "12");
}
 
TEST(SoundexTest, MakeSoundeLengthFour) {
    std::string soundex = "A";
    makeSoundeLengthFour(soundex);
    EXPECT_EQ(soundex, "A000");
    soundex = "A123";
    makeSoundeLengthFour(soundex);
    EXPECT_EQ(soundex, "A123");
}
 
TEST(SoundexTest, GenerateSoundexForLetter) {
    std::string name = "ABCD";
    size_t index = 1;
    std::string soundex;
    char previousCode = '0';
    char lastCode = '0';
    generateSoundexForLetter(name, index, soundex, previousCode, lastCode);
    EXPECT_EQ(soundex, "1");
    previousCode = '1';
    lastCode = '1';
    index = 2;
    generateSoundexForLetter(name, index, soundex, previousCode, lastCode);
    EXPECT_EQ(soundex, "12");
}
 
TEST(SoundexTest, HandleSoundex) {
    std::string name = "Example";
    std::string soundex;
    soundex = "E";
    handleSoundex(soundex, name);
    EXPECT_EQ(soundex, "E251");
 
    name = "Soundex";
    soundex = "S";
    handleSoundex(soundex, name);
    EXPECT_EQ(soundex, "S532");
 
    name = "HWY";
    soundex.clear();
    soundex = "H";
    handleSoundex(soundex, name);
    EXPECT_EQ(soundex, "H");
}
 
TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex("Example"), "E251");
    EXPECT_EQ(generateSoundex("Soundex"), "S532");
    EXPECT_EQ(generateSoundex("HWY"), "H000");
    EXPECT_EQ(generateSoundex(""), "");
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Abcd"), "A123");
    EXPECT_EQ(generateSoundex("pfister"), "P236");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}


