#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <ctime>
#include<fstream>
using namespace std;
class clsString
{
private:
	string _Value;
public:
	enum enWhatToCount { SMALLLETTER = 1, CAPITALLETTER = 2, ALL = 3 };
	static char invertCharacters(char a)
	{
		if (!isdigit(a))
		{
			return isupper(a) ? tolower(a) : toupper(a);
		}
	}
	static bool isVowel(char a)
	{
		a = tolower(a);
		return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
	}
	clsString()
	{
		_Value = "";
	}
	clsString(string value)
	{
		_Value = value;
	}
	void setValue(string value)
	{
		_Value = value;
	}
	string getValue()
	{
		return _Value;
	}
	static int length(string text)
	{
		return text.length();
	}
	int length()
	{
		return _Value.length();
	}
	__declspec(property(get = getValue, put = setValue)) string Value;
	//static void printFirstLetterOfEachWord(string text)
	//{
	//	if (text.empty())
	//	{
	//		return;
	//	}
	//	bool isFirstLetter = true;
	//	for (int i = 0; i < text.length(); i++)
	//	{
	//		if (text[i] != ' ' && isFirstLetter)
	//		{
	//			cout << text[i] << endl;
	//		}
	//		isFirstLetter = text[i] == ' ' ? true : false;
	//	}
	//}
	//void printFirstLetterOfEachWord()
	//{
	//	printFirstLetterOfEachWord(_Value);
	//}
	static string UpperAllLettersInString(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = toupper(text[i]);
		}
		return text;
	}
	void UpperAllLettersInString()
	{
		_Value = UpperAllLettersInString(_Value);
	}
	static string LowerAllLettersInString(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = tolower(text[i]);
		}
		return text;
	}
	void LowerAllLettersInString()
	{
		_Value = LowerAllLettersInString(_Value);
	}
	static string InvertText(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = invertCharacters(text[i]);
		}
		return text;
	}
	void InvertText()
	{
		_Value = InvertText(_Value);
	}
	static int countLetters(string text, enWhatToCount choice = enWhatToCount::ALL)
	{
		int count = 0;
		if (choice == enWhatToCount::ALL)
		{
			return text.length();
		}
		for (int i = 0; i < text.length(); i++)
		{
			if (choice == enWhatToCount::CAPITALLETTER && isupper(text[i]))
			{
				count++;
			}
			else if (choice == enWhatToCount::SMALLLETTER && islower(text[i]))
			{
				count++;
			}
		}
		return count;
	}
	int countLetters(enWhatToCount choice = enWhatToCount::ALL)
	{
		return countLetters(_Value, choice);
	}
	static int countCapitalLettersCount(string text)
	{
		int upperLetterCount = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (isupper(text[i]))
			{
				upperLetterCount++;
			}
		}
		return upperLetterCount;
	}
	int countCapitalLettersCount()
	{
		return countCapitalLettersCount(_Value);
	}
	static int countSmallLettersCount(string text)
	{
		int smallLetterCount = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (islower(text[i]))
			{
				smallLetterCount++;
			}
		}
		return smallLetterCount;
	}
	int countSmallLettersCount()
	{
		return countSmallLettersCount(_Value);
	}
	static int countSpecficLetter(string text, char c, bool MatchCase = true)
	{
		int count = 0;
		for (int i = 0; i < text.size(); i++)
		{
			if (MatchCase)
			{
				if (text[i] == c)
				{
					count++;
				}
			}
			else
			{
				if (toupper(text[i]) == toupper(c))
				{
					count++;
				}
			}
		}
		return count;
	}
	int countSpecficLetter(char c, bool MatchCase = true)
	{
		return countSpecficLetter(_Value, c, MatchCase);
	}
	static void printWord(string text)
	{
		string delim = " ";
		string word = "";
		int pos = 0;
		while ((pos = text.find(delim)) != string::npos)
		{
			word = "";
			word = text.substr(0, pos);
			if (word != "")
			{
				cout << word << endl;
			}
			text.erase(0, pos + delim.size());
		}
		if (text != "")
		{
			cout << text << endl;
		}
	}
	void printWord()
	{
		printWord(_Value);
	}
	static int countWords(string text)
	{
		int count = 0;
		string delim = " ";
		string word = "";
		int pos = 0;
		while ((pos = text.find(delim)) != string::npos)
		{
			word = "";
			word = text.substr(0, pos);
			if (word != "")
			{
				count++;
			}
			text.erase(0, pos + delim.size());
		}
		if (text != "")
		{
			count += 1;
		}
		return count;
	}
	int countWords()
	{
		return countWords(_Value);
	}
	static vector<string> split(string text, string delim)
	{
		vector<string>words;
		string word = "";
		int pos = 0;
		while ((pos = text.find(delim)) != string::npos)
		{
			word = "";
			word = text.substr(0, pos);
			/*	if (word != "")
				{*/
			words.push_back(word);
			//}
			text.erase(0, pos + delim.size());
		}
		if (text != "")
		{
			words.push_back(text);
		}
		return words;
	}
	vector<string>split(string delim)
	{
		return split(_Value, delim);
	}
	static string trimLeft(string text)
	{
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ')
			{
				return text.substr(i, text.length() - i);
			}
		}
		return "";
	}
	void trimLeft()
	{
		_Value = trimLeft(_Value);
	}
	static string trimRight(string text)
	{
		for (int i = text.length() - 1; i >= 0; i--)
		{
			if (text[i] != ' ')
			{
				return text.substr(0, i + 1);
			}
		}
		return "";
	}
	void trimRight()
	{
		_Value = trimRight(_Value);
	}
	static string trim(string text)
	{
		return trimLeft(trimRight(text));
	}
	void trim()
	{
		_Value = trim(_Value);
	}
	static string joinString(vector<string>& names, string delim = " ")
	{
		if (names.empty())
		{
			return "";
		}
		string text = "";
		for (string& name : names)
		{
			text += name + delim;
		}
		return text.substr(0, text.size() - delim.size());
	}
	static string joinString(string arr[], int length, string delim = " ")
	{
		if (length == 0)
		{
			return "";
		}
		string text = "";
		for (int i = 0; i < length; i++)
		{
			text += arr[i] + delim;
		}
		return text.substr(0, text.size() - delim.size());
	}
	static string reverseWords(string s1)
	{
		string s2 = "";
		vector<string> words = split(s1, " ");
		vector<string>::iterator it = words.end();
		while (it != words.begin())
		{
			--it;
			s2 += *it + " ";
		}
		return s2.substr(0, s2.size() - 1);
	}
	void reverseWords()
	{
		_Value = reverseWords(_Value);
	}
	//static string replaceWordUsingBuiltInFunction(string text, string word, string replace)
	//{
	//	int pos = text.find(word);
	//	while (pos != string::npos)
	//	{
	//		text = text.replace(pos, word.length(), replace);
	//		pos = text.find(word);
	//	}
	//	return text;
	//}
	//void replaceWordUsingBuiltInFunction(string word, string replace)
	//{
	//	_Value= replaceWordUsingBuiltInFunction(_Value,word, replace);
	//}
	static string replaceWord(string text, string word, string replace, bool matchCase = true)
	{
		if (text.empty())
		{
			return "";
		}
		string text2 = "";
		vector<string>words = split(text, " ");
		for (string& s : words)
		{
			if (matchCase)
			{
				if (s == word)
				{
					s = replace;
				}
			}
			else
			{
				if (LowerAllLettersInString(s) == LowerAllLettersInString(word))
				{
					s = replace;
				}
			}
		}
		return joinString(words);
	}
	string replaceWord(string word, string replace, bool matchCase = true)
	{
		return replaceWord(_Value, word, replace, matchCase);
	}
	static string replaceWordUsingBuiltInFunction(string text, string word, string replace)
	{
		int pos = text.find(word);
		while (pos != string::npos)
		{
			text = text.replace(pos, word.length(), replace);
			pos = text.find(word);
		}
		return text;
	}
	void replaceWordUsingBuiltInFunction(string word, string replace)
	{
		_Value = replaceWordUsingBuiltInFunction(_Value, word, replace);
	}
	static string removePunctuations(string text)
	{
		string text2;
		for (int i = 0; i < text.size(); i++)
		{
			if (!ispunct(text[i]))
			{
				text2 += text[i];
			}
		}
		return text2;
	}
	void removePunctuations()
	{
		_Value = removePunctuations(_Value);
	}
	static void printVowels(string text)
	{
		cout << " vowels of string is: ";
		for (int i = 0; i < text.length(); i++)
		{
			if (isVowel(text[i]))
			{
				cout << text[i] << "   ";
			}
		}
	}
	void printVowels()
	{
		printVowels(_Value);
	}
	static int countVowels(string text)
	{
		int vowelCount = 0;
		for (int i = 0; i < text.length(); i++)
		{
			if (isVowel(text[i]))
			{
				vowelCount++;
			}
		}
		return vowelCount;
	}
	int countVowels()
	{
		return countVowels(_Value);
	}
	static string lowerFirstLetterOfEachWord(string text)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && isFirstLetter)
			{
				text[i] = tolower(text[i]);
			}
			isFirstLetter = text[i] == ' ' ? true : false;
		}
		return text;
	}
	void lowerFirstLetterOfEachWord()
	{
		_Value = lowerFirstLetterOfEachWord(_Value);
	}
	static string UpperFirstLetterOfEachWord(string text)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] != ' ' && isFirstLetter)
			{
				text[i] = toupper(text[i]);
			}
			isFirstLetter = text[i] == ' ' ? true : false;
		}
		return text;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}
};


