#include <iostream>
#include <string>
#include "Soundex.h"
#include <cctype>
#include <map>
using namespace std;

bool isPrevLetterHWY(std::string& name, size_t& i) {
  return (name[i-1] == 'H' || name[i-1] == 'W' || name[i-1] == 'Y');
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

void generateSoundexForPrevLetterHWY(const std::string& name, size_t& i, std::string& soundex, char& lastCode) {
             char currCode = getSoundexCode(name[i]);
           if(lastCode != currCode) {
               soundex += currCode;
  }
}

void generateSoundexForCurrentLetter(const std::string& name, size_t& i, std::string& soundex, char& previousCode) {
  if (getSoundexCode(name[i]) != '0' && getSoundexCode(name[i]) != previousCode) {
    soundex += getSoundexCode(name[i]);
  }
}


void handleSoundexLengthFour(std::string& soundex) {
  while (soundex.length() < 4) {
        soundex += '0';
    }
}

std::string generateSoundex(const std::string& name) {
  
    if (name.empty()) return "";
    
    std::string soundex(1, toupper(name[0]));
    char previousLetter = toupper(name[0]);
    char previousCode = getSoundexCode(name[0]);
    
    char lastLetter = toupper(name[0]);
    char lastCode = getSoundexCode(name[0]);
    
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        if (isPrevLetterHWY(name, i)) {
          generateSoundexForPrevLetterHWY(name, i, soundex, lastCode);
        }
        else {
          generateSoundexForCurrentLetter(name, i, soundex, previousCode);
        }
        lastCode = previousCode;
        previousCode = getSoundexCode(name[i]);
    }

    handleSoundexLengthFour(soundex);
    return soundex;
}


int main() {
std::string name;
    std::cout << "Enter a name: ";
    std::cin >> name;
 
    std::string soundexCode = generateSoundex(name);
    std::cout << "Soundex code for " << name << " is " << soundexCode << std::endl;
 
    return 0;
}
