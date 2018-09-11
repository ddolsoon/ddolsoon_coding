#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

long long result = 0;

int test_cases;
string expression;
vector<string> arr;

bool isError(string expr) {


	stack<char> s;
	s.push(expr[0]);
	for (int i = 1; i < expr.size(); i++) {

		if (s.size() == 0) {
			s.push(expr[i]);
			continue;
		}

		if (s.top() == '(' && expr[i] == ')') {
			s.pop();
		}
		else if (s.top() == '{' && expr[i] == '}') {
			s.pop();
		}
		else if (s.top() == '[' && expr[i] == ']') {
			s.pop();
		}
		else {
			s.push(expr[i]);
		}
	}

	if (s.size() != 0) {
		return true;
	}
	else {
		return false;
	}

}

int main(void) {

	cin >> test_cases;
	while (test_cases > 0) {

		cin >> expression;
		arr.push_back(string(1, expression[0]));

		if (isError(expression)) {
			cout << '0' << '\n';
			arr.clear();
			test_cases--;
			continue;
		}

		for (int i = 1; i < expression.size(); i++) {

			if (arr[arr.size() - 1] == "(" && expression[i] == ')') {
				arr.pop_back();
				arr.push_back("1");
			}
			else if (arr[arr.size() - 1] == "{" && expression[i] == '}') {
				arr.pop_back();
				arr.push_back("2");
			}
			else if (arr[arr.size() - 1] == "[" && expression[i] == ']') {
				arr.pop_back();
				arr.push_back("3");
			}
			else {
				arr.push_back(string(1, expression[i]));
			}

		}


		arr.insert(arr.begin(), "(");
		arr.push_back(")");

		while (arr.size() != 1) {

			int open_bracket = 0;
			for (int i = arr.size() - 1; i >= 0; i--) {
				if (arr[i] == "(" || arr[i] == "{" || arr[i] == "[") {
					open_bracket = i;
					break;
				}
			}

			int close_bracket = arr.size() - 1;
			for (int i = open_bracket; i <arr.size(); i++) {
				if (arr[i] == ")" || arr[i] == "}" || arr[i] == "]") {
					close_bracket = i;
					break;
				}
			}

			long long temp_result = 0;

			for (int i = open_bracket + 1; i < close_bracket; i++) {
				temp_result += (stoll(arr[i]) % 100000000);
			}

			if (arr[open_bracket] == "(") {
				temp_result *= 1;
			}
			else if (arr[open_bracket] == "{") {
				temp_result *= 2;
			}
			else if (arr[open_bracket] == "[") {
				temp_result *= 3;
			}


			arr.insert(arr.begin() + close_bracket + 1, to_string(temp_result));

			for (int i = 0; i < close_bracket - open_bracket + 1; i++) {
				arr.erase(arr.begin() + open_bracket);
			}

		}

		cout << stoll(arr[0]) % 100000000 << '\n';

		arr.clear();
		test_cases--;

	}

	return 0;
}
