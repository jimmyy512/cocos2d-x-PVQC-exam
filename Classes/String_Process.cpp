#include "String_Process.h"
STRING_PROCESS::STRING_PROCESS(int numOfWord)
{
	splitThreeTypeString(split(numOfWord));
}
void STRING_PROCESS::splitThreeTypeString(std::string wantTosplit)
{
	int pos;
	std::string pattern = "\t";
	wantTosplit += pattern;
	int size = wantTosplit.size();
	int type = 0;
	for (int i = 0; i < size; i++)
	{
		pos = wantTosplit.find(pattern, i);//§ä¦r
		if ((int)pos < size)
		{
			std::string s = wantTosplit.substr(i, pos - i);//¨ú¦r¦ê
			i = pos + pattern.size() - 1;
			if (type == 0)
				number_word = s;
			else if (type == 1)
				english_word = s;
			else
				chinese_word = s;
			type++;
		}
	}
}
std::string STRING_PROCESS::getNumberWord()
{
	return number_word;
}
std::string STRING_PROCESS::getEnglishWord()
{
	return english_word;
}
std::string STRING_PROCESS::getChineseWord()
{
	return chinese_word;
}
std::string STRING_PROCESS::split(int num)
{
	int pos;
	std::string result;
	std::string pattern = "\n";
	std::string fileStr = cocos2d::FileUtils::getInstance()->getStringFromFile("PVQC.txt");
	fileStr += pattern;
	int size = fileStr.size();
	int time = 0;
	for (int i = 0; i < size; i++)
	{
		pos = fileStr.find(pattern, i);//§ä¦r
		if ((int)pos < size)
		{
			std::string s = fileStr.substr(i, pos - i);//¨ú¦r¦ê
			i = pos + pattern.size() - 1;
			if (++time == num)
			{
				result = s;
				break;
			}
		}
	}
	return result;
}
