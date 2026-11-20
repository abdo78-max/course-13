#pragma once
#include<iostream>
#include<vector>
#include"clsMyStackArr.h"
#include<stack>
using namespace std;
class clsMyString
{
private:
	stack<string>_undo;
	stack<string>_redo;
	string value;
public:
	clsMyString(string value = "")
	{
		this->value = value;
	}
	void setValue(string value)
	{
		_undo.push(this->value);
		this->value = value;
		while (!_redo.empty())
		{
			_redo.pop();
		}
	}
	string getValue()
	{
		return value;
	}
	__declspec(property(get = getValue, put = setValue))string valueProperty;
	void undo()
	{
		if (_undo.empty())
		{
			return;
	    }
		_redo.push(value);
		value = _undo.top();
		_undo.pop();
	}
	void redo()
	{
		if (_redo.empty())
		{
			return;
		}
		_undo.push(value);
		value = _redo.top();
		_redo.pop();
	}
};

