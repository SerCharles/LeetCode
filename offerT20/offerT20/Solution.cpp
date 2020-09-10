#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		s = strip(s);
		if (s.size() == 0) return false;
		int point_place = -1;
		int e_place = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') point_place = i;
			if (s[i] == 'e') e_place = i;
		}
		//整数
		if (point_place == -1 && e_place == -1) {
			return isInt(s);
		}
		//小数
		else if (point_place != -1 && e_place == -1) {
			string first = s.substr(0, point_place);
			string second = s.substr(point_place + 1, s.size() - point_place - 1);
			bool first_true = isInt(first);
			bool second_true = isPositiveInt(second);
			bool first_empty = isEmpty(first);
			bool second_empty = isEmptyPositive(second);
			if (first_true && second_true) return true;
			if (first_empty && second_true) return true;
			if (first_true && second_empty) return true;
			return false;
		}
		//科学计数法整数
		else if (point_place == -1 && e_place != -1) {
			string first = s.substr(0, e_place);
			string second = s.substr(e_place + 1, s.size() - e_place - 1);
			return isInt(first) && isInt(second);
		}
		//科学计数法小数
		else if (point_place < e_place) {
			string first = s.substr(0, point_place);
			string second = s.substr(point_place + 1, e_place - point_place - 1);
			string third = s.substr(e_place + 1, s.size() - e_place - 1);
			bool first_true = isInt(first);
			bool second_true = isPositiveInt(second);
			bool first_empty = isEmpty(first);
			bool second_empty = isEmptyPositive(second);
			bool result = false;
			if (first_true && second_true) result = true;
			else if (first_empty && second_true)  result = true;
			else if (first_true && second_empty)  result = true;
			else result = false;
			result = result && isInt(third);
			return result;

		}
		else {
			return false;
		}
		return true;
	}
	bool isEmpty(string s) {
		if (s.size() == 0) return true;
		if (s.size() == 1 && (s[0] == '+' || s[0] == '-')) return true;
		else return false;
	}
	bool isEmptyPositive(string s) {
		if (s.size() == 0) return true;
		else return false;
	}

	bool isInt(string s) {
		if (s.size() == 0) return false;
		if (s[0] == '+' || s[0] == '-') {
			string new_s = s.substr(1, s.size() - 1);
			return isPositiveInt(new_s);
		}
		return isPositiveInt(s);
	}
	bool isPositiveInt(string s) {
		if (s.size() == 0) return false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < '0' || s[i] > '9') {
				return false;
			}
		}
		return true;
	}
	string strip(string s) {
		int start = 0;
		int end = s.size() - 1;
		while (start < s.size() && s[start] == ' ') {
			start++;
		}
		while (end >= 0 && s[end] == ' ') {
			end--;
		}
		string new_s;
		if (end < start) return new_s;
		new_s = s.substr(start, end - start + 1);
		return new_s;
	}
};