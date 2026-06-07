#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 检查是否是整型
bool isInteger(char *s) {
	if (s[0] == '\0') {
		return false;
	}

	int idx = 0;
	if (s[0] == '+' || s[0] == '-') {
		idx = 1;
	}

	if (s[idx] == '\0') {
		return false;
	}

	while (s[idx] != '\0') {
		if (s[idx] < '0' || s[idx] > '9') {
			return false;
		}
		idx++;
	}
	return true;
}

bool isNumber(char* s) {
	// 空串，直接返回false
	if (s[0] == '\0') {
		return false;
	}

	// 单个字符就必须为数字
	if (strlen(s) == 1 && (s[0] < '0' || s[0] > '9')) {
		return false;
	}

	int idx = 0;
	int first = 0;
	int dot = -1;
	// 检查第一个字符，只能是+/-/./数字
	// if (!(s[0] >= '0' && s[0] <= '9') && s[0] != '.' && s[0] != '+' && s[0] != '-') {
	// 	return false;
	// }
	if (s[idx] >= '0' && s[idx] <= '9') {
		// do nothing
	} else if (s[idx] == '.') {
		first = idx + 1;
		idx = idx + 1;
		dot = idx;
	} else if (s[idx] == '+' || s[idx] == '-') {
		first = idx + 1;
		idx = idx + 1;
	} else {
		return false;
	}
	
	while (s[idx] != '\0') {
		// 是小数点的话要判断是否已经有了，小数点只允许有一个
		if (s[idx] == '.') {
			if (dot >= 0) {
				return false;
			} else {
				dot = idx;
				idx++;
				continue;
			}
		} else if (s[idx] == 'e' || s[idx] == 'E') {
			// 这里要判断一下前面的小数是否合法(整数的话不用管)
			if (idx - dot <= 1 && dot - first <= 1) {
				return false;
			} else {
				return isInteger(s + idx + 1);
			}
		} else if (s[idx] >= '0' && s[idx] <= '9') {
			idx++;
			continue;
		} else {
			return false;
		}
		idx++;
	}

	// 这里要判断一下前面的小数是否合法(整数的话不用管)
	if (idx - dot <= 1 && dot - first <= 1) {
		return false;
	} else {
		return true;
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("the call pattern is as \"./vaild 2\n\"");
		return 1;
	}

	printf("the result is %s\n", isNumber(argv[1]) ? "True" : "False");
	return 0;
}
