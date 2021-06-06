#pragma once
#include<iostream>
#include<string>
using namespace std;

namespace Ex {
	class Exception {
	protected:
		string text;
		string source;
		int line;
		string date;
	public:
		Exception(string text, string source, int line, string date)
			: text(text), source(source), line(line), date(date)
		{
		}
		void printMessage() const {
			cout << "+++++++++++++ ERROR INFO +++++++++++++" << endl;
			cout << "Error Content : " << text << endl;
			cout << "Source : " << source << endl;
			cout << "Line number : " << line << endl;
			cout << "Date : " << date << endl;
		}
		string GetMessage() {

			return text + "  " + source + "  " + "  " + to_string(line) + "  " + date ;
		}


	};

	class NotFoundDataException :public Exception {
	public:
		NotFoundDataException(string text, string source, int line, string date)
			:Exception(text, source, line, date)
		{
		}
	};

	class WrongLoginException :public Exception {
	public:
		WrongLoginException(string text, string source, int line, string date)
			:Exception(text, source, line, date)
		{
		}
	};

}