#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 检查是否是整型
bool isInteger(char *s) {
	if (s[0] == '\0') {
		return false;
	}
	if (s[0] == '+' || s[0] == '-') {
		int idx = 1;
		while (s[idx] != '\0') {
			if (s[idx] < '0' || s[idx] > 9) {
				return false;
			}
		}
		if (idx == 1) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
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

	// 检查第一个字符，只能是+/-/./数字
	if (!(s[0] >= '0' && s[0] <= '9') || s[0] == '.' || s[0] == '+' || s[0] == '-') {
		return false;
	}

	int idx = 1;
	// 标记当前是否已经有小数点,如果有的话当前idx应该在小数位
	bool dot = false;
	if (s[0] == '.') {
		dot = true;
	}
	while (s[idx] != '\0') {
		
	}

	return false;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("the call pattern is as \"./vaild 2\n\"");
		return 1;
	}

	printf("the result is %s\n", isNumber(argv[1]) ? "True" : "False");
	return 0;
}
