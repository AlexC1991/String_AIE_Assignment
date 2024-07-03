#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER

class String
{
public:
	int passed = 0;
	int failed = 0;

	String();
	String(const char* _str);

	String(const String& _other);

	~String();

	size_t Length() const;
	char& CharacterAt(size_t _index);
	const char& CharacterAt(size_t _index) const;

	bool EqualTo(const String& _other) const;

	String& Append(const String& _str);
	String& Prepend(const String& _str);

	const char* CStr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& _str);
	size_t Find(size_t _startIndex, const String& _str);

	String& Replace(const String& _find, const String& _replace);

	String& ReadFromConsole();
	String& WriteToConsole();

	int LessThanOperator (const String& rhs) const;

	bool operator==(const String& _other);
	bool operator!=(const String& _other);

	String& operator=(const String& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

	String& CheckingScore();

	String& PrintingTD();

	struct testingResults
	{
		bool validChecker;
		int baseScore;
	};


private:
	char *charDataVariab;
	size_t length;
};

#endif