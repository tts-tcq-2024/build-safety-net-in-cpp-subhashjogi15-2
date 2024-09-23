#include "Soundex.h"
using namespace std;
 
bool isPrevLetterHWY(const std::string& name, size_t& iterator) {
  return (toupper(name[iterator-1]) == 'H' || toupper(name[iterator-1]) == 'W' || toupper(name[iterator-1]) == 'Y');
}

char getSoundexCode(char c) {
    std::map<char, char> soundexMap = {
        {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'},
        {'H', '0'}, {'W', '0'}, {'Y', '0'}, {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    auto it = soundexMap.find(toupper(c));
    return (it != soundexMap.end()) ? it->second : '0';
}

void generateSoundexIfPrevLetterHWY(const std::string& name, size_t& iterator, std::string& soundex, char& lastCode) {
  char currCode = getSoundexCode(name[iterator]);
  if(lastCode != currCode) {
     soundex += currCode;
  }
}

void generateSoundexIfPrevLetterNotHWY(const std::string& name, size_t& iterator, std::string& soundex, char& previousCode) {
if (getSoundexCode(name[iterator]) != '0' && getSoundexCode(name[iterator]) != previousCode) {
    char currCode = getSoundexCode(name[iterator]);
    soundex += currCode;
  }
}

void makeSoundeLengthFour(std::string& soundex) {
  while (soundex.length() < 4) {
        soundex += '0';
    }
}

void generateSoundexForLetter(const std::string& name, size_t& iterator, std::string& soundex, char& previousCode, char& lastCode) {
  if (isPrevLetterHWY(name, iterator)) {
    generateSoundexIfPrevLetterHWY(name, iterator, soundex, lastCode);
  }
  else {
    generateSoundexIfPrevLetterNotHWY(name, iterator, soundex, previousCode);
  }
}

/*  In the below function, "previousLetter" indicates the letter which is at the left side of the current letter
	"previousCode" indicates the soundex code of the letter which is at the left side of the current letter
	
	"lastLetter" indicates the letter which is at the 2nd left of the current letter.
	"lastCode" indicates the soundex code of the letter which is at the 2nd left of the current letter
	"iterator" refers to iterator pointing to current letter	*/

void handleSoundex(std::string& soundex, const std::string& name) {
    char previousLetter = toupper(name[0]);
    char previousCode = getSoundexCode(name[0]);
    char lastLetter = toupper(name[0]);
    char lastCode = getSoundexCode(name[0]);
    for (size_t iterator = 1; iterator < name.length() && soundex.length() < 4; ++iterator) {
      generateSoundexForLetter(name, iterator, soundex, previousCode, lastCode);
        lastCode = previousCode;

        previousCode = getSoundexCode(name[iterator]);
    }
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    std::string soundex(1, toupper(name[0]));
    handleSoundex(soundex, name);
    makeSoundeLengthFour(soundex);
    return soundex;
}
