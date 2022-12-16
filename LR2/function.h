#pragma once
#include <stack>
#include <map>
#include "Exception.h"


class Function
{
public:
	Function(int begin, int end);

	void push(int value, bool debug = false);
	void push(string label, bool debug = false);
	void pop(bool debug = false);
	void pop(string label, bool debug = false);
	void printStack();
	void printVariables();
	void clear();
	int size();
	void peek(string label, bool debug = false); //������� ������� ����� � �������� �������� ����������
	void dup(bool debug = false); //�������������� ����� �� ������� ����� (�.�. �������� � ���� ����� � ������� �����):
	void add(bool debug = false); //������� ��� ����� �� �����, ������� �� � ����� �������� � ����
	void sub(bool debug = false); //������� ��� ����� �� �����, ������ �� ������� ��������� ������ � �������� �������� � ����
	void div(bool debug = false); //������� ��� ����� �� �����, ��������� ������ �������� �� ������ � ������� �������� � ����
	void mul(bool debug = false); //������� ��� ����� �� �����, ����������� �� � ������������ �������� � ����
	bool isEqual(bool debug);
	bool isOver(bool debug);

	int funcBegin, funcEnd;
	stack <int> stack;
	map <string, int> variables;

};