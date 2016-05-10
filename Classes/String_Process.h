#ifndef _String_Process_H_
#define _String_Process_H_
#include "cocos2d.h"

class STRING_PROCESS
{
protected:
	std::string number_word;
	std::string english_word;
	std::string chinese_word;
	
	std::string split(int num);
	void splitThreeTypeString(std::string wantTosplit);
public:
	STRING_PROCESS(int numOfWord);
	std::string getNumberWord();
	std::string getEnglishWord();
	std::string getChineseWord();
};
#endif